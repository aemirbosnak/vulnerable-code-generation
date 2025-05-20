//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <device> <output>\n", argv[0]);
        return 1;
    }

    int device = open(argv[1], O_RDONLY);
    if (device == -1) {
        perror("open");
        return 1;
    }

    struct stat stat;
    fstat(device, &stat);

    void *buffer = malloc(BUFFER_SIZE);

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen");
        return 1;
    }

    unsigned char *data = (unsigned char *) buffer;
    while (1) {
        int bytes_read = read(device, buffer, BUFFER_SIZE);
        if (bytes_read == 0) {
            break;
        }

        int i = 0;
        while (i < bytes_read) {
            if (data[i] == 0x00) {
                fprintf(output, "\n");
            } else {
                fprintf(output, "%c", data[i]);
            }
            i++;
        }
    }

    free(buffer);
    fclose(output);
    close(device);

    return 0;
}