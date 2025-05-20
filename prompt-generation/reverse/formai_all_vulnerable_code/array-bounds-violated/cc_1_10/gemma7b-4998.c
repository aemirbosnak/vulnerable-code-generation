//Gemma-7B DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define GUARD_HOUSE_SIZE 5
#define ARCH_SIZE 10

typedef struct Knight {
    char name[20];
    int strength;
    int agility;
    int courage;
} Knight;

Knight knights[GUARD_HOUSE_SIZE];

void patrol_the_castle(Knight knight) {
    int i;
    for (i = 0; i < ARCH_SIZE; i++) {
        if (knights[i].strength >= knight.strength) {
            printf("Knight %s has defeated the evil arch villain!\n", knight.name);
            exit(0);
        }
    }
    printf("Knight %s has bravely defended the castle.\n", knight.name);
}

int main() {
    int i;
    for (i = 0; i < GUARD_HOUSE_SIZE; i++) {
        knights[i].strength = rand() % 100;
        knights[i].agility = rand() % 100;
        knights[i].courage = rand() % 100;
        knights[i].name[0] = 'A' + i;
    }

    printf("Enter the name of the knight you want to control:");
    char knight_name[20];
    scanf("%s", knight_name);

    Knight chosen_knight;
    for (i = 0; i < GUARD_HOUSE_SIZE; i++) {
        if (strcmp(knights[i].name, knight_name) == 0) {
            chosen_knight = knights[i];
            break;
        }
    }

    patrol_the_castle(chosen_knight);

    return 0;
}