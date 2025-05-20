//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MIN_SIDE 2
#define MAX_SIDE 6
#define NUM_DICE 3

typedef struct {
    int sides;
    int number;
} CyberDice;

void roll_dice(CyberDice* dice) {
    dice->number = rand() % (dice->sides + 1);
}

void print_dice(const CyberDice* dice) {
    printf("Cyber Die %d: ", dice->number);
    switch (dice->sides) {
        case 2:
            printf("2-sided\n");
            break;
        case 4:
            printf("4-sided\n");
            break;
        case 6:
            printf("6-sided\n");
            break;
        case 8:
            printf("8-sided\n");
            break;
        case 10:
            printf("10-sided\n");
            break;
        case 12:
            printf("12-sided\n");
            break;
        case 20:
            printf("20-sided\n");
            break;
        default:
            printf("Invalid number of sides: %d\n", dice->sides);
            break;
    }
}

int main() {
    CyberDice dice[NUM_DICE];
    srand(time(NULL));

    printf("Welcome to the Cyberpunk Dice Roller!\n");
    printf("Rolling the following dice:\n");

    for (size_t i = 0; i < NUM_DICE; ++i) {
        printf("Die %d: ", i + 1);
        scanf("%d", &dice[i].sides);
    }

    for (size_t i = 0; i < NUM_DICE; ++i) {
        roll_dice(&dice[i]);
        print_dice(&dice[i]);
    }

    return 0;
}