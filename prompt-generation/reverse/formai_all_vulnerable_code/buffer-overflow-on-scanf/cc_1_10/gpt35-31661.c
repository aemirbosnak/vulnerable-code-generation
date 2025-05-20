//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initializeMap(char map[ROWS][COLS]);
void printMap(char map[ROWS][COLS]);
void createAsteroids(char map[ROWS][COLS], int numAsteroids);

int main() {
    char map[ROWS][COLS];
    int numAsteroids;

    // seed for random numbers
    srand(time(NULL));

    printf("Welcome, space adventurer!\n");
    printf("Please enter the number of asteroids you want to encounter: ");
    scanf("%d", &numAsteroids);

    printf("\nGenerating asteroid field...\n");

    // initialize map
    initializeMap(map);

    // create asteroids
    createAsteroids(map, numAsteroids);

    // print map
    printMap(map);

    printf("\nSafe travels!\n");

    return 0;
}

// function to initialize the map with empty space
void initializeMap(char map[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            map[i][j] = ' ';
        }
    }
}

// function to print the map
void printMap(char map[ROWS][COLS]) {
    int i, j;

    printf("\n   1 2 3 4 5 6 7 8 9 10\n");
    printf("  ---------------------\n");

    for (i = 0; i < ROWS; i++) {
        printf("%c| ", 'A' + i);
        for (j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("|\n");
    }

    printf("  ---------------------\n");
}

// function to randomly place asteroids on the map
void createAsteroids(char map[ROWS][COLS], int numAsteroids) {
    int i, j, asteroids = 0;

    while (asteroids < numAsteroids) {
        i = rand() % ROWS;
        j = rand() % COLS;

        if (map[i][j] == ' ') {
            map[i][j] = '*';
            asteroids++;
        }
    }
}