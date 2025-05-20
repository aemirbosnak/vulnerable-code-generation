//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define ROWS 10
#define COLS 100

char ascii_art[ROWS][COLS];

void create_ascii(char input[]) {
    int len = strlen(input);
    int row = 0;
    int col = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] == ' ') {
            col++;
        }
        else if (input[i] == '\n') {
            row++;
            col = 0;
        }
        else {
            char c = input[i];
            int ascii_val = (int) c;
            ascii_art[row][col] = ascii_val;
            col++;
        }
    }
}

void print_ascii() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (ascii_art[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("%c", ascii_art[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter text to be converted to ASCII art:\n");
    char input[MAX_LEN];
    fgets(input, MAX_LEN, stdin);

    create_ascii(input);
    print_ascii();

    return 0;
}