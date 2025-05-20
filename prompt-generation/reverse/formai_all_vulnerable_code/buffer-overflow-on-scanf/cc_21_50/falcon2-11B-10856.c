//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int screen_width = 800;
    int screen_height = 600;
    int ball_width = 10;
    int ball_height = 10;
    int paddle_width = 100;
    int paddle_height = 20;
    int ball_speed_x = 2;
    int ball_speed_y = 2;
    int paddle_speed_x = 5;
    int paddle_speed_y = 5;
    int score_a = 0;
    int score_b = 0;
    int time_to_start = 0;

    // Create window
    srand(time(NULL));
    printf("Pong Game with AI Opponent\n");
    printf("Hit 'q' to quit, 'p' to pause/unpause game, 'a' to move left paddle, 'd' to move right paddle\n");
    printf("Press enter to start game\n");
    scanf("%c", &time_to_start);

    while (time_to_start) {
        // Clear screen
        system("cls");
    }

    system("cls");

    // Create ball
    int x_pos = (screen_width / 2) - (ball_width / 2);
    int y_pos = (screen_height / 2) - (ball_height / 2);
    int ball_x = x_pos;
    int ball_y = y_pos;

    // Create paddles
    int paddle_x = screen_width / 2 - paddle_width / 2;
    int paddle_y = screen_height - paddle_height - 10;
    int paddle_a_x = paddle_x;
    int paddle_a_y = paddle_y;
    int paddle_b_x = paddle_x;
    int paddle_b_y = paddle_y;

    // Game loop
    while (1) {
        // Clear screen
        system("cls");

        // Draw game
        printf("Pong Game with AI Opponent\n");
        printf("Score: %d - %d\n", score_a, score_b);
        printf("Hit 'q' to quit, 'p' to pause/unpause game, 'a' to move left paddle, 'd' to move right paddle\n");

        // Draw ball
        printf("Ball X: %d\n", ball_x);
        printf("Ball Y: %d\n", ball_y);
        printf("Ball Width: %d\n", ball_width);
        printf("Ball Height: %d\n", ball_height);
        printf("Ball Speed X: %d\n", ball_speed_x);
        printf("Ball Speed Y: %d\n\n", ball_speed_y);

        // Move ball
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        // Move paddles
        if (ball_y - ball_height > paddle_a_y) {
            paddle_a_y -= paddle_speed_y;
        } else if (ball_y + ball_height < paddle_a_y) {
            paddle_a_y += paddle_speed_y;
        }
        if (ball_y - ball_height > paddle_b_y) {
            paddle_b_y -= paddle_speed_y;
        } else if (ball_y + ball_height < paddle_b_y) {
            paddle_b_y += paddle_speed_y;
        }

        // Check for collision
        if (ball_x < 0 || ball_x > screen_width || ball_y < 0 || ball_y > screen_height) {
            // Reset ball position
            ball_x = (screen_width / 2) - (ball_width / 2);
            ball_y = (screen_height / 2) - (ball_height / 2);

            // Determine winner
            if (ball_x > paddle_a_x && ball_x < paddle_b_x && ball_y < paddle_a_y) {
                score_a++;
            } else if (ball_x < paddle_a_x && ball_x > paddle_b_x && ball_y < paddle_b_y) {
                score_b++;
            }

            // Reset ball speed
            ball_speed_x = -ball_speed_x;
            ball_speed_y = -ball_speed_y;
        }

        // Draw paddles
        printf("Paddle A X: %d\n", paddle_a_x);
        printf("Paddle A Y: %d\n", paddle_a_y);
        printf("Paddle B X: %d\n", paddle_b_x);
        printf("Paddle B Y: %d\n\n", paddle_b_y);

        // Check for player input
        if (getchar() == 'q') {
            break;
        } else if (getchar() == 'p') {
            time_to_start = 1;
        } else if (getchar() == 'a') {
            paddle_a_x -= paddle_speed_x;
        } else if (getchar() == 'd') {
            paddle_b_x += paddle_speed_x;
        }

        // Sleep for 100 milliseconds
        sleep(1);
    }

    // Cleanup
    printf("Game Over\n");
    printf("Score: %d - %d\n", score_a, score_b);
    printf("Hit 'q' to quit\n");
    scanf("%c", &time_to_start);
    while (time_to_start) {
        // Clear screen
        system("cls");
    }

    return 0;
}