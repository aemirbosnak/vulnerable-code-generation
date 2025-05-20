//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CODE_LENGTH 5
#define MAX_CODE_WIDTH 10

typedef struct {
    char *code;
    int length;
} MorseCode;

MorseCode morse_codes[] = {
    {"A", 1},
    {"B", 2},
    {"C", 2},
    {"D", 3},
    {"E", 1},
    {"F", 2},
    {"G", 3},
    {"H", 4},
    {"I", 2},
    {"J", 3},
    {"K", 3},
    {"L", 2},
    {"M", 2},
    {"N", 2},
    {"O", 3},
    {"P", 4},
    {"Q", 5},
    {"R", 3},
    {"S", 3},
    {"T", 1},
    {"U", 2},
    {"V", 3},
    {"W", 4},
    {"X", 4},
    {"Y", 3},
    {"Z", 2},
    {"0", 5},
    {"1", 2},
    {"2", 3},
    {"3", 4},
    {"4", 4},
    {"5", 3},
    {"6", 3},
    {"7", 4},
    {"8", 4},
    {"9", 5}
};

int get_morse_code_index(char c) {
    int i;
    for (i = 0; i < sizeof(morse_codes) / sizeof(MorseCode); i++) {
        if (tolower(c) == tolower(morse_codes[i].code[0])) {
            return i;
        }
    }
    return -1;
}

int get_morse_code_length(int index) {
    if (index >= 0 && index < sizeof(morse_codes) / sizeof(MorseCode)) {
        return morse_codes[index].length;
    }
    return 0;
}

int get_morse_code_width(int length) {
    if (length > 0 && length <= MAX_CODE_WIDTH) {
        return length;
    }
    return MAX_CODE_WIDTH;
}

void print_morse_code(char *code, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf(". ");
    }
    printf(" ");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++) {
        int index = get_morse_code_index(text[i]);
        if (index >= 0) {
            int code_length = get_morse_code_length(index);
            int code_width = get_morse_code_width(code_length);
            char *code = morse_codes[index].code;

            printf("%s ", code);
            print_morse_code(code, code_length);

            if ((i + 1) % code_width == 0) {
                printf("\n");
            }
        }
    }

    return 0;
}