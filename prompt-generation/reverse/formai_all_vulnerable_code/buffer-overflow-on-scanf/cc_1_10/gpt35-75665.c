//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* encrypt(char *message, int shiftKey)
{
    int messageLength = strlen(message);
    char *encryptedMessage = (char*) malloc(messageLength);
    memset(encryptedMessage, 0, messageLength);

    for(int i=0; i<messageLength; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            encryptedMessage[i] = (message[i] - 'a' + shiftKey) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            encryptedMessage[i] = (message[i] - 'A' + shiftKey) % 26 + 'A';
        }
        else
        {
            encryptedMessage[i] = message[i];
        }
    }

    return encryptedMessage;
}

char* decrypt(char *message, int shiftKey)
{
    int messageLength = strlen(message);
    char *decryptedMessage = (char*) malloc(messageLength);
    memset(decryptedMessage, 0, messageLength);

    for(int i=0; i<messageLength; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            decryptedMessage[i] = (message[i] - 'a' - shiftKey + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            decryptedMessage[i] = (message[i] - 'A' - shiftKey + 26) % 26 + 'A';
        }
        else
        {
            decryptedMessage[i] = message[i];
        }
    }

    return decryptedMessage;
}

int main()
{
    char message[50];
    int shiftKey;

    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter shift key: ");
    scanf("%d", &shiftKey);

    char *encryptedMessage = encrypt(message, shiftKey);
    printf("Encrypted Message: %s \n", encryptedMessage);

    char *decryptedMessage = decrypt(encryptedMessage, shiftKey);
    printf("Decrypted Message: %s \n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}