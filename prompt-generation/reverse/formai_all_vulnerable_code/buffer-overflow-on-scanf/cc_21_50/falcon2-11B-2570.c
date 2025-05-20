//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    int ball_row, ball_col;
    int player_row, player_col;
    int opponent_row, opponent_col;
    int ball_x_dir, ball_y_dir;
    int score1, score2;

    score1 = 0;
    score2 = 0;

    printf("Welcome to Pong Game with AI Opponent!\n");

    while (1) {
        printf("Enter your row: ");
        scanf("%d", &row);
        printf("Enter your column: ");
        scanf("%d", &col);
        player_row = row;
        player_col = col;

        printf("Enter your opponent's row: ");
        scanf("%d", &opponent_row);
        printf("Enter your opponent's column: ");
        scanf("%d", &opponent_col);
        opponent_row = opponent_row;
        opponent_col = opponent_col;

        ball_row = (player_row + opponent_row) / 2;
        ball_col = (player_col + opponent_col) / 2;

        ball_x_dir = 1;
        ball_y_dir = 1;

        while (1) {
            if (ball_row <= 0 || ball_row >= 10 || ball_col <= 0 || ball_col >= 10) {
                ball_x_dir = -ball_x_dir;
                ball_y_dir = -ball_y_dir;
            }

            ball_row += ball_x_dir;
            ball_col += ball_y_dir;

            if (ball_row < 0 || ball_row > 10 || ball_col < 0 || ball_col > 10) {
                ball_x_dir = -ball_x_dir;
                ball_y_dir = -ball_y_dir;
            }

            if (ball_row == 0 || ball_row == 10 || ball_col == 0 || ball_col == 10) {
                break;
            }

            printf("Row: %d, Col: %d\n", ball_row, ball_col);
            printf("Opponent's Row: %d, Col: %d\n", opponent_row, opponent_col);
            printf("Player's Row: %d, Col: %d\n", player_row, player_col);
            printf("Direction: %d, %d\n", ball_x_dir, ball_y_dir);
            printf("Score1: %d, Score2: %d\n", score1, score2);
            printf("Press any key to continue...\n");
            getchar();
        }

        if (ball_row == 0) {
            if (ball_col == player_col) {
                score2 += 1;
            } else {
                score1 += 1;
            }
        } else if (ball_row == 10) {
            if (ball_col == opponent_col) {
                score2 += 1;
            } else {
                score1 += 1;
            }
        }

        if (score1 == 10 || score2 == 10) {
            break;
        }
    }

    printf("Game Over!\n");
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);
    return 0;
}