//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 112233

struct shared_memory {
    int flag;
    char message[256];
};

int main() {
    int shmid;
    struct shared_memory *mem;

    // Creating shared memory segment
    shmid = shmget(SHM_KEY, sizeof(struct shared_memory), IPC_CREAT | 0666);
    if(shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attaching shared memory segment
    mem = (struct shared_memory*) shmat(shmid, NULL, 0);
    if(mem == (struct shared_memory*) -1) {
        perror("shmat");
        exit(1);
    }

    // Setting flag to 0
    mem->flag = 0;

    // Forking
    pid_t pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) { // Child Process
        while(1) {
            // Checking flag value
            if(mem->flag == 1) {
                printf("Received message from Parent Process: %s\n", mem->message);
                // Setting flag value back to 0
                mem->flag = 0;
            }
            sleep(1);
        }
    }
    else { // Parent Process
        char message[256];
        while(1) {
            printf("Enter a message to send to Child Process: ");
            fgets(message, 256, stdin);
            message[strlen(message)-1] = '\0';
            // Copying message to shared memory segment
            strcpy(mem->message, message);
            // Setting flag value to 1
            mem->flag = 1;
            sleep(1);
        }
    }

    // Detaching shared memory segment
    if(shmdt(mem) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Removing shared memory segment
    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}