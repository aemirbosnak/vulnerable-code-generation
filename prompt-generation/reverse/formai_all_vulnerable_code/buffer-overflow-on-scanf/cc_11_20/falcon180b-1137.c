//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *description;
    int north, south, east, west;
} Room;

Room rooms[10] = {
    {"You are in a small room with doors to the north and east.", 1, 0, 1, 0},
    {"This is a dark hallway with a door to the south.", 0, 1, 0, 0},
    {"A large chamber with high ceilings and pillars.", 0, 0, 1, 0},
    {"The walls here are covered in strange symbols.", 0, 0, 0, 1},
    {"A narrow passageway leading eastward.", 0, 0, 1, 0},
    {"A room filled with dusty old books.", 0, 1, 0, 0},
    {"A winding staircase leading upwards.", 0, 0, 0, 1},
    {"A dimly lit room with a single door to the west.", 1, 0, 0, 0},
    {"A cold stone floor and iron bars on the windows.", 0, 0, 1, 0},
    {"The exit from the maze."}
};

int main() {
    int playerX = 0, playerY = 0;
    int choice;

    srand(time(NULL));

    printf("Welcome to the Maze of Doom!\n");
    printf("You find yourself in room %d.\n", 1);

    while(1) {
        system("clear");
        printf("You are in room %d.\n", playerX + 1);
        printf("%s\n", rooms[playerX].description);

        printf("What would you like to do?\n");
        printf("1. Go north\n");
        printf("2. Go south\n");
        printf("3. Go east\n");
        printf("4. Go west\n");
        printf("5. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(rooms[playerX].north == 1) {
                    playerY++;
                } else {
                    printf("There is no door to the north.\n");
                }
                break;
            case 2:
                if(rooms[playerX].south == 1) {
                    playerY--;
                } else {
                    printf("There is no door to the south.\n");
                }
                break;
            case 3:
                if(rooms[playerX].east == 1) {
                    playerX++;
                } else {
                    printf("There is no door to the east.\n");
                }
                break;
            case 4:
                if(rooms[playerX].west == 1) {
                    playerX--;
                } else {
                    printf("There is no door to the west.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if(playerX == 9 && playerY == 9) {
            printf("Congratulations! You have escaped the Maze of Doom!\n");
            exit(0);
        }
    }

    return 0;
}