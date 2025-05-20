//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma pack(push, 1)
typedef struct _sCube {
    char name[21];
    int min;
    int max;
} sCube;
#pragma pack(pop)

sCube _aCubes[] = {
    {"Cube of Fate", 1, 6},
    {"Cube of Fortune", 1, 9},
    {"Cube of Doom", 1, 20},
    {"Cube of Light", 2, 6},
    {"Cube of Darkness", 2, 20},
    {"Cube of Life", 3, 12},
    {"Cube of Death", 3, 12},
    {"Cube of Wishes", 4, 25},
    {"Cube of Illusions", 4, 4},
    {"Cube of Riddles", 5, 10},
    {"Cube of Secrets", 6, 15},
};

void rollDice(int *pResult, int dice, int sides) {
    int i, result = 0;

    for (i = 0; i < dice; i++)
        result += rand() % sides + 1;

    *pResult = result;
}

void printCube(sCube cube) {
    printf("Name: %s\nMin: %d\nMax: %d\n", cube.name, cube.min, cube.max);
}

int main() {
    int i, result, choice;
    sCube *pCube;

    srand(time(NULL));

    printf("Welcome to The Enigmatic Cube of Chance!\n");

    for (i = 0; i < sizeof(_aCubes) / sizeof(sCube); i++) {
        printCube(_aCubes[i]);
    }

    printf("Choose a cube: ");
    scanf("%d", &choice);

    pCube = &_aCubes[choice - 1];

    printf("Rolling %s...\n", pCube->name);

    rollDice(&result, 1, pCube->max - pCube->min + 1);

    printf("Result: %d\n", result);

    return 0;
}