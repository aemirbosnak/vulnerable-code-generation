//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1024

typedef struct {
    int pid;
    char name[MAX_SIZE];
    int size;
} process_t;

int compare_size(const void *a, const void *b) {
    process_t *p1 = (process_t *) a;
    process_t *p2 = (process_t *) b;

    if (p1->size > p2->size) {
        return -1;
    } else if (p1->size < p2->size) {
        return 1;
    } else {
        return 0;
    }
}

void get_process_info(int pid, char *name, int *size) {
    char path[MAX_SIZE];
    sprintf(path, "/proc/%d/statm", pid);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open %s\n", path);
        exit(1);
    }

    char buffer[MAX_SIZE];
    int bytes_read = read(fd, buffer, MAX_SIZE);
    if (bytes_read == -1) {
        printf("Error: Could not read %s\n", path);
        exit(1);
    }

    char *token = strtok(buffer, " ");
    int pages = atoi(token);

    *size = pages * getpagesize();

    close(fd);
}

int main() {
    char command[MAX_SIZE];
    printf("Enter command: ");
    scanf("%s", command);

    pid_t pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        exit(1);
    } else if (pid == -1) {
        printf("Error: Could not fork\n");
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);

    char status_char;
    if (WIFEXITED(status)) {
        status_char = 'X';
    } else if (WIFSIGNALED(status)) {
        status_char = 'S';
    } else {
        status_char = '?';
    }

    process_t process;
    process.pid = pid;
    get_process_info(pid, process.name, &process.size);

    printf("%-5c %-10d %-16s %-10d\n", status_char, process.pid, process.name, process.size);

    return 0;
}