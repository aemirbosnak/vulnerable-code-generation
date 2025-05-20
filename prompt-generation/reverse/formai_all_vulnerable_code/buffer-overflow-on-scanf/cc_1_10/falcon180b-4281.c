//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int health;
    int sanity;
} Character;

void initializeCharacter(Character* character) {
    strcpy(character->name, "John Doe");
    character->age = 30;
    character->health = 100;
    character->sanity = 100;
}

void printCharacterStats(Character* character) {
    printf("Name: %s\n", character->name);
    printf("Age: %d\n", character->age);
    printf("Health: %d\n", character->health);
    printf("Sanity: %d\n", character->sanity);
}

int main() {
    srand(time(NULL));

    Character player;
    initializeCharacter(&player);
    printCharacterStats(&player);

    int choice;
    int randomEvent = rand() % 2;

    if (randomEvent == 0) {
        printf("You find a first aid kit, restoring 25 health points.\n");
        player.health += 25;
    } else {
        printf("You encounter a ghost, losing 10 sanity points.\n");
        player.sanity -= 10;
    }

    while (player.health > 0 && player.sanity > 0) {
        printf("What would you like to do?\n");
        printf("1. Explore the house\n");
        printf("2. Rest\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You explore the house and find a secret room.\n");
                break;
            case 2:
                printf("You take a nap and restore 10 health points.\n");
                player.health += 10;
                break;
            default:
                printf("Invalid choice.\n");
        }

        int randomEvent2 = rand() % 2;

        if (randomEvent2 == 0) {
            printf("You find a snack, restoring 10 health points.\n");
            player.health += 10;
        } else {
            printf("You hear strange noises, losing 5 sanity points.\n");
            player.sanity -= 5;
        }
    }

    if (player.health <= 0) {
        printf("You have died.\n");
    } else {
        printf("You have gone insane.\n");
    }

    return 0;
}