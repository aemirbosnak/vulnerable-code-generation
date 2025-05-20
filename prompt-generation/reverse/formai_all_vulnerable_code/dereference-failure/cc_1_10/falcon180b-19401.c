//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUF_SIZE 1024

char *read_file(int fd, int *size) {
    char *buf = malloc(BUF_SIZE);
    int n = 0;
    while ((n = read(fd, buf + n, BUF_SIZE - n)) > 0) {
        buf = realloc(buf, n + BUF_SIZE);
    }
    buf[n] = '\0';
    *size = n;
    return buf;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <pid> <process_name>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);
    char *process_name = argv[2];

    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open %s\n", path);
        exit(1);
    }

    char *cmdline = read_file(fd, NULL);
    close(fd);

    char *token = strtok(cmdline, "\0");
    while (token!= NULL) {
        if (strcmp(token, process_name) == 0) {
            printf("Process found: %s (PID: %d)\n", process_name, pid);
            exit(0);
        }
        token = strtok(NULL, "\0");
    }

    printf("Process not found: %s (PID: %d)\n", process_name, pid);
    exit(1);
}