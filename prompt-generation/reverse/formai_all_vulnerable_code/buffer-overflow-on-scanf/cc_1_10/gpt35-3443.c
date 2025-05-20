//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define maximum length for character arrays
#define MAX_NAME_LENGTH 20
#define MAX_PLANET_DESCRIPTION_LENGTH 50
#define MAX_PLANET_COUNT 5

// Define structures for planets and players
typedef struct Planet {
    char name[MAX_NAME_LENGTH];
    char description[MAX_PLANET_DESCRIPTION_LENGTH];
    int reward;
} Planet;

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Function to get a random planet from the planets array
Planet get_random_planet(Planet planets[]){
    int planet_index = rand() % MAX_PLANET_COUNT; // Choose a random index between 0 and MAX_PLANET_COUNT-1
    return planets[planet_index]; // Return the planet at that index
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the planets array
    Planet planets[MAX_PLANET_COUNT] = {
        {"Mercury", "A small rocky planet closest to the sun", 100},
        {"Venus", "A bright and hot planet with thick clouds of sulfuric acid", 200},
        {"Earth", "The only known planet with life", 300},
        {"Mars", "A cold and dusty planet with ice caps at the poles", 400},
        {"Jupiter", "The largest planet in the solar system with many moons", 500}
    };
    
    // Initialize the player
    Player player;
    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("Please enter your name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", player.name);
    
    // Game loop
    bool continue_playing = true;
    while(continue_playing){
        // Get a random planet and display its name and description
        Planet current_planet = get_random_planet(planets);
        printf("\nYou have landed on %s\n", current_planet.name);
        printf("%s\n", current_planet.description);
        
        // Ask the player if they want to explore or leave
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the planet\n");
        printf("2. Leave the planet\n");
        int choice;
        scanf("%d", &choice);
        
        // Handle the player's choice
        if(choice == 1){
            // Add the planet's reward to the player's score
            player.score += current_planet.reward;
            printf("\nYou have earned %d points!\n", current_planet.reward);
        }
        else if(choice == 2){
            // End the game
            printf("\nThank you for playing, %s! Your final score is %d.\n", player.name, player.score);
            continue_playing = false;
        }
        else{
            // Invalid choice
            printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}