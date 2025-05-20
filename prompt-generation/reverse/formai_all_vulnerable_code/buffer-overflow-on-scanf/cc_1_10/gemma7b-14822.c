//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room;
    int type;
    float fear_factor;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Anya", 1, 1, 3.5},
    {"Boris", 2, 2, 2.8},
    {"Chloe", 3, 3, 2.2},
    {"David", 4, 4, 1.9},
    {"Elizabeth", 5, 5, 1.6},
    {"Frederick", 6, 6, 1.3},
    {"Gertrude", 7, 7, 0.9},
    {"Henry", 8, 8, 0.6},
    {"Ian", 9, 9, 0.3},
    {"Ivan", 10, 10, 0.1}
};

int main() {
    int i, j, room, fear_level;
    char name[20];

    // Seed the random number generator
    srand(time(NULL));

    // Get the room number from the user
    printf("Enter the room number: ");
    scanf("%d", &room);

    // Check if the room is haunted
    for (i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room == room) {
            // Get the ghost's name and fear level
            name[0] = ghosts[i].name[0];
            fear_level = ghosts[i].fear_factor;

            // Print the ghost's name and fear level
            printf("The room is haunted by %s. The fear level is %.2f.\n", name, fear_level);

            // Play a sound effect
            system("play sound.wav");

            // Flash the lights
            system("flash lights.bat");

            // Wait for the user to leave the room
            printf("Please leave the room.\n");
            scanf("Enter to continue...");
        }
    }

    // If the room is not haunted, print an error message
    if (room != -1) {
        printf("The room is not haunted.\n");
    }

    return 0;
}