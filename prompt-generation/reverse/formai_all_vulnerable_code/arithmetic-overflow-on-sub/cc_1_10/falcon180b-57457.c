//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generate_map(int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (rand() % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int width, height, player_x = 0, player_y = 0;
    char move;
    Point spaceship;

    srand(time(NULL));
    printf("Enter the width of the map: ");
    scanf("%d", &width);
    printf("Enter the height of the map: ");
    scanf("%d", &height);

    generate_map(width, height);

    while (1) {
        system("clear");
        printf("Your spaceship is at (%d, %d)\n", player_x, player_y);
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                spaceship.y--;
                break;
            case 'a':
                spaceship.x--;
                break;
            case's':
                spaceship.y++;
                break;
            case 'd':
                spaceship.x++;
                break;
            default:
                printf("Invalid move\n");
        }

        if (spaceship.x < 0 || spaceship.x >= width || spaceship.y < 0 || spaceship.y >= height) {
            printf("You crashed into an asteroid!\n");
            return 0;
        }

        if (spaceship.x == width - 1 && spaceship.y == height - 1) {
            printf("Congratulations! You reached the end of the map.\n");
            return 0;
        }
    }

    return 0;
}