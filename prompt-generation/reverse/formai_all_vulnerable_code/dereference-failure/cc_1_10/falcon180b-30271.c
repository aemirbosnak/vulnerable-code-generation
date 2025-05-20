//Falcon-180B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define BUF_SIZE 1024

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    char *buf = (char *)mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        while (1) {
            char c = getchar();
            if (c == '\n') {
                munmap(buf, BUF_SIZE);
                close(fd);
                exit(0);
            }
            memcpy(buf, &c, 1);
            mprotect(buf, BUF_SIZE, PROT_READ);
        }
    } else {
        while (1) {
            mprotect(buf, BUF_SIZE, PROT_WRITE);
            char c = *buf;
            if (c == '\n') {
                munmap(buf, BUF_SIZE);
                close(fd);
                exit(0);
            }
            putchar(c);
        }
    }

    return 0;
}