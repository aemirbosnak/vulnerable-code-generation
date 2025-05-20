//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

// Morse code dictionary
struct {
    char *code;
    int length;
} morse_dict[] = {
    {"A", 1},
    {"B", 2},
    {"C", 3},
    {"D", 4},
    {"E", 5},
    {"F", 6},
    {"G", 7},
    {"H", 8},
    {"I", 2},
    {"J", 3},
    {"K", 5},
    {"L", 4},
    {"M", 2},
    {"N", 2},
    {"O", 3},
    {"P", 5},
    {"Q", 8},
    {"R", 3},
    {"S", 3},
    {"T", 1},
    {"U", 2},
    {"V", 4},
    {"W", 5},
    {"X", 6},
    {"Y", 6},
    {"Z", 7},
    {"0", 5},
    {"1", 2},
    {"2", 3},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 5}
};

int main() {
    char input[1000];
    int i, j, k, length = 0;

    // Get user input
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
        length--;
    }

    // Convert input to uppercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Convert input to Morse code
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < sizeof(morse_dict) / sizeof(morse_dict[0]); j++) {
            if (input[i] == morse_dict[j].code[0]) {
                for (k = 0; k < morse_dict[j].length; k++) {
                    printf(". ");
                }
                length += morse_dict[j].length;
                break;
            }
        }
        if (i < strlen(input) - 1) {
            printf(" ");
        }
    }

    return 0;
}