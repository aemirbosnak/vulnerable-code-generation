//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MESSAGES 100
#define MAX_SIZE 256

int main() {
    int shmid;
    char *shared_memory;
    char *message;

    key_t key;
    if ((key = ftok(".", '1')) == -1) {
        perror("ftok");
        return 1;
    }

    if ((shmid = shmget(key, MAX_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        return 1;
    }

    shared_memory = (char *) shmat(shmid, NULL, 0);

    if (shared_memory == (char *) -1) {
        perror("shmat");
        return 1;
    }

    while (1) {
        scanf("%s", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }

        if (strlen(message) > MAX_SIZE) {
            printf("Message too long, truncated\n");
            message[MAX_SIZE] = '\0';
        }

        if (strlen(message) > 0) {
            if (shmdt(shared_memory) == -1) {
                perror("shmdt");
                return 1;
            }

            if (shmctl(shmid, IPC_RMID, NULL) == -1) {
                perror("shmctl");
                return 1;
            }

            if ((shmid = shmget(key, MAX_SIZE, 0666)) == -1) {
                perror("shmget");
                return 1;
            }

            shared_memory = (char *) shmat(shmid, NULL, 0);

            if (shared_memory == (char *) -1) {
                perror("shmat");
                return 1;
            }
        }

        if (write(1, message, strlen(message)) == -1) {
            perror("write");
            return 1;
        }

        printf("Received message: %s\n", message);
    }

    return 0;
}