//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define MAX_CODE_NUMBER 26

struct MorseCode {
    char letter;
    char code[MAX_CODE_LENGTH];
};

struct MorseCode morseCodeTable[MAX_CODE_NUMBER] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}
};

void printMorseCode(char code[MAX_CODE_LENGTH]) {
    for (int i = 0; i < strlen(code); i++) {
        printf("%c", code[i]);
        usleep(100000);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char text[1000];
    strcpy(text, argv[1]);

    for (int i = 0; i < strlen(text); i++) {
        char letter = toupper(text[i]);
        for (int j = 0; j < MAX_CODE_NUMBER; j++) {
            if (morseCodeTable[j].letter == letter) {
                printf("%c: %s\n", letter, morseCodeTable[j].code);
                printMorseCode(morseCodeTable[j].code);
            }
        }
    }

    return 0;
}