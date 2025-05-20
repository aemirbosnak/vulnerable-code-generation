//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    printf("\033[ %d ; %d H", x, y);
}

int main() {
    system("clear");
    int x, y;
    char ch;
    int map[20][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    map[10][10] = 1;
    map[11][10] = 1;
    map[11][11] = 1;
    map[10][11] = 1;

    gotoxy(10, 10);
    printf("O");

    while (1) {
        ch = getchar();
        switch (ch) {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            default:
                break;
        }

        if (map[x][y] == 1) {
            gotoxy(x, y);
            printf("O");
        } else {
            gotoxy(x, y);
            printf(" ");
        }
    }

    return 0;
}