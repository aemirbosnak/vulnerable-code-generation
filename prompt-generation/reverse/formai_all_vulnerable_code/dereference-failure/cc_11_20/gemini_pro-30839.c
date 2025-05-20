//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", "|", "  ", "  ", "  ", "  ", "  ", "  ", " ", " "
};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    int len = strlen(text);
    char *morse = malloc(len * 5); // Allocate enough space for the Morse code

    int i, j;
    for (i = 0; i < len; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32; // Convert to uppercase
        }
        for (j = 0; j < 26; j++) {
            if (c == 'A' + j) {
                strcat(morse, morse_table[j]);
                break;
            }
        }
        if (j == 26) {
            for (j = 0; j < 10; j++) {
                if (c == '0' + j) {
                    strcat(morse, morse_table[26 + j]);
                    break;
                }
            }
        }
        if (j == 36) {
            switch (c) {
                case ' ':
                    strcat(morse, "  ");
                    break;
                case '.':
                    strcat(morse, ".----");
                    break;
                case ',':
                    strcat(morse, "--..--");
                    break;
                case '?':
                    strcat(morse, "..--..");
                    break;
                case '/':
                    strcat(morse, "-..-.");
                    break;
                case '(':
                    strcat(morse, "-.--.");
                    break;
                case ')':
                    strcat(morse, "-.--.-");
                    break;
                case '&':
                    strcat(morse, ".-...");
                    break;
                case ':':
                    strcat(morse, "---...");
                    break;
                case ';':
                    strcat(morse, "-.-.-.");
                    break;
                case '=':
                    strcat(morse, "-...-");
                    break;
                case '+':
                    strcat(morse, ".-.-.");
                    break;
                case '-':
                    strcat(morse, "-....-");
                    break;
                case '_':
                    strcat(morse, "..--.-");
                    break;
                case '"':
                    strcat(morse, ".-..-.");
                    break;
                case '\'':
                    strcat(morse, ".----.");
                    break;
                case '!':
                    strcat(morse, "-.-.--");
                    break;
                case '|':
                    strcat(morse, ".-....");
                    break;
            }
        }
    }

    return morse;
}

// Main function
int main() {
    char *text = "Hello World!";
    char *morse = text_to_morse(text);

    printf("Text: %s\n", text);
    printf("Morse code: %s\n", morse);

    free(morse);
    return 0;
}