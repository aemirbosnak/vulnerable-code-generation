//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MONSTERS 5
#define TREASURES 3

typedef struct {
    char name[50];
    int health;
    int attack;
} Monster;

typedef struct {
    char name[50];
    int value;
} Treasure;

void generateMonsters(Monster monsters[MONSTERS]) {
    srand(time(NULL));
    for (int i = 0; i < MONSTERS; i++) {
        monsters[i].health = rand() % 100 + 1;
        monsters[i].attack = rand() % 100 + 1;
        sprintf(monsters[i].name, "Monster %d", i + 1);
    }
}

void generateTreasures(Treasure treasures[TREASURES]) {
    for (int i = 0; i < TREASURES; i++) {
        treasures[i].value = rand() % 1000 + 1;
        sprintf(treasures[i].name, "Treasure %d", i + 1);
    }
}

void printRoom(int roomNumber) {
    printf("You are in room %d.\n", roomNumber);
}

int main() {
    Monster monsters[MONSTERS];
    Treasure treasures[TREASURES];

    generateMonsters(monsters);
    generateTreasures(treasures);

    int roomNumber = 1;
    int choice;

    while (1) {
        system("clear");
        printf("Welcome to the Haunted House!\n");
        printf("You are currently in room %d.\n", roomNumber);

        printf("\nWhat would you like to do?\n");
        printf("1. Fight a monster\n");
        printf("2. Search for treasure\n");
        printf("3. Move to another room\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Fight a monster
            break;
        case 2:
            // Search for treasure
            break;
        case 3:
            printf("\nWhich room would you like to move to?\n");
            scanf("%d", &roomNumber);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}