//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ROWS 10
#define COLS 80

/* Function to convert text to ASCII Art */
void text_to_art(char text[], int len) {
    /* Initialize 2D array to store the ASCII Art */
    char art[ROWS][COLS] = {0}; 
    int row, col, i, j, k = 0;
    int char_ascii;
    
    /* Loop through each character of the text */
    for (i = 0; i < len; i++) {
        /* Convert character to ASCII number */
        char_ascii = (int) text[i];
        /* Determine row and column for the corresponding ASCII Art */
        row = (char_ascii - 32) / 8;
        col = (char_ascii - 32) % 8;
        /* Place ASCII Art in corresponding location */
        for (j = row * 2; j < (row * 2) + 2; j++) {
            for (k = col * 10; k < (col * 10) + 8; k++) {
                art[j][k] = '#';
            }
        }
    }
    
    /* Print the resulting ASCII Art */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    int len, i;
    
    /* Prompt user to enter text */
    printf("Enter some text: ");
    gets(text);
    
    /* Convert all characters to uppercase */
    for (i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }
    
    /* Calculate length of text */
    len = strlen(text);
    
    /* Convert text to ASCII Art and print */
    text_to_art(text, len);
    
    return 0;
}