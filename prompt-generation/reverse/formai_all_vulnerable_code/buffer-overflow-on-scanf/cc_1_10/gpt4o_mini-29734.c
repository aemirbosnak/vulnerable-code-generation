//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_TREASURES 3
#define MAX_MONSTERS 3

typedef struct {
    int id;
    int hasTreasure;
    int monsterType;
} Room;

typedef struct {
    int id;
    char *name;
    int strength;
} Monster;

void createDungeon(Room rooms[], int roomCount) {
    for (int i = 0; i < roomCount; i++) {
        rooms[i].id = i + 1;
        rooms[i].hasTreasure = rand() % 2; // Randomly decide if there's treasure
        rooms[i].monsterType = (rooms[i].hasTreasure && rand() % 2 == 0) ? rand() % MAX_MONSTERS + 1 : 0; // Assign monster only if there's treasure
    }
}

void describeRoom(Room room) {
    printf("You are in Room %d.\n", room.id);
    if (room.hasTreasure) {
        printf("There is treasure here!\n");
    } else {
        printf("This room is empty.\n");
    }
    
    if (room.monsterType) {
        printf("Beware! A monster is lurking here!\n");
    }
}

void encounterMonster(int monsterType, Monster monsters[]) {
    printf("You encounter %s!\n", monsters[monsterType - 1].name);
    printf("It has a strength of %d!\n", monsters[monsterType - 1].strength);
}

int main() {
    srand(time(NULL));
    
    Room rooms[MAX_ROOMS];
    Monster monsters[MAX_MONSTERS] = {
        {1, "Goblin", 5},
        {2, "Skeleton", 7},
        {3, "Orc", 10}
    };

    createDungeon(rooms, MAX_ROOMS);

    int roomIndex = 0;
    char command[50];
    int treasureCollected = 0;

    printf("Welcome to the Dungeon Adventure!\n");

    while (1) {
        describeRoom(rooms[roomIndex]);

        if (rooms[roomIndex].monsterType) {
            encounterMonster(rooms[roomIndex].monsterType, monsters);
            printf("Do you want to fight or flee? (fight/flee): ");
            scanf("%s", command);

            if (strcmp(command, "fight") == 0) {
                printf("You bravely fight the monster and defeat it!\n");
            } else {
                printf("You flee back to the previous room!\n");
                roomIndex = (roomIndex > 0) ? roomIndex - 1 : roomIndex; // Stay in the same room if at the start
                continue;
            }
        }

        if (rooms[roomIndex].hasTreasure) {
            printf("You collect the treasure!\n");
            treasureCollected++;
            rooms[roomIndex].hasTreasure = 0; // Remove treasure after collecting it
        }
        
        if (treasureCollected >= MAX_TREASURES) {
            printf("Congratulations! You collected all the treasure!\n");
            break;
        }

        printf("Do you want to move to the next room? (yes/no): ");
        scanf("%s", command);
        
        if (strcmp(command, "yes") == 0) {
            roomIndex = (roomIndex < MAX_ROOMS - 1) ? roomIndex + 1 : roomIndex; // Ensure we don't go beyond the last room
        } else {
            printf("You chose to stay in the room.\n");
        }
    }

    printf("Thank you for playing! You collected %d treasures!\n", treasureCollected);
    return 0;
}