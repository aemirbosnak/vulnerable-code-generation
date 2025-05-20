//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRIDSize 10

int X, Y;
char Grid[GRIDSize][GRIDSize];
int AlienX, AlienY;
int Attempts = 0;

void InitializeGrid() {
    int i, j;
    for (i = 0; i < GRIDSize; i++) {
        for (j = 0; j < GRIDSize; j++) {
            Grid[i][j] = '-';
        }
    }
    Grid[X][Y] = 'S';
    srand(time(NULL));
    AlienX = rand() % GRIDSize;
    AlienY = rand() % GRIDSize;
}

void DisplayGrid() {
    int i, j;
    for (i = 0; i < GRIDSize; i++) {
        for (j = 0; j < GRIDSize; j++) {
            printf(" %c ", Grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int CheckGameStatus() {
    if (X == AlienX && Y == AlienY) {
        return 1;
    }
    return 0;
}

void DisplayEndMessage(int status) {
    if (status == 1) {
        printf("Congratulations! You have successfully captured the alien.\n");
    } else {
        printf("Game Over! The alien has escaped.\n");
    }
}

void PlayGame() {
    char direction;
    printf("Welcome to Space Adventure!\n");
    printf("Your mission is to capture the alien by reaching its location on the Grid.\n");
    InitializeGrid();
    DisplayGrid();

    do {
        printf("Enter your next move (U/D/L/R): ");
        scanf(" %c", &direction);
        if (direction == 'U') {
            if (X > 0) {
                X--;
            }
        } else if (direction == 'D') {
            if (X < GRIDSize - 1) {
                X++;
            }
        } else if (direction == 'L') {
            if (Y > 0) {
                Y--;
            }
        } else if (direction == 'R') {
            if (Y < GRIDSize - 1) {
                Y++;
            }
        }
        Attempts++;
        Grid[X][Y] = 'S';
        DisplayGrid();
    } while (!CheckGameStatus() && Attempts < 15);

    DisplayEndMessage(CheckGameStatus());
}

int main() {
    PlayGame();
    return 0;
}