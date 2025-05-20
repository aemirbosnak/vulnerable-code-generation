//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width, height, score = 0;
    int paddle_x, paddle_y, ball_x, ball_y;

    printf("Welcome to my Breakout Game Clone!\n");
    printf("Enter the width of the screen: ");
    scanf("%d", &width);
    printf("Enter the height of the screen: ");
    scanf("%d", &height);

    int screen[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            screen[i][j] = 0;
        }
    }

    while (1) {
        printf("\n1. Play Game\n2. Exit\n");
        int choice = getchar();
        if (choice == '1') {
            paddle_x = (width - 10) / 2;
            paddle_y = (height - 20) / 2;
            ball_x = (width - 10) / 2;
            ball_y = (height - 20) / 2;

            while (ball_y >= 0 && ball_y < height && ball_x >= 0 && ball_x < width) {
                // Paddle movement
                if (getchar() == 'w') {
                    paddle_y -= 2;
                } else if (getchar() =='s') {
                    paddle_y += 2;
                }

                // Ball movement
                ball_x += getchar() == 'd'? 1 : -1;
                ball_y += getchar() == 'd'? 1 : -1;

                // Check for collisions
                if (screen[ball_y][ball_x] == 1) {
                    ball_x = (width - 10) / 2;
                    ball_y = (height - 20) / 2;
                    score++;
                }

                // Check for paddle collision
                if (screen[ball_y][paddle_x] == 1 && paddle_y > ball_y) {
                    ball_x = (width - 10) / 2;
                    ball_y = (height - 20) / 2;
                    score++;
                }

                // Check for top and bottom wall collisions
                if (ball_y <= 0 || ball_y >= height) {
                    ball_x = (width - 10) / 2;
                    ball_y = (height - 20) / 2;
                }

                // Check for left and right wall collisions
                if (ball_x <= 0 || ball_x >= width) {
                    ball_x = (width - 10) / 2;
                    ball_y = (height - 20) / 2;
                }

                // Update screen
                screen[ball_y][ball_x] = 1;
                screen[paddle_y][paddle_x] = 2;
            }

            printf("\nScore: %d\n", score);
        } else if (choice == '2') {
            break;
        }
    }

    return 0;
}