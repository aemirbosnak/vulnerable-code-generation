//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main(int argc, char** argv) {
    FILE* input_file = NULL;
    FILE* output_file = NULL;
    char input_filename[MAX_LEN];
    char output_filename[MAX_LEN];
    char encryption_key[MAX_LEN];
    unsigned long file_size = 0;
    unsigned long bytes_remaining = 0;
    unsigned long bytes_to_read = 0;
    char* file_buffer = NULL;
    char* file_ptr = NULL;
    int key_index = 0;
    int i, j;

    // Read the input file name from the user
    printf("Enter the name of the file to encrypt: ");
    fgets(input_filename, MAX_LEN, stdin);
    input_filename[strlen(input_filename) - 1] = '\0'; // remove newline character

    // Attempt to open the input file
    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Failed to open %s\n", input_filename);
        return 1;
    }

    // Read the output file name from the user
    printf("Enter the name of the output file: ");
    fgets(output_filename, MAX_LEN, stdin);
    output_filename[strlen(output_filename) - 1] = '\0'; // remove newline character

    // Attempt to open the output file
    output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Failed to open %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Read the encryption key from the user
    printf("Enter the encryption key: ");
    fgets(encryption_key, MAX_LEN, stdin);
    encryption_key[strlen(encryption_key) - 1] = '\0'; // remove newline character

    // Get the file size
    fseek(input_file, 0L, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // Allocate memory for the file buffer
    file_buffer = (char*)malloc(file_size);
    if (!file_buffer) {
        printf("Failed to allocate memory for the file buffer\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    // Read the file into the buffer
    bytes_remaining = file_size;
    file_ptr = file_buffer;
    while (bytes_remaining > 0) {
        bytes_to_read = (bytes_remaining < MAX_LEN) ? bytes_remaining : MAX_LEN;
        fread(file_ptr, 1, bytes_to_read, input_file);
        file_ptr += bytes_to_read;
        bytes_remaining -= bytes_to_read;
    }

    // Encrypt the file using the encryption key
    key_index = 0;
    file_ptr = file_buffer;
    for (i = 0; i < file_size; i++) {
        *file_ptr ^= encryption_key[key_index];
        file_ptr++;
        key_index = (key_index + 1) % strlen(encryption_key);
    }

    // Write the encrypted file to disk
    fwrite(file_buffer, 1, file_size, output_file);

    // Free the file buffer memory and close the files
    free(file_buffer);
    fclose(input_file);
    fclose(output_file);

    // Print a success message
    printf("Encryption successful!\n");

    return 0;
}