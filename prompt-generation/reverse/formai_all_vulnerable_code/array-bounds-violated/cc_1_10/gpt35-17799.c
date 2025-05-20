//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_SIZE 50

char map[MAX_MAP_SIZE][MAX_MAP_SIZE];

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char* name;
    Position position;
} Monster;

Monster player = {"Player", {0,0}};

void printMap(int mapSize) {
    int i, j;
    for (i = 0; i < mapSize; i++) {
        for (j = 0; j < mapSize; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(int mapSize) {
    int i, j;

    // Generate empty map
    for (i = 0; i < mapSize; i++) {
        for (j = 0; j < mapSize; j++) {
            map[i][j] = ' ';
        }
    }

    // Add player to map
    map[player.position.y][player.position.x] = '@';

    // Add monsters to map
    Monster slime = {"Slime", {rand() % mapSize, rand() % mapSize}};
    map[slime.position.y][slime.position.x] = 'S';

    Monster dragon = {"Dragon", {rand() % mapSize, rand() % mapSize}};
    map[dragon.position.y][dragon.position.x] = 'D';
}

void updateMap(int mapSize) {
    int i, j;

    // Reset map
    for (i = 0; i < mapSize; i++) {
        for (j = 0; j < mapSize; j++) {
            map[i][j] = ' ';
        }
    }

    // Add player to map
    map[player.position.y][player.position.x] = '@';

    // Move monsters and add them to map
    Monster slime = {"Slime", {rand() % mapSize, rand() % mapSize}};
    map[slime.position.y][slime.position.x] = 'S';

    Monster dragon = {"Dragon", {rand() % mapSize, rand() % mapSize}};
    map[dragon.position.y][dragon.position.x] = 'D';
}

void movePlayer(char direction, int mapSize) {
    switch (direction) {
        case 'w':
            if (player.position.y - 1 >= 0) {
                player.position.y--;
            }
            break;
        case 'a':
            if (player.position.x - 1 >= 0) {
                player.position.x--;
            }
            break;
        case 's':
            if (player.position.y + 1 < mapSize) {
                player.position.y++;
            }
            break;
        case 'd':
            if (player.position.x + 1 < mapSize) {
                player.position.x++;
            }
            break;
        default:
            printf("Invalid direction\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int mapSize = 10; // Default map size
    char choice;

    printf("Welcome to Shape Shifting Rogue-like game!\n");
    printf("Would you like to change the map size? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter the desired map size (max %d): ", MAX_MAP_SIZE);
        scanf("%d", &mapSize);
        if (mapSize > MAX_MAP_SIZE) {
            printf("Invalid map size, defaulting to %d", MAX_MAP_SIZE);
            mapSize = MAX_MAP_SIZE;
        }
    }

    generateMap(mapSize);
    printMap(mapSize);
    printf("Use w,a,s,d to move and q to quit\n");

    while (1) {
        char direction;
        scanf(" %c", &direction);

        if (direction == 'q') {
            break;
        }

        movePlayer(direction, mapSize);
        updateMap(mapSize);
        printMap(mapSize);
    }

    return 0;
}