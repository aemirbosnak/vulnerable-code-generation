//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10
#define SHM_KEY 5678

int shmid;
char *shmptr;

typedef struct {
    int val;
    int pid;
} shared_data;

void init_shmem() {
    int shmflg = IPC_CREAT | 0666;
    shmid = shmget(SHM_KEY, SIZE * sizeof(shared_data), shmflg);
    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }
    shmptr = (char *) shmat(shmid, NULL, 0);
    if ((int) shmptr == -1) {
        printf("Error in shmat\n");
        exit(1);
    }
    memset(shmptr, 0, SIZE * sizeof(shared_data));
}

void write_to_shmem(int index, int val, int pid) {
    shared_data *ptr = (shared_data *) shmptr;
    ptr[index].val = val;
    ptr[index].pid = pid;
}

void read_from_shmem(int index) {
    shared_data *ptr = (shared_data *) shmptr;
    printf("Value at index %d: %d\n", index, ptr[index].val);
    printf("PID of process that wrote to index %d: %d\n", index, ptr[index].pid);
}

int main(int argc, char *argv[]) {
    int index = 0;
    int val = 42;
    int pid = getpid();
    int status;

    init_shmem();

    if (fork() == 0) {
        write_to_shmem(index, val, pid);
        exit(0);
    }

    wait(&status);

    read_from_shmem(index);

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}