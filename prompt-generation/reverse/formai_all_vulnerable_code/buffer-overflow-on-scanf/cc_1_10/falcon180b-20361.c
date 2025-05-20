//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[10][10]; // our map
int playerx = 0, playery = 0; // player's position
int score = 0; // player's score

void initmap() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = rand() % 2; // random 0 or 1
        }
    }
    map[0][0] = 0; // set starting position to 0
    map[9][9] = 0; // set ending position to 0
}

void drawmap() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (map[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    int nx, ny;
    nx = playerx + dx;
    ny = playery + dy;
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx][ny] == 0) {
        playerx = nx;
        playery = ny;
    }
}

int main() {
    srand(time(NULL));
    initmap();
    while (1) {
        system("clear");
        drawmap();
        printf("Score: %d\n", score);
        if (playerx == 9 && playery == 9) {
            printf("You win!\n");
            break;
        }
        char ch;
        scanf("%c", &ch);
        if (ch == 'w' || ch == 'W') {
            move(0, -1);
        } else if (ch =='s' || ch == 'S') {
            move(0, 1);
        } else if (ch == 'a' || ch == 'A') {
            move(-1, 0);
        } else if (ch == 'd' || ch == 'D') {
            move(1, 0);
        }
    }
    return 0;
}