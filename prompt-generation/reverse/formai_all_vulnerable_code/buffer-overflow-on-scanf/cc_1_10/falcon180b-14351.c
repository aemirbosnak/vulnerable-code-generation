//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char message[100];
    char key[100];
    char encrypted_message[200];
    char decrypted_message[200];
    int i, j, k, n;

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    n = strlen(message);
    k = strlen(key);

    if(n > k)
    {
        printf("Error: The message is longer than the key.\n");
        return 0;
    }

    for(i=0, j=0; i<n; i++, j++)
    {
        if(j == k)
            j = 0;

        encrypted_message[i] = message[i] ^ key[j];
    }

    printf("Encrypted message: %s\n", encrypted_message);

    for(i=0, j=0; i<n; i++, j++)
    {
        if(j == k)
            j = 0;

        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}