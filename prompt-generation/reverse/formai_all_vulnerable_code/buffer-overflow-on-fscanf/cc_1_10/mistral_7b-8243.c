//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol;
    int code;
} TranslationTable;

void loadTranslationTable(FILE *tableFile, TranslationTable *table, int size) {
    char symbol[2];
    int code;
    for (int i = 0; i < size; i++) {
        if (fscanf(tableFile, "%s%d", symbol, &code) != 2) {
            fprintf(stderr, "Invalid table format\n");
            exit(EXIT_FAILURE);
        }
        table[i].symbol = symbol[0];
        table[i].code = code;
    }
}

int translate(TranslationTable table[], char *input, int size) {
    int output = 0;
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < size; j++) {
            if (tolower(input[i]) == table[j].symbol) {
                output += table[j].code;
                break;
            }
        }
    }
    return output;
}

int main() {
    FILE *tableFile = fopen("alien_table.txt", "r");
    if (!tableFile) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int tableSize;
    if (fscanf(tableFile, "%d", &tableSize) != 1) {
        fprintf(stderr, "Invalid table size\n");
        fclose(tableFile);
        return EXIT_FAILURE;
    }

    TranslationTable table[tableSize];
    loadTranslationTable(tableFile, table, tableSize);
    fclose(tableFile);

    char input[100];
    printf("Enter alien text: ");
    scanf("%s", input);

    int output = translate(table, input, tableSize);
    printf("Human translation: ");

    for (int i = 0; i < tableSize; i++) {
        if (table[i].code <= output && table[i].code > 0) {
            printf("%c", table[i].symbol);
            output -= table[i].code;
        }
    }

    printf("\n");
    return EXIT_SUCCESS;
}

// alien_table.txt:
// A 1
// B 2
// C 3
// D 4
// E 5
// F 6
// G 7
// H 8
// I 9
// J 10