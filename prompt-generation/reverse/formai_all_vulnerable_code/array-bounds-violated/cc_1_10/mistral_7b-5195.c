//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Alien character set
char alien_chars[] = { '!', '@', '#', '%', '&', '*', '(', ')', '_', '+' };

char alien_language[ROWS][COLS];
char earth_language[ROWS][COLS];

void initialize_alien_language() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            alien_language[i][j] = alien_chars[rand() % 11];
        }
    }
}

void initialize_earth_language() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            earth_language[i][j] = 'A' + rand() % 26;
        }
    }
}

char translate_alien_to_earth(int row, int col) {
    return earth_language[row][col];
}

int main() {
    initialize_alien_language();
    initialize_earth_language();

    printf("\nAlien Language:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", alien_language[i][j]);
        }
        printf("\n");
    }

    printf("\nEnglish Translation:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", translate_alien_to_earth(i, j));
        }
        printf("\n");
    }

    return 0;
}