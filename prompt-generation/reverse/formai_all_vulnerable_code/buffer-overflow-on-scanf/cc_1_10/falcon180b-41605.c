//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 5678
#define SEM_KEY 1234
#define BUFFER_SIZE 100
#define MAX_PROCESSES 5

char buffer[BUFFER_SIZE];
int buffer_index = 0;
int sem_id;
int shm_id;

void initialize() {
    sem_id = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }
    semctl(sem_id, 0, SETVAL, 1);

    shm_id = shmget(SHM_KEY, BUFFER_SIZE, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }
}

void send_message(int sender_id, char* message) {
    int id = shmget(SHM_KEY, 0, 0);
    char* shm_buffer = (char*)shmat(id, NULL, 0);
    strcat(shm_buffer, message);
    shmdt(shm_buffer);
}

void receive_message(int receiver_id) {
    int id = shmget(SHM_KEY, 0, 0);
    char* shm_buffer = (char*)shmat(id, NULL, 0);
    strcpy(buffer, shm_buffer);
    shmdt(shm_buffer);
    printf("Received message: %s\n", buffer);
}

int main() {
    int num_processes = 0;
    int *process_ids;
    int i;

    initialize();

    while (num_processes < MAX_PROCESSES) {
        printf("Enter number of processes (up to %d): ", MAX_PROCESSES - num_processes);
        scanf("%d", &num_processes);
    }

    process_ids = (int*)malloc(num_processes * sizeof(int));

    for (i = 0; i < num_processes; i++) {
        int pid = fork();
        if (pid == 0) {
            printf("Child process %d created\n", getpid());
            if (i == 0) {
                send_message(getpid(), "Hello from process 1");
            } else {
                send_message(getpid(), "Hello from process 2");
            }
            exit(0);
        } else {
            process_ids[i] = pid;
        }
    }

    for (i = 0; i < num_processes; i++) {
        int status;
        waitpid(process_ids[i], &status, 0);
        printf("Child process %d terminated\n", process_ids[i]);
    }

    return 0;
}