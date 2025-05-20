//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define NUM_DICE 2

// Function to generate a random number between 1 and n
int rand_int(int n) {
    return rand() % n + 1;
}

// Function to roll the dice and print the result
void roll_dice() {
    int i, j;
    int sum = 0;

    // Roll the first die
    int die1 = rand_int(NUM_SIDES) + 1;
    printf("Rolling the first die...\n");
    for (i = 1; i <= NUM_SIDES; i++) {
        printf("%d ", i);
    }
    printf("The first die shows %d.\n", die1);

    // Roll the second die
    int die2 = rand_int(NUM_SIDES) + 1;
    printf("Rolling the second die...\n");
    for (i = 1; i <= NUM_SIDES; i++) {
        printf("%d ", i);
    }
    printf("The second die shows %d.\n", die2);

    // Calculate the sum of the two dice
    for (i = 1; i <= NUM_DICE; i++) {
        sum += die1 + die2;
    }
    printf("The total is %d.\n", sum);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int choice;
    do {
        printf("Cyberpunk Dice Roller\n");
        printf("1. Roll the dice\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            roll_dice();
            break;
        case 2:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 2);

    return 0;
}