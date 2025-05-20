//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MEMORY_SIZE 4096

typedef struct{
    int pid;
    void* ptr;
    size_t size;
} allocation;

int main(){
    // Initialize memory
    char memory[MEMORY_SIZE];
    allocation* allocations = (allocation*)malloc(sizeof(allocation) * MAX_PLAYERS);
    int num_players = 0;
    int num_allocations = 0;

    printf("Welcome to the Memory Management Multiplayer Game!\n");
    printf("You can add up to %d players, and allocate a maximum of %d bytes.\n\n", MAX_PLAYERS, MEMORY_SIZE);

    // Main game loop
    while(1){
        printf("%d players currently connected.\n", num_players);
        printf("Enter 'add' to add a player, 'alloc' to allocate memory, or 'exit' to exit the game: ");

        char command[10];
        scanf("%s", command);

        // Add player command
        if(strcmp(command, "add") == 0){
            if(num_players < MAX_PLAYERS){
                allocations[num_allocations].pid = num_players;
                allocations[num_allocations].ptr = NULL;
                allocations[num_allocations].size = 0;
                num_allocations++;
                num_players++;

                printf("New player added! Player ID is %d.\n", num_players-1);
            }
            else{
                printf("Maximum number of players reached!\n");
            }
        }
        // Allocate memory command
        else if(strcmp(command, "alloc") == 0){
            if(num_players == 0){
                printf("No players connected! Please add a player first.\n");
                continue;
            }

            printf("Enter player ID (0-%d): ", num_players-1);
            int pid;
            scanf("%d", &pid);

            if(pid < 0 || pid >= num_players){
                printf("Invalid player ID! Please enter a number between 0 and %d.\n", num_players-1);
                continue;
            }

            printf("Enter allocation size (max %d bytes): ", MEMORY_SIZE);
            size_t size;
            scanf("%lu", &size);

            if(size <= 0 || size > MEMORY_SIZE){
                printf("Invalid allocation size! Please enter a number between 1 and %d.\n", MEMORY_SIZE);
                continue;
            }

            // Check if there is enough free memory
            int free_bytes = MEMORY_SIZE;
            for(int i=0; i<num_allocations; i++){
                free_bytes -= allocations[i].size;
            }

            if(free_bytes < size){
                printf("Not enough free memory! Please select a smaller allocation size.\n");
                continue;
            }

            // Allocate memory
            void* ptr = malloc(size);

            if(ptr == NULL){
                printf("Memory allocation failed! Please try again with a smaller size.\n");
                continue;
            }

            allocations[num_allocations-1].ptr = ptr;
            allocations[num_allocations-1].size = size;

            printf("Memory allocated successfully for player %d at address %p!\n", pid, ptr);
        }
        // Exit command
        else if(strcmp(command, "exit") == 0){
            printf("Exiting game...\n");
            break;
        }
        // Invalid command
        else{
            printf("Invalid command! Please try again.\n");
        }
    }

    // Free all memory
    for(int i=0; i<num_allocations; i++){
        if(allocations[i].ptr != NULL){
            free(allocations[i].ptr);
        }
    }

    free(allocations);

    return 0;
}