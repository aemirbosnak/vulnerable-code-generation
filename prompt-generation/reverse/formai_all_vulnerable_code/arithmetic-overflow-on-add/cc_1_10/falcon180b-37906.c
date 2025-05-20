//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_NUM 6
#define DICE_MAX 6

void roll_dice(int num_dice, int sides) {
    int i, result = 0;
    for (i = 0; i < num_dice; i++) {
        result += rand() % sides + 1;
    }
    printf("Rolling %d %d-sided dice...\n", num_dice, sides);
    printf("Result: %d\n", result);
}

int main() {
    int choice, num_dice, sides;
    srand(time(NULL));

    while (1) {
        printf("\nWelcome to the Dice Roller!\n\n");
        printf("1. Roll 1 dice\n");
        printf("2. Roll multiple dice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of sides on the dice: ");
            scanf("%d", &sides);
            roll_dice(1, sides);
            break;
        case 2:
            printf("Enter the number of dice: ");
            scanf("%d", &num_dice);
            printf("Enter the number of sides on the dice: ");
            scanf("%d", &sides);
            roll_dice(num_dice, sides);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}