//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
    char* name;
    int size;
} Room;

typedef struct Monster {
    char* name;
    int health;
} Monster;

void enterRoom(Room* room, Monster* monster) {
    printf("Entering the %s room...\n", room->name);
    printf("A %s appears! It has %d health.\n", monster->name, monster->health);
    printf("What do you do?\n");
    printf("1. Run away!\n");
    printf("2. Fight the monster!\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You run away, and the monster disappears.\n");
    } else if (choice == 2) {
        printf("You fight the monster!\n");
        printf("The monster has %d health remaining.\n", monster->health);
        printf("What do you do?\n");
        printf("1. Attack!\n");
        printf("2. Run away!\n");
        int attackChoice;
        scanf("%d", &attackChoice);
        if (attackChoice == 1) {
            printf("You attack the monster!\n");
            printf("The monster has %d health remaining.\n", monster->health - 10);
            printf("What do you do?\n");
            printf("1. Attack!\n");
            printf("2. Run away!\n");
            int runChoice;
            scanf("%d", &runChoice);
            if (runChoice == 1) {
                printf("You attack the monster!\n");
                printf("The monster has %d health remaining.\n", monster->health - 10);
            } else {
                printf("You run away!\n");
            }
        } else {
            printf("You run away!\n");
        }
    } else {
        printf("Invalid choice. Try again.\n");
        printf("What do you do?\n");
        printf("1. Run away!\n");
        printf("2. Fight the monster!\n");
        int choice2;
        scanf("%d", &choice2);
        if (choice2 == 1) {
            printf("You run away, and the monster disappears.\n");
        } else if (choice2 == 2) {
            printf("You fight the monster!\n");
            printf("The monster has %d health remaining.\n", monster->health);
            printf("What do you do?\n");
            printf("1. Attack!\n");
            printf("2. Run away!\n");
            int attackChoice2;
            scanf("%d", &attackChoice2);
            if (attackChoice2 == 1) {
                printf("You attack the monster!\n");
                printf("The monster has %d health remaining.\n", monster->health - 10);
            } else {
                printf("You run away!\n");
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

void leaveRoom(Room* room) {
    printf("Leaving the %s room...\n", room->name);
}

void moveToRoom(Room* startRoom, Room* endRoom) {
    printf("Moving to the %s room...\n", endRoom->name);
    leaveRoom(startRoom);
    enterRoom(endRoom, NULL);
}

int main() {
    Room* startRoom = (Room*) malloc(sizeof(Room));
    Room* hallway = (Room*) malloc(sizeof(Room));
    startRoom->name = "Hallway";
    startRoom->size = 10;
    hallway->name = "Bedroom";
    hallway->size = 20;

    Room* livingRoom = (Room*) malloc(sizeof(Room));
    livingRoom->name = "Living Room";
    livingRoom->size = 30;

    Room* kitchen = (Room*) malloc(sizeof(Room));
    kitchen->name = "Kitchen";
    kitchen->size = 40;

    Room* bathroom = (Room*) malloc(sizeof(Room));
    bathroom->name = "Bathroom";
    bathroom->size = 50;

    Room* diningRoom = (Room*) malloc(sizeof(Room));
    diningRoom->name = "Dining Room";
    diningRoom->size = 60;

    Room* basement = (Room*) malloc(sizeof(Room));
    basement->name = "Basement";
    basement->size = 70;

    Monster* monster1 = (Monster*) malloc(sizeof(Monster));
    monster1->name = "Zombie";
    monster1->health = 100;

    Monster* monster2 = (Monster*) malloc(sizeof(Monster));
    monster2->name = "Ghost";
    monster2->health = 150;

    Monster* monster3 = (Monster*) malloc(sizeof(Monster));
    monster3->name = "Werewolf";
    monster3->health = 200;

    Room* currentRoom = startRoom;
    enterRoom(currentRoom, NULL);

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go up\n");
        printf("4. Go down\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            moveToRoom(currentRoom, hallway);
            enterRoom(hallway, monster1);
            enterRoom(livingRoom, monster2);
            enterRoom(kitchen, monster3);
            printf("There is no way to go left.\n");
        } else if (choice == 2) {
            moveToRoom(currentRoom, livingRoom);
            enterRoom(livingRoom, NULL);
            printf("There is no way to go right.\n");
        } else if (choice == 3) {
            moveToRoom(currentRoom, diningRoom);
            enterRoom(diningRoom, NULL);
            printf("There is no way to go up.\n");
        } else if (choice == 4) {
            moveToRoom(currentRoom, basement);
            enterRoom(basement, NULL);
            printf("There is no way to go down.\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    free(startRoom);
    free(hallway);
    free(livingRoom);
    free(kitchen);
    free(bathroom);
    free(diningRoom);
    free(basement);
    free(monster1);
    free(monster2);
    free(monster3);
    return 0;
}