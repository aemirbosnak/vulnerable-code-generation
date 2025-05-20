//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 3

typedef struct Enemy {
    int health;
    char name[20];
} Enemy;

Enemy enemies[3] = {
    {
        .health = 100,
        .name = "Goblin"
    },
    {
        .health = 80,
        .name = "orc"
    },
    {
        .health = 60,
        .name = "skeleton"
    }
};

int main() {
    int lives = MAX_LIVES;
    char input;

    // Print the game title
    printf("-----------------------------------\n");
    printf("Welcome to the Arena of Doom!\n");
    printf("-----------------------------------\n");

    // Loop until the player loses or wins
    while (lives > 0) {
        // Display the enemies' health
        printf("Enemies:");
        for (int i = 0; i < 3; i++) {
            printf(" %s: %d%%", enemies[i].name, enemies[i].health);
        }

        // Get the player's input
        printf("\nEnter your command (attack/ defend): ");
        scanf(" %c", &input);

        // Process the player's input
        switch (input) {
            case 'a':
                // Attack the enemies
                for (int i = 0; i < 3; i++) {
                    enemies[i].health -= 20;
                }
                break;
            case 'd':
                // Defend against the enemies
                lives++;
                break;
            default:
                // Invalid input
                printf("Invalid command.\n");
                break;
        }

        // Check if the player has won or lost
        if (enemies[0].health <= 0 || enemies[1].health <= 0 || enemies[2].health <= 0) {
            printf("You have won! Congratulations!\n");
            break;
        } else if (lives == 0) {
            printf("You have lost. Game over.\n");
            break;
        }
    }

    return 0;
}