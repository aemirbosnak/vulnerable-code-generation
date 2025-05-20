//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number_of_dice, sides_per_die, i, j, sum = 0;
    char play_again;

    srand(time(NULL)); // Seed the random number generator with the current time

    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &number_of_dice);

        if (number_of_dice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (number_of_dice <= 0);

    do {
        printf("How many sides should each die have? ");
        scanf("%d", &sides_per_die);

        if (sides_per_die <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (sides_per_die <= 0);

    int dice[number_of_dice]; // Create an array to store the values rolled for each die

    for (i = 0; i < number_of_dice; i++) {
        dice[i] = rand() % sides_per_die + 1; // Roll each die and store the result in the array
        sum += dice[i]; // Add the value of each die to the total sum
    }

    printf("You rolled %d dice with %d sides each:\n", number_of_dice, sides_per_die);

    for (i = 0; i < number_of_dice; i++) {
        printf("Die %d: %d\n", i + 1, dice[i]); // Print the value of each die
    }

    printf("The total sum of all dice is: %d\n", sum);

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &play_again);

    while (play_again!= 'y' && play_again!= 'n') {
        printf("Invalid input. Please enter y or n.\n");
        scanf(" %c", &play_again);
    }

    if (play_again == 'y') {
        main(); // Recursive call to restart the program
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}