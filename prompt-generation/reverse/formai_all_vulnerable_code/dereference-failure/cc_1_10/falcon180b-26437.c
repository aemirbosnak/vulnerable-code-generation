//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SEM_KEY 1234
#define SEM_ID (IPC_PRIVATE | (SEM_KEY << 16))
#define SEM_VALUE 1
#define SEM_PERM (0666 | IPC_CREAT | IPC_EXCL)

int main() {
    int shmid, semid, i;
    char *shmptr;
    struct sembuf sembuf;

    semid = semget(SEM_ID, SEM_VALUE, SEM_PERM);
    if(semid == -1) {
        printf("Error: semget() failed\n");
        exit(1);
    }

    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0777);
    if(shmid == -1) {
        printf("Error: shmget() failed\n");
        exit(2);
    }

    shmptr = shmat(shmid, NULL, 0);
    if(shmptr == (void *) -1) {
        printf("Error: shmat() failed\n");
        exit(3);
    }

    *shmptr = 1;
    for(i = 0; i < 10; i++) {
        sembuf.sem_num = 0;
        sembuf.sem_op = -1;
        sembuf.sem_flg = 0;
        if(semop(semid, &sembuf, 1) == -1) {
            printf("Error: semop() failed\n");
            exit(4);
        }
        printf("Process %d is waiting for the semaphore\n", getpid());
        sleep(1);
    }

    if(shmdt(shmptr) == -1) {
        printf("Error: shmdt() failed\n");
        exit(5);
    }

    if(semctl(semid, 0, IPC_RMID) == -1) {
        printf("Error: semctl() failed\n");
        exit(6);
    }

    return 0;
}