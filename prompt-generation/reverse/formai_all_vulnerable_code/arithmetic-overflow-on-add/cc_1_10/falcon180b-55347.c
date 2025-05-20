//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10000 // Total memory size in bytes

typedef struct {
    int size;
    int free;
    int used;
} Memory;

int main() {
    int i;
    Memory mem;

    // Initialize memory
    mem.size = MEM_SIZE;
    mem.free = MEM_SIZE;
    mem.used = 0;

    printf("Memory Usage Monitor\n");
    printf("----------------------\n");

    while(1) {
        printf("\nCurrent Memory Status:\n");
        printf("------------------------\n");
        printf("Total Memory: %d bytes\n", mem.size);
        printf("Free Memory: %d bytes\n", mem.free);
        printf("Used Memory: %d bytes\n", mem.used);
        printf("------------------------\n");

        // Allocate memory
        printf("Enter the number of bytes to allocate: ");
        scanf("%d", &i);

        if(mem.free >= i) {
            mem.free -= i;
            mem.used += i;
            printf("%d bytes allocated\n", i);
        } else {
            printf("Insufficient memory\n");
        }

        // Deallocate memory
        printf("Enter the number of bytes to deallocate: ");
        scanf("%d", &i);

        if(mem.used >= i) {
            mem.free += i;
            mem.used -= i;
            printf("%d bytes deallocated\n", i);
        } else {
            printf("Invalid deallocation size\n");
        }

        // Print memory status every 10 iterations
        if((i % 10) == 0) {
            printf("\nCurrent Memory Status:\n");
            printf("------------------------\n");
            printf("Total Memory: %d bytes\n", mem.size);
            printf("Free Memory: %d bytes\n", mem.free);
            printf("Used Memory: %d bytes\n", mem.used);
            printf("------------------------\n");
        }
    }

    return 0;
}