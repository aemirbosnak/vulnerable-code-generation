//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<string.h>

#define SIZE 20

typedef struct {
    int id;
    char name[20];
} person;

int shmid,shm_fd;
person *shm;

void create_shared_memory() {
    int i;
    shmid = shmget(IPC_PRIVATE, sizeof(person)*SIZE, IPC_CREAT|0600);
    if(shmid < 0) {
        printf("Error in shmget");
        exit(1);
    }
    shm = (person*)shmat(shmid, NULL, 0);
    if((int)shm == -1) {
        printf("Error in shmat");
        exit(1);
    }
    for(i=0;i<SIZE;i++) {
        shm[i].id = -1;
        strcpy(shm[i].name, " ");
    }
}

void write_to_shared_memory(int id,char *name) {
    int i;
    for(i=0;i<SIZE;i++) {
        if(shm[i].id == -1) {
            shm[i].id = id;
            strcpy(shm[i].name, name);
            break;
        }
    }
}

void read_from_shared_memory() {
    int i;
    for(i=0;i<SIZE;i++) {
        if(shm[i].id!= -1) {
            printf("ID: %d, Name: %s\n",shm[i].id,shm[i].name);
        }
    }
}

int main() {
    int i,pid;
    for(i=0;i<3;i++) {
        pid = fork();
        if(pid == 0) {
            create_shared_memory();
            write_to_shared_memory(i+1, "Child Process");
            sleep(1);
            read_from_shared_memory();
            shmdt(shm);
            exit(0);
        }
        else {
            wait(NULL);
        }
    }
    return 0;
}