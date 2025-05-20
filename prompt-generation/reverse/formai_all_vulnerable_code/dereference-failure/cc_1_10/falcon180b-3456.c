//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main()
{
    printf("Enter a message: ");
    char message[MAX];
    fgets(message, MAX, stdin);

    int i, j, n, p, q, e, phi_n;
    char *str;
    char *key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    n = strlen(message);
    char *m = calloc(n+1, sizeof(char));
    str = calloc(n+1, sizeof(char));

    // Convert message to uppercase
    for (i = 0; i < n; i++)
    {
        if (isalpha(message[i]))
        {
            m[i] = toupper(message[i]);
        }
        else
        {
            m[i] = message[i];
        }
    }

    // Generate public and private keys
    p = 2;
    q = 3;
    e = 5;
    phi_n = (p-1)*(q-1);
    int d = (e^-1) % phi_n;

    printf("Public Key: %d, %d\n", p, e);
    printf("Private Key: %d, %d\n", q, d);

    // Encrypt message using public key
    char *encrypted_message = calloc(n+1, sizeof(char));
    for (i = 0; i < n; i++)
    {
        if (isalpha(m[i]))
        {
            int index = 0;
            while (key[index]!= m[i])
            {
                index++;
            }
            encrypted_message[i] = (index + e) % 26;
        }
        else
        {
            encrypted_message[i] = m[i];
        }
    }

    // Decrypt message using private key
    char *decrypted_message = calloc(n+1, sizeof(char));
    for (i = 0; i < n; i++)
    {
        if (isalpha(encrypted_message[i]))
        {
            int index = 0;
            while (key[index]!= encrypted_message[i])
            {
                index++;
            }
            decrypted_message[i] = (index - d + 26) % 26;
        }
        else
        {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    // Print results
    printf("Encrypted Message: %s\n", encrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);

    return 0;
}