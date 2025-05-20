//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt(FILE *fp, char *key)
{
    char ch;
    int i, j, k, len = strlen(key);

    // Reading the file character by character
    while ((ch = fgetc(fp))!= EOF)
    {
        if (isalpha(ch))
        {
            // Encrypting the character using the key
            ch = (ch + key[i % len] - 'a' + 26) % 26 + 'a';
            fputc(ch, fp);
        }
        else
        {
            // Writing non-alphabetic characters as it is
            fputc(ch, fp);
        }
        i++;
    }
}

// Function to decrypt the file
void decrypt(FILE *fp, char *key)
{
    char ch;
    int i, j, k, len = strlen(key);

    // Reading the file character by character
    while ((ch = fgetc(fp))!= EOF)
    {
        if (isalpha(ch))
        {
            // Decrypting the character using the key
            ch = (ch - key[i % len] + 26) % 26 + 'a';
            fputc(ch, fp);
        }
        else
        {
            // Writing non-alphabetic characters as it is
            fputc(ch, fp);
        }
        i++;
    }
}

int main()
{
    char filename[50], key[50], choice;
    FILE *fp;

    // Taking input from the user
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Opening the file in read mode
    fp = fopen(filename, "r");

    // Checking if the file exists
    if (fp == NULL)
    {
        printf("File not found!");
        exit(0);
    }

    // Taking input from the user for encryption or decryption
    printf("Enter 1 for encryption and 2 for decryption: ");
    scanf("%c", &choice);

    // Encrypting or decrypting the file based on user choice
    if (choice == '1')
    {
        encrypt(fp, key);
        printf("File encrypted successfully!");
    }
    else if (choice == '2')
    {
        decrypt(fp, key);
        printf("File decrypted successfully!");
    }
    else
    {
        printf("Invalid choice!");
    }

    // Closing the file
    fclose(fp);

    return 0;
}