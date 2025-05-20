//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "your_secret_key"

// XOR encryption function
void encrypt(char *plaintext, char *ciphertext) {
    int keylen = strlen(KEY);
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
    }
}

// XOR decryption function
void decrypt(char *ciphertext, char *plaintext) {
    int keylen = strlen(KEY);
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
    }
}

int main() {
    // Get the input file name
    char input_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);

    // Get the output file name
    char output_file[100];
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Read the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    fseek(input, 0, SEEK_END);
    long input_file_size = ftell(input);
    rewind(input);
    char *input_buffer = malloc(input_file_size);
    if (input_buffer == NULL) {
        perror("Error allocating memory for input buffer");
        fclose(input);
        return EXIT_FAILURE;
    }
    fread(input_buffer, input_file_size, 1, input);
    fclose(input);

    // Encrypt the input buffer
    char *ciphertext = malloc(input_file_size);
    if (ciphertext == NULL) {
        perror("Error allocating memory for ciphertext buffer");
        free(input_buffer);
        return EXIT_FAILURE;
    }
    encrypt(input_buffer, ciphertext);

    // Write the ciphertext to the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        free(input_buffer);
        free(ciphertext);
        return EXIT_FAILURE;
    }
    fwrite(ciphertext, input_file_size, 1, output);
    fclose(output);

    // Decrypt the ciphertext
    char *decrypted_buffer = malloc(input_file_size);
    if (decrypted_buffer == NULL) {
        perror("Error allocating memory for decrypted buffer");
        free(input_buffer);
        free(ciphertext);
        return EXIT_FAILURE;
    }
    decrypt(ciphertext, decrypted_buffer);

    // Verify the decrypted text
    if (strcmp(input_buffer, decrypted_buffer) != 0) {
        printf("Error: Decrypted text does not match original text\n");
        free(input_buffer);
        free(ciphertext);
        free(decrypted_buffer);
        return EXIT_FAILURE;
    }

    printf("File encrypted and decrypted successfully\n");

    // Free the allocated memory
    free(input_buffer);
    free(ciphertext);
    free(decrypted_buffer);

    return EXIT_SUCCESS;
}