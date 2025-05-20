//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 10

int board[BOARD_SIZE][BOARD_SIZE];
int playerX, playerY, treasureX, treasureY;

void initBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Place Player
    srand(time(NULL));
    playerX = rand() % BOARD_SIZE;
    playerY = rand() % BOARD_SIZE;
    board[playerX][playerY] = 1;

    // Place treasure
    do {
        treasureX = rand() % BOARD_SIZE;
        treasureY = rand() % BOARD_SIZE;
    } while(board[treasureX][treasureY] != 0);

    board[treasureX][treasureY] = 2;
}

void drawBoard() {
    printf("+");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                printf("   |");
            } else if(board[i][j] == 1) {
                printf(" X |");
            } else if(board[i][j] == 2) {
                printf(" T |");
            } else {
                printf("###|");
            }
        }
        printf("\n+");
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

int getDirection() {
    printf("Enter Direction (1 - Up, 2 - Down, 3 - Left, 4 - Right): ");
    int direction;
    scanf("%d", &direction);
    return direction;
}

void updateBoard(int direction) {
    board[playerX][playerY] = 0;

    switch(direction) {
        case 1: // Up
            playerX--;
            break;
        case 2: // Down
            playerX++;
            break;
        case 3: // Left
            playerY--;
            break;
        case 4: // Right
            playerY++;
            break;
        default:
            printf("Invalid direction\n");
            break;
    }

    if(playerX < 0 || playerY < 0 || playerX >= BOARD_SIZE || playerY >= BOARD_SIZE) {
        printf("Player went out of the board, game over!\n");
        exit(0);
    }

    if(board[playerX][playerY] == 2) {
        printf("You found the treasure, you win!\n");
        exit(0);
    }

    board[playerX][playerY] = 1;
}

int main() {
    initBoard();
    drawBoard();

    while(1) {
        int direction = getDirection();
        updateBoard(direction);
        drawBoard();
    }

    return 0;
}