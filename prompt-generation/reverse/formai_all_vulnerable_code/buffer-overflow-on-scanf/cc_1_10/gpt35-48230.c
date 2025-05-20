//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define Morse code characters
const char* morse[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                         "....", "..", ".---", "-.-", ".-..", "--", "-.",
                         "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                         "...-", ".--", "-..-", "-.--", "--..", ".----",
                         "..---", "...--", "....-", ".....", "-....",
                         "--...", "---..", "----.", "-----", "/"};

// Convert a character to Morse code
char* char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morse[c - 'A'];
    }
    else if (c >= '0' && c <= '9') {
        return morse[c - '0' + 26];
    }
    else if (c == ' ') {
        return morse[36];
    }
    else {
        return "";
    }
}

// Convert a string to Morse code
char* text_to_morse(char* text) {
    int i, j;
    char *morse_code = (char*) malloc(strlen(text) * 5 + 1);
    char *morse_char;

    for (i = 0; i < strlen(text); i++) {
        morse_char = char_to_morse(text[i]);

        for (j = 0; j < strlen(morse_char); j++) {
            morse_code[i*5+j] = morse_char[j];
        }
        morse_code[i*5+j] = ' ';
    }
    morse_code[i*5-1] = '\0';

    return morse_code;
}

int main() {
    char text[1000];
    char *morse_code;

    printf("Enter text to convert to Morse code:\n");
    scanf("%[^\n]", text);

    morse_code = text_to_morse(text);

    printf("\nMorse code: %s\n", morse_code);

    free(morse_code);
    return 0;
}