//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

void encrypt(int key, char* data)
{
    if (*data == '\0')
        return;
    else
    {
        int ascii = (int)*data;
        ascii += key;
        *data = (char)ascii; // Encrypting character
        encrypt(key, data + 1); // Recursive call to encrypt next character
    }
}

void decrypt(int key, char* data)
{
    if (*data == '\0')
        return;
    else
    {
        int ascii = (int)*data;
        ascii -= key;
        *data = (char)ascii; // Decrypting character
        decrypt(key, data + 1); // Recursive call to decrypt next character
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Enter encryption/decryption key: ");
    scanf("%d", &key);

    // Encrypting message
    encrypt(key, message);
    printf("Encrypted message: %s", message);

    // Decrypting message
    decrypt(key, message);
    printf("\nDecrypted message: %s", message);

    return 0;
}