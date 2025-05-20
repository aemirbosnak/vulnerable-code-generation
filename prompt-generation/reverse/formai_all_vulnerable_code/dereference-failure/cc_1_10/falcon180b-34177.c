//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 1000

typedef struct {
    int num_sides;
    char *name;
} Dice;

Dice dice[MAX_DICE];
int num_dice = 0;

void roll_dice(int num_rolls) {
    int i, j, roll;
    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            roll = rand() % dice[j].num_sides + 1;
            printf("%s: %d\n", dice[j].name, roll);
        }
    }
}

int main() {
    int choice, num_sides, num_dice_to_roll;
    char name[20];

    srand(time(NULL));

    while (1) {
        printf("1. Roll dice\n2. Add dice\n3. Remove dice\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of dice to roll: ");
            scanf("%d", &num_dice_to_roll);
            roll_dice(num_dice_to_roll);
            break;
        case 2:
            printf("Enter number of sides: ");
            scanf("%d", &num_sides);
            printf("Enter name: ");
            scanf("%s", name);
            dice[num_dice].num_sides = num_sides;
            strcpy(dice[num_dice].name, name);
            num_dice++;
            break;
        case 3:
            printf("Enter name of dice to remove: ");
            scanf("%s", name);
            for (int i = 0; i < num_dice; i++) {
                if (strcmp(dice[i].name, name) == 0) {
                    for (int j = i; j < num_dice - 1; j++) {
                        dice[j] = dice[j + 1];
                    }
                    num_dice--;
                    break;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}