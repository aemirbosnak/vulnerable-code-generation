//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_KEY_LEN 32
#define BUFFER_SIZE 1024

void encrypt_file(char *file_name, char *key);
void decrypt_file(char *file_name, char *key);
void display_error_message(char *error_message);

int main()
{
    char file_name[MAX_FILE_NAME];
    char key[MAX_KEY_LEN];

    int choice;

    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Select an option (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    printf("Enter the encryption key (max 32 characters): ");
    scanf("%s", key);

    switch (choice)
    {
    case 1:
        encrypt_file(file_name, key);
        break;

    case 2:
        decrypt_file(file_name, key);
        break;

    default:
        display_error_message("Invalid choice.");
        break;
    }

    return 0;
}

void encrypt_file(char *file_name, char *key)
{
    FILE *file_in, *file_out;

    char buffer[BUFFER_SIZE];

    int read_bytes;

    file_in = fopen(file_name, "rb");

    if (file_in == NULL)
    {
        display_error_message("Unable to open input file.");
        return;
    }

    strcat(file_name, ".enc");

    file_out = fopen(file_name, "wb");

    if (file_out == NULL)
    {
        display_error_message("Unable to create output file.");
        return;
    }

    while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0)
    {
        for (int i = 0; i < read_bytes; i++)
            buffer[i] ^= key[i % strlen(key)];

        fwrite(buffer, 1, read_bytes, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("File encrypted successfully.\n");
}

void decrypt_file(char *file_name, char *key)
{
    FILE *file_in, *file_out;

    char buffer[BUFFER_SIZE];

    int read_bytes;

    file_in = fopen(file_name, "rb");

    if (file_in == NULL)
    {
        display_error_message("Unable to open input file.");
        return;
    }

    strncpy(file_name, file_name, strlen(file_name) - 4);

    file_out = fopen(file_name, "wb");

    if (file_out == NULL)
    {
        display_error_message("Unable to create output file.");
        return;
    }

    while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0)
    {
        for (int i = 0; i < read_bytes; i++)
            buffer[i] ^= key[i % strlen(key)];

        fwrite(buffer, 1, read_bytes, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("File decrypted successfully.\n");
}

void display_error_message(char *error_message)
{
    printf("%s\n", error_message);
}