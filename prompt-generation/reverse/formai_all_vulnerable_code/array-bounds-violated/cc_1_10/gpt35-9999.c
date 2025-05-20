//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <string.h>

char *MORSE_CODE[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char decodeMorse(char *morseCode) {
    for(int i=0; i<26; i++) {
        if(strcmp(MORSE_CODE[i], morseCode) == 0) {
            return i+'A';
        }
    }
    return ' ';
}

void encodeMorse(char *text) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        if(text[i] == ' ') {
            printf(" ");
        } else {
            printf("%s ", MORSE_CODE[text[i]-'A']);
        }
    }
}

int main() {
    char input[100];

    printf("Enter a message to convert to Morse code: ");
    fgets(input, 100, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    printf("\nMorse code: ");
    encodeMorse(input);

    printf("\n\nEnter Morse code to decode: ");
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    printf("\nDecoded message: ");
    while(token != NULL) {
        printf("%c", decodeMorse(token));
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}