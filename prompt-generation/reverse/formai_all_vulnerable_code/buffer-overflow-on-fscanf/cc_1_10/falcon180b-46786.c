//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_MORSE_CODE_LENGTH 500

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    char input_word[MAX_WORD_LENGTH];
    char morse_code_word[MAX_MORSE_CODE_LENGTH];
    char *morse_code_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-";

    while (fscanf(input_file, "%s", input_word)!= EOF) {
        strcpy(morse_code_word, "");
        for (int i = 0; i < strlen(input_word); i++) {
            if (isalpha(input_word[i])) {
                int index = tolower(input_word[i]) - 'a';
                strcat(morse_code_word, morse_code_table[index]);
                strcat(morse_code_word, " ");
            } else if (isdigit(input_word[i])) {
                int index = input_word[i] - '0';
                strcat(morse_code_word, morse_code_table[index * 10]);
                strcat(morse_code_word, " ");
            } else {
                strcat(morse_code_word, " ");
            }
        }
        strcat(morse_code_word, "\n");
        fprintf(output_file, "%s", morse_code_word);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}