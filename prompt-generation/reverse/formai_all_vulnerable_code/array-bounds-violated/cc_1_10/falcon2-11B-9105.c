//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Room {
    char name[20];
    int x, y;
};

int main() {
    srand(time(NULL));

    struct Room rooms[5] = {
        {"Entrance Hall", 0, 0},
        {"Living Room", 1, 1},
        {"Kitchen", 2, 2},
        {"Dining Room", 3, 3},
        {"Basement", 4, 4}
    };

    struct Room currentRoom = rooms[rand() % 5];
    int direction = rand() % 4;

    printf("You find yourself standing in the entrance hall of a large, old mansion.\n");

    while (direction!= 0) {
        if (direction == 1) {
            printf("You go into the living room.\n");
            currentRoom = rooms[currentRoom.x + 1];
        }
        else if (direction == 2) {
            printf("You go into the kitchen.\n");
            currentRoom = rooms[currentRoom.y - 1];
        }
        else if (direction == 3) {
            printf("You go into the dining room.\n");
            currentRoom = rooms[currentRoom.x - 1];
        }
        else {
            printf("You go down to the basement.\n");
            currentRoom = rooms[currentRoom.y + 1];
        }

        printf("You are now in %s.\n", currentRoom.name);
    }

    printf("You find yourself in the basement, but you can't see any stairs.\n");

    while (1) {
        printf("What do you do? (1) Explore, (2) Rest, (3) Exit\n");
        int choice = getchar();

        switch (choice) {
            case '1':
                printf("You explore the basement and find a secret passage.\n");
                printf("You make your way through the passage and find yourself in %s.\n", currentRoom.name);
                break;
            case '2':
                printf("You decide to take a rest.\n");
                printf("You wake up in the basement, but you can't see any stairs.\n");
                break;
            case '3':
                printf("You decide to exit the haunted house.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}