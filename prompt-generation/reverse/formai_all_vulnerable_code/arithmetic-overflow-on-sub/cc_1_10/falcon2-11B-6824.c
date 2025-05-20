//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    int key;
    int count = 0;
    int time_limit = 10;
    int correct_count = 0;
    struct timespec start, end;
    struct itimerspec timer;

    clock_gettime(CLOCK_MONOTONIC, &start);

    pid = fork();

    if (pid == 0) {
        // Child Process
        while(1) {
            count = 0;
            correct_count = 0;
            key = getchar();
            if (key == EOF) {
                exit(0);
            }

            clock_gettime(CLOCK_MONOTONIC, &end);
            if ((end.tv_sec - start.tv_sec) >= time_limit) {
                break;
            }

            if (key == 'a' || key == 'A') {
                correct_count++;
                count++;
            }
        }
        printf("You have typed %d keys in %d seconds.\n", count, (end.tv_sec - start.tv_sec));
        printf("You have typed %d keys correctly in %d seconds.\n", correct_count, (end.tv_sec - start.tv_sec));
        exit(0);
    }

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    waitpid(pid, &status, 0);

    printf("Child process returned with status %d\n", WEXITSTATUS(status));
}