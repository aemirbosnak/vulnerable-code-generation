//Falcon-180B DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the size of our kingdom (heap)
#define HEAP_SIZE 1000

// Our kingdom's current population (allocated memory blocks)
int population = 0;

// The lord of the kingdom (our memory manager)
void* my_malloc(size_t size) {
    void* result;
    // If we have no more land to offer, we cannot grant this request
    if (population >= HEAP_SIZE) {
        printf("My liege, our kingdom is full. We cannot grant this request.\n");
        return NULL;
    }
    // Grant the request and increase our population
    result = malloc(size);
    if (result!= NULL) {
        population++;
    }
    return result;
}

// A loyal knight (our memory deallocator)
void my_free(void* ptr) {
    // If the given pointer was not granted by us, we cannot free it
    if (ptr == NULL || *(size_t*)ptr!= HEAP_SIZE) {
        printf("My liege, this request is not of our kingdom.\n");
        return;
    }
    // Free the land and decrease our population
    free(ptr);
    population--;
}

int main() {
    // Initialize our kingdom's population
    population = 0;

    // Allocate memory for our castle
    void* castle = my_malloc(50);
    // If we were granted land for our castle, build it
    if (castle!= NULL) {
        printf("Our castle has been built!\n");
    }

    // Allocate memory for our army
    void* army = my_malloc(100);
    // If we were granted land for our army, recruit soldiers
    if (army!= NULL) {
        printf("Our army has been recruited!\n");
    }

    // Free memory for our castle and army
    my_free(castle);
    my_free(army);

    // Print the current population of our kingdom
    printf("Our kingdom's population is now %d.\n", population);

    return 0;
}