//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    int id;
    int status;
    char name[20];
    char message[MAX_SIZE];
} message_t;

int main() {
    int shmid;
    key_t key;
    message_t *shm;

    // Create shared memory segment
    key = ftok(".", 65);
    shmid = shmget(key, sizeof(message_t), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = (message_t *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared data
    shm->id = 0;
    shm->status = FALSE;
    strcpy(shm->name, "Sir Lancelot");
    strcpy(shm->message, "Hail, King Arthur!");

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);
        shm->status = TRUE;
        printf("Message sent by %s\n", shm->name);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
        printf("Message received from %s: %s\n", shm->name, shm->message);
    } else {
        // Error forking
        printf("Error forking process\n");
        exit(1);
    }

    return 0;
}