//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: grateful
#include <stdio.h>

int main() {
    int x, y;
    char dir;
    int score = 0;

    printf("Welcome to Pac-Man!\n");

    while (1) {
        printf("Choose a direction (up, down, left, right): ");
        scanf("%c", &dir);

        switch (dir) {
            case 'u':
                if (x > 0) {
                    x--;
                } else if (y > 0) {
                    y--;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 'd':
                if (x < 20) {
                    x++;
                } else if (y < 20) {
                    y++;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 'l':
                if (x > 0) {
                    x--;
                } else if (y > 0) {
                    y--;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 'r':
                if (x < 20) {
                    x++;
                } else if (y > 0) {
                    y--;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        if (x == 10 && y == 10) {
            score++;
            printf("You ate a ghost! Score: %d\n", score);
        }

        printf("Score: %d\n", score);
    }

    return 0;
}