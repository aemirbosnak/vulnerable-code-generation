//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int fd;
    char *ptr;
    int shmid;
    pid_t childpid;

    fd = open("myfifo", O_RDWR);

    if (fd == -1) {
        printf("Error opening FIFO\n");
        exit(1);
    }

    shmid = shmget((key_t)1234, SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error getting shared memory\n");
        exit(1);
    }

    ptr = (char *)shmat(shmid, NULL, 0);

    if (ptr == (char *)-1) {
        printf("Error attaching to shared memory\n");
        exit(1);
    }

    childpid = fork();

    if (childpid == -1) {
        printf("Error forking\n");
        exit(1);
    }

    if (childpid == 0) {
        close(fd);
        write(fd, "Hello from child\n", 17);
        exit(0);
    }

    close(fd);
    read(fd, ptr, SIZE);
    printf("Received message: %s\n", ptr);
    exit(0);
}