//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 100
#define MAX_CODE_TABLE_LENGTH 1000

struct MorseCode {
    char code[MAX_CODE_LENGTH];
    int length;
};

struct MorseCodeTable {
    struct MorseCode *codes;
    int numCodes;
};

void initMorseCodeTable(struct MorseCodeTable *table) {
    table->codes = NULL;
    table->numCodes = 0;
}

void addMorseCode(struct MorseCodeTable *table, char *code) {
    struct MorseCode *newCode = (struct MorseCode *)malloc(sizeof(struct MorseCode));
    strcpy(newCode->code, code);
    newCode->length = strlen(code);
    table->codes = (struct MorseCode *)realloc(table->codes, sizeof(struct MorseCode) * (table->numCodes + 1));
    table->codes[table->numCodes] = *newCode;
    table->numCodes++;
}

void printMorseCodeTable(struct MorseCodeTable *table) {
    if (table->numCodes == 0) {
        printf("No Morse codes found.\n");
        return;
    }
    printf("Morse Code Table:\n");
    printf("----------------\n");
    for (int i = 0; i < table->numCodes; i++) {
        printf("%s (%d): %s\n", table->codes[i].code, table->codes[i].length, table->codes[i].code);
    }
}

void freeMorseCodeTable(struct MorseCodeTable *table) {
    for (int i = 0; i < table->numCodes; i++) {
        free(table->codes[i].code);
    }
    free(table->codes);
}

int main() {
    char input[MAX_CODE_LENGTH];
    struct MorseCodeTable table;
    initMorseCodeTable(&table);
    while (1) {
        printf("Enter Morse code (or 'q' to quit):\n");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        addMorseCode(&table, input);
    }
    printMorseCodeTable(&table);
    freeMorseCodeTable(&table);
    return 0;
}