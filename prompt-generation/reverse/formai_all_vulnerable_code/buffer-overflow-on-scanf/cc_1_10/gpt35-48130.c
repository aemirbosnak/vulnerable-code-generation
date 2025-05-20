//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants defining the size of the ASCII art
#define ROWS 8
#define COLS 60

// Function to print a row of the ASCII art
void printRow(char* string, int row) {
    for (int i = 0; i < strlen(string); i++) {
        int asciiVal = (int)string[i];
        for (int j = 0; j < 8; j++) {
            printf("%c", (asciiVal & (1 << (7-j))) ? 'X' : ' ');
        }
    }
    printf("\n");
}

// Function to generate the ASCII art string
char* generateAsciiArt(char* string) {
    char* asciiArt = malloc(sizeof(char) * (ROWS * strlen(string) * 8 + 1));
    int pos = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < strlen(string); j++) {
            int asciiVal = (int)string[j];
            for (int k = 0; k < 8; k++) {
                asciiArt[pos++] = (asciiVal & (1 << (7-k))) ? 'X' : ' ';
            }
        }
        asciiArt[pos++] = '\n';
    }
    asciiArt[pos] = '\0';
    return asciiArt;
}

int main() {
    // Take input from the user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Generate the ASCII art and print it
    char* asciiArt = generateAsciiArt(input);
    for (int i = 0; i < ROWS; i++) {
        printRow(asciiArt, i);
    }

    free(asciiArt);
    return 0;
}