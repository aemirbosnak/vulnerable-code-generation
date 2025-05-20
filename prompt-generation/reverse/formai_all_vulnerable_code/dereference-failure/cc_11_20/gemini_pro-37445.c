//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

#define FILE_SIZE 100000

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source file> <destination file> <number of processes>\n", argv[0]);
        return 1;
    }

    int num_procs = atoi(argv[3]);
    if (num_procs < 1) {
        fprintf(stderr, "Number of processes must be greater than 0\n");
        return 1;
    }

    // Create a shared memory region
    int shm_fd = shm_open("file_sync", O_RDWR | O_CREAT, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    if (ftruncate(shm_fd, FILE_SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    char *shm_addr = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Create a pipe
    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork processes
    for (int i = 0; i < num_procs; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            // Child process
            close(pipe_fds[0]); // Close the read end of the pipe

            int fd = open(argv[1], O_RDONLY);
            if (fd == -1) {
                perror("open");
                return 1;
            }

            while (1) {
                char buf[1024];
                ssize_t nbytes = read(fd, buf, sizeof(buf));
                if (nbytes == -1) {
                    perror("read");
                } else if (nbytes == 0) {
                    break;
                }

                // Write the data to the shared memory region
                memcpy(shm_addr + i * FILE_SIZE / num_procs, buf, nbytes);

                // Notify the parent process that data has been written
                write(pipe_fds[1], &i, sizeof(i));
            }

            close(fd);
            close(pipe_fds[1]);
            return 0;
        }
    }

    // Parent process
    close(pipe_fds[1]); // Close the write end of the pipe

    // Open the destination file
    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read the data from the shared memory region and write it to the destination file
    for (int i = 0; i < num_procs; i++) {
        ssize_t nbytes;
        do {
            nbytes = read(pipe_fds[0], &i, sizeof(i));
            if (nbytes == -1) {
                perror("read");
            }
        } while (nbytes == -1 && errno == EINTR);

        if (nbytes == 0) {
            break;
        }

        write(fd, shm_addr + i * FILE_SIZE / num_procs, FILE_SIZE / num_procs);
    }

    close(fd);
    close(pipe_fds[0]);
    shm_unlink("file_sync");
    return 0;
}