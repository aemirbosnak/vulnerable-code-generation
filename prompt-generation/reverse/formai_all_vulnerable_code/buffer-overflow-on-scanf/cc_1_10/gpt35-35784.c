//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
//This program demonstrates Interprocess Communication using shared memory and semaphores in C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHMSIZE 1024 //Define maximum size for the shared memory variable
#define SEMKEY 5555 //Semaphore key value

//Semaphore operations
void semLock(int, int);
void semUnlock(int, int);

int main() {
    int shmid, semid;
    char *shm, message[SHMSIZE];
    key_t shmkey, semkey;

    //Create shared memory
    shmkey = ftok(".", 's');
    if ((shmid = shmget(shmkey, SHMSIZE, IPC_CREAT | 0666)) < 0) {
        perror("Failed to create shared memory segment");
        exit(1);
    }

    //Attach to shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("Failed to attach to shared memory segment");
        exit(1);
    }

    //Create semaphore
    semkey = ftok(".", 'a');
    if ((semid = semget(semkey, 1, IPC_CREAT | 0666)) == -1) {
        perror("Failed to create semaphore");
        exit(1);
    }

    //Initialize semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("Failed to initialize semaphore");
        exit(1);
    }

    //Main program loop
    while(1) {
        printf("\nEnter message: ");
        scanf("%s", message);

        //Lock semaphore
        semLock(semid, 0);

        //Write to shared memory
        sprintf(shm, "%s", message);

        //Unlock semaphore
        semUnlock(semid, 0);

        //Display message
        printf("Message sent: %s\n", message);

        //Sleep for 1 second
        sleep(1);
    }
    return 0;
}

void semLock(int semid, int semnum) {
    struct sembuf sops;
    sops.sem_num = semnum;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;

    if (semop(semid, &sops, 1) == -1) {
        perror("Failed to lock semaphore");
        exit(1);
    }
}

void semUnlock(int semid, int semnum) {
    struct sembuf sops;
    sops.sem_num = semnum;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;

    if (semop(semid, &sops, 1) == -1) {
        perror("Failed to unlock semaphore");
        exit(1);
    }
}