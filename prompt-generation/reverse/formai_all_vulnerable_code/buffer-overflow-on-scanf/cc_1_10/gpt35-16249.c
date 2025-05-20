//FormAI DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to Cyber Memory Management.\n\n");
    printf("Initializing memory...\n\n");

    int memory_size = 1024; // Total memory in bytes
    int max_allocatable = 256; // Maximum memory that can be allocated in bytes
    int allocated = 0; // Currently allocated memory in bytes
    int chunks = 0; // Number of chunks allocated
    int menu_choice = 0; // User's menu choice

    printf("Memory initialized. Total memory: %d bytes. Maximum allocatable memory: %d bytes.\n", memory_size, max_allocatable);

    while(menu_choice != 3){ // Loop until user chooses to exit
        printf("\nMENU\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice){
            case 1: // Allocate memory
            {
                if(allocated + max_allocatable <= memory_size){ // Check if there is enough memory
                    int size = rand() % max_allocatable + 1; // Randomly generate size of chunk to allocate
                    int* ptr = (int*) malloc(size); // Allocate memory
                    printf("Allocated %d bytes at address %p\n", size, ptr);
                    allocated += size;
                    chunks++;
                }
                else{ // Not enough memory
                    printf("Error: Insufficient memory\n");
                }
                break;
            }
            case 2: // Free memory
            {
                if(chunks == 0){ // Check if there are no chunks to free
                    printf("No memory to free\n");
                }
                else{ // Free memory
                    int random_chunk = rand() % chunks + 1; // Randomly select a chunk to free
                    int* ptr = (int*) malloc(max_allocatable); // Allocate a new chunk
                    printf("Freed %d bytes at address %p\n", max_allocatable, ptr);
                    free(ptr); // Free the chunk
                    allocated -= max_allocatable;
                    chunks--;
                }
                break;
            }
            case 3: // Exit
            {
                printf("Exiting...\n");
                break;
            }
            default: // Invalid choice
            {
                printf("Error: Invalid choice\n");
            }
        }
    }

    printf("\nMemory Status\n");
    printf("Memory size: %d bytes\n", memory_size);
    printf("Allocated memory: %d bytes\n", allocated);
    printf("Chunks allocated: %d\n", chunks);

    return 0;
}