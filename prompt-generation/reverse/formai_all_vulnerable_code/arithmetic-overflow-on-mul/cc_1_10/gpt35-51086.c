//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
// Implementation of a simple compression algorithm using Run-Length Encoding (RLE)
// Decentralized style using multithreading to compress and decompress data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char* input;
    int input_size;
    char* output;
    int output_size;
} data_t;

void* compress(void* arg) {
    data_t* data = (data_t*)arg;
    int i = 0;
    int count = 1;
    char current = data->input[0];
    for (i = 1; i < data->input_size; i++) {
        if (data->input[i] != current) {
            data->output[data->output_size++] = current;
            data->output[data->output_size++] = count;
            current = data->input[i];
            count = 1;
        } else {
            count++;
        }
    }
    data->output[data->output_size++] = current;
    data->output[data->output_size++] = count;
    return NULL;
}

void* decompress(void* arg) {
    data_t* data = (data_t*)arg;
    int i = 0;
    while (i < data->input_size) {
        char current = data->input[i++];
        int count = data->input[i++];
        int j = 0;
        for (j = 0; j < count; j++) {
            data->output[data->output_size++] = current;
        }
    }
    return NULL;
}

int main() {
    // Read input from file
    FILE* file = fopen("input.txt", "rb");
    if (file == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int input_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* input = (char*)malloc(input_size);
    fread(input, input_size, 1, file);
    fclose(file);

    // Compress the data
    char* compressed = (char*)malloc(2 * input_size);
    int compressed_size = 0;
    pthread_t compress_thread;
    data_t compress_data = {input, input_size, compressed, 0};
    pthread_create(&compress_thread, NULL, compress, &compress_data);
    pthread_join(compress_thread, NULL);
    compressed_size = compress_data.output_size;

    // Write compressed data to file
    file = fopen("compressed.txt", "wb");
    if (file == NULL) {
        printf("Failed to open compressed file\n");
        free(input);
        free(compressed);
        return 1;
    }
    fwrite(compressed, compressed_size, 1, file);
    fclose(file);

    // Read compressed data from file
    file = fopen("compressed.txt", "rb");
    if (file == NULL) {
        printf("Failed to open compressed file\n");
        free(input);
        free(compressed);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int compressed_size2 = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* compressed2 = (char*)malloc(compressed_size2);
    fread(compressed2, compressed_size2, 1, file);
    fclose(file);

    // Decompress the data
    char* output = (char*)malloc(input_size);
    int output_size = 0;
    pthread_t decompress_thread;
    data_t decompress_data = {compressed2, compressed_size2, output, 0};
    pthread_create(&decompress_thread, NULL, decompress, &decompress_data);
    pthread_join(decompress_thread, NULL);
    output_size = decompress_data.output_size;

    // Write decompressed data to file
    file = fopen("output.txt", "wb");
    if (file == NULL) {
        printf("Failed to open output file\n");
        free(input);
        free(compressed);
        free(compressed2);
        free(output);
        return 1;
    }
    fwrite(output, output_size, 1, file);
    fclose(file);

    // Cleanup
    free(input);
    free(compressed);
    free(compressed2);
    free(output);
    return 0;
}