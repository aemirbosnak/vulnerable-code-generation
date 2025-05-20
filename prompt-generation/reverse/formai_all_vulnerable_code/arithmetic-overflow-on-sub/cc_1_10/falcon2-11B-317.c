//Falcon2-11B DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

#define PAGE_SIZE 4096
#define MEM_SIZE (4 * 1024 * 1024)

void* mem_mapped_file(const char* filename) {
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        fprintf(stderr, "Failed to open %s\n", filename);
        exit(1);
    }
    void* ptr = mmap(NULL, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        fprintf(stderr, "Failed to map %s\n", filename);
        exit(1);
    }
    return ptr;
}

void* mem_unmap(void* ptr) {
    int ret = munmap(ptr, MEM_SIZE);
    if (ret == -1) {
        fprintf(stderr, "Failed to unmap %p\n", ptr);
        exit(1);
    }
    return NULL;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    void* mapped_file = mem_mapped_file(filename);
    if (mapped_file == NULL) {
        return 1;
    }

    struct rusage usage_before, usage_after;
    getrusage(RUSAGE_SELF, &usage_before);

    char* buffer = (char*)mapped_file + MEM_SIZE - PAGE_SIZE;
    while (1) {
        if (mmap(buffer, PAGE_SIZE, PROT_READ, MAP_SHARED, -1, 0) == -1) {
            perror("mmap");
            return 1;
        }

        buffer += PAGE_SIZE;
        int pages_to_flush = buffer - (char*)mapped_file;
        if (pages_to_flush < 0) {
            pages_to_flush = 0;
        }
        if (munmap((void*)mapped_file + pages_to_flush, pages_to_flush * PAGE_SIZE) == -1) {
            perror("munmap");
            return 1;
        }
        mapped_file += pages_to_flush;

        getrusage(RUSAGE_SELF, &usage_after);
        double time_spent = usage_after.ru_utime.tv_sec - usage_before.ru_utime.tv_sec;
        time_spent += (double)usage_after.ru_utime.tv_usec - (double)usage_before.ru_utime.tv_usec;
        time_spent *= 1e-6;
        time_spent += usage_after.ru_stime.tv_sec - usage_before.ru_stime.tv_sec;
        time_spent += (double)usage_after.ru_stime.tv_usec - (double)usage_before.ru_stime.tv_usec;
        time_spent *= 1e-6;
        printf("Pages read: %d, Time spent: %f\n", pages_to_flush, time_spent);

        if (pages_to_flush < PAGE_SIZE) {
            break;
        }
    }

    mem_unmap(mapped_file);

    return 0;
}