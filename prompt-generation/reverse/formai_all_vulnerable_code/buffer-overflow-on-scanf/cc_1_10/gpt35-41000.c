//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void encrypt(char plainText[], char key[]);
void decrypt(char cipherText[], char key[]);

int main()
{
    char plainText[MAX_SIZE];
    char cipherText[MAX_SIZE];
    char choice;
    char key[MAX_SIZE];

    printf("Enter a string to encrypt: ");
    fgets(plainText, MAX_SIZE, stdin);

    printf("\nEnter a key: ");
    fgets(key, MAX_SIZE, stdin);

    printf("Choose an option:\n");
    printf("\t1. Encrypt\n");
    printf("\t2. Decrypt\n");
    printf("\t3. Exit\n");
    printf("\nEnter your choice: ");

    scanf("%c", &choice);

    switch (choice)
    {
        case '1':
            encrypt(plainText, key);
            printf("\nEncrypted Text: %s", plainText);
            break;
        case '2':
            decrypt(cipherText, key);
            printf("\nDecrypted Text: %s", cipherText);
            break;
        case '3':
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}

void encrypt(char plainText[], char key[])
{
    int keyLength = strlen(key) - 1; // -1 to remove the newline character
    int plainTextLength = strlen(plainText) - 1; // -1 to remove the newline character

    for (int i = 0, j = 0; i < plainTextLength; i++, j++)
    {
        if (j == keyLength)
        {
            j = 0;
        }

        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                plainText[i] = ((plainText[i] - 'A') + (toupper(key[j]) - 'A')) % 26 + 'A';
            }
            else
            {
                plainText[i] = ((plainText[i] - 'a') + (toupper(key[j]) - 'A')) % 26 + 'a';
            }
        }
    }
}

void decrypt(char cipherText[], char key[])
{
    int keyLength = strlen(key) - 1; // -1 to remove the newline character
    int cipherTextLength = strlen(cipherText) - 1; // -1 to remove the newline character

    for (int i = 0, j = 0; i < cipherTextLength; i++, j++)
    {
        if (j == keyLength)
        {
            j = 0;
        }

        if (isalpha(cipherText[i]))
        {
            if (isupper(cipherText[i]))
            {
                cipherText[i] = ((cipherText[i] - 'A') - (toupper(key[j]) - 'A') + 26) % 26 + 'A';
            }
            else
            {
                cipherText[i] = ((cipherText[i] - 'a') - (toupper(key[j]) - 'A') + 26) % 26 + 'a';
            }
        }
    }
}