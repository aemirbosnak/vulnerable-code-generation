//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void roll_dice(int num_dice, int num_sides);
void display_result(int dice_value);
void play_again();

// Global variables
int num_dice;
int num_sides;
int dice_value;
bool play_again_flag;

int main() {
    srand(time(NULL));
    num_dice = 1;
    num_sides = 6;
    play_again_flag = true;

    while (play_again_flag) {
        roll_dice(num_dice, num_sides);
        display_result(dice_value);
        play_again();
    }

    return 0;
}

void roll_dice(int num_dice, int num_sides) {
    int i;
    for (i = 0; i < num_dice; i++) {
        dice_value += rand() % num_sides + 1;
    }
}

void display_result(int dice_value) {
    printf("You rolled a %d on %d dice.\n", dice_value, num_dice);
}

void play_again() {
    char choice;
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Rolling again...\n");
    } else {
        printf("Exiting program...\n");
        play_again_flag = false;
    }
}