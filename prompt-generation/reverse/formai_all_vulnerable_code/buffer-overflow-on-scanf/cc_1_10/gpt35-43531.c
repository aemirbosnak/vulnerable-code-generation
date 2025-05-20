//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char *str);
void decrypt(char *str);

int main()
{
    char message[MAX_SIZE];
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("\nChoose an option: \n");
    printf("1. Encrypt message \n");
    printf("2. Decrypt message \n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(message);
            printf("\nEncrypted message: %s", message);
            break;
        case 2:
            decrypt(message);
            printf("\nDecrypted message: %s", message);
            break;
        default:
            printf("\nInvalid choice");
            break;
    }

    return 0;
}

void encrypt(char *str)
{
    int i;
    char key = 'k';

    for(i = 0; i < strlen(str); i++){
        str[i] = str[i] ^ key;
    }
}

void decrypt(char *str)
{
    int i;
    char key = 'k';

    for(i = 0; i < strlen(str); i++){
        str[i] = str[i] ^ key;
    }
}