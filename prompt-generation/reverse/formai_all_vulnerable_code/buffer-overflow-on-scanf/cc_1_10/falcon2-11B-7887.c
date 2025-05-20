//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char description[100];
    int health;
    int level;
} Room;

typedef struct {
    char name[50];
    char description[100];
    Room* rooms[10];
} Dungeon;

void generateDungeon(Dungeon* dungeon) {
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        Room newRoom;

        sprintf(newRoom.name, "%s %s", "Room", i + 1);
        sprintf(newRoom.description, "A room with %d enemies and %d items", rand() % 10 + 1, rand() % 10 + 1);
        newRoom.health = rand() % 100 + 100;
        newRoom.level = rand() % 5 + 1;

        dungeon->rooms[i] = &newRoom;
    }
}

void printDungeon(Dungeon* dungeon) {
    printf("Dungeon Map\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", dungeon->rooms[i]->name);
    }
}

void playGame(Dungeon* dungeon) {
    printf("Welcome to the dungeon!\n");
    printf("Room 1\n");
    printf("%s\n", dungeon->rooms[0]->description);

    printf("\nWhat do you want to do?\n");
    printf("1. Fight monsters\n");
    printf("2. Search for items\n");
    printf("3. Explore the dungeon\n");
    printf("4. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You attack the monsters and defeat them!\n");
            break;
        case 2:
            printf("You find a treasure chest and open it!\n");
            break;
        case 3:
            printf("You explore the dungeon and find new rooms!\n");
            break;
        case 4:
            printf("You leave the dungeon and win the game!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

int main() {
    Dungeon dungeon;
    generateDungeon(&dungeon);

    printf("Dungeon Map\n");
    printDungeon(&dungeon);

    playGame(&dungeon);

    return 0;
}