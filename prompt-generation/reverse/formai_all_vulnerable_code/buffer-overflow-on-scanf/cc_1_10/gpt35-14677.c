//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey" // Define a secret key to encrypt and decrypt the file

void encrypt_file(char *filename);
void decrypt_file(char *filename);

int main()
{
    char filename[100];
    int choice;

    printf("Please enter the filename to encrypt or decrypt: ");
    scanf("%s", filename);

    printf("Please choose an option: \n");
    printf("1. Encrypt the file\n");
    printf("2. Decrypt the file\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encrypt_file(filename);
            break;
        case 2:
            decrypt_file(filename);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}

// Function to encrypt the file
void encrypt_file(char *filename)
{
    FILE *fp;
    char ch;
    int i = 0;

    // Open the file in read mode
    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening the file");
        return;
    }

    // Create a new file for writing
    FILE *fpOut = fopen("encrypted_file.txt", "w");

    // Iterate through the file character by character
    while((ch = fgetc(fp)) != EOF)
    {
        // XOR each character with the corresponding character in the key
        ch = ch ^ KEY[i];

        // Write the encrypted character to the new file
        fputc(ch, fpOut);

        // Move to the next character in the key
        i++;
        if(KEY[i] == '\0')
            i = 0;
    }

    printf("File encrypted successfully. Encrypted file saved as encrypted_file.txt\n");

    // Close the files
    fclose(fp);
    fclose(fpOut);
}

// Function to decrypt the file
void decrypt_file(char *filename)
{
    FILE *fp;
    char ch;
    int i = 0;

    // Open the file in read mode
    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening the file");
        return;
    }

    // Create a new file for writing
    FILE *fpOut = fopen("decrypted_file.txt", "w");

    // Iterate through the file character by character
    while((ch = fgetc(fp)) != EOF)
    {
        // XOR each character with the corresponding character in the key
        ch = ch ^ KEY[i];

        // Write the decrypted character to the new file
        fputc(ch, fpOut);

        // Move to the next character in the key
        i++;
        if(KEY[i] == '\0')
            i = 0;
    }

    printf("File decrypted successfully. Decrypted file saved as decrypted_file.txt\n");

    // Close the files
    fclose(fp);
    fclose(fpOut);
}