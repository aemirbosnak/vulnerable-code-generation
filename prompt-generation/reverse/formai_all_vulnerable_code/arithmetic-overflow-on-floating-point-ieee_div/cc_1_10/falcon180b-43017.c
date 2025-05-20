//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define WPM_MIN 10
#define WPM_MAX 80

void print_grid(char grid[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void generate_random_string(char str[ROWS][COLS]) {
    int i, j;
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            str[i][j] = letters[rand() % strlen(letters)];
        }
    }
}

int main() {
    char grid[ROWS][COLS];
    char input_str[ROWS * COLS];
    int i, j, correct_chars = 0, wrong_chars = 0, total_chars = 0;
    int wpm, accuracy;
    int start_time, end_time, elapsed_time;

    srand(time(NULL));
    generate_random_string(grid);
    printf("Random string: ");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
    }
    printf("\n");

    fgets(input_str, sizeof(input_str), stdin);
    total_chars = strlen(input_str);

    correct_chars = 0;
    wrong_chars = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (isalpha(grid[i][j])) {
                if (tolower(grid[i][j]) == tolower(input_str[j])) {
                    correct_chars++;
                } else {
                    wrong_chars++;
                }
            }
        }
    }

    accuracy = (float)correct_chars / total_chars * 100;
    wpm = (float)total_chars / (elapsed_time / 60);

    printf("Accuracy: %.2f%%\n", accuracy);
    printf("WPM: %.2f\n", wpm);

    return 0;
}