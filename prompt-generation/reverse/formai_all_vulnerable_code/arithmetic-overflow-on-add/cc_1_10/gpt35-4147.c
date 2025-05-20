//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int seconds) {
    int millisecond = 1000 * seconds;
    clock_t startTime = clock();
    while(clock() < startTime + millisecond);
}

int main() {
    char playerName[50];
    int choice, coins = 0, health = 100;
    srand(time(NULL));
    
    printf("*** Welcome to the Text-Based Adventure Game ***\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("*** Hello %s! Let's start our adventure!***\n\n", playerName);
    delay(2);
    
    printf("*** You are in a dark cave and you have a torch as your only source of light. ***\n");
    printf("*** You have to find your way out of the cave and discover the treasure. ***\n\n");
    delay(2);
    
    while (health > 0) {
        printf("*** You have %d health and %d coins. ***\n", health, coins);
        printf("What do you want to do next?\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Check inventory\n");
        printf("5. Quit game\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("*** You move forward and find a treasure chest. ***\n");
                int randomCoins = rand() % 21;
                coins += randomCoins;
                health -= 10;
                printf("*** You found %d coins! ***\n", randomCoins);
                printf("*** You lost 10 health. You have %d health left. ***\n", health);
                delay(2);
                break;
            case 2:
                printf("*** You turn left and see a monster! ***\n");
                printf("*** The monster attacks you and you lose 20 health. ***\n");
                health -= 20;
                delay(2);
                break;
            case 3:
                printf("*** You turn right and avoid a trap. ***\n");
                printf("*** You found a potion that restores 30 health. ***\n");
                health += 30;
                delay(2);
                break;
            case 4:
                printf("*** You check your inventory. You have %d coins and %d health. ***\n", coins, health);
                delay(2);
                break;
            case 5:
                printf("*** Goodbye! Thanks for playing! ***\n");
                exit(0);
            default:
                printf("*** Oops! Invalid input! Please try again. ***\n");
                delay(2);
        }
        
        if (health <= 0) {
            printf("*** Sorry %s, you lost the game :( ***\n", playerName);
            printf("*** Your final score is %d coins. Thanks for playing! ***\n", coins);
            exit(0);
        }
        
        if (coins >= 100) {
            printf("*** Congratulations %s, you won the game! ***\n", playerName);
            printf("*** You achieved %d coins with %d health left. Thanks for playing! ***\n", coins, health);
            exit(0);
        }
    }
    return 0;
}