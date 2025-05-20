//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>

#define BUFFER_SIZE 1024

char *get_process_name(pid_t pid) {
    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/cmdline", pid);
    FILE *file = fopen(path, "r");
    if (!file) {
        return NULL;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, file);
    fclose(file);
    if (read <= 0) {
        free(line);
        return NULL;
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

void print_process_info(pid_t pid) {
    char *name = get_process_name(pid);
    if (!name) {
        printf("Process %d: Unknown\n", pid);
        return;
    }
    printf("Process %d: %s\n", pid, name);
    free(name);
}

int main() {
    printf("Enter PID of process to view:\n");
    pid_t pid;
    if (scanf("%d", &pid)!= 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Viewing process %d...\n", pid);
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        printf("Out of memory\n");
        return 1;
    }
    int status;
    while (waitpid(pid, &status, WUNTRACED)!= -1) {
        if (WIFEXITED(status)) {
            printf("Process %d exited with status %d\n", pid, WEXITSTATUS(status));
            break;
        } else if (WIFSTOPPED(status)) {
            int signal = WSTOPSIG(status);
            printf("Process %d stopped by signal %d\n", pid, signal);
        } else if (WIFCONTINUED(status)) {
            printf("Process %d continued\n", pid);
        }
    }
    free(buffer);
    return 0;
}