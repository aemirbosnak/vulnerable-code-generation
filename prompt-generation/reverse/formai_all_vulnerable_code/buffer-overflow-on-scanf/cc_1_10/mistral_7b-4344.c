//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 5
#define SIDES_PER_DICE 6
#define MIN_ROLL 1
#define MAX_ROLL 6

typedef struct {
    int sides;
    int num_faces_up;
} dice_t;

void roll_dice(dice_t *dice) {
    dice->num_faces_up = rand() % (dice->sides + 1);
}

void print_dice(dice_t *dice) {
    printf("\nRolled a %d sided dice and got %d faces up!\n", dice->sides, dice->num_faces_up);
}

void roll_dice_set(dice_t *dice_set, int num_rolls) {
    for (int i = 0; i < NUM_DICE; i++) {
        dice_t *dice = &dice_set[i];
        roll_dice(dice);
    }

    for (int i = 0; i < num_rolls; i++) {
        dice_t *dice = dice_set;
        for (int j = 0; j < NUM_DICE; j++) {
            print_dice(dice++);
            roll_dice(dice);
            if (i != num_rolls - 1) {
                printf("------------------------------------------\n");
            }
        }
    }
}

int main() {
    srand(time(NULL));

    dice_t dice_set[NUM_DICE];

    printf("Welcome, brave adventurer, to the mystic dice den!\n");
    printf("Prepare yourself for a thrilling roller coaster ride,\n");
    printf("as you embark on a quest to uncover the secrets of the dice!\n\n");

    int num_rolls;

    printf("Enter the number of rolls you wish to make: ");
    scanf("%d", &num_rolls);

    roll_dice_set(dice_set, num_rolls);

    printf("\nYour journey comes to an end, adventurer. May fortune have smiled upon you.\n");

    return 0;
}