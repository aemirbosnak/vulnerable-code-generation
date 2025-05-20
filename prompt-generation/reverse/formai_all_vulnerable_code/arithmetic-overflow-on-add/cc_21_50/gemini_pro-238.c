//GEMINI-pro DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Donald Knuth
/* Praise to thee, O Master Programmer! */
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SPEED 100000

int main() {
    int x, y, ai_x, ai_y, ball_x, ball_y, ball_dx, ball_dy, score_p1, score_p2, c;
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    srand(time(NULL));
    ball_x = 39;
    ball_y = 15;
    ball_dx = 1;
    ball_dy = 1;
    score_p1 = 0;
    score_p2 = 0;
    while (1) {
        int new_x = x;
        int new_y = y;
        int new_ai_x = ai_x;
        if ((c = getchar()) != EOF) {
            switch (c) {
                case 'w':
                    new_y--;
                    break;
                case 's':
                    new_y++;
                    break;
                case 'a':
                    new_x--;
                    break;
                case 'd':
                    new_x++;
                    break;
                case 'q':
                    return 0;
            }
        }
        if (new_x < 0) new_x = 0;
        if (new_x > 78) new_x = 78;
        if (new_y < 0) new_y = 0;
        if (new_y > 29) new_y = 29;
        x = new_x;
        y = new_y;
        new_ai_x = ball_x - ai_x;
        if (new_ai_x < 0) new_ai_x = 0;
        if (new_ai_x > 78) new_ai_x = 78;
        ai_x = new_ai_x;
        ball_x += ball_dx;
        ball_y += ball_dy;
        if (ball_x <= 0 || ball_x >= 79) {
            ball_dx = -ball_dx;
            if (ball_x <= 0) score_p2++;
            else score_p1++;
        }
        if (ball_y <= 0 || ball_y >= 30) ball_dy = -ball_dy;
        if (ball_x == x && ball_y >= y && ball_y <= y + 4) {
            ball_dx = -ball_dx;
            if (ball_dx < 0) ball_dx--;
            else ball_dx++;
        }
        if (ball_x == ai_x && ball_y >= ai_y && ball_y <= ai_y + 4) {
            ball_dx = -ball_dx;
            if (ball_dx < 0) ball_dx--;
            else ball_dx++;
        }
        system("clear");
        printf("Score:");
        printf("\nPlayer 1: %d", score_p1);
        printf("\nPlayer 2: %d", score_p2);
        printf("\n\n");
        for (int i = 0; i < 80; i++) printf("-");
        printf("\n");
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 80; j++) {
                if (i == y && j == x) printf("P");
                else if (i == ai_y && j == ai_x) printf("A");
                else if (i == ball_y && j == ball_x) printf("o");
                else printf(" ");
            }
            printf("\n");
        }
        for (int i = 0; i < 80; i++) printf("-");
        printf("\n");
        usleep(SPEED);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    return 0;
}