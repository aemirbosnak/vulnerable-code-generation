//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main(int argc, char **argv) {
    int shm_fd;
    void *shm_ptr;
    pid_t child_pid;

    // Create shared memory segment
    shm_fd = shm_open(SHM_KEY, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    if (ftruncate(shm_fd, SHM_SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Map shared memory segment into address space
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Write data to shared memory
    strcpy(shm_ptr, "Hello, world!");

    // Fork child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        sleep(1);
        // Read data from shared memory
        printf("Child says: %s\n", shm_ptr);
    } else {
        // Parent process
        wait(NULL);
    }

    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    return 0;
}