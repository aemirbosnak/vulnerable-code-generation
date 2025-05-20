//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MORSE_CODE_LENGTH 26
#define MORSE_CODE_DELIMITER " "

typedef struct {
    char letter;
    char *morse_code;
} MorseCode;

MorseCode morse_codes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
    {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
    {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}
};

char *convert_to_morse_code(char input) {
    int i;
    for (i = 0; i < MORSE_CODE_LENGTH; i++) {
        if (morse_codes[i].letter == input) {
            return morse_codes[i].morse_code;
        }
    }
    return "";
}

void print_morse_code(char *morse_code) {
    int i;
    for (i = 0; i < strlen(morse_code); i++) {
        printf("%c", morse_code[i]);
        usleep(200000);
    }
    printf("%c", '\n');
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide a string to convert to Morse code.\n");
        return 1;
    }

    char *input = argv[1];
    char *morse_code = convert_to_morse_code(input[0]);

    while (morse_code!= NULL) {
        printf("%c ", input[0]);
        print_morse_code(morse_code);
        input++;
        morse_code = convert_to_morse_code(input[0]);
    }

    return 0;
}