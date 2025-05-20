//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 0x12345678
#define SIZE 1024

int main()
{
    int shmid, fd;
    char *shmptr;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1)
    {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shmptr, 0, SIZE);

    // Fork child process
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        // Parent process writes to shared memory segment
        fd = open("/dev/null", O_RDONLY);
        dup2(fd, 0);
        close(fd);

        execlp("./child", "child", NULL);
        perror("execlp");
        exit(1);
    }
    else
    {
        // Child process reads from shared memory segment
        sleep(1);

        int count = 0;
        while (count < 10)
        {
            printf("Child process read count: %d\n", *(int *) shmptr);
            sleep(1);
            count++;
        }

        // Detach shared memory segment
        if (shmdt(shmptr) == -1)
        {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    }

    return 0;
}