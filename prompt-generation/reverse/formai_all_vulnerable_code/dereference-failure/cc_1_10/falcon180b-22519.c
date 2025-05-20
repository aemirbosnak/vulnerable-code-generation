//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 32
#define MAX_CODE_WORDS 4096

typedef struct {
    char *code;
    int code_length;
} MorseCode;

MorseCode morse_codes[MAX_CODE_WORDS];
int num_morse_codes = 0;

void load_morse_codes(void) {
    FILE *f;
    char line[MAX_CODE_LENGTH];
    MorseCode mc;
    int i;

    f = fopen("morse_codes.txt", "r");

    if (f == NULL) {
        printf("Error: Could not open morse_codes.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_CODE_LENGTH, f)!= NULL) {
        if (num_morse_codes >= MAX_CODE_WORDS) {
            printf("Error: Too many Morse codes\n");
            exit(1);
        }

        mc.code = strdup(line);
        mc.code_length = strlen(line);

        for (i = 0; i < mc.code_length; i++) {
            if (!isalpha(line[i])) {
                printf("Error: Invalid character in Morse code: %s\n", line);
                exit(1);
            }
        }

        morse_codes[num_morse_codes++] = mc;
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    char input_text[1000000];
    int input_length;
    int i;

    load_morse_codes();

    printf("Enter text to convert to Morse code: ");
    fgets(input_text, sizeof(input_text), stdin);
    input_length = strlen(input_text);

    for (i = 0; i < input_length; i++) {
        if (isalpha(input_text[i])) {
            int j;
            for (j = 0; j < num_morse_codes; j++) {
                if (toupper(input_text[i]) == toupper(morse_codes[j].code[0])) {
                    printf("%s ", morse_codes[j].code);
                    break;
                }
            }
        } else {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}