//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Define the length of the run-length encoding block
#define RUN_LENGTH_BLOCK_LENGTH 10

// Define the maximum number of characters in the input
#define MAX_INPUT_SIZE 100000

// Define the number of possible characters that can be compressed
#define NUM_CHARS 256

// Define the maximum length of the Huffman code for each character
#define MAX_CODE_LENGTH 50

// Define a structure to hold a single run-length encoding block
typedef struct RunLengthBlock {
    char character;
    int count;
} RunLengthBlock;

// Define a structure to hold a single Huffman code
typedef struct HuffmanCode {
    char character;
    char code[MAX_CODE_LENGTH];
} HuffmanCode;

// Function to generate a run-length encoding of the input string
void generate_run_length_encoding(char *input, RunLengthBlock *output, int *output_length) {
    int input_length = strlen(input);
    int i, j = 0;
    for (i = 0; i < input_length; i++) {
        if (i % RUN_LENGTH_BLOCK_LENGTH == 0) {
            output[j].character = input[i];
            output[j].count = 1;
            j++;
        } else {
            output[j-1].count++;
        }
    }
    *output_length = j;
}

// Function to generate a Huffman code for each character in the input
void generate_huffman_codes(RunLengthBlock *input, int input_length, HuffmanCode *output, int *output_length) {
    // Create a frequency table for each character
    int frequency[NUM_CHARS];
    memset(frequency, 0, NUM_CHARS*sizeof(int));
    int i;
    for (i = 0; i < input_length; i++) {
        frequency[input[i].character]++;
    }

    // Create a Huffman tree based on the frequency table
    int parent[NUM_CHARS];
    memset(parent, -1, NUM_CHARS*sizeof(int));
    int num_nodes = NUM_CHARS;
    while (num_nodes > 1) {
        int min1 = MAX_INPUT_SIZE;
        int min2 = MAX_INPUT_SIZE;
        int min1_index = -1;
        int min2_index = -1;
        for (i = 0; i < NUM_CHARS; i++) {
            if (frequency[i] > 0 && parent[i] == -1) {
                if (frequency[i] < min1) {
                    min2 = min1;
                    min2_index = min1_index;
                    min1 = frequency[i];
                    min1_index = i;
                } else if (frequency[i] < min2) {
                    min2 = frequency[i];
                    min2_index = i;
                }
            }
        }
        parent[min1_index] = num_nodes;
        parent[min2_index] = num_nodes;
        frequency[num_nodes] = frequency[min1_index] + frequency[min2_index];
        num_nodes++;
    }

    // Generate Huffman codes for each character
    char code[MAX_CODE_LENGTH];
    int code_length = 0;
    for (i = 0; i < NUM_CHARS; i++) {
        output[i].character = (char)i;
        if (frequency[i] > 0) {
            int j = i;
            while (parent[j] != -1) {
                if (j == parent[j]) {
                    code[code_length] = '0';
                } else {
                    if (j == parent[parent[j]]) {
                        code[code_length] = '0';
                    } else {
                        code[code_length] = '1';
                    }
                }
                j = parent[j];
                code_length++;
            }
            code_length--;
            int k;
            for (k = 0; k < code_length; k++) {
                output[i].code[k] = code[code_length-k-1];
            }
            output[i].code[k] = '\0';
            code_length = 0;
        }
    }

    *output_length = NUM_CHARS;
}

int main() {
    // Read in the input from a file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    char input[MAX_INPUT_SIZE];
    int input_length = fread(input, sizeof(char), MAX_INPUT_SIZE, input_file);
    input[input_length] = '\0';
    fclose(input_file);

    // Generate a run-length encoding of the input string
    RunLengthBlock run_length_output[MAX_INPUT_SIZE/RUN_LENGTH_BLOCK_LENGTH];
    int run_length_output_length;
    generate_run_length_encoding(input, run_length_output, &run_length_output_length);

    // Generate a Huffman code for each character in the input
    HuffmanCode huffman_output[NUM_CHARS];
    int huffman_output_length;
    generate_huffman_codes(run_length_output, run_length_output_length, huffman_output, &huffman_output_length);

    // Write the compressed output to a file
    FILE *output_file = fopen("output.bin", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }
    fwrite(&run_length_output_length, sizeof(int), 1, output_file);
    fwrite(run_length_output, sizeof(RunLengthBlock), run_length_output_length, output_file);
    fwrite(&huffman_output_length, sizeof(int), 1, output_file);
    fwrite(huffman_output, sizeof(HuffmanCode), huffman_output_length, output_file);
    fclose(output_file);

    return 0;
}