//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int encode(char *message, int key);
int decode(char *message, int key);

int main()
{
    char message[100];
    int key, option;

    printf("Enter message to encode/decode: ");
    scanf("%[^\n]s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter option:\n");
    printf("1. Encode\n2. Decode\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            encode(message, key);
            printf("Encoded message: %s\n", message);
            break;

        case 2:
            decode(message, key);
            printf("Decoded message: %s\n", message);
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}

int encode(char *message, int key)
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        message[i] = (message[i] + key) % 256;  // modulo 256 for ASCII
    }
    return 0;
}

int decode(char *message, int key)
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        message[i] = (message[i] - key + 256) % 256;  // add 256 and modulo 256 for ASCII
    }
    return 0;
}