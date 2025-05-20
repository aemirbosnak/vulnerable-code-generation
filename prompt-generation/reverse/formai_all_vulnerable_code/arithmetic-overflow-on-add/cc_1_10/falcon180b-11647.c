//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char message[100];
    int key;
    char encrypted_message[100];
    char decrypted_message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key between 0 and 25: ");
    scanf("%d", &key);

    printf("Enter a message to decrypt: ");
    scanf("%s", decrypted_message);

    // Encryption
    int i = 0;
    while (message[i])
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                encrypted_message[i] = ((message[i] + key - 65) % 26) + 65;
            }
            else
            {
                encrypted_message[i] = ((message[i] + key - 97) % 26) + 97;
            }
        }
        else
        {
            encrypted_message[i] = message[i];
        }
        i++;
    }
    encrypted_message[i] = '\0';

    // Decryption
    i = 0;
    while (encrypted_message[i])
    {
        if (isalpha(encrypted_message[i]))
        {
            if (isupper(encrypted_message[i]))
            {
                decrypted_message[i] = ((encrypted_message[i] - key - 65) % 26) + 65;
            }
            else
            {
                decrypted_message[i] = ((encrypted_message[i] - key - 97) % 26) + 97;
            }
        }
        else
        {
            decrypted_message[i] = encrypted_message[i];
        }
        i++;
    }
    decrypted_message[i] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}