//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ART_WIDTH 15
#define ART_HEIGHT 10

char art[ART_HEIGHT][ART_WIDTH + 1];

void initArt() {
    for (int i = 0; i < ART_HEIGHT; ++i) {
        for (int j = 0; j <= ART_WIDTH; ++j) {
            if (i == 0)
                art[i][j] = j < ART_WIDTH ? '*' : '\0';
            else if (i == 1)
                art[i][j] = j == 0 ? 'o' : j < ART_WIDTH / 2 ? '*' : ' ';
            else if (i == 2) {
                if (j == 0)
                    art[i][j] = 'O';
                else if (j < ART_WIDTH / 2)
                    art[i][j] = '*';
                else if (j > ART_WIDTH / 2 && j < ART_WIDTH)
                    art[i][j] = ' ';
                else
                    art[i][j] = '*';
            } else {
                if (j == 0)
                    art[i][j] = '\0';
                else if (isalpha(toupper(j - ART_WIDTH / 2))) {
                    int index = toupper(j - ART_WIDTH / 2) - 'A' + 2 * (i - 2);
                    art[i][j] = index < 0 || index > 25 ? '*' : ' ';
                    if (art[i][j] == ' ') {
                        art[i][j] = '*';
                        for (int k = 0; k < i - 2; ++k)
                            art[i][j - (ART_WIDTH / 2) + k] = ' ';
                    }
                } else
                    art[i][j] = '*';
            }
        }
    }
}

void printArt(const char* text) {
    int textLength = strlen(text);
    for (int i = 0; i < ART_HEIGHT; ++i) {
        for (int j = 0; j <= ART_WIDTH; ++j)
            printf("%c", art[i][j]);
        printf("\n");
    }

    for (int i = 0; i < textLength; ++i) {
        int asciiX = text[i] - 'A' + ART_WIDTH / 2;
        int row = 2 + (text[i] - 'A') / 3;
        for (int j = 0; j < ART_WIDTH; ++j) {
            if (art[row][j] != '*')
                printf("%c", art[row][j]);
            else
                printf(" %d", asciiX + j);
        }
        printf("\n");
    }
}

int main() {
    initArt();
    char input[100];
    printf("Enter a text: ");
    scanf("%s", input);
    printArt(input);
    return 0;
}