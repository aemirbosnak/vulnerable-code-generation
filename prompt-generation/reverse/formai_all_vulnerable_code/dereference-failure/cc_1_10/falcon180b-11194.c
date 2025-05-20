//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000
#define KEY_SIZE 8

void encrypt(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int i, j, key_index;

    for (i = 0; i < MAX_FILE_SIZE; i++) {
        buffer[i] = fgetc(input_file);
    }

    for (i = 0; i < MAX_FILE_SIZE; i++) {
        key_index = i % KEY_SIZE;
        j = (buffer[i] + key[key_index]) % 256;
        fputc(j, output_file);
    }
}

void decrypt(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int i, j, key_index;

    for (i = 0; i < MAX_FILE_SIZE; i++) {
        buffer[i] = fgetc(input_file);
    }

    for (i = 0; i < MAX_FILE_SIZE; i++) {
        key_index = i % KEY_SIZE;
        j = (buffer[i] - key[key_index]) % 256;
        if (j < 0) {
            j += 256;
        }
        fputc(j, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char key[KEY_SIZE];
    char input_file_name[100], output_file_name[100];

    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    printf("Enter the encryption key (8 characters): ");
    scanf("%s", key);

    input_file = fopen(input_file_name, "rb");
    output_file = fopen(output_file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    encrypt(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully!\n");

    return 0;
}