//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

void encrypt(char* key, char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (!input ||!output) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int key_index = 0;

    while (fread(buffer, sizeof(char), MAX_FILE_SIZE, input) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= key[key_index % strlen(key)];
            key_index++;
        }

        fwrite(buffer, sizeof(char), strlen(buffer), output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char* key, char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (!input ||!output) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int key_index = 0;

    while (fread(buffer, sizeof(char), MAX_FILE_SIZE, input) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= key[key_index % strlen(key)];
            key_index++;
        }

        fwrite(buffer, sizeof(char), strlen(buffer), output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char key[MAX_KEY_SIZE];
    printf("Enter encryption key: ");
    scanf("%s", key);

    char input_file[100];
    printf("Enter input file name: ");
    scanf("%s", input_file);

    char output_file[100];
    printf("Enter output file name: ");
    scanf("%s", output_file);

    if (strcmp(input_file, output_file) == 0) {
        printf("Error: Input and output files cannot be the same.\n");
        return 1;
    }

    printf("Encrypting file...\n");
    encrypt(key, input_file, output_file);

    printf("Decrypting file...\n");
    decrypt(key, output_file, input_file);

    printf("Done!\n");
    return 0;
}