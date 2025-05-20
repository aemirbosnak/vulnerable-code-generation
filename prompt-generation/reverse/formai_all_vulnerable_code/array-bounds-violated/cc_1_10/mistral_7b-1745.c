//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    int x, y;
} point;

char landscape[WIDTH][HEIGHT] = {
    "#################",
    "#...............#",
    "#..o.........o..#",
    "#......oo......#",
    "#..o.....ooo..o#",
    "#....oo....oo....",
    "#.....oo.........",
    "#############....",
    "#################",
    "#################"
};

void generate_art(point start) {
    point current = start;
    char symbol;

    printf("%s\n", landscape[current.y]);

    while (current.x > 0 || current.x < WIDTH - 1 || current.y > 0 || current.y < HEIGHT - 1) {
        symbol = landscape[current.y][current.x];

        if (symbol == 'o') {
            printf(" X");
            if (current.x > 0) current.x--;
            if (current.x < WIDTH - 1) current.x++;
            if (current.y > 0) current.y--;
            if (current.y < HEIGHT - 1) current.y++;
        } else if (symbol == '#') {
            switch (rand() % 4) {
                case 0:
                    printf(" R");
                    current.x += 2;
                    break;
                case 1:
                    printf(" C");
                    current.y++;
                    break;
                case 2:
                    printf(" W");
                    current.x--;
                    break;
                case 3:
                    printf(" T");
                    current.y--;
                    break;
            }
        } else {
            printf("%c", symbol);
            if (current.x > 0) current.x--;
            if (current.x < WIDTH - 1) current.x++;
            if (current.y > 0) current.y--;
            if (current.y < HEIGHT - 1) current.y++;
        }

        printf("%s\n", landscape[current.y]);
    }
}

int main() {
    point start = {15, 5};

    printf("Post-Apocalyptic Scene\n");
    generate_art(start);

    return 0;
}