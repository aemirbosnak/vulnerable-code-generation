//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 100

typedef struct {
    char *code;
    int length;
} MorseCode;

MorseCode morse_table[] = {
    {"A", 2}, {"B", 3}, {"C", 4}, {"D", 5}, {"E", 6}, {"F", 7}, {"G", 8}, {"H", 9}, {"I", 2}, {"J", 3},
    {"K", 5}, {"L", 4}, {"M", 3}, {"N", 2}, {"O", 3}, {"P", 5}, {"Q", 8}, {"R", 3}, {"S", 3}, {"T", 2},
    {"U", 4}, {"V", 6}, {"W", 9}, {"X", 5}, {"Y", 5}, {"Z", 7}, {"0", 5}, {"1", 2}, {"2", 5}, {"3", 5},
    {"4", 4}, {"5", 4}, {"6", 6}, {"7", 3}, {"8", 3}, {"9", 5}
};

int main() {
    char *input;
    int input_length;
    char *output;
    int output_length;

    printf("Enter the text to convert to Morse code: ");
    scanf("%s", input);
    input_length = strlen(input);

    output_length = input_length * 4;
    output = malloc(output_length + 1);
    if (output == NULL) {
        printf("Error: Out of memory\n");
        return 1;
    }

    for (int i = 0; i < input_length; i++) {
        char c = toupper(input[i]);
        MorseCode *code = NULL;

        for (int j = 0; j < MAX_CODE_LENGTH; j++) {
            if (morse_table[j].code == NULL) {
                break;
            }

            if (c == morse_table[j].code[0]) {
                code = &morse_table[j];
                break;
            }
        }

        if (code == NULL) {
            sprintf(output + i * 4, " ");
        } else {
            strncat(output, code->code, code->length);
        }
    }

    printf("Morse code: %s\n", output);

    free(output);
    return 0;
}