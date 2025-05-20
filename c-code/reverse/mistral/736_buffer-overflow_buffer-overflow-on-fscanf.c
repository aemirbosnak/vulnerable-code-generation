#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int fd[2];
    pipe(fd);

    pid = fork();

    if (pid > 0) { // parent process
        char buffer[10];
        close(fd[0]);
        write(fd[1], "01234567890123456789012345678901234567890123456789012345678901234567890", 100);
        close(fd[1]);
        wait(NULL);
    } else { // child process
        char buffer[10];
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("CPU usage: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
