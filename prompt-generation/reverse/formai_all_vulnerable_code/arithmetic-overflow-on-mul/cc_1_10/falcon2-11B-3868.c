//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid, status;
    int wstatus;
    int i;
    char buff[255];

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        while (1) {
            i = getpid();
            sprintf(buff, "Child process %d (PID %d)", i, pid);
            printf("%s\n", buff);

            i = getpid();
            sprintf(buff, "Child process %d (PID %d)", i, pid);
            printf("%s (%d%%)\n", buff, i * 100 / getpid());

            sleep(1);
        }
    } else {
        // Parent process
        while (1) {
            i = getpid();
            sprintf(buff, "Parent process %d (PID %d)", i, pid);
            printf("%s\n", buff);

            i = getpid();
            sprintf(buff, "Parent process %d (PID %d)", i, pid);
            printf("%s (%d%%)\n", buff, i * 100 / getpid());

            waitpid(pid, &wstatus, 0);
            if (wstatus > 0) {
                printf("Child process %d terminated with status %d\n", wstatus, wstatus);
            }

            sleep(1);
        }
    }
}