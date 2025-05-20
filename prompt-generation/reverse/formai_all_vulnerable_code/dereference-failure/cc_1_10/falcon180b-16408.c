//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 100
#define SHM_KEY 0x12345678

int main() {
    int shmid;
    char *shmaddr;
    int fd[2];
    pid_t childpid;
    char input[MAX_SIZE];
    char output[MAX_SIZE];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    shmid = shmget(SHM_KEY, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    childpid = fork();

    if (childpid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        execlp("cat", "cat", NULL);
        perror("execlp");
        exit(1);
    } else {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        while (fgets(input, MAX_SIZE, stdin)!= NULL) {
            strcpy(shmaddr, input);
            sleep(1);
        }
        close(fd[0]);
    }

    return 0;
}