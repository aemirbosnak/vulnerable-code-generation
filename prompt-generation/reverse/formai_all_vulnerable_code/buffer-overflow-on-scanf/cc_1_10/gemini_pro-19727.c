//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1024

// Morse code table
char morse_table[][7] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
    "..--..", "-....-", "-..--", "-.--.", ".-..-", "-.--.-", "-..-.", "-....-",
    "..--.-", ".----.", "-....-", "--..--", "-..-", "-.--", "--.", "---", ".--.-.",
    ".-..-", "-..-.", "-..--", "-.--.-", ".-.-.-", "-....-", "--..--", "---..",
    "----.", "-----", ".-.-.-", "..--..", "-....-", "-..--", "-.--.", ".-..-",
    "-.--.-", "-..-.", "-....-", "..--.-", ".----.", "-....-", "--..--", "-..-",
    "-.--", "--.", "---", ".--.-.", ".-..-", "-..-.", "-..--", "-.--.-", ".-.-.-",
    "-....-", "--..--", "---..", "----.", "-----"
};

// Convert a character to Morse code
void char_to_morse(char c, char *morse_code) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        strcpy(morse_code, morse_table[index]);
    } else {
        morse_code[0] = '\0';
    }
}

// Convert a string to Morse code
void string_to_morse(char *str, char *morse_code) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        char morse[7];
        char_to_morse(c, morse);
        strcat(morse_code, morse);
        strcat(morse_code, " ");
    }
}

// Print the Morse code representation of a string
void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

int main() {
    char msg[MAX_MSG_LEN];
    char morse_code[MAX_MSG_LEN];

    printf("Enter a message to convert to Morse code: ");
    scanf("%s", msg);

    string_to_morse(msg, morse_code);
    print_morse_code(morse_code);

    return 0;
}