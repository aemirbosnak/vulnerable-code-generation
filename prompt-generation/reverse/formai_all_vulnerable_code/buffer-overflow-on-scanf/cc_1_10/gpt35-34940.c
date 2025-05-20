//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

void printMap(char map[MAP_SIZE][MAP_SIZE]) {
    for(int i=0; i<MAP_SIZE; i++) {
        for(int j=0; j<MAP_SIZE; j++) {
            printf("|%c", map[i][j]);
        }
        printf("|\n");
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    int playerPosX = 0, playerPosY = 0;

    srand(time(NULL));
    for(int i=0; i<MAP_SIZE; i++) {
        for(int j=0; j<MAP_SIZE; j++) {
            int r = rand() % 5;
            if(r == 0) {
                map[i][j] = 'X';
            } else {
                map[i][j] = ' ';
            }
        }
    }
    map[playerPosX][playerPosY] = 'O';

    printMap(map);

    char input;
    while(1) {
        printf("Enter a direction (w,a,s,d): ");
        scanf(" %c", &input);

        int newPosX = playerPosX, newPosY = playerPosY;
        switch(input) {
            case 'w':
                newPosX--;
                break;
            case 'a':
                newPosY--;
                break;
            case 's':
                newPosX++;
                break;
            case 'd':
                newPosY++;
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }

        if(newPosX < 0 || newPosY < 0 || newPosX >= MAP_SIZE || newPosY >= MAP_SIZE) {
            printf("You have reached the boundary of space.\n");
            continue;
        }

        if(map[newPosX][newPosY] == 'X') {
            printf("You have encountered a deadly asteroid and died.\n");
            break;
        }

        map[playerPosX][playerPosY] = ' ';
        playerPosX = newPosX;
        playerPosY = newPosY;
        map[playerPosX][playerPosY] = 'O';

        printMap(map);
    }

    return 0;
}