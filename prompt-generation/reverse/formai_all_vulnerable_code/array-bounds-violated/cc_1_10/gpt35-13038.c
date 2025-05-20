//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 100

void generateAsciiArt(char* text) {
    int len = strlen(text);
    int asciiLetters[26][9][7] = { // create a 3D array for each alphabet ascii art
        {
            {0,0,1,1,1,0,0},
            {0,1,0,0,0,1,0},
            {1,0,0,0,0,0,1},
            {1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,0,0,0,0,0,1},
            {0,1,0,0,0,1,0},
            {0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0}
        },
        {
            {1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,1,1,1,1,1,0},
            {1,0,0,0,0,0,1},
            {1,0,0,0,0,0,1},
            {1,1,1,1,1,1,0},
            {0,0,0,0,0,0,1},
            {1,1,1,1,1,1,0}
        },
        // repeat the same pattern for all other alphabets
        // . . .
    };
    for (int i = 0; i < 9; i++) { // for each row
        for (int j = 0; j < len; j++) { // for each letter of text
            int letterIndex = (int)(text[j] - 'a'); // get the ascii art index for that letter
            for (int k = 0; k < 7; k++) { // for each column
                printf("%s", asciiLetters[letterIndex][i][k] ? "*" : " ");
            }
            printf("  "); // add space between letters
        }
        printf("\n"); // start new row
    }
}

int main() {
    char text[MAX_CHAR];
    printf("Enter a text to generate ASCII art: ");
    fgets(text, MAX_CHAR, stdin); // read input from user
    printf("\n");
    generateAsciiArt(text);
    return 0;
}