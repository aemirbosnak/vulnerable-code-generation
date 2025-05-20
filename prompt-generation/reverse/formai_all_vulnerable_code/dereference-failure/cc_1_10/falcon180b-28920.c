//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024
#define MAX_FILES 1000

struct file_info {
    char name[256];
    int size;
    int is_deleted;
};

int main(int argc, char *argv[]) {
    int fd, i, j, num_files = 0;
    char device[256] = "/dev/sda1";
    struct stat stat_buf;
    struct file_info *files = NULL;

    if (argc > 1) {
        strncpy(device, argv[1], 256);
    }

    fd = open(device, O_RDONLY);
    if (fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        return 1;
    }

    if (fstat(fd, &stat_buf) == -1) {
        printf("Error getting device stats: %s\n", strerror(errno));
        return 1;
    }

    printf("Device size: %ld bytes\n", stat_buf.st_size);

    files = malloc(sizeof(struct file_info) * MAX_FILES);

    for (i = 0; i < MAX_FILES; i++) {
        memset(files[i].name, 0, 256);
        files[i].size = 0;
        files[i].is_deleted = 0;
    }

    num_files = read_files(fd, files);

    printf("Found %d files:\n", num_files);

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }

    free(files);
    close(fd);

    return 0;
}

int read_files(int fd, struct file_info *files) {
    char buf[BUF_SIZE];
    int num_files = 0;

    while (read(fd, buf, BUF_SIZE) > 0) {
        int i = 0;
        while (i < BUF_SIZE) {
            if (buf[i] == 0) {
                if (i > 0 && i < BUF_SIZE - 1 && buf[i - 1] == '.' && buf[i + 1] == '.') {
                    // Deleted file
                    strncpy(files[num_files].name, &buf[0], i - 1);
                    files[num_files].name[i - 1] = '\0';
                    files[num_files].is_deleted = 1;
                } else {
                    strncpy(files[num_files].name, &buf[0], i);
                    files[num_files].name[i] = '\0';
                }
                num_files++;
                i += strlen(files[num_files - 1].name) + 1;
            } else {
                i++;
            }
        }
    }

    return num_files;
}