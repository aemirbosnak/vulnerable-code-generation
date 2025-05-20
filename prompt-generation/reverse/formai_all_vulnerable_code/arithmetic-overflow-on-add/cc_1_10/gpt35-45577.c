//FormAI DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
/* This post-apocalyptic C interprocess communication example program demonstrates how two processes can communicate using shared memory and semaphores. The scenario is that two survivors are trying to signal each other in order to coordinate their efforts in scavenging for resources. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>

#define SHM_SIZE 1024
#define SEM_KEY 666
#define SHM_KEY 777

/* Define a struct encapsulating the shared data */
struct shared_data {
    int num_resources;
    char message[256];
};

/* Decrement the value of the semaphore pointed to by sem_id */
void sem_wait(int sem_id) {
    struct sembuf sem_op = {0};
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    semop(sem_id, &sem_op, 1);
}

/* Increment the value of the semaphore pointed to by sem_id */
void sem_signal(int sem_id) {
    struct sembuf sem_op = {0};
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;
    semop(sem_id, &sem_op, 1);
}

int main() {
    int shm_id;
    int sem_id;
    struct shared_data *data;

    /* Create the semaphore */
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget() failed");
        exit(EXIT_FAILURE);
    }

    /* Initialize the semaphore */
    if (semctl(sem_id, 0, SETVAL, 1) == -1) {
        perror("semctl() failed");
        exit(EXIT_FAILURE);
    }

    /* Create the shared memory segment */
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    /* Attach to the shared memory segment */
    data = (struct shared_data*) shmat(shm_id, NULL, 0);
    if (data == (struct shared_data*) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    /* Set up the shared data */
    data->num_resources = 5;
    sprintf(data->message, "We need more supplies!");

    /* Fork a child process */
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        /* Child process */
        sem_wait(sem_id);

        /* Read the shared data */
        printf("Child process reading shared data: num_resources=%d, message=%s\n", data->num_resources, data->message);

        /* Update the shared data */
        data->num_resources += 2;
        sprintf(data->message, "Found some canned food and a crowbar.");

        sem_signal(sem_id);

        /* Detach from the shared memory segment */
        shmdt((void*) data);

        return(EXIT_SUCCESS);
    } else {
        /* Parent process */
        sem_wait(sem_id);

        /* Read the shared data */
        printf("Parent process reading shared data: num_resources=%d, message=%s\n", data->num_resources, data->message);

        /* Update the shared data */
        data->num_resources += 3;
        sprintf(data->message, "I found a map and a medical kit.");

        sem_signal(sem_id);

        /* Wait for the child process to finish */
        waitpid(pid, NULL, 0);

        /* Read the shared data one more time */
        printf("Parent process reading shared data: num_resources=%d, message=%s\n", data->num_resources, data->message);

        /* Detach from the shared memory segment */
        shmdt((void*) data);

        /* Delete the semaphore */
        if (semctl(sem_id, 0, IPC_RMID) == -1) {
            perror("semctl() failed");
        }

        /* Delete the shared memory segment */
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("shmctl() failed");
        }

        return(EXIT_SUCCESS);
    }
}