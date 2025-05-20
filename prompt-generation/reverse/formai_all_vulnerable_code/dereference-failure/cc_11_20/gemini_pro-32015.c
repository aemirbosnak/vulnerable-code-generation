//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FIFO_NAME "/tmp/my_fifo"

int main(int argc, char** argv) {
    int fd, i, status;
    char *shared_mem;

    if (mkfifo(FIFO_NAME, 0666) < 0) {
        perror("mkfifo");
        exit(1);
    }

    fd = open(FIFO_NAME, O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    shared_mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    for (i = 0; i < 10; i++) {
        if (fork() == 0) {
            close(fd);
            while (1) {
                if (read(fd, shared_mem, 4096) > 0) {
                    printf("Child %d: %s\n", getpid(), shared_mem);
                }
            }
            exit(0);
        }
    }

    while (1) {
        scanf("%s", shared_mem);
        write(fd, shared_mem, 4096);
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            break;
        }
    }

    close(fd);
    munmap(shared_mem, 4096);
    unlink(FIFO_NAME);

    return 0;
}