//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_MOVES 15

typedef struct Position {
    int x;
    int y;
} Position;

void printMap(char map[][MAP_SIZE]);
void initializeMap(char map[][MAP_SIZE]);
int isMoveValid(char map[][MAP_SIZE], Position currentPos, Position targetPos);
int getRand();

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    initializeMap(map);
    printMap(map);
    Position startPos = {getRand(), getRand()};
    Position endPos = {getRand(), getRand()};
    int numMoves = MAX_MOVES;
    while(numMoves > 0 && !(startPos.x == endPos.x && startPos.y == endPos.y)) {
        printf("Enter move: ");
        char move;
        scanf("%c", &move);
        getchar(); //clear input buffer
        Position tempPos = startPos;
        switch(move) {
            case 'u':
                tempPos.x--;
                break;
            case 'd':
                tempPos.x++;
                break;
            case 'l':
                tempPos.y--;
                break;
            case 'r':
                tempPos.y++;
                break;
            default:
                printf("Invalid move\n");
                continue;
        }
        if(isMoveValid(map, startPos, tempPos)) {
            startPos = tempPos;
            numMoves--;
            system("clear");
            printMap(map);
            printf("Moves left: %d\n", numMoves);
        }
        else {
            printf("Invalid move\n");
        }
    }
    if(startPos.x == endPos.x && startPos.y == endPos.y) {
        printf("You have reached the destination! Well done!\n");
    }
    else {
        printf("You have run out of moves. Game over!\n");
    }
    return 0;
}

void initializeMap(char map[][MAP_SIZE]) {
    srand(time(NULL));
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            if(getRand() <= 15) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = ' ';
            }
        }
    }
}

void printMap(char map[][MAP_SIZE]) {
    printf("\n");
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int isMoveValid(char map[][MAP_SIZE], Position currentPos, Position targetPos) {
    if(targetPos.x < 0 || targetPos.x >= MAP_SIZE || targetPos.y < 0 || targetPos.y >= MAP_SIZE) {
        return 0;
    }
    else if(map[targetPos.x][targetPos.y] == '#') {
        return 0;
    }
    else if(abs(targetPos.x - currentPos.x) + abs(targetPos.y - currentPos.y) != 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int getRand() {
    return rand() % 100 + 1;
}