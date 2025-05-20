//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

void read_file(int fd, char *buffer) {
    ssize_t bytes_read = 0;
    while ((bytes_read = read(fd, buffer + bytes_read, MAX_FILE_SIZE - bytes_read)) > 0) {
        if (bytes_read == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                fprintf(stderr, "Error reading file: %s\n", strerror(errno));
                exit(1);
            }
        }
    }
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(1);
    }
    buffer[bytes_read] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    read_file(fd, buffer);

    char *signature = "intrusion_detected";
    size_t signature_len = strlen(signature);
    char *ptr = strstr(buffer, signature);

    if (ptr!= NULL) {
        fprintf(stdout, "Intrusion detected at offset %zu\n", ptr - buffer);
    } else {
        fprintf(stdout, "No intrusion detected\n");
    }

    close(fd);
    free(buffer);

    return 0;
}