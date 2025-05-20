//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void display_dice(int sides, int *results, int count);
void print_dice_face(int num);
void roll_dice(int dice_count, int sides, int *results);

int main() {
    int dice_count, sides;
    int results[MAX_DICE];

    printf("Welcome to the Genius Dice Roller!\n");
    printf("Enter the number of dice to roll (1 - %d): ", MAX_DICE);
    scanf("%d", &dice_count);
    if(dice_count < 1 || dice_count > MAX_DICE) {
        printf("Please enter a valid number of dice.\n");
        return 1;
    }

    printf("Enter the number of sides on each die (1 - %d): ", MAX_SIDES);
    scanf("%d", &sides);
    if(sides < 1 || sides > MAX_SIDES) {
        printf("Please enter a valid number of sides.\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    roll_dice(dice_count, sides, results);
    display_dice(sides, results, dice_count);
    
    return 0;
}

void roll_dice(int dice_count, int sides, int *results) {
    for(int i = 0; i < dice_count; i++) {
        results[i] = (rand() % sides) + 1; // Roll the dice
    }
}

void display_dice(int sides, int *results, int count) {
    printf("\nYou rolled the following dice:\n");
    
    for(int i = 0; i < count; i++) {
        printf("Die %d: ", i + 1);
        print_dice_face(results[i]);
    }
}

void print_dice_face(int num) {
    switch(num) {
        case 1:
            printf("-------\n|     |\n|  *  |\n|     |\n-------\n");
            break;
        case 2:
            printf("-------\n| *   |\n|     |\n|   * |\n-------\n");
            break;
        case 3:
            printf("-------\n| *   |\n|  *  |\n|   * |\n-------\n");
            break;
        case 4:
            printf("-------\n| * * |\n|     |\n| * * |\n-------\n");
            break;
        case 5:
            printf("-------\n| * * |\n|  *  |\n| * * |\n-------\n");
            break;
        case 6:
            printf("-------\n| * * |\n| * * |\n| * * |\n-------\n");
            break;
        case 7:
            printf("-------\n| * * * |\n|     |\n| * * * |\n-------\n");
            break;
        case 8:
            printf("-------\n| * * * |\n| *  *  |\n| * * * |\n-------\n");
            break;
        case 9:
            printf("-------\n| * * * |\n| * * * |\n| * * * |\n-------\n");
            break;
        // For illustrative purposes, we can just extend up to 20 with the same pattern
        case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
            printf("-------\n| /\\ /\\ |\n|/  \\/  \\|\n| \\/\\/\\/ |\n-------\n");
            break;
        default:
            printf("Invalid roll!\n");
            break;
    }
}