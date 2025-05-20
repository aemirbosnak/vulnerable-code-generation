//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 50

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

void createTextArt(TextArt *textArt, const char *inputText) {
    int textLength = strlen(inputText);
    int width = 0, height = 0;
    char *artText = malloc(textLength + 1);

    for (int i = 0; i < textLength; i++) {
        if (isalpha(inputText[i])) {
            artText[i] = tolower(inputText[i]);
            width++;
        }
    }

    artText[textLength] = '\0';
    textArt->text = artText;
    textArt->width = width;
    textArt->height = 1;
}

void printTextArt(TextArt *textArt) {
    int i, j;
    for (i = 0; i < textArt->height; i++) {
        for (j = 0; j < textArt->width; j++) {
            printf("%c", textArt->text[i * textArt->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char inputText[MAX_WIDTH + 1];
    printf("Enter some text: ");
    fgets(inputText, MAX_WIDTH, stdin);
    inputText[strcspn(inputText, "\n")] = '\0';

    TextArt textArt;
    createTextArt(&textArt, inputText);
    printTextArt(&textArt);

    return 0;
}