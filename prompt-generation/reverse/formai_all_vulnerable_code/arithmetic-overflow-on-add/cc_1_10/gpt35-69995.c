//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the encryption key */
#define ENCRYPTION_KEY 13

/* Function to encrypt a file */
void encrypt_file(char* input_file_path, char* output_file_path, int key)
{
    /* Open the input file and output file */
    FILE* input_file = fopen(input_file_path, "rb");
    if(input_file == NULL)
    {
        printf("Error: Could not open input file.\n");
        return;
    }
    
    FILE* output_file = fopen(output_file_path, "wb");
    if(output_file == NULL)
    {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return;
    }
    
    /* Read the input file, encrypt each byte, and write to the output file */
    int byte;
    while((byte = fgetc(input_file)) != EOF)
    {
        byte = (byte + key) % 256; /* Perform the encryption */
        fputc(byte, output_file);
    }
    
    /* Close the input file and output file */
    fclose(input_file);
    fclose(output_file);
}

/* Main function to run the program */
int main(int argc, char* argv[])
{
    /* Check if the input arguments are valid */
    if(argc != 3)
    {
        printf("Error: Invalid input arguments. Usage: file_encryptor input_file_path output_file_path\n");
        return 1;
    }
    
    /* Get the input file path and output file path */
    char* input_file_path = argv[1];
    char* output_file_path = argv[2];
    
    /* Encrypt the file */
    encrypt_file(input_file_path, output_file_path, ENCRYPTION_KEY);
    
    /* Display success message */
    printf("File '%s' successfully encrypted and saved as '%s'.\n", input_file_path, output_file_path);
    
    return 0;
}