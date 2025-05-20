//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define BUFFER_SIZE 4096

typedef struct {
    char *filename;
    int fd;
    off_t size;
    char *buffer;
    int recover;
} FileData;

void print_help() {
    printf("Usage:./program [filename] [recover]\n");
    printf("Where:\n");
    printf("  filename - name of the file to recover\n");
    printf("  recover   - whether to attempt recovery (0 = no, 1 = yes)\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_help();
        return 1;
    }

    char *filename = argv[1];
    int recover = atoi(argv[3]);

    FileData data;
    data.filename = filename;
    data.fd = open(filename, O_RDONLY);

    if (data.fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat st;
    if (fstat(data.fd, &st) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        close(data.fd);
        return 1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("File is too large to recover.\n");
        close(data.fd);
        return 1;
    }

    data.size = st.st_size;
    data.buffer = malloc(BUFFER_SIZE);

    if (data.buffer == NULL) {
        printf("Out of memory.\n");
        close(data.fd);
        return 1;
    }

    int bytes_read = 0;
    while ((bytes_read = read(data.fd, data.buffer, BUFFER_SIZE)) > 0) {
        if (recover) {
            if (bytes_read > 0) {
                printf("Recovering file...\n");
                write(data.fd, data.buffer, bytes_read);
            }
        }
        else {
            printf("File contents:\n");
            while (bytes_read > 0) {
                printf("%s", data.buffer);
                bytes_read -= strlen(data.buffer);
                data.buffer += strlen(data.buffer);
            }
        }
    }

    free(data.buffer);
    close(data.fd);

    return 0;
}