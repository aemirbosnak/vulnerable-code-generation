//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

void alienTranslator(char inputString[]) {
    int i, j, length = 0, rows = 0, columns = 0;
    char delimiter[2] = " ", symbol[5] = "";
    char *token;

    // Determine length of inputString
    length = strlen(inputString);

    // Determine number of rows and columns
    columns = length / 5;
    if (length % 5 != 0) {
        columns += 1;
    }
    rows = 5;

    // Create 2D array for alien language translation
    char alienArray[rows][columns];

    // Initialize array with empty spaces
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            alienArray[i][j] = ' ';
        }
    }

    // Tokenize inputString and populate alienArray
    token = strtok(inputString, delimiter);
    i = 0;
    j = 0;
    while (token != NULL) {
        strcpy(symbol, token);
        if (strlen(symbol) == 1) {
            alienArray[i][j] = symbol[0];
        } else if (strlen(symbol) == 2) {
            alienArray[i][j] = symbol[0];
            alienArray[i+1][j] = symbol[1];
            i += 1;
        } else if (strlen(symbol) == 3) {
            alienArray[i][j] = symbol[0];
            alienArray[i+1][j] = symbol[1];
            alienArray[i+2][j] = symbol[2];
            i += 2;
        }
        token = strtok(NULL, delimiter);
        j++;
        i = 0;
    }

    // Print alien language translation
    printf("Translated alien language:\n\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c", alienArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char inputString[100];

    // Prompt user for input
    printf("Enter an alien language to translate (use spaces for separation): ");
    fgets(inputString, 100, stdin);

    // Call alienTranslator function
    alienTranslator(inputString);

    return 0;
}