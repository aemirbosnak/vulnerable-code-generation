//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_LEN 1000

typedef struct {
    char *code;
    int len;
} MorseCode;

MorseCode morse_codes[] = {
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
    {"N", 6},
    {"O", 3},
    {"P", 5},
    {"Q", 8},
    {"R", 3},
    {"S", 3},
    {"T", 1},
    {"U", 4},
    {"V", 6},
    {"W", 9},
    {"X", 6},
    {"Y", 3},
    {"Z", 7},
    {"0", 5},
    {"1", 2},
    {"2", 5},
    {"3", 5},
    {"4", 4},
    {"5", 4},
    {"6", 6},
    {"7", 3},
    {"8", 5},
    {"9", 5}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int len = strlen(text);
    char *morse_code = calloc(len * 2 + 1, sizeof(char));

    for (int i = 0; i < len; i++) {
        char c = toupper(text[i]);
        int morse_code_len;

        for (int j = 0; j < MAX_CODE_LEN; j++) {
            if (morse_codes[j].code[0] == c) {
                morse_code_len = morse_codes[j].len;
                break;
            }
        }

        if (morse_code_len == 0) {
            printf("Invalid character: %c\n", c);
            return 1;
        }

        for (int j = 0; j < morse_code_len; j++) {
            morse_code[i * 2 + j] = morse_codes[j].code[0];
        }
    }

    printf("Morse code: %s\n", morse_code);

    return 0;
}