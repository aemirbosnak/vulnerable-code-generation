//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "YOUR_ENCRYPTION_KEY"

// Function to encrypt a file
int encrypt_file(char *input_file, char *output_file)
{
    // Open the input file
    FILE *fin = fopen(input_file, "rb");
    if (fin == NULL)
    {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *fout = fopen(output_file, "wb");
    if (fout == NULL)
    {
        perror("Error opening output file");
        fclose(fin);
        return -1;
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long file_size = ftell(fin);
    rewind(fin);

    // Create a buffer to store the encrypted data
    char *buffer = malloc(file_size);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(fin);
        fclose(fout);
        return -1;
    }

    // Read the file into the buffer
    fread(buffer, 1, file_size, fin);

    // Encrypt the buffer
    for (long i = 0; i < file_size; i++)
    {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted data to the output file
    fwrite(buffer, 1, file_size, fout);

    // Free the buffer
    free(buffer);

    // Close the files
    fclose(fin);
    fclose(fout);

    return 0;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file)
{
    // Open the input file
    FILE *fin = fopen(input_file, "rb");
    if (fin == NULL)
    {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *fout = fopen(output_file, "wb");
    if (fout == NULL)
    {
        perror("Error opening output file");
        fclose(fin);
        return -1;
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long file_size = ftell(fin);
    rewind(fin);

    // Create a buffer to store the decrypted data
    char *buffer = malloc(file_size);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(fin);
        fclose(fout);
        return -1;
    }

    // Read the file into the buffer
    fread(buffer, 1, file_size, fin);

    // Decrypt the buffer
    for (long i = 0; i < file_size; i++)
    {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted data to the output file
    fwrite(buffer, 1, file_size, fout);

    // Free the buffer
    free(buffer);

    // Close the files
    fclose(fin);
    fclose(fout);

    return 0;
}

// Main function
int main()
{
    // Get the input file name
    char input_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);

    // Get the output file name
    char output_file[100];
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Get the encryption/decryption option
    int option;
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &option);

    // Encrypt or decrypt the file
    int status;
    if (option == 1)
    {
        status = encrypt_file(input_file, output_file);
        if (status == 0)
        {
            printf("File encrypted successfully!\n");
        }
        else
        {
            printf("Error encrypting file!\n");
        }
    }
    else if (option == 2)
    {
        status = decrypt_file(input_file, output_file);
        if (status == 0)
        {
            printf("File decrypted successfully!\n");
        }
        else
        {
            printf("Error decrypting file!\n");
        }
    }
    else
    {
        printf("Invalid option!\n");
    }

    return 0;
}