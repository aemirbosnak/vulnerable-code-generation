//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int shmid;
char *shmaddr;

void main() {

    int fd[2]; // file descriptors for pipes
    pid_t pid; // process id for child process

    if(pipe(fd) == -1) { // create a pipe
        printf("Pipe failed\n");
        exit(1);
    }

    switch(pid = fork()) { // create a child process
        case -1:
            printf("Fork Failed\n");
            exit(1);
        case 0: // child process
            close(fd[0]); // close reading end of pipe
            write(fd[1], "CHILD", 6); // write to pipe
            exit(0);
        default: // parent process
            close(fd[1]); // close writing end of pipe
            read(fd[0], &shmaddr, SIZE); // read from pipe
            printf("Shared memory address: %p\n", shmaddr);
            break;
    }

    if(shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777) == -1) { // create shared memory
        printf("Shared memory failed\n");
        exit(1);
    }

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777); // get shared memory ID

    if(shmid == -1) {
        printf("Shared memory failed\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0); // attach shared memory to process

    if(shmaddr == (char *) -1) {
        printf("Shared memory failed\n");
        exit(1);
    }

    strcpy(shmaddr, "PARENT"); // write to shared memory

    if(waitpid(pid, NULL, 0) == -1) { // wait for child process to exit
        printf("Wait failed\n");
        exit(1);
    }

    printf("Child exited\n");

    shmdt(shmaddr); // detach shared memory from process

    if(shmdt(shmaddr) == -1) {
        printf("Shared memory failed\n");
        exit(1);
    }

    shmctl(shmid, IPC_RMID, NULL); // remove shared memory

    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Shared memory failed\n");
        exit(1);
    }

    exit(0);
}