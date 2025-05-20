//FormAI DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16

void encrypt(char *text, char *key);
void decrypt(char *text, char *key);

int main()
{
    char text[1000], key[MAX_KEY_LENGTH];
    int choice;

    printf("Enter the text to encrypt: ");
    fgets(text, 1000, stdin);
    printf("Enter the key (max length %d): ", MAX_KEY_LENGTH);
    fgets(key, MAX_KEY_LENGTH, stdin);

    printf("\nChoose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encrypt(text, key);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            decrypt(text, key);
            printf("Decrypted text: %s\n", text);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void xor(char *text, char *key)
{
    int i, j;
    int key_length = strlen(key);

    for(i = 0, j = 0; text[i] != '\0'; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }
        text[i] ^= key[j];
    }
}

void encrypt(char *text, char *key)
{
    xor(text, key);
}

void decrypt(char *text, char *key)
{
    xor(text, key);
}