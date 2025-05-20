//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    pid_t pid;

    printf("Parent process started with PID %d\n", getpid());

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0600);
    if (shmid < 0) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmaddr = (char *) shmat(shmid, NULL, 0);
    if ((int) shmaddr == -1) {
        printf("Error in shmat\n");
        exit(2);
    }

    printf("Shared memory attached at %p\n", shmaddr);

    pid = fork();

    if (pid < 0) {
        printf("Error in fork\n");
        exit(3);
    } else if (pid == 0) {
        char *child_message = "Child process started with PID ";
        char *child_message_end = child_message + strlen(child_message);
        sprintf(child_message_end, "%d\n", getpid());
        strcpy(shmaddr, child_message);
        exit(0);
    } else {
        wait(NULL);
        printf("Child process terminated with PID %d\n", pid);
        printf("Message from child: %s", shmaddr);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}