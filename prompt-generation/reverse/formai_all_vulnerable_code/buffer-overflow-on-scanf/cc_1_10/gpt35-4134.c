//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define DESTINATION 'D'
#define OBSTACLE 'O'
#define EMPTY_SPACE ' '

// function prototypes
void generate_map(char map[MAP_SIZE][MAP_SIZE]);
void print_map(char map[MAP_SIZE][MAP_SIZE]);
void navigate(char map[MAP_SIZE][MAP_SIZE]);

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));

    char map[MAP_SIZE][MAP_SIZE];

    // generate the map
    generate_map(map);

    printf("Welcome to GPS Navigation Simulation!\n");
    print_map(map);

    // start navigation
    navigate(map);

    return 0;
}

void generate_map(char map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            // randomly generate obstacles and empty spaces
            if (rand() % 4 == 0) {
                map[i][j] = OBSTACLE;
            } else {
                map[i][j] = EMPTY_SPACE;
            }
        }
    }

    // randomly generate the destination
    int dest_x = rand() % MAP_SIZE;
    int dest_y = rand() % MAP_SIZE;
    map[dest_x][dest_y] = DESTINATION;
}

void print_map(char map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void navigate(char map[MAP_SIZE][MAP_SIZE]) {
    int x = 0;
    int y = 0;

    while (1) {
        // check if we reached the destination
        if (map[x][y] == DESTINATION) {
            printf("Congratulations! You have reached your destination!\n");
            break;
        }

        // ask for user input to move
        char direction;
        printf("Enter direction (n/s/e/w): ");
        scanf(" %c", &direction);

        // move according to user input
        switch (direction) {
            case 'n':
                x--;
                break;
            case 's':
                x++;
                break;
            case 'e':
                y++;
                break;
            case 'w':
                y--;
                break;
            default:
                printf("Invalid direction\n");
                continue;
        }

        // check if the move is valid
        if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) {
            printf("Invalid move\n");
            x = (x < 0) ? 0 : ((x >= MAP_SIZE) ? MAP_SIZE - 1 : x);
            y = (y < 0) ? 0 : ((y >= MAP_SIZE) ? MAP_SIZE - 1 : y);
            continue;
        }
        if (map[x][y] == OBSTACLE) {
            printf("Obstacle detected!\n");
            x = (x < 0) ? 0 : ((x >= MAP_SIZE) ? MAP_SIZE - 1 : x);
            y = (y < 0) ? 0 : ((y >= MAP_SIZE) ? MAP_SIZE - 1 : y);
            continue;
        }

        // print updated map
        print_map(map);
    }
}