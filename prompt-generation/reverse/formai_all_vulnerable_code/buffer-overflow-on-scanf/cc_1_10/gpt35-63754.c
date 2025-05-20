//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt data using XOR cipher
void encrypt(char* key, char* input_file_name, char* output_file_name)
{
    // Open input file in read mode
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        return;
    }

    // Open output file in write mode
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        return;
    }

    // Get the length of the key
    int key_length = strlen(key);

    // Variable to hold the current position in the key
    int current_position = 0;

    // Read data from input file and encrypt it using XOR cipher
    int data;
    while ((data = fgetc(input_file)) != EOF) {
        fputc(data ^ key[current_position], output_file);
        current_position = (current_position + 1) % key_length;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);
}

// Function to decrypt data using XOR cipher
void decrypt(char* key, char* input_file_name, char* output_file_name)
{
    // Open input file in read mode
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        return;
    }

    // Open output file in write mode
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        return;
    }

    // Get the length of the key
    int key_length = strlen(key);

    // Variable to hold the current position in the key
    int current_position = 0;

    // Read data from input file and decrypt it using XOR cipher
    int data;
    while ((data = fgetc(input_file)) != EOF) {
        fputc(data ^ key[current_position], output_file);
        current_position = (current_position + 1) % key_length;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);
}

int main()
{
    // Get the key from the user
    char key[256];
    printf("Enter the key: ");
    scanf("%s", key);

    // Get the name of the input file from the user
    char input_file_name[256];
    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    // Get the name of the output file from the user
    char output_file_name[256];
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    // Encrypt the data in the input file using the key and write it to the output file
    encrypt(key, input_file_name, output_file_name);

    // Decrypt the data in the output file using the key and write it to a new file
    char decrypted_file_name[256];
    strcpy(decrypted_file_name, "decrypted_");
    strcat(decrypted_file_name, output_file_name);
    decrypt(key, output_file_name, decrypted_file_name);

    printf("Encryption and decryption completed successfully.\n");

    return 0;
}