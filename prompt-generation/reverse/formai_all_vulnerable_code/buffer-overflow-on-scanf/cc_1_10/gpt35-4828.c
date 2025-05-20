//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RESOURCES 10 // maximum number of resources
#define MAX_RESOURCES_PER_PLAYER 5 // maximum number of resources per player

int available_resources[MAX_RESOURCES]; // array to track available resources
int num_players; // number of players
int player_resources[MAX_RESOURCES_PER_PLAYER]; // array to track each player's resources

// Function to check if a request for resources can be fulfilled
bool check_request(int request[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > available_resources[i]) {
            return false;
        }
    }
    return true;
}

// Function to allocate resources to a player
void allocate_request(int request[], int player_num) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available_resources[i] -= request[i];
        player_resources[player_num] += request[i];
    }
}

// Function to free resources from a player
void free_resources(int release[], int player_num) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available_resources[i] += release[i];
        player_resources[player_num] -= release[i];
    }
}

int main() {
    // Prompt user for number of players
    printf("Please enter the number of players: ");
    scanf("%d", &num_players);

    // Prompt user for available resources
    printf("Please enter the available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &available_resources[i]);
    }

    // Main game loop
    bool game_over = false;
    while (!game_over) {
        for (int i = 0; i < num_players; i++) {
            // Prompt current player for resource request
            int request[MAX_RESOURCES];
            printf("Player %d, please enter your resource request:\n", i+1);
            for (int j = 0; j < MAX_RESOURCES; j++) {
                scanf("%d", &request[j]);
            }

            // Check if request can be fulfilled
            if (check_request(request)) {
                allocate_request(request, i);

                // Print allocation confirmation
                printf("Player %d's request has been allocated.\n", i+1);
                printf("Updated resource availability:\n");
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    printf("%d ", available_resources[j]);
                }
                printf("\n");
            }
            else {
                // Print rejection message
                printf("Player %d's request has been rejected due to insufficient resources.\n", i+1);
            }

            // Prompt current player for resource release
            int release[MAX_RESOURCES];
            printf("Player %d, please enter any resources you wish to release:\n", i+1);
            for (int j = 0; j < MAX_RESOURCES; j++) {
                scanf("%d", &release[j]);
            }

            // Free resources from player
            free_resources(release, i);

            // Check if game is over
            int total_resources = 0;
            for (int j = 0; j < num_players; j++) {
                total_resources += player_resources[j];
            }
            if (total_resources == MAX_RESOURCES*num_players) {
                game_over = true;
                printf("Game over! All resources have been allocated.\n");
                break;
            }
        }
    }
    
    return 0;
}