//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int sides;
    int value;
} Die;

void print_dice(const Die* die) {
    printf("D%d: ", die->sides);
    if (die->value > 0) {
        printf("%d\n", die->value);
    } else {
        printf("Malus %d\n", -die->value);
    }
}

int roll_die(Die* die) {
    if (die->sides > 20) {
        printf("Error: Cannot create a die with more than 20 sides.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    die->value = rand() % (die->sides + 1);
}

void print_dice_array(const Die* dice, int size) {
    int i;

    for (i = 0; i < size; i++) {
        print_dice(dice + i);
    }
}

int main() {
    int num_dice, sides_per_die, i;

    printf("Welcome to the Dice Roller! Enter the number of dice and sides per die:\n");
    scanf("%d%d", &num_dice, &sides_per_die);

    Die* dice = (Die*) calloc(num_dice, sizeof(Die));

    if (dice == NULL) {
        printf("Error: Failed to allocate memory for the dice.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < num_dice; i++) {
        dice[i].sides = sides_per_die;
    }

    printf("Rolling %d D%d...\n", num_dice, sides_per_die);

    for (i = 0; i < num_dice; i++) {
        roll_die(&dice[i]);
    }

    print_dice_array(dice, num_dice);

    free(dice);

    return EXIT_SUCCESS;
}