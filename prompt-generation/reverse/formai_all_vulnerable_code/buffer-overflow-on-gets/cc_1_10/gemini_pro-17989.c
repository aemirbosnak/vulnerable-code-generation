//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256

typedef struct {
    unsigned char symbol;
    unsigned long frequency;
} Symbol;

typedef struct {
    Symbol symbols[MAX_SYMBOLS];
    unsigned long num_symbols;
} SymbolTable;

typedef struct {
    unsigned char code[MAX_SYMBOLS];
    unsigned long code_lengths[MAX_SYMBOLS];
} HuffmanCode;

void sort_symbols(SymbolTable *table) {
    for (int i = 0; i < table->num_symbols - 1; i++) {
        for (int j = 0; j < table->num_symbols - i - 1; j++) {
            if (table->symbols[j].frequency > table->symbols[j + 1].frequency) {
                Symbol temp = table->symbols[j];
                table->symbols[j] = table->symbols[j + 1];
                table->symbols[j + 1] = temp;
            }
        }
    }
}

void build_huffman_tree(SymbolTable *table, HuffmanCode *code) {
    while (table->num_symbols > 1) {
        Symbol *s1 = &table->symbols[0];
        Symbol *s2 = &table->symbols[1];

        Symbol new_symbol;
        new_symbol.frequency = s1->frequency + s2->frequency;
        new_symbol.symbol = 0;  // Not used

        table->symbols[0] = new_symbol;
        table->symbols[1] = table->symbols[table->num_symbols - 1];
        table->num_symbols--;

        sort_symbols(table);

        code->code[s1->symbol] = 0;
        code->code_lengths[s1->symbol] = 1;
        code->code[s2->symbol] = 1;
        code->code_lengths[s2->symbol] = 1;
    }
}

void print_huffman_code(HuffmanCode *code) {
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (code->code_lengths[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < code->code_lengths[i]; j++) {
                printf("%d", code->code[i] >> (code->code_lengths[i] - j - 1) & 1);
            }
            printf("\n");
        }
    }
}

int main() {
    SymbolTable table;
    table.num_symbols = 0;

    char input[1024];
    printf("Enter the input string: ");
    gets(input);

    for (int i = 0; input[i] != '\0'; i++) {
        int found = 0;
        for (int j = 0; j < table.num_symbols; j++) {
            if (table.symbols[j].symbol == input[i]) {
                table.symbols[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            table.symbols[table.num_symbols].symbol = input[i];
            table.symbols[table.num_symbols].frequency = 1;
            table.num_symbols++;
        }
    }

    sort_symbols(&table);

    HuffmanCode code;
    build_huffman_tree(&table, &code);

    printf("Huffman Code:\n");
    print_huffman_code(&code);

    return 0;
}