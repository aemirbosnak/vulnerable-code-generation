//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 10

typedef struct {
    char data[SIZE];
    int count;
} shared_memory;

int main() {
    int shmid;
    int fd;
    shared_memory *ptr;
    char *shm_name = "my_shm";
    char *shm_file = "/dev/shm/my_shm";

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    fd = open(shm_file, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        printf("Error opening shared memory file\n");
        exit(1);
    }

    if (ftruncate(fd, SIZE) == -1) {
        printf("Error truncating shared memory file\n");
        exit(1);
    }

    if (mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0) == MAP_FAILED) {
        printf("Error mapping shared memory\n");
        exit(1);
    }

    ptr = (shared_memory *) mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        printf("Error mapping shared memory\n");
        exit(1);
    }

    ptr->count = 0;

    strcpy(ptr->data, "Hello, world!");

    if (munmap(ptr, SIZE) == -1) {
        printf("Error unmapping shared memory\n");
        exit(1);
    }

    if (close(fd) == -1) {
        printf("Error closing shared memory file\n");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory\n");
        exit(1);
    }

    return 0;
}