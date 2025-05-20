//Falcon-180B DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>

void shape_shift(char* file_name) {
    char* new_file_name = "new_file.txt";
    int fd = open(file_name, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    int file_size = lseek(fd, 0, SEEK_END);
    char* file_content = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_content == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    char* new_file_content = malloc(file_size);
    memcpy(new_file_content, file_content, file_size);
    int i = 0;
    while (i < file_size) {
        if (new_file_content[i] == 'a') {
            new_file_content[i] = 'b';
        }
        i++;
    }
    munmap(file_content, file_size);
    close(fd);
    fd = open(new_file_name, O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    write(fd, new_file_content, file_size);
    close(fd);
    free(new_file_content);
    printf("Shape shifting complete!\n");
}

int main() {
    char* file_name = "file.txt";
    shape_shift(file_name);
    return 0;
}