//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define SHMSIZE 100

typedef struct {
    int id;
    char name[20];
    bool isDone;
} task;

int main() {
    int shmid;
    key_t key;
    task *taskList;
    char *sharedMem;
    bool keepRunning = true;

    // generate unique key
    if ((key = ftok("shared_memory_example", 'R')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // allocate memory
    if ((shmid = shmget(key, SHMSIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget error");
        exit(1);
    }

    // attach to shared memory
    sharedMem = shmat(shmid, (void *)0, 0);
    if (sharedMem == (char *)(-1)) {
        perror("shmat error");
        exit(1);
    }

    // assign struct to shared memory pointer
    taskList = (task *)sharedMem;

    // initialize task list
    for (int i = 0; i < 10; i++) {
        taskList[i].id = i + 1;
        sprintf(taskList[i].name, "Task %d", i + 1);
        taskList[i].isDone = false;
    }

    // print initial task list
    printf("Initial task list:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d\tName: %s\tIs Done: %s\n",
               taskList[i].id,
               taskList[i].name,
               taskList[i].isDone ? "true" : "false");
    }

    while (keepRunning) {
        // receive input
        printf("\nEnter ID of completed task or q to quit: ");
        char input[20];
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;

        // validate input
        if (strcmp(input, "q") == 0) {
            keepRunning = false;
        } else {
            int id = atoi(input);
            if (id < 1 || id > 10) {
                printf("Invalid ID. Please try again.\n");
            } else if (taskList[id - 1].isDone) {
                printf("Task already marked as done. Please try again.\n");
            } else {
                // mark task as done
                taskList[id - 1].isDone = true;

                // print updated task list
                printf("\nUpdated task list:\n");
                for (int i = 0; i < 10; i++) {
                    printf("ID: %d\tName: %s\tIs Done: %s\n",
                           taskList[i].id,
                           taskList[i].name,
                           taskList[i].isDone ? "true" : "false");
                }
            }
        }
    }

    // detach from shared memory
    if (shmdt(sharedMem) == -1) {
        perror("shmdt error");
        exit(1);
    }

    // remove shared memory
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl error");
        exit(1);
    }

    return 0;
}