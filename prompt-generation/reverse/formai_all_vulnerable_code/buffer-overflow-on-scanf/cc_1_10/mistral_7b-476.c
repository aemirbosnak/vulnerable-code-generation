//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MY_PI 3.14159265358979323846
#define FIRST_ROLL 1
#define SECOND_ROLL 2
#define THIRD_ROLL 3
#define FOURTH_ROLL 4
#define FIFTH_ROLL 5
#define SIXTH_ROLL 6
#define SEVENTH_ROLL 7

typedef struct {
    int side_count;
    int sides[6];
} Die;

void enigma_dice_roll(Die* die, int roll_count) {
    int i, j, k, l;
    double r, g;

    srand((unsigned int)time(NULL));

    for (i = 0; i < roll_count; i++) {
        for (j = 0; j < 6; j++) {
            die->sides[j] = 0;
        }

        g = (double)rand() / MY_PI;
        r = g * 360.0;

        for (k = 0; k < 6; k++) {
            l = (int)((r + k * 60.0) / 30.0) % 6;
            die->sides[l]++;
        }

        for (k = 0, printf("Roll #%d:\n", i + 1); k < 6; k++) {
            printf("%d ", die->sides[k]);
            if (k == 5) printf("\n\n");
        }
    }
}

int main(void) {
    Die my_die;

    printf("Welcome to The Enigma of the Seven Sided Spheres! Enter the number of rolls:\n");
    int rolls;
    scanf("%d", &rolls);

    enigma_dice_roll(&my_die, rolls);

    return EXIT_SUCCESS;
}