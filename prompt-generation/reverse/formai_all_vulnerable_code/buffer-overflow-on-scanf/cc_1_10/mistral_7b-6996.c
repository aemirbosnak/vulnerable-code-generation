//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code for each letter and number
const char *morse[] = {
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
    "--..", // Y
    "-.--", // Z
    "--..--", // 0
    "....---", // 1
    "..--..", // 2
    "...--.", // 3
    "....-.", // 4
    "--...", // 5
    "---..", // 6
    "----.", // 7
    "-----", // 8
    "-----.", // 9
};

// Function to convert a single character to Morse code
void char_to_morse(char c) {
    int i;

    // Convert uppercase letters and numbers
    if (isalpha(c) || isdigit(c)) {
        for (i = 0; i < 36; i++) {
            if (c == toupper(morse[i][0])) {
                printf("%s", morse[i]);
                return;
            }
        }
    }

    // For any other character, print a single dot for Morse code representation
    printf(".");
}

// Function to convert a string to Morse code
void string_to_morse(const char *str) {
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++) {
        char_to_morse(str[i]);
        if (str[i] != ' ') continue;
        printf("/");
    }
}

int main() {
    char text[100];

    printf("Enter text: ");
    scanf("%s", text);

    string_to_morse(text);

    return 0;
}