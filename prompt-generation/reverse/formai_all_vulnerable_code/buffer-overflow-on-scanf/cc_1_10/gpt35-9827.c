//FormAI DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void encrypt(char *file_name, char *key);

int main(int argc, char *argv[]) {
    char file_name[MAX_FILE_NAME_LENGTH], key[MAX_BUFFER_SIZE];

    printf("Enter name of file to encrypt: ");
    scanf("%s", file_name);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(file_name, key);

    return 0;
}

void encrypt(char *file_name, char *key) {
    FILE *fp_in, *fp_out;
    char buffer[MAX_BUFFER_SIZE];
    int i, j, len_key, len_message;

    len_key = strlen(key);
    fp_in = fopen(file_name, "rb");

    // Handle file open errors
    if (fp_in == NULL) {
        printf("Error opening file %s.\n", file_name);
        exit(1);
    }

    // Create encrypted file name
    char encrypted_file_name[MAX_FILE_NAME_LENGTH];
    strncpy(encrypted_file_name, file_name, MAX_FILE_NAME_LENGTH - 4);
    strcat(encrypted_file_name, "_enc");

    // Open encrypted file for writing
    fp_out = fopen(encrypted_file_name, "wb");

    // Handle file open errors
    if (fp_out == NULL) {
        printf("Error creating encrypted file %s.\n", encrypted_file_name);
        exit(1);
    }

    while (!feof(fp_in)) {
        // Read the buffer from input file
        int read_len = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fp_in);
        len_message = read_len;

        // Encrypt the buffer
        for (i = 0, j = 0; i < len_message; ++i, ++j) {
            if (j >= len_key) {
                j = 0;
            }

            buffer[i] = buffer[i] ^ key[j];
        }

        // Write the buffer to output file
        fwrite(buffer, sizeof(char), len_message, fp_out);
    }

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    printf("Encryption completed. Encrypted file saved as %s.\n", encrypted_file_name);
}