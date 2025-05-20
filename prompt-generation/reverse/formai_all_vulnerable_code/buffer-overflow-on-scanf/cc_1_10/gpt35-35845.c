//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define BUFFER_SIZE 1024
#define KEY 0x1F // Define the encryption key

int main()
{
    printf("=== C File Encryptor ===\n\n");

    char file_name[MAX_FILE_NAME];

    // Get the file name from the user
    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);

    // Open the input file for reading
    FILE *input_file = fopen(file_name, "rb");

    if (input_file == NULL)
    {
        printf("Error: Can't open the input file!\n");
        return 1;
    }

    // Create the output file with a .enc file extension
    char output_file_name[MAX_FILE_NAME];
    sprintf(output_file_name, "%s.enc", file_name);
    FILE *output_file = fopen(output_file_name, "wb");

    if (output_file == NULL)
    {
        printf("Error: Can't create the output file!\n");
        fclose(input_file);
        return 1;
    }

    // Read the input file in chunks and encrypt each chunk before writing it to the output file
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file)))
    {
        // Encrypt the buffer
        for (int i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= KEY;
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("The file %s has been encrypted and saved as %s.\n", file_name, output_file_name);

    return 0;
}