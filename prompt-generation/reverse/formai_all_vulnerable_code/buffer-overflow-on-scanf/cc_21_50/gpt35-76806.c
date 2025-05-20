//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define color codes as strings
    char* redCode = "FF0000";
    char* blueCode = "0000FF";
    char* greenCode = "00FF00";
    char* yellowCode = "FFFF00";

    // Define player variables
    char player1[10];
    char player2[10];
    int choice;

    printf("Welcome to the Color Code Converter game!\n");
    printf("Player 1, what is your name?\n");
    scanf("%s", player1);
    printf("Player 2, what is your name?\n");
    scanf("%s", player2);

    while(1) {
        printf("\n%s, choose a color code to convert (1. Red, 2. Blue, 3. Green, 4. Yellow):\n", player1);
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("The RGB color code for red is %s.\n", redCode);
                    break;
            case 2: printf("The RGB color code for blue is %s.\n", blueCode);
                    break;
            case 3: printf("The RGB color code for green is %s.\n", greenCode);
                    break;
            case 4: printf("The RGB color code for yellow is %s.\n", yellowCode);
                    break;
            default: printf("Invalid input, try again.\n");
                    break;
        }

        printf("\n%s, do you want to guess the HEX color code? (0. No, 1. Yes):\n", player2);
        scanf("%d", &choice);

        if(choice == 1) {
            char guess[10];
            printf("Guess the HEX color code:\n");
            scanf("%s", guess);

            if(strcmp(guess, redCode) == 0 || strcmp(guess, blueCode) == 0 ||
               strcmp(guess, greenCode) == 0 || strcmp(guess, yellowCode) == 0) {
                printf("You guessed correctly!\n");
            } else {
                printf("Sorry, the correct answer is %s.\n", redCode);
            }
        }

        printf("\n%s, choose a color code to convert (1. Red, 2. Blue, 3. Green, 4. Yellow):\n", player2);
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("The HEX color code for red is #%s.\n", redCode);
                    break;
            case 2: printf("The HEX color code for blue is #%s.\n", blueCode);
                    break;
            case 3: printf("The HEX color code for green is #%s.\n", greenCode);
                    break;
            case 4: printf("The HEX color code for yellow is #%s.\n", yellowCode);
                    break;
            default: printf("Invalid input, try again.\n");
                    break;
        }

        printf("\n%s, do you want to guess the RGB color code? (0. No, 1. Yes):\n", player1);
        scanf("%d", &choice);

        if(choice == 1) {
            char guess[10];
            printf("Guess the RGB color code:\n");
            scanf("%s", guess);

            if(strcmp(guess, redCode) == 0 || strcmp(guess, blueCode) == 0 ||
               strcmp(guess, greenCode) == 0 || strcmp(guess, yellowCode) == 0) {
                printf("You guessed correctly!\n");
            } else {
                printf("Sorry, the correct answer is %s.\n", redCode);
            }
        }

        printf("\nDo you want to play again? (0. No, 1. Yes):\n");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}