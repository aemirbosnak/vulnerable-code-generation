//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char* text, int key);
void decrypt(char* text, int key);

int main()
{
    char text[MAX_LEN];
    int key;

    // Read user input
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt text
    encrypt(text, key);

    // Display encrypted text and key
    printf("Encrypted text: %s\n", text);
    printf("Encryption key: %d\n", key);

    // Decrypt text
    decrypt(text, key);

    // Display decrypted text
    printf("Decrypted text: %s\n", text);

    return 0;
}

void encrypt(char* text, int key)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        // Encrypt each character with key
        text[i] = ((text[i] - 'a' + key) % 26) + 'a';
    }
}

void decrypt(char* text, int key)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        // Decrypt each character with key
        text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
    }
}