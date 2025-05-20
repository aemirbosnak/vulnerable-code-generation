//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MISSIONS 5
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int energy;
    int shields;
    char mission_description[150];
} Spaceship;

void initialize_spaceship(Spaceship *ship, const char *name) {
    strcpy(ship->name, name);
    ship->energy = 100;
    ship->shields = 100;
    snprintf(ship->mission_description, sizeof(ship->mission_description),
             "Retrieve the mysterious artifact from the abandoned moon base.");
}

void display_status(Spaceship *ship) {
    printf("Spaceship: %s\n", ship->name);
    printf("Energy Level: %d\n", ship->energy);
    printf("Shield Strength: %d\n", ship->shields);
    printf("Current Mission: %s\n", ship->mission_description);
    printf("-------------------------\n");
}

void perform_action(Spaceship *ship) {
    char action[20];
    
    printf("Choose an action: (explore/attack/rest) ");
    scanf("%s", action);

    if (strcmp(action, "explore") == 0) {
        int event = rand() % 3;
        if (event == 0) {
            printf("You found a hidden space treasure!\n");
            ship->energy += 20;
        } else if (event == 1) {
            printf("You encountered an asteroid field!\n");
            ship->shields -= 30;
        } else {
            printf("You met a friendly alien trader!\n");
            ship->energy += 10;
            ship->shields += 10;
        }
    } else if (strcmp(action, "attack") == 0) {
        printf("You are attacking a space pirate ship!\n");
        int attack_result = rand() % 2;
        if (attack_result == 0) {
            printf("You successfully defeated the pirate!\n");
        } else {
            printf("You took damage in battle!\n");
            ship->shields -= 20;
        }
    } else if (strcmp(action, "rest") == 0) {
        printf("You chose to rest and recharge.\n");
        ship->energy += 15;
        ship->shields += 15;
    } else {
        printf("Invalid action! Please try again.\n");
    }

    // Ensure energy and shields are within bounds
    if (ship->energy > 100) ship->energy = 100;
    if (ship->shields > 100) ship->shields = 100;
    if (ship->shields < 0) ship->shields = 0;

    printf("\n");
}

int main() {
    srand(time(0));  // Seed for random number generation
    Spaceship player_ship;
    char ship_name[MAX_NAME_LEN];

    printf("Welcome to the Galactic Exploration Program!\n");
    printf("Enter your spaceship name: ");
    scanf("%s", ship_name);

    initialize_spaceship(&player_ship, ship_name);
    
    char continue_game;
    do {
        display_status(&player_ship);
        perform_action(&player_ship);
        
        if (player_ship.shields <= 0) {
            printf("Your ship has been destroyed! Game Over.\n");
            break;
        }

        printf("Do you want to continue your adventure? (y/n): ");
        scanf(" %c", &continue_game);
        
    } while (continue_game == 'y');

    printf("Thank you for playing, Captain %s!\n", player_ship.name);

    return 0;
}