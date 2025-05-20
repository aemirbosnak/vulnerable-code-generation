//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
/* This program simulates a memory management system using statistical models.
It randomly generates memory requests and frees, and keeps track of the total number of requests and the percentage of requests fulfilled.
The program also introduces a garbage collector that runs periodically to free up unused memory blocks.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Size of memory pool in bytes.
#define POOL_SIZE 10000

// Threshold for garbage collector to run (in percentage of free memory).
#define GC_THRESHOLD 10

// Struct for a block of memory.
typedef struct Block {
    struct Block* next;
    int size;
    bool free;
} Block;

// The memory pool.
static char pool[POOL_SIZE];

// The head of the free block list.
static Block* free_list;

// The total number of memory requests.
static int total_requests = 0;

// The total number of requests fulfilled.
static int fulfilled_requests = 0;

// Helper function to display statistics.
void display_stats() {
    printf("Total requests: %d\n", total_requests);
    printf("Fulfilled requests: %d (%.2f%%)\n", fulfilled_requests, (float)fulfilled_requests/total_requests * 100);
}

// Helper function to randomly generate the size of a memory request.
int get_request_size() {
    return rand() % (POOL_SIZE/2) + 1; // Requests can be up to half the size of the memory pool.
}

// Helper function to traverse the free block list and find a block that is large enough to hold the request.
Block* find_block(int size) {
    Block* current = free_list;
    while (current != NULL) {
        if (current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Helper function to split a block into two smaller blocks.
void split_block(Block* block, int size) {
    Block* new_block = (Block*)(block->free + size);
    new_block->next = block->next;
    new_block->size = block->size - size;
    new_block->free = true;
    block->next = new_block;
    block->size = size;
}

// Function to allocate memory of a given size.
void* my_malloc(int size) {
    total_requests++;
    Block* block = find_block(size);
    if (block == NULL) {
        return NULL;
    }
    if (block->size > size) {
        split_block(block, size);
    }
    block->free = false;
    fulfilled_requests++;
    return block->free + sizeof(Block);
}

// Function to free memory.
void my_free(void* ptr) {
    Block* block = (Block*)(ptr - sizeof(Block));
    block->free = true;
}

// Function to run the garbage collector.
void run_gc() {
    int free_space = 0;
    Block* current = free_list;
    while (current != NULL) {
        if (current->free) {
            free_space += current->size;
        }
        current = current->next;
    }
    if ((float)free_space/POOL_SIZE * 100 <= GC_THRESHOLD) {
        printf("Running garbage collector...\n");
        current = free_list;
        Block* previous = NULL;
        while (current != NULL) {
            if (current->free && current->next != NULL && current->next->free) {
                current->size += current->next->size + sizeof(Block);
                current->next = current->next->next;
            }
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));
    
    // Initialize the free block list.
    Block* initial_block = (Block*)pool;
    initial_block->next = NULL;
    initial_block->size = POOL_SIZE - sizeof(Block);
    initial_block->free = true;
    free_list = initial_block;
    
    // Generate memory requests and frees at random.
    for (int i = 0; i < 1000; i++) {
        int action = rand() % 2;
        if (action) {
            int size = get_request_size();
            void* ptr = my_malloc(size);
            if (ptr != NULL) {
                printf("Allocated %d bytes at %p\n", size, ptr);
            }
            else {
                printf("Failed to allocate %d bytes\n", size);
            }
        }
        else {
            Block* current = free_list;
            int count = 0;
            while (current != NULL) {
                if (!current->free) {
                    count++;
                }
                current = current->next;
            }
            if (count > 0) {
                int index = rand() % count + 1;
                current = free_list;
                while (index > 0) {
                    if (!current->free) {
                        index--;
                    }
                    if (index == 0) {
                        printf("Freed memory at %p (size %d)\n", current->free + sizeof(Block), current->size);
                        my_free(current->free + sizeof(Block));
                        break;
                    }
                    current = current->next;
                }
            }
        }
        if (rand() % 10 == 0) { // Run the garbage collector periodically.
            run_gc();
        }
    }
    
    // Display statistics after simulation is complete.
    display_stats();
    
    return 0;
}