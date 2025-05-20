//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 1024

struct mem_info {
    char name[64];
    size_t size;
};

struct mem_usage {
    size_t total;
    size_t used;
    size_t free;
};

void init_mem_info(struct mem_info* mi, const char* name, size_t size) {
    strcpy(mi->name, name);
    mi->size = size;
}

void init_mem_usage(struct mem_usage* mu) {
    mu->total = 0;
    mu->used = 0;
    mu->free = 0;
}

void print_mem_usage(struct mem_usage mu) {
    printf("Total RAM usage: %lld bytes (%lld KB, %lld MB)\n", (long long)mu.total, (long)mu.total / 1024, (long)mu.total / (1024 * 1024));
    printf("Free RAM: %lld bytes (%lld KB, %lld MB)\n", (long long)(mu.total - mu.used), (long)(mu.total - mu.used) / 1024, (long)((mu.total - mu.used) / (1024 * 1024)));
}

void* malloc_with_info(size_t size, const char* name, struct mem_info* mi) {
    void* ptr = malloc(size);
    if (ptr != NULL) {
        mi->size += size;
    }
    return ptr;
}

void free_with_info(void* ptr, size_t size, const char* name, struct mem_info* mi) {
    if (ptr != NULL) {
        mi->size -= size;
        free(ptr);
    }
}

void check_memory() {
    struct mem_info mi_program;
    struct mem_info mi_heap;
    struct mem_usage mu;

    init_mem_info(&mi_program, "Program", 0);
    init_mem_info(&mi_heap, "Heap", 0);
    init_mem_usage(&mu);

    while (1) {
        mu.used = mi_program.size + mi_heap.size;
        mu.free = sysconf(_SC_PHYS_PAGES) * getpagesize();

        print_mem_usage(mu);

        if (mu.used > mu.free) {
            printf("Ran out of memory!\n");
            break;
        }

        init_mem_usage(&mu);

        void* arr = malloc_with_info(10 * sizeof(int), &mi_heap, &mi_program);
        if (arr != NULL) {
            for (int i = 0; i < 10; i++) {
                ((int*)arr)[i] = i;
            }
            printf("Allocated array of 10 integers with size %ld bytes\n", (long)10 * sizeof(int));
        }

        sleep(1);

        free_with_info(arr, 10 * sizeof(int), &mi_heap, &mi_program);
        printf("Freed array of 10 integers with size %ld bytes\n", (long)10 * sizeof(int));
    }

    free(mi_program.name);
    free(mi_heap.name);
}

int main() {
    check_memory();
    return 0;
}