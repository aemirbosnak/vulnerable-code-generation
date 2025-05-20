//FormAI DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024
#define ENCRYPTION_KEY 0x0F

void encryptFile(FILE* input_file, FILE* output_file) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (size_t index = 0; index < bytes_read; ++index) {
            buffer[index] ^= ENCRYPTION_KEY;
        }

        fwrite(buffer, 1, bytes_read, output_file);
    }
}

int main() {
    char input_file_name[MAX_FILE_NAME_LENGTH], output_file_name[MAX_FILE_NAME_LENGTH];
    FILE* input_file;
    FILE* output_file;

    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    input_file = fopen(input_file_name, "rb");

    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    output_file = fopen(output_file_name, "wb");

    if (output_file == NULL) {
        fclose(input_file);
        printf("Error: Could not open output file\n");
        return 1;
    }

    encryptFile(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully");
    return 0;
}