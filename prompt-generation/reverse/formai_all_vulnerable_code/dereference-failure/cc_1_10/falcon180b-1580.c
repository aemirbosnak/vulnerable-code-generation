//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // Key length in bytes

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);

    char* input_data = (char*)malloc(input_size);
    char* output_data = (char*)malloc(input_size + KEY_SIZE);

    fread(input_data, input_size, 1, input);
    fclose(input);

    int i = 0, j = 0;
    while (i < input_size) {
        output_data[j++] = input_data[i] ^ key[i % KEY_SIZE];
        i++;
    }

    fwrite(output_data, input_size + KEY_SIZE, 1, output);
    fclose(output);

    free(input_data);
    free(output_data);
}

void decrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);

    char* input_data = (char*)malloc(input_size);
    char* output_data = (char*)malloc(input_size - KEY_SIZE);

    fread(input_data, input_size, 1, input);
    fclose(input);

    int i = 0, j = 0;
    while (i < input_size) {
        output_data[j++] = input_data[i] ^ key[i % KEY_SIZE];
        i++;
    }

    fwrite(output_data, input_size - KEY_SIZE, 1, output);
    fclose(output);

    free(input_data);
    free(output_data);
}

int main() {
    char* input_file = "input.txt";
    char* output_file = "output.txt";
    char* key = "mysecretkey123";

    encrypt(input_file, output_file, key);
    decrypt(output_file, "decrypted.txt", key);

    return 0;
}