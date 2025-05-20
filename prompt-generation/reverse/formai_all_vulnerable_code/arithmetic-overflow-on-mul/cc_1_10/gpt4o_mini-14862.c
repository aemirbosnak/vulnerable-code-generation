//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void memory_stats() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalVirtualMem = memInfo.totalram;
    totalVirtualMem += memInfo.totalswap;
    totalVirtualMem *= memInfo.mem_unit;

    long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    virtualMemUsed *= memInfo.mem_unit;

    long totalPhysMem = memInfo.totalram * memInfo.mem_unit;

    printf("----------------------------------------------------------------------------- \n");
    printf("Total Virtual Memory: %.2f GB\n", (float)totalVirtualMem / (1024 * 1024 * 1024));
    printf("Used Virtual Memory: %.2f GB\n", (float)virtualMemUsed / (1024 * 1024 * 1024));
    printf("Total Physical Memory: %.2f GB\n", (float)totalPhysMem / (1024 * 1024 * 1024));
    printf("----------------------------------------------------------------------------- \n");
}

void free_memory() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long freeMem = memInfo.freeram * memInfo.mem_unit;
    
    printf("Now let’s play a game of hide and seek with our memory!\n");
    printf("Seek closely; how much memory is free? \n");
    printf("Currently, there is %.2f GB of free RAM lurking around...\n", (float)freeMem / (1024 * 1024 * 1024));
    printf("----------------------------------------------------------------------------- \n");
}

void memory_gathering(int iterations) {
    void* memory_chunks[iterations];
    printf("Time to gather a few memory chunks! Let's allocate some.\n\n");

    for (int i = 0; i < iterations; ++i) {
        memory_chunks[i] = malloc((i + 1) * 1024 * 1024); // Allocating memory increase
        if (memory_chunks[i] == NULL) {
            printf("Bah! Memory failed to allocate for chunk %d.\n", i);
            exit(EXIT_FAILURE);
        }
        printf("Chunk %d allocated, size: %d MB\n", i, i + 1);
    }
    printf("All chunks gathered. Time for a feast!\n");

    // Free memory chunks
    for (int i = 0; i < iterations; ++i) {
        free(memory_chunks[i]);
        printf("Chunk %d freed. It was a good snack!\n", i);
    }
    printf("Everything's cleaned up!\n");
}

int main() {
    printf("Welcome to the Mysterious Realm of RAM Monitoring!\n");
    printf("Here, we’ll reveal the secrets of your system’s memory...\n");

    memory_stats();
    free_memory();

    int intervals = 5; // Number of chunks to allocate
    printf("In the spirit of adventure, let’s gather %d memory chunks!\n", intervals);
    memory_gathering(intervals);

    printf("Curiosity quenched, and memory explored. Until next time...\n");
    return 0;
}