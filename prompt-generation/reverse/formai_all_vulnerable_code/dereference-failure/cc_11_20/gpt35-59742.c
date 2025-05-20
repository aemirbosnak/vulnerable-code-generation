//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 32

typedef struct {
    unsigned int bitstream;
    int num_bits;
} Bitstream;

typedef struct {
    int code[MAX_CODE_LENGTH];
    int code_length;
} Code;

void encode(char *input, char *output) {
    // initialize frequency array
    int freq[256] = {0};
    for (int i = 0; input[i] != '\0'; i++) {
        freq[(unsigned char)input[i]]++;
    }

    // build Huffman tree
    int num_nodes = 256;
    int *nodes = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = i;
    }
    while (num_nodes > 1) {
        // find lowest frequency nodes
        int min_idx1 = 0;
        int min_idx2 = 1;
        for (int i = 2; i < num_nodes; i++) {
            if (freq[nodes[i]] < freq[nodes[min_idx1]]) {
                min_idx2 = min_idx1;
                min_idx1 = i;
            } else if (freq[nodes[i]] < freq[nodes[min_idx2]]) {
                min_idx2 = i;
            }
        }

        // create new node and update frequency array
        int new_node = num_nodes++;
        nodes[min_idx1] = new_node;
        nodes[min_idx2] = -1;
        freq[new_node] = freq[nodes[min_idx1]] + freq[nodes[min_idx2]];
    }
    int root = nodes[0];
    free(nodes);

    // create codebook
    Code codebook[256];
    int code_length = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            int node = i;
            while (node != root) {
                int parent = -1;
                for (int j = 0; j < num_nodes; j++) {
                    if (nodes[j] == node) {
                        parent = j;
                        break;
                    }
                }

                if (parent % 2 == 0) {  // node is left child
                    codebook[i].code[code_length++] = 0;
                } else {  // node is right child
                    codebook[i].code[code_length++] = 1;
                }

                node = (parent - 1) / 2;
            }

            // reverse code and store code length
            for (int j = 0; j < code_length / 2; j++) {
                int temp = codebook[i].code[j];
                codebook[i].code[j] = codebook[i].code[code_length - j - 1];
                codebook[i].code[code_length - j - 1] = temp;
            }
            codebook[i].code_length = code_length;

            // reset code length for next symbol
            code_length = 0;
        }
    }

    // write header to output file
    FILE *outfile = fopen(output, "wb");
    fwrite(&root, sizeof(int), 1, outfile);
    fwrite(freq, sizeof(int), 256, outfile);

    // encode input and write to output file
    Bitstream bitstream = {0, 0};
    for (int i = 0; input[i] != '\0'; i++) {
        Code code = codebook[(unsigned char)input[i]];
        for (int j = 0; j < code.code_length; j++) {
            bitstream.bitstream <<= 1;
            bitstream.bitstream |= code.code[j];
            bitstream.num_bits++;
            if (bitstream.num_bits == 32) {
                fwrite(&bitstream.bitstream, sizeof(int), 1, outfile);
                bitstream.bitstream = 0;
                bitstream.num_bits = 0;
            }
        }
    }

    // flush remaining bitstream to output file
    if (bitstream.num_bits > 0) {
        bitstream.bitstream <<= (32 - bitstream.num_bits);
        fwrite(&bitstream.bitstream, sizeof(int), 1, outfile);
    }

    fclose(outfile);
}

void decode(char *input, char *output) {
    // read header from input file
    FILE *infile = fopen(input, "rb");
    int root;
    fread(&root, sizeof(int), 1, infile);
    int freq[256];
    fread(freq, sizeof(int), 256, infile);

    // build Huffman tree
    int num_nodes = 256;
    int *nodes = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = i;
    }
    while (num_nodes > 1) {
        // find lowest frequency nodes
        int min_idx1 = 0;
        int min_idx2 = 1;
        for (int i = 2; i < num_nodes; i++) {
            if (freq[nodes[i]] < freq[nodes[min_idx1]]) {
                min_idx2 = min_idx1;
                min_idx1 = i;
            } else if (freq[nodes[i]] < freq[nodes[min_idx2]]) {
                min_idx2 = i;
            }
        }

        // create new node and update frequency array
        int new_node = num_nodes++;
        nodes[min_idx1] = new_node;
        nodes[min_idx2] = -1;
        freq[new_node] = freq[nodes[min_idx1]] + freq[nodes[min_idx2]];
    }
    int root_node = nodes[0];
    free(nodes);

    // decode input and write to output file
    FILE *outfile = fopen(output, "wb");
    Bitstream bitstream = {0, 0};
    int node = root_node;
    while (1) {
        if (bitstream.num_bits == 0) {
            if (fread(&bitstream.bitstream, sizeof(int), 1, infile) == 0) {
                break;
            }
            bitstream.num_bits = 32;
        }

        if (node < 0) {
            node = root_node;
        }

        if ((bitstream.bitstream & (1 << (bitstream.num_bits - 1))) == 0) {  // go left
            node = 2 * node + 1;
        } else {  // go right
            node = 2 * node + 2;
        }

        bitstream.num_bits--;
        if (node <= 255) {  // reached leaf node
            fwrite(&node, sizeof(char), 1, outfile);
            node = root_node;
        }
    }

    fclose(infile);
    fclose(outfile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <e|d> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "e") == 0) {
        encode(argv[2], argv[3]);
    } else if (strcmp(argv[1], "d") == 0) {
        decode(argv[2], argv[3]);
    } else {
        printf("Usage: %s <e|d> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    return 0;
}