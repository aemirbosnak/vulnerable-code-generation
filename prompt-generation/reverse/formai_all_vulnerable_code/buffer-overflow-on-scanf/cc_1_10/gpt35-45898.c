//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 50
#define MAX_COMPRESSED_SIZE 1000

// Function to compress a given string using RLE algorithm
char* compress(char* data) {
    int length = strlen(data);
    int count = 1;
    char* compressed = (char*)malloc(MAX_COMPRESSED_SIZE * sizeof(char));
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == data[i+1]) {
            count++;
        }
        else {
            compressed[index++] = data[i];
            compressed[index++] = count + '0';
            count = 1;
        }
    }
    compressed[index] = '\0';
    return compressed;
}

// Function to decompress a given compressed string using RLE algorithm
char* decompress(char* compressed) {
    int length = strlen(compressed);
    char* decompressed = (char*)malloc(MAX_COMPRESSED_SIZE * sizeof(char));
    int index = 0;
    for (int i = 0; i < length; i += 2) {
        int count = compressed[i+1] - '0';
        for (int j = 0; j < count; j++) {
            decompressed[index++] = compressed[i];
        }
    }
    decompressed[index] = '\0';
    return decompressed;
}

int main() {
    char input_file_name[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    FILE* input_file = fopen(input_file_name, "r");
    if (!input_file) {
        printf("Couldn't open file %s\n", input_file_name);
        return 1;
    }
    char* data = (char*)malloc(MAX_COMPRESSED_SIZE * sizeof(char));
    char buffer[10];
    while (!feof(input_file)) {
        fgets(buffer, 10, input_file);
        strcat(data, buffer);
    }
    fclose(input_file);
    char* compressed_data = compress(data);
    char output_file_name[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);
    FILE* output_file = fopen(output_file_name, "w");
    if (!output_file) {
        printf("Couldn't create file %s\n", output_file_name);
        return 1;
    }
    fputs(compressed_data, output_file);
    fclose(output_file);
    printf("Successfully compressed and saved to file %s\n", output_file_name);
    char* decompressed_data = decompress(compressed_data);
    printf("Original data: %s\n", data);
    printf("Decompressed data: %s\n", decompressed_data);
    free(data);
    free(compressed_data);
    free(decompressed_data);
    return 0;
}