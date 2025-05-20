//Falcon-180B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <assert.h>

#define BUF_SIZE 1024

char *filename = "test.txt";
int fd;

void read_file(void) {
    char buf[BUF_SIZE];
    ssize_t n;

    while ((n = read(fd, buf, BUF_SIZE)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }

    if (n < 0) {
        perror("read");
    }
}

void write_file(void) {
    char buf[BUF_SIZE];
    ssize_t n;

    printf("Enter text to write: ");
    fgets(buf, BUF_SIZE, stdin);
    n = strlen(buf);

    if (buf[n - 1] == '\n') {
        buf[n - 1] = '\0';
        n--;
    }

    while ((n = write(fd, buf, n)) > 0) {
        // Do nothing
    }

    if (n < 0) {
        perror("write");
    }
}

void close_file(void) {
    close(fd);
}

int main(int argc, char *argv[]) {
    pid_t pid;

    if ((fd = open(filename, O_RDWR | O_CREAT, 0666)) < 0) {
        perror("open");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        read_file();
        close_file();
        exit(0);
    } else {
        write_file();
        close_file();
        wait(NULL);
    }

    return 0;
}