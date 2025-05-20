//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024
#define MAX_CODE_SIZE 1024
#define MAX_FREQ_SIZE 256

typedef struct {
    unsigned char code[MAX_CODE_SIZE];
    int code_len;
} huffman_code_t;

typedef struct {
    unsigned char symbol;
    unsigned int freq;
} freq_elem_t;

void get_frequency(const unsigned char *input_text, int input_len, freq_elem_t freq_table[MAX_FREQ_SIZE]) {
    memset(freq_table, 0, MAX_FREQ_SIZE * sizeof(freq_elem_t));
    for (int i = 0; i < input_len; i++) {
        freq_table[input_text[i]].symbol = input_text[i];
        freq_table[input_text[i]].freq++;
    }
}

int compare_freq_elems(const void *a, const void *b) {
    freq_elem_t *fa = (freq_elem_t *)a;
    freq_elem_t *fb = (freq_elem_t *)b;
    if (fa->freq == fb->freq) {
        return (int)(fa->symbol - fb->symbol);
    } else {
        return (int)(fa->freq - fb->freq);
    }
}

void build_huffman_tree(freq_elem_t freq_table[MAX_FREQ_SIZE], int num_freq_elems, int *huffman_tree) {
    memset(huffman_tree, -1, MAX_FREQ_SIZE * 2 * sizeof(int));
    int node_index = num_freq_elems;
    for (int i = 0; i < num_freq_elems - 1; i++) {
        int min1, min2;
        min1 = min2 = MAX_FREQ_SIZE;
        int j;
        for (j = 0; j < node_index; j++) {
            if ((huffman_tree[j] == -1) && (freq_table[j].freq < min1)) {
                min2 = min1;
                min1 = freq_table[j].freq;
            } else if ((huffman_tree[j] == -1) && (freq_table[j].freq < min2)) {
                min2 = freq_table[j].freq;
            }
        }
        for (j = 0; j < node_index; j++) {
            if (freq_table[j].freq == min1) {
                huffman_tree[j] = node_index;
                break;
            }
        }
        for (j = 0; j < node_index; j++) {
            if (freq_table[j].freq == min2) {
                huffman_tree[j] = node_index;
                break;
            }
        }
        freq_table[node_index].freq = min1 + min2;
        node_index++;
    }
}

void generate_huffman_codes(int *huffman_tree, int node_index, huffman_code_t *huffman_codes) {
    for (int i = 0; i < node_index; i++) {
        huffman_code_t *code = &huffman_codes[i];
        int node = i;
        while (huffman_tree[node] != -1) {
            if (huffman_tree[huffman_tree[node]] == -1) {
                code->code_len++;
            }
            code->code[code->code_len++] = (unsigned char)(huffman_tree[huffman_tree[node]] == node);
            node = huffman_tree[node];
        }
    }
}

int compress_text(const unsigned char *input_text, int input_len, unsigned char *output_text) {
    freq_elem_t freq_table[MAX_FREQ_SIZE];
    get_frequency(input_text, input_len, freq_table);
    qsort(freq_table, MAX_FREQ_SIZE, sizeof(freq_elem_t), compare_freq_elems);
    int huffman_tree[MAX_FREQ_SIZE * 2];
    build_huffman_tree(freq_table, MAX_FREQ_SIZE, huffman_tree);
    huffman_code_t huffman_codes[MAX_FREQ_SIZE];
    memset(huffman_codes, 0, MAX_FREQ_SIZE * sizeof(huffman_code_t));
    generate_huffman_codes(huffman_tree, MAX_FREQ_SIZE * 2 - 1, huffman_codes);
    unsigned int output_offset = 0, output_bit_offset = 0, input_offset = 0;
    int output_len = 0;
    while (input_offset < input_len) {
        int symbol = input_text[input_offset++];
        huffman_code_t *code = &huffman_codes[symbol];
        for (int i = 0; i < code->code_len; i++) {
            if (output_bit_offset == 8) {
                output_text[output_offset++] = 0;
                output_bit_offset = 0;
            }
            if (code->code[i]) {
                output_text[output_offset] |= (1 << (7 - output_bit_offset));
            }
            output_bit_offset++;
        }
    }
    if (output_bit_offset > 0) {
        output_text[output_offset++] = 0;
    }
    output_len = output_offset;
    return output_len;
}

int decompress_text(const unsigned char *input_text, int input_len, unsigned char *output_text) {
    freq_elem_t freq_table[MAX_FREQ_SIZE];
    get_frequency(input_text, input_len, freq_table);
    qsort(freq_table, MAX_FREQ_SIZE, sizeof(freq_elem_t), compare_freq_elems);
    int huffman_tree[MAX_FREQ_SIZE * 2];
    build_huffman_tree(freq_table, MAX_FREQ_SIZE, huffman_tree);
    int input_offset = 0, output_offset = 0;
    int node_index = MAX_FREQ_SIZE * 2 - 1;
    while (input_offset < input_len - 1) {
        int node = node_index - 1;
        while (huffman_tree[node] != -1) {
            if (huffman_tree[huffman_tree[node]] == -1) {
                output_text[output_offset++] = freq_table[node].symbol;
                node = node_index - 1;
            } else {
                int bit = (input_text[input_offset] & (1 << (7 - (input_offset % 8)))) ? 1 : 0;
                input_offset++;
                if (bit) {
                    node = huffman_tree[node + 1];
                } else {
                    node = huffman_tree[node];
                }
            }
        }
    }
    return output_offset;
}

void print_huffman_tree(int *huffman_tree, int node_index) {
    printf("Huffman tree:\n");
    for (int i = 0; i < node_index; i++) {
        int node = i;
        while (huffman_tree[node] != -1) {
            node = huffman_tree[node];
        }
        printf("[%d]\n", i);
        for (int j = 0; j < node_index; j++) {
            printf("  %d [%d]", j, huffman_tree[j]);
            if (huffman_tree[j] == node) {
                printf(" ***");
            }
            printf("\n");
        }
    }
}

int main(int argc, char **argv) {
    unsigned char input_text[MAX_INPUT_SIZE];
    unsigned char output_text[MAX_OUTPUT_SIZE];
    memset(input_text, 0, MAX_INPUT_SIZE);
    memset(output_text, 0, MAX_OUTPUT_SIZE);
    printf("Enter the text to compress:\n");
    fgets((char *)input_text, MAX_INPUT_SIZE, stdin);
    input_text[strlen((char *)input_text) - 1] = 0; // Remove newline
    int input_len = strlen((char *)input_text);
    printf("Compressing text...\n");
    int output_len = compress_text(input_text, input_len, output_text);
    printf("Compressed %d bytes to %d bytes (%.2lf%% compression ratio).\n", input_len, output_len, 100.0 * (1.0 - (double)output_len / (double)input_len));
    printf("Compressed data (binary):\n");
    for (int i = 0; i < output_len; i++) {
        printf("%02x ", output_text[i]);
    }
    printf("\n");
    printf("Decompressing text...\n");
    input_len = decompress_text(output_text, output_len, input_text);
    printf("Decompressed %d bytes to %d bytes.\n", output_len, input_len);
    printf("Decompressed text: %s\n", input_text);
    return 0;
}