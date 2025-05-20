//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, sides, roll;
    char choice = 'y';
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of dice you want to roll: ");
    scanf("%d", &num);
    while (num <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &num);
    }

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    while (sides <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &sides);
    }
    printf("\n");


     printf("______██░░░░░░░░░░░██\n");
     printf("_____█░░░░░░░░░░░░░░█\n");
     printf("_____█░░▓▓▓░░░░▓▓▓░░█\n");
     printf("_____█░░▓▓▓░░░░▓▓▓░░█\n");
     printf("_____█░░░░░░░░░░░░░░█\n");
     printf("_____█░░░░░░░░░░░░░░█\n");
     printf("_____█░░░░░░░░░░░░░░█\n");
     printf("_____█░░░░░░░░░░░░░░█\n");
     printf("__▄▄▄█░░░░░░░░░░░░░░█▄▄▄\n");
     
    while (choice == 'y') {
        int i;
        printf("\nRolling %d %d-sided dice...\n", num, sides);
        for (i = 0; i < num; i++) {
            roll = (rand() % sides) + 1;
            printf("Dice %d: %d\n", i+1, roll);
        }

        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice);
        while (choice != 'y' && choice != 'n') {
            printf("Invalid input. Please enter either 'y' or 'n': ");
            scanf(" %c", &choice);
        }
    }
    printf("\nThanks for rolling with us!\n");

     printf("______░▒░░░░░░░░░░░░░▒░\n");
     printf("______░▒░░░░░░░░░░░░░▒░\n");
     printf("______░▒████████████▒░\n");
     printf("______░░░░░░░░░░░░░░░░░\n");
     printf("______░░░░░░░░░░░░░░░░░\n");
     printf("______░░░░░░░░░░░░░░░░░\n");
     printf("______░░▓▓░░░░░░░░▓▓░░\n");
     printf("______░░▓▓░░░░░░░░▓▓░░\n");
     printf("______░░░░░░░░░░░░░░░░░\n");

    return 0;
}