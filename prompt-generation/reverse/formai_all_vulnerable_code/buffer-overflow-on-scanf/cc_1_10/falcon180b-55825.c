//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CODE_LENGTH 5
#define MAX_CODE_WORD_LENGTH 10
#define MAX_CODE_TABLE_LENGTH 26

typedef struct {
    char code;
    char *word;
} CodeTable;

CodeTable codeTable[MAX_CODE_TABLE_LENGTH];
int codeTableLength = 0;

void initializeCodeTable() {
    codeTable[0].code = 'A';
    codeTable[0].word = ".-";
    codeTableLength++;

    codeTable[1].code = 'B';
    codeTable[1].word = "-...";
    codeTableLength++;

    codeTable[2].code = 'C';
    codeTable[2].word = "-.-.";
    codeTableLength++;

    //...

    codeTable[25].code = 'Z';
    codeTable[25].word = "--..";
    codeTableLength++;
}

int main() {
    initializeCodeTable();

    // Example usage
    char input[MAX_CODE_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", input);

    char output[MAX_CODE_LENGTH];
    output[0] = '\0';
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            char code = toupper(input[i]);
            for (int j = 0; j < codeTableLength; j++) {
                if (codeTable[j].code == code) {
                    strcat(output, codeTable[j].word);
                    break;
                }
            }
        } else {
            strcat(output, " ");
        }
    }

    printf("Morse code: %s\n", output);

    return 0;
}