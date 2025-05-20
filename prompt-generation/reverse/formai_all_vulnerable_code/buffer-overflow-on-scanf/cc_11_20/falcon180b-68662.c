//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

int main() {
    int num_dice, num_faces, i, j, face_value;
    int *dice_values;

    srand(time(NULL));

    // get number of dice and number of faces from user
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter number of faces: ");
    scanf("%d", &num_faces);

    // check if input is valid
    if (num_dice <= 0 || num_faces <= 0 || num_dice > MAX_FACES || num_faces > MAX_VALUE) {
        printf("Invalid input.\n");
        return 1;
    }

    // allocate memory for dice values array
    dice_values = (int *)malloc(num_dice * sizeof(int));
    if (dice_values == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // initialize dice values to 0
    for (i = 0; i < num_dice; i++) {
        dice_values[i] = 0;
    }

    // roll the dice
    for (i = 0; i < num_dice; i++) {
        for (j = 0; j < num_faces; j++) {
            face_value = rand() % num_faces + 1;
            dice_values[i] += face_value;
        }
    }

    // print the results
    printf("Rolling %d dice with %d faces each:\n", num_dice, num_faces);
    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: ", i+1);
        for (j = 0; j < num_faces; j++) {
            printf("%d ", dice_values[i]/j+1);
        }
        printf("\n");
    }

    return 0;
}