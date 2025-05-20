//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

void encrypt(char *msg, int key);
void decrypt(char *msg, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter message: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *msg, int key)
{
    int i;
    for(i = 0; i < strlen(msg); i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = ((msg[i] - 'a') + key) % 26 + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = ((msg[i] - 'A') + key) % 26 + 'A';
        }
    }
}

void decrypt(char *msg, int key)
{
    int i;
    for(i = 0; i < strlen(msg); i++)
    {
        if(msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = ((msg[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = ((msg[i] - 'A') - key + 26) % 26 + 'A';
        }
    }
}