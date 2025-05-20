//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 20
#define MAX_DICE 100

typedef struct {
    int faces;
    int value;
} Die;

typedef struct {
    Die *dice;
    int num_dice;
} Roll;

void init_die(Die *die, int faces) {
    die->faces = faces;
    die->value = rand() % faces + 1;
}

void init_roll(Roll *roll, int num_dice, int faces) {
    roll->dice = malloc(sizeof(Die) * num_dice);
    roll->num_dice = num_dice;

    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], faces);
    }
}

void roll_dice(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        roll->dice[i].value = rand() % roll->dice[i].faces + 1;
    }
}

void print_roll(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        printf("Die %d: %d\n", i + 1, roll->dice[i].value);
    }
}

void free_roll(Roll *roll) {
    free(roll->dice);
}

int main() {
    srand(time(NULL));

    int num_dice, faces;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of faces on each die: ");
    scanf("%d", &faces);

    Roll roll;
    init_roll(&roll, num_dice, faces);

    while (1) {
        roll_dice(&roll);
        print_roll(&roll);

        printf("Roll again? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    free_roll(&roll);

    return 0;
}