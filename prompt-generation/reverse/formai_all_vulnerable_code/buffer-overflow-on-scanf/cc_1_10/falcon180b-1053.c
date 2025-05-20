//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    time_t t;
    time(&t);
    srand(t);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    while (fread(buffer, sizeof(char), BLOCK_SIZE, input) > 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    while (fread(buffer, sizeof(char), BLOCK_SIZE, input) > 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[100], output_file[100], key[KEY_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    generate_key(key);

    printf("Do you want to encrypt or decrypt the file? (e/d): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        encrypt(input_file, output_file, key);
        printf("File encrypted successfully\n");
    } else if (choice == 'd' || choice == 'D') {
        decrypt(input_file, output_file, key);
        printf("File decrypted successfully\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}