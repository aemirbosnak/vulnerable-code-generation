//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    int value;
} TranslationTable;

void die(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main() {
    TranslationTable table[] = {
        {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10},
        {'K', 11}, {'L', 12}, {'M', 13}, {'N', 14}, {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19}, {'T', 20},
        {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24}, {'Y', 25}, {'Z', 26}, {'a', 27}, {'b', 28}, {'c', 29}, {'d', 30},
        {'e', 31}, {'f', 32}, {'g', 33}, {'h', 34}, {'i', 35}, {'j', 36}, {'k', 37}, {'l', 38}, {'m', 39}, {'n', 40},
        {'o', 41}, {'p', 42}, {'q', 43}, {'r', 44}, {'s', 45}, {'t', 46}, {'u', 47}, {'v', 48}, {'w', 49}, {'x', 50},
        {'y', 51}, {'z', 52}
    };

    char input[100];
    int input_len;
    char output[100];
    int output_len;

    printf("Earthling, you are about to encounter an Alien Language Translator. Do not panic!\n");
    printf("Input your Earth language string: ");
    fgets(input, sizeof(input), stdin);
    input_len = strlen(input);

    if (input[input_len - 1] == '\n') input[input_len - 1] = '\0';

    printf("Alien language translation in progress...\n");

    int i = 0;
    for (; input[i] != '\0'; ++i) {
        for (int j = 0; j < sizeof(table) / sizeof(TranslationTable); ++j) {
            if (input[i] == table[j].symbol) {
                output[output_len++] = table[j].value + '0';
                break;
            }
        }

        if (output_len >= sizeof(output)) {
            die("Output buffer overflow!\n");
        }
    }

    output[output_len] = '\0';

    printf("Alien language translated: %s\n", output);

    return 0;
}