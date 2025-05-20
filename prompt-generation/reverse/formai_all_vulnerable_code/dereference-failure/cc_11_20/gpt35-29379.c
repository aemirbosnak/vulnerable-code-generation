//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/*-----------------------------------------------*/
/* Program Name: Interprocess CommunicationExample*/
/* Description: This program demonstrates an       */
/*              example of interprocess communication */
/*              using shared memory and semaphores   */
/*              in C programming language.           */
/* Author: Claude Shannon                           */
/*-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>

#define SHM_KEY 1234

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

int main() {
    /* Create shared memory segment */
    int shmid;
    if ((shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    
    /* Attach shared memory segment to process */
    int *shared_data;
    if ((shared_data = shmat(shmid, NULL, 0)) == (int*) -1) {
        perror("shmat");
        exit(1);
    }
    
    /* Create semaphore to synchronize access to shared memory */
    int semid;
    if ((semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666)) < 0) {
        perror("semget");
        exit(1);
    }
    
    /* Initialize semaphore */
    union semun arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) < 0) {
        perror("semctl");
        exit(1);
    }
    
    /* Fork process to create two child processes */
    pid_t pid1, pid2;
    if ((pid1 = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid1 == 0) {
        /* Writer process */
        while (1) {
            /* Wait for semaphore */
            struct sembuf sops;
            sops.sem_num = 0;
            sops.sem_op = -1;
            sops.sem_flg = 0;
            if (semop(semid, &sops, 1) < 0) {
                perror("semop");
                exit(1);
            }
            
            /* Write to shared memory */
            *shared_data = rand() % 100;
            
            /* Release semaphore */
            sops.sem_op = 1;
            if (semop(semid, &sops, 1) < 0) {
                perror("semop");
                exit(1);
            }
            
            usleep(1000000);
        }
    } else {
        if ((pid2 = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid2 == 0) {
            /* Reader process */
            while (1) {
                /* Wait for semaphore */
                struct sembuf sops;
                sops.sem_num = 0;
                sops.sem_op = -1;
                sops.sem_flg = 0;
                if (semop(semid, &sops, 1) < 0) {
                    perror("semop");
                    exit(1);
                }
                
                /* Read from shared memory */
                printf("Shared data: %d\n", *shared_data);
                
                /* Release semaphore */
                sops.sem_op = 1;
                if (semop(semid, &sops, 1) < 0) {
                    perror("semop");
                    exit(1);
                }
                
                usleep(1000000);
            }
        } else {
            /* Parent process */
            /* Wait for child processes to terminate */
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
            
            /* Detach shared memory segment from process */
            if (shmdt(shared_data) < 0) {
                perror("shmdt");
                exit(1);
            }
            
            /* Remove shared memory segment */
            if (shmctl(shmid, IPC_RMID, NULL) < 0) {
                perror("shmctl");
                exit(1);
            }
            
            /* Remove semaphore */
            if (semctl(semid, 0, IPC_RMID) < 0) {
                perror("semctl");
                exit(1);
            }
        }
    }
    
    return 0;
}