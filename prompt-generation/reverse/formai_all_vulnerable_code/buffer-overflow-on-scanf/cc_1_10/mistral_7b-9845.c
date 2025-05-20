//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 26
char morse[][LENGTH] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

void textToMorse(char *text) {
    int i = 0;
    int j = 0;
    int len = strlen(text);

    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            printf("%s ", morse[text[i] - 'A']);
            i++;
        } else if (text[i] == ' ') {
            printf("%s ", morse[26]);
            i++;
        } else {
            printf("Invalid character: %c\n", text[i]);
            break;
        }
    }
}

int main() {
    char inputText[100];

    printf("Enter the text: ");
    scanf("%s", inputText);

    textToMorse(inputText);

    printf("\nMorse Code: ");

    return 0;
}