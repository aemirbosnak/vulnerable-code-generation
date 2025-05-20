//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
/*
* Cyberpunk Cryptography Implementation
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

char* encrypt(char *text, int key);
char* decrypt(char *text, int key);

int main()
{
    char text[MAX_LEN];
    int key;
    
    printf("Enter the message to encrypt: ");
    fgets(text, MAX_LEN, stdin);

    printf("Enter the key to use for encryption: ");
    scanf("%d", &key);

    char* encrypted_text = encrypt(text, key);
    printf("Encrypted message: %s", encrypted_text);

    printf("\n\n");

    char* decrypted_text = decrypt(encrypted_text, key);
    printf("Decrypted message: %s", decrypted_text);

    return 0;
}

char* encrypt(char *text, int key)
{
    int len = strlen(text);
    char* encrypted_text = (char*) malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            encrypted_text[i] = (((text[i] - 'a') + key) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypted_text[i] = (((text[i] - 'A') + key) % 26) + 'A';
        }
        else
        {
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text[len] = '\0';

    return encrypted_text;
}

char* decrypt(char *text, int key)
{
    int len = strlen(text);
    char* decrypted_text = (char*) malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            decrypted_text[i] = (((text[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            decrypted_text[i] = (((text[i] - 'A') - key + 26) % 26) + 'A';
        }
        else
        {
            decrypted_text[i] = text[i];
        }
    }

    decrypted_text[len] = '\0';

    return decrypted_text;
}