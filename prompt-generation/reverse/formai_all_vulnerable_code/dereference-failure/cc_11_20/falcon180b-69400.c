//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024

int main()
{
    int shmid;
    char *shmaddr;
    struct stat statbuf;
    int fd;
    int pid;
    int status;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory to zero
    for (i = 0; i < SIZE; i++)
    {
        *(shmaddr + i) = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == 0)
    {
        // Child process
        for (i = 0; i < SIZE; i++)
        {
            *(shmaddr + i) = 1;
        }
        exit(0);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    // Wait for child process to finish
    waitpid(pid, &status, 0);

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, &statbuf) == -1)
    {
        perror("shmctl");
        exit(1);
    }

    // Print shared memory usage
    fd = open("/proc/self/smaps", O_RDONLY);
    if (fd!= -1)
    {
        char buf[1024];
        while (read(fd, buf, 1024) > 0)
        {
            if (strstr(buf, "shmid=")!= NULL)
            {
                printf("Shared memory usage: %d bytes\n", SIZE);
                break;
            }
        }
        close(fd);
    }

    return 0;
}