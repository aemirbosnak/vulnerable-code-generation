//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define SEM_ID 0x2000
#define MSG_ID 0x3000
#define SHM_ID 0x4000
#define KEY 0x1234

int main() {
    int shmid = shmget(KEY, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    char *buffer = shm;
    pid_t pid1 = fork();
    if (pid1 == 0) {
        for (int i = 0; i < MAX_SIZE; i++) {
            buffer[i] = 'A' + i;
        }
        buffer[MAX_SIZE - 1] = '\0';
        printf("Child 1 wrote to shared memory\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Child 1 has written to shared memory\n");
    }
    pid_t pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2 reading from shared memory: %s\n", buffer);
        exit(0);
    } else {
        wait(NULL);
    }
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    return 0;
}