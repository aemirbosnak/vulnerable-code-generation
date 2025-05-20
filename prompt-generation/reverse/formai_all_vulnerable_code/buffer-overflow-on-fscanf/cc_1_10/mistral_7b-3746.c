//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    int value;
} TranslationTableEntry;

void loadTranslationTable(const char *filename, TranslationTableEntry *table, int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *numEntries = 0;

    while (fscanf(file, "%c%d", &table[*numEntries].symbol, &table[*numEntries].value) == 2) {
        (*numEntries)++;
    }

    fclose(file);
}

int translate(TranslationTableEntry *table, int numEntries, const char *source) {
    int result = 0;
    int length = strlen(source);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < numEntries; j++) {
            if (source[i] == table[j].symbol) {
                result += table[j].value;
                break;
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <translation_table_file> <source_string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    TranslationTableEntry table[100];
    int numEntries = 0;

    loadTranslationTable(argv[1], table, &numEntries);

    int sourceLength = strlen(argv[2]);
    int result = translate(table, numEntries, argv[2]);

    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}