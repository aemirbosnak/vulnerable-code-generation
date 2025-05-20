//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define MORSE_CODE_LENGTH 128

void printMorseCode(char morseCode[]) {
    static const char *morseTable[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    int index;
    char character;

    printf("%s: ", morseTable[morseCode[0] - 'A' - 26 * (isdigit(morseCode[0]))]);
    for (int i = 1; morseCode[i] != '\0'; i++) {
        if (isdigit(morseCode[i])) {
            index = morseCode[i] - '0';
            if (index > 9) {
                index -= 10;
                printf(" ");
            }
            if (morseCode[i - 1] != ' ') {
                printf(" ");
            }
            printMorseCode(morseTable[3 + index]);
        } else {
            index = morseCode[i] - 'A';
            if (index < 0 || index > 25) {
                printf("Invalid character: %c\n", morseCode[i]);
                exit(EXIT_FAILURE);
            }
            if (morseCode[i - 1] != ' ') {
                printf(" ");
            }
            printMorseCode(morseTable[index]);
        }

        if (morseCode[i + 1] != '\0') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter text or type 'exit' to quit: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (strlen(input) > MAX_INPUT_LENGTH) {
            printf("Maximum input length exceeded.\n");
            continue;
        }

        printMorseCode(input);
    }

    return EXIT_SUCCESS;
}