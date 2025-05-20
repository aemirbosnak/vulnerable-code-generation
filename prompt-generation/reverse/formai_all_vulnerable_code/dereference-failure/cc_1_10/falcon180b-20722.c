//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 5
#define MAX_CODE_VALUE 26

typedef struct {
    char code[MAX_CODE_LENGTH];
    int value;
} MorseCode;

MorseCode morseCodeTable[] = {
    {"A", 1}, {"B", 2}, {"C", 3}, {"D", 4}, {"E", 5},
    {"F", 6}, {"G", 7}, {"H", 8}, {"I", 9}, {"J", 10},
    {"K", 11}, {"L", 12}, {"M", 13}, {"N", 14}, {"O", 15},
    {"P", 16}, {"Q", 17}, {"R", 18}, {"S", 19}, {"T", 20},
    {"U", 21}, {"V", 22}, {"W", 23}, {"X", 24}, {"Y", 25},
    {"Z", 26}, {"0", 27}, {"1", 28}, {"2", 29}, {"3", 30},
    {"4", 31}, {"5", 32}, {"6", 33}, {"7", 34}, {"8", 35},
    {"9", 36}, {".", 37}, {",", 38}, {"?", 39}, {"'", 40},
    {"-", 41}, {"/", 42}, {"@", 43}, {" ", 44}, {"!", 45},
    {"\"", 46}, {"$", 47}, {"&", 48}, {"*", 49}, {"(", 50},
    {")", 51}, {"=", 52}, {"+", 53}, {"_", 54}, {"^", 55},
    {"{", 56}, {"|", 57}, {"}", 58}, {"~", 59}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int textLength = strlen(text);

    // Convert text to uppercase
    for (int i = 0; i < textLength; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }

    // Add space between words
    char *word = strtok(text, " ");
    while (word!= NULL) {
        printf("%s ", word);
        word = strtok(NULL, " ");
    }

    return 0;
}