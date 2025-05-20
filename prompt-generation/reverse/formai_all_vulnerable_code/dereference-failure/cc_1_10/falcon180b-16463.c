//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILE_SIZE (1024*1024*1024) // 1GB

typedef struct {
    char *filename;
    int inode;
    int size;
    int deleted;
} file_info_t;

file_info_t *read_inode_table(int fd) {
    file_info_t *files = malloc(sizeof(file_info_t) * MAX_FILE_SIZE);
    int i = 0;
    while (i < MAX_FILE_SIZE) {
        if (read(fd, &files[i], sizeof(file_info_t)) == -1) {
            break;
        }
        i++;
    }
    return files;
}

void print_files(file_info_t *files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }
}

void recover_files(file_info_t *files, int count) {
    printf("Recovering files...\n");
    for (int i = 0; i < count; i++) {
        if (files[i].deleted) {
            char filename[256];
            sprintf(filename, "recovered_%d.txt", i);
            int fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if (fd == -1) {
                printf("Error creating file: %s\n", strerror(errno));
            } else {
                write(fd, &files[i], sizeof(file_info_t));
                close(fd);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <device> <mount_point>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        return 1;
    }
    char *mount_point = argv[2];
    file_info_t *files = read_inode_table(fd);
    if (files == NULL) {
        printf("Error reading inode table\n");
        return 1;
    }
    int count = 0;
    while (count < MAX_FILE_SIZE && files[count].filename[0]!= '\0') {
        count++;
    }
    print_files(files, count);
    recover_files(files, count);
    close(fd);
    return 0;
}