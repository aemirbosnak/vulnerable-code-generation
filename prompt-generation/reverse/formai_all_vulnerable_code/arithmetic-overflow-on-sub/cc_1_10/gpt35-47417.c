//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Struct for player information
struct player {
    char name[20];
    int health;
    int damage;
};

// Function to generate random number
int randomNum(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Set up random seed for generating random numbers
    srand(time(0));

    // Initialize player information
    struct player player1, player2;
    player1.health = 100;
    player2.health = 100;

    // Get player1 information
    printf("Player1, what is your name?\n");
    scanf("%s", player1.name);
    printf("Player1, what is your damage per attack?\n");
    scanf("%d", &player1.damage);

    // Get player2 information
    printf("Player2, what is your name?\n");
    scanf("%s", player2.name);
    printf("Player2, what is your damage per attack?\n");
    scanf("%d", &player2.damage);

    // Game loop
    while (true) {
        // Player1 attack
        printf("%s attacks %s!\n", player1.name, player2.name);
        player2.health -= player1.damage;
        printf("%s now has %d health remaining!\n", player2.name, player2.health);
        if (player2.health <= 0) {
            printf("%s wins!\n", player1.name);
            break;
        }

        // Player2 attack
        printf("%s attacks %s!\n", player2.name, player1.name);
        player1.health -= player2.damage;
        printf("%s now has %d health remaining!\n", player1.name, player1.health);
        if (player1.health <= 0) {
            printf("%s wins!\n", player2.name);
            break;
        }

        // Generate random number to determine if a health pack appears
        int chance = randomNum(1, 10);
        if (chance <= 3) {
            // Health pack appears
            printf("A health pack has appeared!\n");
            // Determine which player gets the health pack
            int playerNum = randomNum(1, 2);
            if (playerNum == 1) {
                printf("%s grabs the health pack and gains 20 health!\n", player1.name);
                player1.health += 20;
            } else {
                printf("%s grabs the health pack and gains 20 health!\n", player2.name);
                player2.health += 20;
            }
        }
    }

    return 0;
}