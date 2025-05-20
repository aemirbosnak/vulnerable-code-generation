//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
/*
 * Claude Shannon's File Encryptor
 *
 * This program takes in a file and encrypts it using a simple Caesar cipher.
 * The cipher is based on the idea of shifting each letter in the file by a fixed amount.
 *
 * Usage: ./file_encryptor <file_to_encrypt> <key>
 *
 * Example: ./file_encryptor secret_message.txt 5
 */

#include <stdio.h>
#include <string.h>

// The Caesar cipher function
char* caesar_cipher(char* input, int key) {
    char* output = malloc(strlen(input) + 1);
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key) % 26 + 'A';
        }
        output[i] = c;
    }
    return output;
}

// The main function
int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: ./file_encryptor <file_to_encrypt> <key>\n");
        return 1;
    }

    // Get the file name and key
    char* file_name = argv[1];
    int key = atoi(argv[2]);

    // Open the file
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    // Read the file contents
    char* contents = malloc(1000000);
    fread(contents, 1, 1000000, file);
    fclose(file);

    // Encrypt the file contents
    char* encrypted = caesar_cipher(contents, key);

    // Write the encrypted contents to a new file
    char* encrypted_file_name = malloc(strlen(file_name) + 1);
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".encrypted");
    FILE* encrypted_file = fopen(encrypted_file_name, "w");
    if (encrypted_file == NULL) {
        printf("Error: Could not open file %s\n", encrypted_file_name);
        return 1;
    }
    fwrite(encrypted, 1, strlen(encrypted), encrypted_file);
    fclose(encrypted_file);

    // Free memory
    free(contents);
    free(encrypted);
    free(encrypted_file_name);

    return 0;
}