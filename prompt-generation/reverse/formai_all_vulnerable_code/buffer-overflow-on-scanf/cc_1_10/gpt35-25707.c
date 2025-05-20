//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char playerName[20];
    int playerHealth = 10;
    int playerScore = 0;
    char playerAction[20];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", playerName);
    printf("Welcome, %s! You are in a dark cave and you need to find your way out.\n", playerName);

    while(playerHealth > 0) {
        printf("\nHealth: %d\nScore: %d\n", playerHealth, playerScore);
        printf("What do you want to do next? (move/exit) ");
        scanf("%s", playerAction);

        if(strcmp(playerAction, "exit") == 0) {
            printf("Goodbye, %s!\n", playerName);
            break;
        }
        else if(strcmp(playerAction, "move") == 0) {
            printf("Which direction? (north/south/east/west) ");
            scanf("%s", playerAction);

            if(strcmp(playerAction, "north") == 0) {
                printf("You went north and found a treasure chest! You gained 5 points.\n");
                playerScore += 5;
            }
            else if(strcmp(playerAction, "south") == 0) {
                printf("You went south and found a monster! You lost 2 health points.\n");
                playerHealth -= 2;
            }
            else if(strcmp(playerAction, "east") == 0) {
                printf("You went east and found a river! You lost 1 health point.\n");
                playerHealth--;
            }
            else if(strcmp(playerAction, "west") == 0) {
                printf("You went west and found a map to the exit! You gained 10 points.\n");
                playerScore += 10;
            }
            else {
                printf("Invalid direction! Please try again.\n");
            }
        }
        else {
            printf("Invalid action! Please try again.\n");
        }
    }

    if(playerHealth <= 0) {
        printf("\nGame over! You died and your final score was %d.\n", playerScore);
    }

    return 0;
}