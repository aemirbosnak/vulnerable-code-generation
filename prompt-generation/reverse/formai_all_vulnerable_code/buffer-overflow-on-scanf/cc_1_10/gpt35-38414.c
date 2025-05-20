//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    printf("Welcome to the File Encryptor program!\n\n");
    printf("I hope you're ready for some top-secret encoding.\n\n");

    char file_to_encrypt[50];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", file_to_encrypt);

    // Open the file to be encrypted
    FILE *file_pointer;
    file_pointer = fopen(file_to_encrypt, "r");

    if (file_pointer == NULL)
    {
        printf("\nSorry! The file does not exist. Please try again.\n\n");
        printf("Enter the name of the file you want to encrypt: ");
        scanf("%s", file_to_encrypt);
        file_pointer = fopen(file_to_encrypt, "r");
    }

    int shift_value;
    printf("Enter a shift value for the encryption algorithm: ");
    scanf("%d", &shift_value);

    // Create a new file to store the encrypted data
    char encrypted_file_name[50];
    strncpy(encrypted_file_name, file_to_encrypt, strlen(file_to_encrypt) - 4);
    strcat(encrypted_file_name, "_encrypted.txt");

    FILE *encrypted_file_pointer;
    encrypted_file_pointer = fopen(encrypted_file_name, "w");

    // Read the file, encrypt the data, and write it to the new file
    char current_character;
    while ((current_character = getc(file_pointer)) != EOF)
    {
        if (current_character == '\n')
        {
            fputc('\n', encrypted_file_pointer);
        }
        else
        {
            current_character += shift_value;
            fputc(current_character, encrypted_file_pointer);
        }
    }

    // Close the files
    fclose(file_pointer);
    fclose(encrypted_file_pointer);

    printf("\n\nHooray! Your file has been successfully encrypted and saved as '%s'.\n\n", encrypted_file_name);

    return 0;
}