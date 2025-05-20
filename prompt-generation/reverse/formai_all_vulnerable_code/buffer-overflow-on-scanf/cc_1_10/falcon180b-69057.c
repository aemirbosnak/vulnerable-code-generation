//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Vector2D;

void generateRandomGalaxy(int width, int height, int numStars) {
    srand(time(NULL));

    for (int i = 0; i < numStars; i++) {
        int x = rand() % width;
        int y = rand() % height;

        printf("* ");
    }
}

void printGalaxy(int width, int height, Vector2D playerPosition) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == playerPosition.y && j == playerPosition.x) {
                printf("@ ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void movePlayer(Vector2D* playerPosition, char direction) {
    switch (direction) {
        case 'w':
            (*playerPosition).y--;
            break;
        case 'a':
            (*playerPosition).x--;
            break;
        case's':
            (*playerPosition).y++;
            break;
        case 'd':
            (*playerPosition).x++;
            break;
        default:
            break;
    }
}

int main() {
    int width, height, numStars;

    printf("Enter galaxy width: ");
    scanf("%d", &width);

    printf("Enter galaxy height: ");
    scanf("%d", &height);

    printf("Enter number of stars: ");
    scanf("%d", &numStars);

    Vector2D playerPosition = {0, 0};

    generateRandomGalaxy(width, height, numStars);

    while (1) {
        system("clear");
        printGalaxy(width, height, playerPosition);

        char input;
        scanf("%c", &input);

        movePlayer(&playerPosition, input);

        if (playerPosition.x < 0 || playerPosition.x >= width || playerPosition.y < 0 || playerPosition.y >= height) {
            printf("You have reached the edge of the galaxy!\n");
            break;
        }
    }

    return 0;
}