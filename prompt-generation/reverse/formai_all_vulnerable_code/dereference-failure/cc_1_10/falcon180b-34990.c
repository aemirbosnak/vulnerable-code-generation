//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define PAGE_SIZE 4096
#define MAX_ROUNDS 100

typedef struct {
    char* filename;
    int fd;
    void* addr;
    size_t length;
    int num_rounds;
} file_t;

void randomize_file(file_t* file) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROUNDS; i++) {
        void* addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (addr == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }
        memset(addr, rand() % 256, PAGE_SIZE);
        msync(addr, PAGE_SIZE, MS_SYNC);
        munmap(addr, PAGE_SIZE);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <num_rounds>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int num_rounds = atoi(argv[2]);

    file_t file = {0};
    file.filename = filename;
    file.fd = open(filename, O_RDWR);
    if (file.fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(file.fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }

    file.length = sb.st_size;
    file.addr = mmap(NULL, file.length, PROT_READ | PROT_WRITE, MAP_SHARED, file.fd, 0);
    if (file.addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    randomize_file(&file);

    if (msync(file.addr, file.length, MS_SYNC) == -1) {
        perror("msync");
        return 1;
    }

    if (munmap(file.addr, file.length) == -1) {
        perror("munmap");
        return 1;
    }

    close(file.fd);
    return 0;
}