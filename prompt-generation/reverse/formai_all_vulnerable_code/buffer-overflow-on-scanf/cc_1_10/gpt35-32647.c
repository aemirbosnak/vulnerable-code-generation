//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// global variables
int shmid;

// function to show menu
void show_menu() {
    printf("\n\n***** SHARED MEMORY *****\n");
    printf("1. Write data to shared memory\n");
    printf("2. Read data from shared memory\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// function to write data to shared memory
void write_to_shared_memory() {
    char data[50];
    printf("\nEnter data to write on shared memory (max length: 50): ");
    scanf("%s", data);
    char *shm_addr;
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if(shm_addr == (char*) -1) {
        perror("shmat error");
        exit(EXIT_FAILURE);
    }
    strcpy(shm_addr, data);
    shmdt(shm_addr);
    printf("\nData written to shared memory successfully!\n");
}

// function to read data from shared memory
void read_from_shared_memory() {
    char *shm_addr;
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if(shm_addr == (char*) -1) {
        perror("shmat error");
        exit(EXIT_FAILURE);
    }
    printf("\nData in shared memory: %s\n", shm_addr);
    shmdt(shm_addr);
}

int main() {
    // create shared memory segment
    key_t key = ftok("shared_mem.c", 1);
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);
    if(shmid == -1) {
        perror("Shared memory creation error");
        exit(EXIT_FAILURE);
    }

    int choice;
    do {
        show_menu();  // print menu options
        scanf("%d", &choice);  // get user choice
        switch(choice) {
            case 1:
                write_to_shared_memory();  // write data to shared memory
                break;
            case 2:
                read_from_shared_memory();  // read data from shared memory
                break;
            case 3:
                printf("\nExiting...\n");
                shmctl(shmid, IPC_RMID, NULL);  // remove shared memory segment
                break;
            default:
                printf("\nInvalid choice! Please try again...\n");
        }
        sleep(1);  // sleep for 1 second between iterations
    } while(choice != 3);
    
    return 0;
}