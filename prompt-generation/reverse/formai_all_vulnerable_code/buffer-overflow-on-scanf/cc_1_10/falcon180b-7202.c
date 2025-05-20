//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey"

void encrypt(char* file_name, char* output_file_name) {
    FILE* input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(2);
    }

    char buffer[1024];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, sizeof(char), sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(buffer, sizeof(char), buffer_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt(char* file_name, char* output_file_name) {
    FILE* input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(2);
    }

    char buffer[1024];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, sizeof(char), sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(buffer, sizeof(char), buffer_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_file_name[100];
    char output_file_name[100];

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file_name);

    strcat(input_file_name, ".enc");
    strcpy(output_file_name, input_file_name);
    strcat(output_file_name, ".dec");

    encrypt(input_file_name, output_file_name);

    printf("File encrypted successfully!\n");

    return 0;
}