//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[10][10];
int playerX = 0;
int playerY = 0;
int score = 0;

void initMap() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
    map[0][0] = '@';
}

void printMap() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int move(int dx, int dy) {
    int nx = playerX + dx;
    int ny = playerY + dy;
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
        if (map[nx][ny] == '.') {
            playerX = nx;
            playerY = ny;
            return 1;
        }
    }
    return 0;
}

void gameOver() {
    printf("Game Over!\n");
    printf("Your score is: %d\n", score);
    exit(0);
}

int main() {
    srand(time(0));
    initMap();
    printMap();

    while (1) {
        char key;
        printf("Press a key to move (q to quit): ");
        scanf(" %c", &key);
        if (key == 'q') {
            gameOver();
        } else if (key == 'w' && move(0, -1)) {
            score++;
        } else if (key =='s' && move(0, 1)) {
            score++;
        } else if (key == 'a' && move(-1, 0)) {
            score++;
        } else if (key == 'd' && move(1, 0)) {
            score++;
        }
        printMap();
    }

    return 0;
}