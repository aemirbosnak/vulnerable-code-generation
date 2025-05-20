//FormAI DATASET v1.0 Category: File Encyptor ; Style: satisfied
// Unique C File Encryptor example program
// This program takes a file and encrypts it using a user-provided key

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function that encrypts data using a user-provided key
void encrypt(char* input_file, char* output_file, char* key) {
    FILE *fp_input, *fp_output;
    char buffer[BUFFER_SIZE];
    int key_length = strlen(key);
    int i, j, k = 0;

    // Open input file for reading
    fp_input = fopen(input_file, "rb");
    if(fp_input == NULL) {
        printf("Error: Unable to open input file\n");
        return;
    }

    // Open output file for writing
    fp_output = fopen(output_file, "wb");
    if(fp_output == NULL) {
        printf("Error: Unable to open output file\n");
        return;
    }

    // Iterate over bytes in input file, encrypting each one with the key
    while(fread(buffer, 1, BUFFER_SIZE, fp_input)) {
        for(i=0; i<BUFFER_SIZE; i++) {
            buffer[i] = buffer[i] ^ key[k];
            k++;
            if(k == key_length) {
                k = 0;
            }
        }
        fwrite(buffer, 1, BUFFER_SIZE, fp_output);
    }

    // Close files
    fclose(fp_input);
    fclose(fp_output);

    printf("Encryption complete!\n");
}

// Function that prompts the user for input file, output file, and key, and calls the encrypt function
void prompt_user() {
    char input_file[100], output_file[100], key[100];

    printf("Enter name of input file to encrypt: ");
    scanf("%s", input_file);

    printf("Enter name of output file: ");
    scanf("%s", output_file);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(input_file, output_file, key);
}

// Main function that calls the prompt_user function
int main() {
    prompt_user();
    return 0;
}