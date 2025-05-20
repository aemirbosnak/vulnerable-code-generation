//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    FILE *input_file, *encrypted_file;
    char input_filename[100], encrypted_filename[100], encryption_key;
    unsigned char buffer[BUFFER_SIZE];

    printf("Enter name of file to be encrypted: ");
    scanf("%s", input_filename);

    printf("Enter encryption key: ");
    scanf("%c", &encryption_key); // Read newline character from the previous scanf

    printf("Enter name of encrypted file: ");
    scanf("%s", encrypted_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Error opening input file");
        exit(1);
    }

    encrypted_file = fopen(encrypted_filename, "wb");
    if (encrypted_file == NULL)
    {
        printf("Error opening encrypted file");
        exit(1);
    }

    while (!feof(input_file)) // Read until end of file
    {
        int bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file);
        for (int i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= encryption_key; // XOR each byte with encryption key
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, encrypted_file);
    }

    fclose(input_file);
    fclose(encrypted_file);

    printf("File encrypted successfully!");

    return 0;
}