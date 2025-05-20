//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number between min and max
int randomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int playerChoice, playerHealth = 100, monsterHealth = 75, lootChance = 50;
    printf("Welcome to the Haunted House Simulator game!\n");
    printf("You enter the haunted house, it is dark and quiet. You hear strange noises coming from the distance.\n");

    // Game loop
    while(playerHealth > 0 && monsterHealth > 0) {
        printf("Press 1 to move forward, 2 to check your health and 3 to quit the game: ");
        scanf("%d", &playerChoice);

        switch(playerChoice) {
            case 1:
                printf("You move forward and see a monster coming towards you!\n");
                int damage = randomNumber(10, 20);
                printf("You attack the monster and deal %d damage\n", damage);
                monsterHealth -= damage;

                // Check if the monster is dead
                if(monsterHealth <= 0) {
                    printf("You defeated the monster!!\n");

                    // Loot system
                    if(randomNumber(1, 100) <= lootChance) {
                        printf("You found a chest and obtained a health potion!\n");
                        playerHealth += 15;
                    }

                    break;
                }

                // Monster attacks the player
                damage = randomNumber(5, 15);
                printf("The monster attacks you and deals %d damage\n", damage);
                playerHealth -= damage;

                // Check if the player is dead
                if(playerHealth <= 0) {
                    printf("You were defeated by the monster... GAME OVER\n");
                    break;
                }

                break;
            case 2:
                printf("Your health is %d\n", playerHealth);
                break;
            case 3:
                printf("You have quit the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}