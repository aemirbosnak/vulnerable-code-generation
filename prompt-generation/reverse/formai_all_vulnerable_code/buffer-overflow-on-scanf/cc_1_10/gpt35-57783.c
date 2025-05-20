//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char room[ROWS][COLS];
int playerRow, playerCol;
bool keyFound = false;

void initializeRoom() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            room[i][j] = '.';
        }
    }
    room[2][1] = 'D';
    room[2][8] = 'K';
}

void printRoom() {
    system("clear");
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", room[i][j]);
        }
        printf("\n");
    }
}

void placePlayer() {
    srand(time(NULL));
    playerRow = rand() % (ROWS - 2) + 1;
    playerCol = rand() % (COLS - 2) + 1;
    room[playerRow][playerCol] = 'P';
}

void movePlayer() {
    int direction;
    printf("Which direction would you like to move? (1 for up, 2 for right, 3 for down, 4 for left): ");
    scanf("%d", &direction);
    switch (direction) {
        case 1:
            if (playerRow > 0) {
                if (room[playerRow - 1][playerCol] == 'D') {
                    printf("You have found the door and escaped the haunted house!\n");
                    exit(0);
                } else if (room[playerRow - 1][playerCol] == 'K') {
                    printf("You have found the key!\n");
                    keyFound = true;
                }
                room[playerRow][playerCol] = '.';
                playerRow--;
                room[playerRow][playerCol] = 'P';
            }
            break;
        case 2:
            if (playerCol < COLS - 1) {
                if (room[playerRow][playerCol + 1] == 'D') {
                    printf("You have found the door and escaped the haunted house!\n");
                    exit(0);
                } else if (room[playerRow][playerCol + 1] == 'K') {
                    printf("You have found the key!\n");
                    keyFound = true;
                }
                room[playerRow][playerCol] = '.';
                playerCol++;
                room[playerRow][playerCol] = 'P';
            }
            break;
        case 3:
            if (playerRow < ROWS - 1) {
                if (room[playerRow + 1][playerCol] == 'D') {
                    printf("You have found the door and escaped the haunted house!\n");
                    exit(0);
                } else if (room[playerRow + 1][playerCol] == 'K') {
                    printf("You have found the key!\n");
                    keyFound = true;
                }
                room[playerRow][playerCol] = '.';
                playerRow++;
                room[playerRow][playerCol] = 'P';
            }
            break;
        case 4:
            if (playerCol > 0) {
                if (room[playerRow][playerCol - 1] == 'D') {
                    printf("You have found the door and escaped the haunted house!\n");
                    exit(0);
                } else if (room[playerRow][playerCol - 1] == 'K') {
                    printf("You have found the key!\n");
                    keyFound = true;
                }
                room[playerRow][playerCol] = '.';
                playerCol--;
                room[playerRow][playerCol] = 'P';
            }
            break;
        default:
            printf("Invalid choice. Please choose again.\n");
            break;
    }
}

int main() {
    initializeRoom();
    placePlayer();
    printRoom();
    while (true) {
        movePlayer();
        if (keyFound) {
            printf("You can now open the door!\n");
        }
        printRoom();
    }
    return 0;
}