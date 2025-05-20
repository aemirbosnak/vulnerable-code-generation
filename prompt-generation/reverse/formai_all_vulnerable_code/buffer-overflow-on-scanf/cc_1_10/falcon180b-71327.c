//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

typedef struct {
    int num_sides;
    char *name;
} dice_t;

dice_t dice[MAX_DICE];
int num_dice = 0;

void add_dice(int num_sides, char *name) {
    if (num_dice >= MAX_DICE) {
        printf("Error: Maximum number of dice reached!\n");
        return;
    }
    dice[num_dice].num_sides = num_sides;
    dice[num_dice].name = name;
    num_dice++;
}

void roll_dice(int num_rolls) {
    int i, j, k, total = 0;
    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            k = rand() % dice[j].num_sides + 1;
            printf("%s: %d\n", dice[j].name, k);
            total += k;
        }
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL));

    add_dice(6, "D6");
    add_dice(8, "D8");
    add_dice(10, "D10");
    add_dice(12, "D12");
    add_dice(20, "D20");

    int num_rolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    roll_dice(num_rolls);

    return 0;
}