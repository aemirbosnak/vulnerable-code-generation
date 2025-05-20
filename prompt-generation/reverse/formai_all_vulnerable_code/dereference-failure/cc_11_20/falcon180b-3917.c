//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
    int shmid, shm_fd;
    char *shm_ptr;
    pid_t pid;
    int status;

    if (argc!= 2) {
        printf("Usage:./program [child/parent]\n");
        exit(1);
    }

    if (strcmp(argv[1], "child") == 0) {
        shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
        if (shmid == -1) {
            perror("shmget");
            exit(1);
        }

        shm_ptr = shmat(shmid, NULL, 0);
        if (shm_ptr == (void *) -1) {
            perror("shmat");
            exit(1);
        }

        sprintf(shm_ptr, "Hello from child process!");
        sleep(5);
        exit(0);
    } else if (strcmp(argv[1], "parent") == 0) {
        shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
        if (shmid == -1) {
            perror("shmget");
            exit(1);
        }

        shm_ptr = shmat(shmid, NULL, 0);
        if (shm_ptr == (void *) -1) {
            perror("shmat");
            exit(1);
        }

        sleep(10);

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            shm_ptr = shmat(shmid, NULL, 0);
            if (shm_ptr == (void *) -1) {
                perror("shmat");
                exit(1);
            }

            printf("Child says: %s\n", shm_ptr);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    } else {
        printf("Invalid argument\n");
        exit(1);
    }

    return 0;
}