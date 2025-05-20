//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MORSE_LETTER_A ".-"
#define MORSE_LETTER_B "-..."
#define MORSE_LETTER_C "-.-."
#define MORSE_LETTER_D "-.."
#define MORSE_LETTER_E "."
#define MORSE_LETTER_F "..-."
#define MORSE_LETTER_G "--."
#define MORSE_LETTER_H "...."
#define MORSE_LETTER_I ".."
#define MORSE_LETTER_J ".---"
#define MORSE_LETTER_K "-.-"
#define MORSE_LETTER_L ".-.."
#define MORSE_LETTER_M "--"
#define MORSE_LETTER_N "-."
#define MORSE_LETTER_O "---"
#define MORSE_LETTER_P ".--."
#define MORSE_LETTER_Q "--.-"
#define MORSE_LETTER_R ".-."
#define MORSE_LETTER_S "..."
#define MORSE_LETTER_T "-"
#define MORSE_LETTER_U "..-"
#define MORSE_LETTER_V "...-"
#define MORSE_LETTER_W ".--"
#define MORSE_LETTER_X "-..-"
#define MORSE_LETTER_Y "-.--"
#define MORSE_LETTER_Z "--.."
#define MORSE_LETTER_SPACE "/"
#define MORSE_LETTER_EOF ".-.-.-"

void convert_to_morse(char* input, char* output) {
    while (*input != '\0') {
        if (*input == 'a') {
            strcpy(output, MORSE_LETTER_A);
        } else if (*input == 'b') {
            strcpy(output, MORSE_LETTER_B);
        } else if (*input == 'c') {
            strcpy(output, MORSE_LETTER_C);
        } else if (*input == 'd') {
            strcpy(output, MORSE_LETTER_D);
        } else if (*input == 'e') {
            strcpy(output, MORSE_LETTER_E);
        } else if (*input == 'f') {
            strcpy(output, MORSE_LETTER_F);
        } else if (*input == 'g') {
            strcpy(output, MORSE_LETTER_G);
        } else if (*input == 'h') {
            strcpy(output, MORSE_LETTER_H);
        } else if (*input == 'i') {
            strcpy(output, MORSE_LETTER_I);
        } else if (*input == 'j') {
            strcpy(output, MORSE_LETTER_J);
        } else if (*input == 'k') {
            strcpy(output, MORSE_LETTER_K);
        } else if (*input == 'l') {
            strcpy(output, MORSE_LETTER_L);
        } else if (*input == 'm') {
            strcpy(output, MORSE_LETTER_M);
        } else if (*input == 'n') {
            strcpy(output, MORSE_LETTER_N);
        } else if (*input == 'o') {
            strcpy(output, MORSE_LETTER_O);
        } else if (*input == 'p') {
            strcpy(output, MORSE_LETTER_P);
        } else if (*input == 'q') {
            strcpy(output, MORSE_LETTER_Q);
        } else if (*input == 'r') {
            strcpy(output, MORSE_LETTER_R);
        } else if (*input == 's') {
            strcpy(output, MORSE_LETTER_S);
        } else if (*input == 't') {
            strcpy(output, MORSE_LETTER_T);
        } else if (*input == 'u') {
            strcpy(output, MORSE_LETTER_U);
        } else if (*input == 'v') {
            strcpy(output, MORSE_LETTER_V);
        } else if (*input == 'w') {
            strcpy(output, MORSE_LETTER_W);
        } else if (*input == 'x') {
            strcpy(output, MORSE_LETTER_X);
        } else if (*input == 'y') {
            strcpy(output, MORSE_LETTER_Y);
        } else if (*input == 'z') {
            strcpy(output, MORSE_LETTER_Z);
        } else if (*input == ' ') {
            strcpy(output, MORSE_LETTER_SPACE);
        } else if (*input == '\0') {
            strcpy(output, MORSE_LETTER_EOF);
        }
        input++;
        output += strlen(output);
    }
}

int main() {
    char input[100];
    char output[100];
    scanf("%s", input);
    convert_to_morse(input, output);
    printf("%s\n", output);
    return 0;
}