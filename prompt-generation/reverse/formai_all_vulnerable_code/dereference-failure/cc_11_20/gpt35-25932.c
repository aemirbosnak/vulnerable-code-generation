//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSIZE 1024

struct shared_memory {
    char message[SHMSIZE];
    int msg_len;
    int ready;
};

int main() {
    int shmid;
    key_t key;
    struct shared_memory *shmptr;

    key = ftok("shared_mem_example", 'R');
    shmid = shmget(key, sizeof(struct shared_memory), 0666|IPC_CREAT);

    if(shmid < 0) {
        perror("Error: Failed to allocate shared memory");
        exit(1);
    }

    shmptr = (struct shared_memory *) shmat(shmid, NULL, 0);

    if(shmptr == (struct shared_memory *) -1) {
        perror("Error: Failed to attach shared memory");
        exit(1);
    }

    shmptr->msg_len = 0;
    shmptr->ready = 0;

    pid_t pid = fork();

    if(pid < 0) {
        perror("Error: Failed to fork child process");
        exit(1);
    } else if(pid == 0) {
        printf("I am the child process with pid: %d\n", getpid());

        while(1) {
            if(shmptr->ready == 1) {
                printf("Received message from parent process: %s\n", shmptr->message);
                shmptr->msg_len = strlen(shmptr->message);
                shmptr->ready = 0;
            }

            if(strncmp(shmptr->message, "exit", 4) == 0 || strncmp(shmptr->message, "quit", 4) == 0) {
                break;
            }

            sleep(1);
        }

        printf("Child process exiting\n");
        exit(0);

    } else {
        printf("I am the parent process with pid: %d\n", getpid());

        char buffer[SHMSIZE];

        while(1) {
            printf("Enter message to send to child process (or enter q/quit/exit to quit): ");
            fgets(buffer, SHMSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if(strlen(buffer) > 0) {
                strncpy(shmptr->message, buffer, SHMSIZE);
                shmptr->ready = 1;
            }

            if(strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "quit", 4) == 0 || strncmp(buffer, "q", 1) == 0) {
                break;
            }

            sleep(1);
        }

        printf("Parent process exiting\n");
        exit(0);
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}