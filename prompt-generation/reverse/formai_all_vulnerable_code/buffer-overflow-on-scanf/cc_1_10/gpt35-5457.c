//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

// Function prototypes
void encrypt(char *str, int key);
void decrypt(char *str, int key);

// Main function
int main()
{
    char str[MAXLEN];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Enter a key (0-255): ");
    scanf("%d", &key);

    // Encrypt the string
    encrypt(str, key);

    // Print the encrypted string
    printf("\nEncrypted string: %s\n", str);

    // Decrypt the string
    decrypt(str, key);

    // Print the decrypted string
    printf("\nDecrypted string: %s\n", str);

    return 0;
}

// Encrypt the string
void encrypt(char *str, int key)
{
    // Loop through each character in the string
    for (int i = 0; i < strlen(str); i++)
    {
        // Perform bitwise XOR with the key
        str[i] = str[i] ^ key;
    }
}

// Decrypt the string
void decrypt(char *str, int key)
{
    // Loop through each character in the string
    for (int i = 0; i < strlen(str); i++)
    {
        // Perform bitwise XOR with the key
        str[i] = str[i] ^ key;
    }
}