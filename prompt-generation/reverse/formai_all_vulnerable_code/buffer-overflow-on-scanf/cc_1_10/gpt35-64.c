//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 7 // number of rows in the ascii art
#define COLS 10 // number of columns in the ascii art

// array to store the ascii art
char ascii[ROWS][COLS];

// function to print the ascii art
void print_ascii() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize the ascii art
    ascii[0][0] = ascii[1][0] = ascii[2][0] = ascii[3][0] = ascii[4][0] = ascii[5][0] = '/';
    ascii[0][9] = ascii[1][9] = ascii[2][9] = ascii[3][9] = ascii[4][9] = ascii[5][9] = '\\';
    ascii[1][1] = ascii[1][2] = ascii[1][3] = ascii[1][4] = ascii[1][5] = ascii[1][6] = ascii[1][7] = ascii[1][8] = '_';
    ascii[2][2] = ascii[2][3] = ascii[2][6] = ascii[2][7] = '|';
    ascii[3][2] = ascii[3][3] = ascii[3][6] = ascii[3][7] = '|';
    ascii[4][2] = ascii[4][3] = ascii[4][6] = ascii[4][7] = '|';
    ascii[5][2] = ascii[5][3] = ascii[5][6] = ascii[5][7] = '|';
    ascii[6][1] = ascii[6][2] = ascii[6][3] = ascii[6][4] = ascii[6][5] = ascii[6][6] = ascii[6][7] = ascii[6][8] = '_';

    // print the ascii art
    printf("Text to ASCII Art Generator\n");
    printf("############################\n\n");
    printf("Enter your text to convert: ");

    char text[100];
    scanf("%s", text);

    printf("\nYour ASCII art:\n\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            ascii[i][j] = ' ';
        }
    }

    for(int i = 0; text[i] != '\0'; i++) {
        if (i >= COLS) {
            break;
        }
        ascii[3][i+2] = text[i];
    }

    print_ascii();

    return 0;
}