//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void intro();
void choosePath();
void randomEncounter();
void battle();
void gameOver();

// Global variables
const int MAX_HEALTH = 10;
int playerHealth = MAX_HEALTH;
int alienHealth = MAX_HEALTH;

int main() {
    srand(time(NULL)); // Seed random number generator
    
    intro();
    choosePath();
    
    return 0;
}

// Introduction to the game
void intro() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("In a post-apocalyptic galaxy filled with danger and adventure,\n");
    printf("you will choose a path to survive and thrive.\n\n");
}

// Prompt the user to choose a path
void choosePath() {
    int choice;
    printf("Choose your path:\n");
    printf("1. Explore planet\n");
    printf("2. Search for resources\n");
    printf("3. Battle aliens\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You landed on a desolate planet...\n");
            randomEncounter(); // Chance for random encounter
            break;
        case 2:
            printf("You set off to search for resources...\n");
            randomEncounter(); // Chance for random encounter
            break;
        case 3:
            printf("You encountered a hostile alien...\n");
            battle(); // Fight the alien
            break;
        default:
            printf("Invalid choice! Try again.\n");
            choosePath(); // Recursively call function until valid choice made
            break;
    }
}

// Randomly generate a chance for a battle encounter
void randomEncounter() {
    int encounterChance = rand() % 3;
    if (encounterChance == 0) {
        printf("You encounter an alien!\n");
        battle(); // Fight the alien
    } else {
        printf("No encounters on this journey.\n");
        gameOver(); // End game
    }
}

// Battle against an alien
void battle() {
    while (playerHealth > 0 && alienHealth > 0) {
        printf("Your health: %d\n", playerHealth);
        printf("Alien health: %d\n", alienHealth);
        int playerAttack = rand() % 3 + 1; // Random attack damage between 1 and 3
        int alienAttack = rand() % 3 + 1;
        printf("You attack the alien for %d damage!\n", playerAttack);
        alienHealth -= playerAttack;
        printf("The alien attacks you for %d damage!\n", alienAttack);
        playerHealth -= alienAttack;
    }
    if (playerHealth <= 0) {
        printf("You were defeated in battle. Game over.\n");
        gameOver();
    } else {
        printf("Congratulations! You defeated the alien and emerged victorious.\n");
        gameOver();
    }
}

// Game over message
void gameOver() {
    printf("Thanks for playing.\n");
    exit(0);
}