//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024
#define NUM_CHILDREN 5

int main() {
    int fd[2];
    int child_pid[NUM_CHILDREN];
    char message[MAX_SIZE];
    int length;
    int i;

    if (pipe(fd) == -1) {
        printf("Error creating pipe\n");
        exit(1);
    }

    for (i = 0; i < NUM_CHILDREN; i++) {
        child_pid[i] = fork();
        if (child_pid[i] == -1) {
            printf("Error forking\n");
            exit(1);
        } else if (child_pid[i] == 0) {
            close(fd[0]);

            while (1) {
                memset(message, 0, MAX_SIZE);
                length = read(fd[1], message, MAX_SIZE);
                if (length <= 0) {
                    break;
                }
                printf("Child %d received message: %s\n", i+1, message);
            }

            exit(0);
        }
    }

    close(fd[1]);

    while (1) {
        memset(message, 0, MAX_SIZE);
        printf("Enter message to send: ");
        scanf("%s", message);

        if (strlen(message) > MAX_SIZE) {
            printf("Message too long\n");
            continue;
        }

        length = write(fd[0], message, strlen(message));
        if (length!= strlen(message)) {
            printf("Error writing to pipe\n");
            exit(1);
        }
    }

    return 0;
}