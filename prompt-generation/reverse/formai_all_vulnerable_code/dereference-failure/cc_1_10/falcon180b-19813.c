//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    char *shmptr;
    int size = MAX_SIZE;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    shmid = shmget(IPC_PRIVATE, size, IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "Error: shmget failed with errno %d\n", errno);
        return 1;
    }

    shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        fprintf(stderr, "Error: shmat failed with errno %d\n", errno);
        return 1;
    }

    strcpy(shmptr, argv[1]);

    printf("Message sent: %s\n", argv[1]);

    for (i = 0; i < strlen(argv[1]) + 1; i++) {
        if (shmptr[i]!= argv[1][i]) {
            fprintf(stderr, "Error: message corrupted\n");
            return 1;
        }
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}