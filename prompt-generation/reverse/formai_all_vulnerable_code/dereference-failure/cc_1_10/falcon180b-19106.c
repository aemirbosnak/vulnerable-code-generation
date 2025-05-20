//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

// XOR encryption function
void xor_encrypt(char* input, int input_size, char* output) {
    char key[strlen(KEY)];
    strcpy(key, KEY);

    int j = 0;
    for (int i = 0; i < input_size; i++) {
        if (i % BLOCK_SIZE == 0) {
            strcpy(key, KEY);
        }
        output[i] = input[i] ^ key[j];
        j++;
        if (j == strlen(KEY)) {
            j = 0;
        }
    }
}

// XOR decryption function
void xor_decrypt(char* input, int input_size, char* output) {
    char key[strlen(KEY)];
    strcpy(key, KEY);

    int j = 0;
    for (int i = 0; i < input_size; i++) {
        output[i] = input[i] ^ key[j];
        j++;
        if (j == strlen(KEY)) {
            j = 0;
        }
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char input_buffer[1024];
    char output_buffer[1024];

    int input_size;
    while ((input_size = fread(input_buffer, 1, sizeof(input_buffer), input_file)) > 0) {
        xor_encrypt(input_buffer, input_size, output_buffer);
        fwrite(output_buffer, 1, input_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encryption complete\n");

    return 0;
}