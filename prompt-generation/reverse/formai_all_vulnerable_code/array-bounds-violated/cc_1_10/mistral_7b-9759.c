//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define SYMBOL '_'
#define HIDE_TIME 1000 // in milliseconds

void print_grid(char grid[ROWS][COLS]);
void hide_grid(char grid[ROWS][COLS]);
int play_round();

int main() {
    char grid[ROWS][COLS];
    int points = 0;
    int rounds = 5;

    srand(time(NULL));

    for (int i = 0; i < rounds; i++) {
        printf("Round %d:\n", i + 1);
        print_grid(grid);
        hide_grid(grid);
        points += play_round();
        printf("You got %d points in this round.\n\n", points);
    }

    printf("Game Over! Your total points are: %d\n", points);
    return 0;
}

void print_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void hide_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = SYMBOL;
        }
    }

    system("clear"); // for Linux/macOS
    // system("cls");  // for Windows
}

int play_round() {
    char grid[ROWS][COLS], user_guess[ROWS][COLS];
    int x, y, correct_x, correct_y;
    int points = 0;

    hide_grid(grid);

    printf("Remember the positions of the 'X' symbols:\n");
    print_grid(grid);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'X') {
                x = i;
                y = j;
            }
        }
    }

    printf("Enter the row and column of the 'X' symbol you remember: ");
    scanf("%d %d", &user_guess[x][y]);

    if (user_guess[x][y] == 'X') {
        points++;
    }

    print_grid(grid);
    printf("Your guess: ");
    print_grid(user_guess);

    return points;
}