//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define MAX_CODE_SIZE 1000

typedef struct {
    char input[MAX_INPUT_SIZE];
    char code[MAX_CODE_SIZE];
} MorseCode;

int is_valid_input(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_code(char *code) {
    int len = strlen(code);
    for (int i = 0; i < len; i++) {
        if (!isalnum(code[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_morse_code(char *morse_code) {
    int len = strlen(morse_code);
    for (int i = 0; i < len; i++) {
        if (!isalnum(morse_code[i])) {
            return 0;
        }
    }
    return 1;
}

void convert_to_morse_code(char *input, char *code) {
    strcpy(code, "");
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (isupper(input[i])) {
            strcat(code, "-");
        } else {
            strcat(code, ".");
        }
        strcat(code, " ");
    }
    strcat(code, "\0");
}

int main() {
    MorseCode morse_code;
    printf("Enter a text to convert to Morse code (max %d characters): ", MAX_INPUT_SIZE);
    scanf("%s", morse_code.input);
    if (!is_valid_input(morse_code.input)) {
        printf("Invalid input. Please enter only alphabets.\n");
        return 0;
    }
    convert_to_morse_code(morse_code.input, morse_code.code);
    if (!is_valid_code(morse_code.code)) {
        printf("Invalid Morse code. Please enter only alphanumeric characters.\n");
        return 0;
    }
    printf("Morse code: %s\n", morse_code.code);
    return 0;
}