//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 100000000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;
} encryption_mode;

encryption_mode* create_encryption_mode(char* key, int key_size, int mode) {
    encryption_mode* result = malloc(sizeof(encryption_mode));
    strncpy(result->key, key, MAX_KEY_SIZE);
    result->key_size = key_size;
    result->mode = mode;
    return result;
}

void encrypt_file(FILE* input_file, FILE* output_file, encryption_mode* mode) {
    char buffer[MAX_FILE_SIZE];
    int buffer_size = fread(buffer, 1, MAX_FILE_SIZE, input_file);
    int i = 0;
    while (i < buffer_size) {
        char c = buffer[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + ((c - 'A' + mode->key_size) % 26);
            } else {
                c = 'a' + ((c - 'a' + mode->key_size) % 26);
            }
        }
        fwrite(&c, 1, 1, output_file);
        i++;
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;

    printf("Enter encryption key: ");
    scanf("%s", key);
    key_size = strlen(key);

    printf("Enter encryption mode (0 for Caesar cipher, 1 for Vigenere cipher): ");
    scanf("%d", &mode);

    encryption_mode* mode_ptr = create_encryption_mode(key, key_size, mode);

    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: output file could not be created\n");
        exit(1);
    }

    encrypt_file(input_file, output_file, mode_ptr);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully\n");

    return 0;
}