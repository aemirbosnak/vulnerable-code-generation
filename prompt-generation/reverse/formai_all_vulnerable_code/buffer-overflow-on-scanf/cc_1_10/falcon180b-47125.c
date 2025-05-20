//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to print the ASCII art
void print_ascii_art(char *text) {
    int len = strlen(text);
    int rows = len / 50 + 1;
    int cols = 50;
    int i, j;

    // Print the header
    printf("+----+------------------------+\n");
    for (i = 0; i < cols; i++) {
        printf("| %c |", 'A' + i);
    }
    printf("\n");

    // Print the ASCII art
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i * cols + j < len) {
                printf("%c ", text[i * cols + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the footer
    printf("+----+------------------------+\n");
}

// Function to convert text to uppercase
void to_uppercase(char *text) {
    int len = strlen(text);
    int i;

    for (i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
    }
}

int main() {
    char text[1000];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", text);

    // Convert the text to uppercase
    to_uppercase(text);

    // Print the ASCII art
    print_ascii_art(text);

    return 0;
}