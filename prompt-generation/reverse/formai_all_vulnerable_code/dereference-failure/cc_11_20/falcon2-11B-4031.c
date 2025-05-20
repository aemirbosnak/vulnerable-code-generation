//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Room {
    int width;
    int height;
    char** walls;
    char** floors;
};

struct Player {
    int x;
    int y;
    char** room;
};

int main() {
    // Generate a room with a width and height of 10
    srand(time(NULL));
    int width = rand() % 20 + 10;
    int height = rand() % 20 + 10;
    struct Room room = {width, height, NULL, NULL};

    // Generate walls and floors for the room
    for (int i = 0; i < height; i++) {
        room.walls = (char**)malloc(width * sizeof(char*));
        room.floors = (char**)malloc(width * sizeof(char*));

        for (int j = 0; j < width; j++) {
            char* wall = (char*)malloc(height * sizeof(char));
            wall[0] = 'W';
            room.walls[j] = wall;

            char* floor = (char*)malloc(height * sizeof(char));
            floor[0] = 'F';
            room.floors[j] = floor;
        }
    }

    // Print the room
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", room.walls[j][i]);
        }
        printf("\n");
    }

    // Move the player around the room
    struct Player player = {0, 0, NULL};
    while (1) {
        printf("Movements: (UP, DOWN, LEFT, RIGHT) \n");
        printf("Current Position: (%d, %d) \n", player.x, player.y);
        char input[10];
        scanf("%s", input);

        if (input[0] == 'U') {
            if (player.y > 0) {
                player.y--;
            } else {
                printf("Cannot move up\n");
            }
        } else if (input[0] == 'D') {
            if (player.y < height - 1) {
                player.y++;
            } else {
                printf("Cannot move down\n");
            }
        } else if (input[0] == 'L') {
            if (player.x > 0) {
                player.x--;
            } else {
                printf("Cannot move left\n");
            }
        } else if (input[0] == 'R') {
            if (player.x < width - 1) {
                player.x++;
            } else {
                printf("Cannot move right\n");
            }
        } else {
            printf("Invalid movement\n");
        }

        printf("New Position: (%d, %d) \n", player.x, player.y);
    }

    return 0;
}