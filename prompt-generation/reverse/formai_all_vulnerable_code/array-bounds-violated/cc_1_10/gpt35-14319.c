//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define DESTINATION 'X'
#define MOVE_UP 'u'
#define MOVE_DOWN 'd'
#define MOVE_LEFT 'l'
#define MOVE_RIGHT 'r'

char map[MAP_SIZE][MAP_SIZE];
int x, y;
char direction = MOVE_UP;

void initializeMap() {
    int i, j;
    for(i=0; i<MAP_SIZE; i++) {
        for(j=0; j<MAP_SIZE; j++) {
            if(i == 0 || j == 0 || i == MAP_SIZE-1 || j == MAP_SIZE-1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '-';
            }
        }
    }

    srand(time(NULL));
    do {
        x = rand() % (MAP_SIZE-2) + 1;
        y = rand() % (MAP_SIZE-2) + 1;
    } while(map[x][y] != '-');
    map[x][y] = DESTINATION;
}

void printMap() {
    int i, j;
    for(i=0; i<MAP_SIZE; i++) {
        for(j=0; j<MAP_SIZE; j++) {
            if(i == x && j == y) {
                printf("O");
            } else {
                printf("%c", map[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void move(char command) {
    map[x][y] = '-';
    switch(command) {
        case MOVE_UP:
            x--;
            break;
        case MOVE_DOWN:
            x++;
            break;
        case MOVE_LEFT:
            y--;
            break;
        case MOVE_RIGHT:
            y++;
            break;
    }
    if(map[x][y] == DESTINATION) {
        printf("You've arrived at your destination!\n");
        exit(0);
    } else {
        map[x][y] = 'O';
    }
    printf("Moving %c...\n", command);
    printMap();
}

void getCommand() {
    printf("Which direction do you want to go?\n");
    printf("u: Up\n");
    printf("d: Down\n");
    printf("l: Left\n");
    printf("r: Right\n");
    scanf(" %c", &direction);
}

int main() {
    initializeMap();
    printf("Welcome to the surreal GPS Navigation Simulation!\n");
    printf("Your goal is to reach the destination marked as %c.\n", DESTINATION);
    printMap();
    while(1) {
        getCommand();
        move(direction);
    }
    return 0;
}