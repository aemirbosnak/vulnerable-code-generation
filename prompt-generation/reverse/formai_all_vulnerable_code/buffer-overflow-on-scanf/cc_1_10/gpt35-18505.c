//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data of recovered files
struct recovered_data {
    char filename[20];
    char content[50];
};

// Function declarations
void recover_data(int recovery_chance);
void print_recovered_data(struct recovered_data *recdata);

// Main function
int main() {
    int players = 0, recovery_chance = 0;
    char player_name[20];

    // Get number of players
    printf("Enter number of players: ");
    scanf("%d", &players);

    // Get recovery chance
    printf("Enter recovery chance (0-100): ");
    scanf("%d", &recovery_chance);

    // Create an array of recovered_data structs
    struct recovered_data recdata[players];

    for (int i = 0; i < players; i++) {
        // Get player name
        printf("Enter player name: ");
        scanf("%s", player_name);

        // Simulate data recovery for each player
        recover_data(recovery_chance);

        // Store recovered data in recdata struct
        strcpy(recdata[i].filename, player_name);
        strcpy(recdata[i].content, "recovered data");
    }

    // Print recovered data
    print_recovered_data(recdata);

    return 0;
}

// Function to simulate data recovery
void recover_data(int recovery_chance) {
    int rand_num = rand() % 100;

    if (rand_num <= recovery_chance) {
        printf("Data recovered!\n");
    } else {
        printf("Data could not be recovered.\n");
    }
}

// Function to print recovered data
void print_recovered_data(struct recovered_data *recdata) {
    printf("\nRecovered data:\n");

    for (int i = 0; i < sizeof(recdata) / sizeof(struct recovered_data); i++) {
        printf("%s: %s\n", recdata[i].filename, recdata[i].content);
    }
}