//FormAI DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_MSG_SIZE 256
#define MAX_CHILD_PROCESSES 10

int child_pid[MAX_CHILD_PROCESSES];
int num_child = 0;

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nTerminating all child processes...\n");
        for (int i = 0; i < num_child; i++) {
            kill(child_pid[i], SIGTERM);
        }
    }
}

int main() {
    signal(SIGINT, signal_handler);

    pid_t pid;
    int fd1[2], fd2[2];
    char msg[MAX_MSG_SIZE];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        printf("Pipe creation failed.\n");
        exit(1);
    }

    printf("Enter number of child processes to create (max %d): ", MAX_CHILD_PROCESSES);
    scanf("%d", &num_child);

    for (int i = 0; i < num_child; i++) {
        pid = fork();
        if (pid == -1) {
            printf("Forking failed.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            close(fd1[1]);  // Close unused write end
            close(fd2[0]);  // Close unused read end
            int child_id = i+1;
            while (true) {
                read(fd1[0], msg, MAX_MSG_SIZE);
                printf("Child %d received message: %s\n", child_id, msg);
                if (strcmp(msg, "exit") == 0) {
                    printf("Child %d terminating...\n", child_id);
                    close(fd1[0]);
                    close(fd2[1]);
                    break;
                }
                strcat(msg, ",ACK");
                write(fd2[1], msg, strlen(msg)+1);
            }
            exit(0);
        } else {
            // Parent process
            close(fd1[0]);  // Close unused read end
            close(fd2[1]);  // Close unused write end
            printf("Child %d created with pid %d\n", i+1, pid);
            child_pid[i] = pid;
        }
    }

    while (true) {
        printf("Enter a message to send (type 'exit' to terminate): ");
        scanf("%s", msg);
        if (strcmp(msg, "exit") == 0) {
            break;
        }
        write(fd1[1], msg, strlen(msg)+1);
        for (int i = 0; i < num_child; i++) {
            read(fd2[0], msg, MAX_MSG_SIZE);
            printf("Received from child %d: %s\n", i+1, msg);
        }
    }

    // Send terminate message to child processes
    strcpy(msg, "exit");
    write(fd1[1], msg, strlen(msg)+1);

    // Wait for child processes to terminate
    int status;
    for (int i = 0; i < num_child; i++) {
        waitpid(child_pid[i], &status, 0);
    }

    printf("All child processes terminated.\n");

    return 0;
}