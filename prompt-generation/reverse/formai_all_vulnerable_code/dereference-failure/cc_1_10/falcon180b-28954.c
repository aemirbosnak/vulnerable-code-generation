//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

typedef struct {
    char *filename;
    int fd;
} file_t;

void init(file_t *files, int num_files) {
    int i;
    for (i = 0; i < num_files; i++) {
        files[i].filename = NULL;
        files[i].fd = -1;
    }
}

int open_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->fd = open(filename, O_RDONLY);
    if (file->fd == -1) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    return 0;
}

int read_file(file_t *file, char *buffer) {
    int bytes_read;
    bytes_read = read(file->fd, buffer, BUF_SIZE);
    if (bytes_read == -1) {
        printf("Error reading from file %s\n", file->filename);
        return -1;
    }
    return bytes_read;
}

int close_file(file_t *file) {
    if (file->fd!= -1) {
        close(file->fd);
        file->fd = -1;
    }
    free(file->filename);
    file->filename = NULL;
    return 0;
}

int main(int argc, char **argv) {
    int num_files;
    char input_buffer[BUF_SIZE];
    file_t files[10];

    init(files, 10);

    printf("Enter number of files to monitor: ");
    scanf("%d", &num_files);

    int i;
    for (i = 0; i < num_files; i++) {
        printf("Enter filename for file %d: ", i+1);
        scanf("%s", input_buffer);
        open_file(files+i, input_buffer);
    }

    while (1) {
        for (i = 0; i < num_files; i++) {
            char buffer[BUF_SIZE];
            int bytes_read = read_file(files+i, buffer);
            if (bytes_read <= 0) {
                continue;
            }
            printf("File %s changed\n", files[i].filename);
        }
        sleep(1);
    }

    return 0;
}