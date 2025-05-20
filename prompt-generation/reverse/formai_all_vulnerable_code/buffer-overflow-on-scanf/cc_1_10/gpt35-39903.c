//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* str, int key);
char* decrypt(char* str, int key);

int main()
{
    char message[100];
    int key;

    // Ask for user input
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);

    // Encrypt message
    char* encryptedMessage = encrypt(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt message
    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}

char* encrypt(char* str, int key)
{
    int length = strlen(str);
    char* encryptedStr = (char*) malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c = (char) (((c - 'a' + key) % 26) + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            c = (char) (((c - 'A' + key) % 26) + 'A');
        }
        encryptedStr[i] = c;
    }

    return encryptedStr;
}

char* decrypt(char* str, int key)
{
    int length = strlen(str);
    char* decryptedStr = (char*) malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c = (char) (((c - 'a' - key + 26) % 26) + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            c = (char) (((c - 'A' - key + 26) % 26) + 'A');
        }
        decryptedStr[i] = c;
    }

    return decryptedStr;
}