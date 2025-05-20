//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

int main() {
    int num_dice, num_faces, max_value, min_value;
    int *dice_values;
    int i, j, k, sum;
    char *dice_str;
    srand(time(NULL));

    // get user input
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of faces on each die (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &num_faces);

    printf("Enter the maximum value on each die (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &max_value);

    printf("Enter the minimum value on each die (between %d and %d): ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &min_value);

    dice_values = (int *) malloc(num_dice * sizeof(int));
    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_faces + min_value;
        printf("%d ", dice_values[i]);
    }
    printf("\n");

    // roll the dice
    for (i = 0; i < num_dice; i++) {
        sum = 0;
        for (j = 0; j < num_faces; j++) {
            k = rand() % num_faces;
            sum += k;
            if (k == dice_values[i]) {
                printf("%d! ", dice_values[i]);
                break;
            }
        }
        if (sum == num_faces) {
            printf("All %d faces rolled! ", num_faces);
        }
        printf("\n");
    }

    // free memory
    free(dice_values);

    return 0;
}