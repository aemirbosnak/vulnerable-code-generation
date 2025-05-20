//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int* dice_values;
} DiceRoller;

void init_dice_roller(DiceRoller* roller, int num_dice, int num_sides) {
    roller->num_dice = num_dice;
    roller->num_sides = num_sides;
    roller->dice_values = malloc(num_dice * sizeof(int));
}

void free_dice_roller(DiceRoller* roller) {
    free(roller->dice_values);
}

void roll_dice(DiceRoller* roller) {
    srand(time(NULL));
    for (int i = 0; i < roller->num_dice; i++) {
        roller->dice_values[i] = rand() % roller->num_sides + 1;
    }
}

void print_dice_rolls(DiceRoller* roller) {
    for (int i = 0; i < roller->num_dice; i++) {
        printf("%d ", roller->dice_values[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    DiceRoller roller;
    init_dice_roller(&roller, num_dice, num_sides);

    int choice;
    do {
        printf("\n");
        printf("1. Roll the dice\n");
        printf("2. Print the dice rolls\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            roll_dice(&roller);
            break;
        case 2:
            print_dice_rolls(&roller);
            break;
        case 3:
            free_dice_roller(&roller);
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}