//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_CODE_LENGTH 5

struct MorseCode {
    char code[MAX_CODE_LENGTH];
    int length;
};

void generateMorseCode(char* input, int index, char* output, int* outputIndex) {
    static struct MorseCode morseTable[] = {
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
        {"M", 3},
        {"N", 2},
        {"O", 3},
        {"P", 5},
        {"Q", 6},
        {"R", 3},
        {"S", 3},
        {"T", 1},
        {"U", 4},
        {"V", 6},
        {"W", 9},
        {"X", 6},
        {"Y", 9},
        {"Z", 7},
        {"1", 5},
        {"2", 5},
        {"3", 5},
        {"4", 6},
        {"5", 5},
        {"6", 5},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"0", 6}
    };

    if (index == strlen(input)) {
        output[(*outputIndex)++] = '\0';
        return;
    }

    struct MorseCode* morseCode = &morseTable[input[index] - 'A'];
    strncat(output, morseCode->code, MAX_CODE_LENGTH);
    generateMorseCode(input, index + 1, output, outputIndex);
}

int main() {
    char input[100];
    char output[1000];
    int outputIndex = 0;

    printf("Enter text to convert to Morse code: ");
    scanf("%s", input);

    generateMorseCode(input, 0, output, &outputIndex);

    printf("Morse code: %s\n", output);

    return 0;
}