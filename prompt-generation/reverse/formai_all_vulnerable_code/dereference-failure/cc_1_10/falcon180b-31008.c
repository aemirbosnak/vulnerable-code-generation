//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x12345678
#define SHM_ID 0x87654321

int main() {
    int shmid;
    void *shm;
    char *shm_ptr;
    int fd;
    struct stat sb;
    char path[20];
    int i;

    if (stat("/dev/shm", &sb) == -1) {
        perror("stat");
        exit(1);
    }

    sprintf(path, "/dev/shm/my_shm_%d", getpid());

    fd = open(path, O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (ftruncate(fd, BUF_SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    shmid = shmget(SHM_KEY, BUF_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) - 1) {
        perror("shmat");
        exit(1);
    }

    printf("Child process ID: %d\n", getpid());
    printf("Shared memory ID: %d\n", shmid);
    printf("Shared memory is attached at: %p\n", shm_ptr);

    for (i = 0; i < BUF_SIZE; i++) {
        shm_ptr[i] = i;
    }

    if (munmap(shm_ptr, BUF_SIZE) == -1) {
        perror("munmap");
        exit(1);
    }

    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    close(fd);

    return 0;
}