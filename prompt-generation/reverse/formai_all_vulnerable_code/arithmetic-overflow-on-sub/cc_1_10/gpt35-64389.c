//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
// Invasive Memory Management Example Program

#include<stdio.h>
#include<stdlib.h>

#define MEM_SIZE 1024 // total size of memory
#define MAX_ALLOCATIONS 10 // number of maximum allowed allocations

// structure to represent each allocation
struct Memory {
    int start;
    int end;
    int size;
};

// array to store each allocation
struct Memory memory[MAX_ALLOCATIONS];

// variable to keep track of number of allocations
int num_allocations = 0;

// function to allocate memory
void allocate_memory(int size) {
    if(num_allocations >= MAX_ALLOCATIONS) {
        printf("Maximum number of allowed allocations reached!\n");
        return;
    }
    
    int start = rand() % MEM_SIZE; // starting location of the allocation
    int end = start + size - 1; // ending location of the allocation
    
    // check if the allocation overlaps with any existing allocation
    for(int i=0; i<num_allocations; i++) {
        if((start >= memory[i].start && start <= memory[i].end) || 
           (end >= memory[i].start && end <= memory[i].end)) {
            printf("Allocation overlaps with existing allocation!\n");
            return;
        }
    }
    
    // add the new allocation to the array
    memory[num_allocations].start = start;
    memory[num_allocations].end = end;
    memory[num_allocations].size = size;
    num_allocations++;
    
    printf("Memory Allocation Successful!\n");
}

// function to deallocate memory
void deallocate_memory(int index) {
    if(index < 0 || index >= num_allocations) {
        printf("Invalid allocation index!\n");
        return;
    }
    
    // remove the allocation from the array
    for(int i=index; i<num_allocations-1; i++) {
        memory[i] = memory[i+1];
    }
    num_allocations--;
    
    printf("Memory Deallocation Successful!\n");
}

// function to display all allocations
void display_allocations() {
    for(int i=0; i<num_allocations; i++) {
        printf("Allocation %d: %d to %d (Size: %d)\n", i+1, memory[i].start, memory[i].end, memory[i].size);
    }
}

int main() {
    int choice, size, index;
    
    printf("Welcome to Invasive Memory Management Example Program!\n");
    
    while(1) {
        printf("\nAvailable Options:\n");
        printf("1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Display All Allocations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the size of the allocation: ");
                scanf("%d", &size);
                allocate_memory(size);
                break;
            case 2:
                printf("Enter the index of the allocation to deallocate: ");
                scanf("%d", &index);
                deallocate_memory(index-1);
                break;
            case 3:
                display_allocations();
                break;
            case 4:
                printf("Exiting Program...Thank you for using Invasive Memory Management Example Program!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}