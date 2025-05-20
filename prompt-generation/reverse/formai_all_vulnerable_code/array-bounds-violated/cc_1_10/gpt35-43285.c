//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE / 2)
#define MAX_CODEBOOK_SIZE 256

typedef struct {
    unsigned char code[MAX_CODEBOOK_SIZE][MAX_CODEBOOK_SIZE];
    unsigned int num_symbols;
} codebook_t;

codebook_t *create_codebook(void) {
    codebook_t *codebook = malloc(sizeof(codebook_t));
    memset(codebook->code, 0, sizeof(codebook->code));
    codebook->num_symbols = 0;
    return codebook;
}

void destroy_codebook(codebook_t *codebook) {
    free(codebook);
}

void add_to_codebook(codebook_t *codebook, unsigned char *symbol, unsigned int symbol_size, unsigned char *code, unsigned int code_size) {

    // add symbol to codebook
    memcpy(codebook->code[codebook->num_symbols], symbol, symbol_size);
    codebook->num_symbols++;

    // add code to codebook
    for (unsigned int i = 0; i < code_size; i++) {
        codebook->code[codebook->num_symbols - 1][i] = code[i];
    }
}

void print_codebook(codebook_t *codebook) {
    printf("Codebook:\n");
    for (unsigned int i = 0; i < codebook->num_symbols; i++) {
        printf("Symbol: %c Code: ", codebook->code[i][0]);
        for (unsigned int j = 1; j < strlen((char *) codebook->code[i]); j++) {
            printf("%c", codebook->code[i][j]);
        }
        printf("\n");
    }
}

int compress(unsigned char *plaintext, unsigned int text_size, unsigned char *compressed) {

    codebook_t *codebook = create_codebook();

    // loop through plaintext
    unsigned int i = 0;
    while (i < text_size) {
        // look for longest match in codebook
        unsigned int match_len = 0;
        unsigned int match_idx = -1;
        for (unsigned int j = 0; j < codebook->num_symbols; j++) {
            unsigned int k = 0;
            while (plaintext[i + k] == codebook->code[j][k + 1]) {
                k++;
            }
            if (k > match_len) {
                match_len = k;
                match_idx = j;
            }
        }

        // output codeword
        memcpy(&compressed[strlen((char *) compressed)], codebook->code[match_idx], strlen((char *) codebook->code[match_idx]));

        // add new symbol to codebook
        unsigned char symbol[MAX_CODEBOOK_SIZE];
        memcpy(symbol, &plaintext[i], match_len+1);
        symbol[match_len+1] = 0;
        add_to_codebook(codebook, symbol, strlen((char *) symbol), &compressed[strlen((char *) compressed) - strlen((char *) codebook->code[match_idx])], strlen((char *) codebook->code[match_idx]));

        // advance i
        i += match_len+1;
    }

    destroy_codebook(codebook);

    return strlen((char *) compressed);
}

int main(void) {
    unsigned char input[MAX_INPUT_SIZE];
    unsigned char output[MAX_OUTPUT_SIZE];

    // read input
    fgets((char *) input, MAX_INPUT_SIZE, stdin);
    input[strlen((char *) input) - 1] = 0;

    // compress
    int output_size = compress(input, strlen((char *) input), output);

    // print output
    printf("Compressed: %s\n", output);
    printf("Output size: %d\n", output_size);

    return 0;
}