//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACES 1000

typedef struct {
    char *name;
    int faces;
} Die;

int main() {
    int num_rolls, i, j, total_faces, max_value;
    Die *dice;
    char input[100];
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_rolls);

    dice = malloc(num_rolls * sizeof(Die));

    for (i = 0; i < num_rolls; i++) {
        printf("What is the name of dice %d? ", i+1);
        scanf("%s", input);
        dice[i].name = strdup(input);

        printf("How many faces does %s have? ", dice[i].name);
        scanf("%d", &dice[i].faces);

        total_faces += dice[i].faces;
    }

    max_value = 1;
    for (i = 0; i < num_rolls; i++) {
        if (dice[i].faces > max_value) {
            max_value = dice[i].faces;
        }
    }

    printf("\n");
    for (i = 0; i < num_rolls; i++) {
        printf("Rolling %s...\n", dice[i].name);
        for (j = 1; j <= dice[i].faces; j++) {
            printf("%s: %d\n", dice[i].name, rand() % dice[i].faces + 1);
        }
        printf("\n");
    }

    printf("Total faces rolled: %d\n", total_faces);
    printf("Max value rolled: %d\n", max_value);

    return 0;
}