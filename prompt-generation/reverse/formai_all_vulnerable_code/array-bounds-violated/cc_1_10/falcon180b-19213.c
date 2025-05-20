//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define variables
char map[10][10];
int x = 0, y = 0;
int direction = 0;

// Define functions
void generateMap() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                map[i][j] = '#';
            } else {
                map[i][j] = rand() % 2 + '0';
            }
        }
    }
}

void printMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    if (map[x + dx][y + dy] == '0' || map[x + dx][y + dy] == '1') {
        x += dx;
        y += dy;
    }
}

int main() {
    generateMap();
    printMap();

    while (1) {
        system("clear");
        printMap();
        printf("You are at (%d, %d)\n", x, y);

        int c = getchar();
        switch (c) {
            case 'w':
                direction = 0;
                break;
            case 'a':
                direction = 1;
                break;
            case's':
                direction = 2;
                break;
            case 'd':
                direction = 3;
                break;
            default:
                direction = 0;
        }

        move(0, -1);
        move(-1, 0);
        move(0, 1);
        move(1, 0);

        usleep(100000);
    }

    return 0;
}