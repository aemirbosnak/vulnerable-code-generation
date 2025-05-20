//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
/* Ada Lovelace Style C File Encryptor Example Program */

/* 
   This program takes a file, encrypts its contents using a user-provided key, and 
   saves the encrypted data to a new file. The program offers the user an option to 
   decrypt the encrypted file by providing the correct key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BUFFER_SIZE 100

void encrypt(char *input_file_name, char *output_file_name, char key[]);
void decrypt(char *input_file_name, char *output_file_name, char key[], int key_length);
void print_char_array(char *array, int length);

int main()
{
    char input_file_name[MAX_FILE_NAME];
    char output_file_name[MAX_FILE_NAME];
    char key[MAX_BUFFER_SIZE];
    int key_length;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file_name);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    key_length = strlen(key);

    printf("Encrypting file...\n");
    encrypt(input_file_name, output_file_name, key);
    printf("File encrypted successfully!\n");

    printf("Would you like to decrypt the file? (y/n): ");
    char option;
    scanf("%s", &option);

    if (option == 'y')
    {
        char decrypt_file_name[MAX_FILE_NAME];
        printf("Enter the name of the file to decrypt: ");
        scanf("%s", decrypt_file_name);

        char decrypted_file_name[MAX_FILE_NAME];
        printf("Enter the name of the decrypted output file: ");
        scanf("%s", decrypted_file_name);

        printf("Enter the decryption key: ");
        scanf("%s", key);

        printf("Decrypting file...\n");
        decrypt(decrypt_file_name, decrypted_file_name, key, key_length);
        printf("File decrypted successfully!\n");
    }

    return 0;
}

void encrypt(char *input_file_name, char *output_file_name, char key[])
{
    FILE *input_file = fopen(input_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");

    char buffer[MAX_BUFFER_SIZE];
    char encrypted_buffer[MAX_BUFFER_SIZE];
    int key_length = strlen(key);
    int i = 0, j = 0;

    while (fgets(buffer, MAX_BUFFER_SIZE, input_file))
    {
        int buffer_length = strlen(buffer);

        for (i = 0, j = 0; i < buffer_length; i++, j = (j + 1) % key_length)
        {
            encrypted_buffer[i] = buffer[i] ^ key[j];
        }

        fputs(encrypted_buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt(char *input_file_name, char *output_file_name, char key[], int key_length)
{
    FILE *input_file = fopen(input_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");

    char buffer[MAX_BUFFER_SIZE];
    char decrypted_buffer[MAX_BUFFER_SIZE];
    int i = 0, j = 0;

    while (fgets(buffer, MAX_BUFFER_SIZE, input_file))
    {
        int buffer_length = strlen(buffer);

        for (i = 0, j = 0; i < buffer_length; i++, j = (j + 1) % key_length)
        {
            decrypted_buffer[i] = buffer[i] ^ key[j];
        }

        fputs(decrypted_buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void print_char_array(char *array, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}