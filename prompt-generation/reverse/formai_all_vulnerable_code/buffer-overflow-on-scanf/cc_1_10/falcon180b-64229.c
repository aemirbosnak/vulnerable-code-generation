//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB

void encrypt_file(FILE *input_file, FILE *output_file) {
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    int input_buffer_size;
    int output_buffer_size = 0;
    int key = 13; // Example encryption key

    while ((input_buffer_size = fread(input_buffer, sizeof(char), MAX_FILE_SIZE, input_file)) > 0) {
        for (int i = 0; i < input_buffer_size; i++) {
            output_buffer[output_buffer_size++] = input_buffer[i] ^ key;
        }
        fwrite(output_buffer, sizeof(char), output_buffer_size, output_file);
        output_buffer_size = 0;
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_file_path[100];
    char output_file_path[100];

    printf("Enter input file path: ");
    scanf("%s", input_file_path);
    printf("Enter output file path: ");
    scanf("%s", output_file_path);

    input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    encrypt_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed.\n");

    return 0;
}