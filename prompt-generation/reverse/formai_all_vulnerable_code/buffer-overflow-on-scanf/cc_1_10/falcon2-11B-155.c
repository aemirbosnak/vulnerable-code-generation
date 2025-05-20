//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

typedef struct {
    char name[50];
    char description[100];
    int x;
    int y;
    int level;
    int hp;
    int max_hp;
    int defense;
    int max_defense;
    int attack;
    int max_attack;
    int gold;
    int max_gold;
} Room;

int main() {
    srand(time(NULL));

    Room rooms[NUM_ROOMS] = {
        {"The Bar", "You are in a dingy bar filled with shady characters. There is a bartender at the end of the room.", 1, 1, 10, 10, 0, 0, 1, 1, 100, 100},
        {"The Docks", "You are on a desolate dock, surrounded by rusted metal and abandoned warehouses.", 2, 2, 20, 20, 1, 1, 2, 2, 200, 200},
        {"The Alley", "You are in a narrow alleyway, lined with trash and graffiti. You hear footsteps approaching.", 3, 3, 30, 30, 2, 2, 3, 3, 300, 300},
        {"The Warehouse", "You are in a vast warehouse filled with crates and machinery. You hear the sound of footsteps echoing in the distance.", 4, 4, 40, 40, 3, 3, 4, 4, 400, 400},
        {"The Boss' Office", "You are in a luxurious office, decorated with expensive furniture and artwork. You hear the sound of someone approaching.", 5, 5, 50, 50, 4, 4, 5, 5, 500, 500}
    };

    int current_room = 0;

    while (1) {
        printf("Current Room: %d\n", current_room);
        printf("%s\n", rooms[current_room].name);
        printf("%s\n", rooms[current_room].description);

        if (current_room == NUM_ROOMS - 1) {
            printf("You have reached the end of the game.\n");
            break;
        }

        printf("What do you want to do?\n");
        printf("1. Move\n");
        printf("2. Attack\n");
        printf("3. Inventory\n");
        printf("4. Exit\n");

        int choice = 0;
        while (1) {
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > 4) {
                printf("Invalid choice.\n");
            } else {
                break;
            }
        }

        switch (choice) {
            case 1:
                printf("You move to the next room.\n");
                current_room++;
                break;
            case 2:
                printf("You attack the enemy.\n");
                // TODO: Implement combat mechanics
                break;
            case 3:
                printf("You check your inventory.\n");
                // TODO: Implement inventory mechanics
                break;
            case 4:
                printf("You exit the game.\n");
                exit(0);
                break;
        }
    }

    return 0;
}