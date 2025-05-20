//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256
#define MAX_CODE_LENGTH 12

typedef struct {
    char symbol;
    int frequency;
    int code;
    int code_length;
} Symbol;

void build_tree(Symbol *tree, int n) {
    int i, j;
    Symbol *left, *right;
    int freq[MAX_SYMBOLS] = {0};

    for (i = 0; i < n; i++) {
        freq[tree[i].symbol]++;
    }

    for (i = 0; i < n; i++) {
        tree[i].frequency = freq[tree[i].symbol];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tree[i].frequency < tree[j].frequency) {
                left = &tree[i];
                right = &tree[j];
            } else {
                left = &tree[j];
                right = &tree[i];
            }
            break;
        }
    }

    tree[0] = *left;
    tree[n - 1] = *right;

    for (i = 1; i < n - 1; i++) {
        tree[i].frequency = freq[tree[i].symbol] + freq[tree[i - 1].symbol] + freq[tree[i + 1].symbol];
    }
}

void generate_codes(Symbol *tree, int n, char *codes) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < MAX_CODE_LENGTH; j++) {
            codes[i * MAX_CODE_LENGTH + j] = '0';
        }
        codes[i * MAX_CODE_LENGTH + k++] = '1';
    }
}

void print_tree(Symbol *tree, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%c %d %d %d\n", tree[i].symbol, tree[i].frequency, tree[i].code, tree[i].code_length);
    }
}

int main() {
    FILE *input_file, *output_file;
    char filename[100];
    char ch;
    int n, i;
    Symbol *tree;
    char codes[MAX_SYMBOLS * MAX_CODE_LENGTH];

    printf("Enter the input file name: ");
    scanf("%s", filename);

    input_file = fopen(filename, "rb");

    fseek(input_file, 0, SEEK_END);
    n = ftell(input_file);

    fseek(input_file, 0, SEEK_SET);

    tree = (Symbol *) malloc(n * sizeof(Symbol));

    for (i = 0; i < n; i++) {
        fread(&ch, 1, 1, input_file);
        tree[i].symbol = ch;
        tree[i].frequency = 0;
    }

    fclose(input_file);

    build_tree(tree, n);

    generate_codes(tree, n, codes);

    printf("Enter the output file name: ");
    scanf("%s", filename);

    output_file = fopen(filename, "wb");

    for (i = 0; i < n; i++) {
        fprintf(output_file, "%c %d %s\n", tree[i].symbol, tree[i].frequency, codes + i * MAX_CODE_LENGTH);
    }

    fclose(output_file);

    printf("Done.\n");

    return 0;
}