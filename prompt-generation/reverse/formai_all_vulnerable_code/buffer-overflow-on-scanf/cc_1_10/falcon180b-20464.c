//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void generate_key(unsigned char key[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *data, unsigned char key[KEY_SIZE]) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char *data, unsigned char key[KEY_SIZE]) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    char input_file[50];
    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);

    unsigned char input_data[input_size];
    fread(input_data, 1, input_size, input);
    fclose(input);

    encrypt(input_data, key);

    char output_file[50];
    printf("Enter output file name: ");
    scanf("%s", output_file);

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fwrite(input_data, 1, input_size, output);
    fclose(output);

    printf("Encryption completed.\n");

    return 0;
}