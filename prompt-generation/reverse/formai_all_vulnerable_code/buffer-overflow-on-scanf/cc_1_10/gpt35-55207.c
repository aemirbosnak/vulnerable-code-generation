//FormAI DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

void encrypt(char message[], char key[]);
void decrypt(char message[], char key[]);

int main()
{
    char message[SIZE];
    char key[SIZE];
    int choice;

    printf("Enter message to be encrypted: ");
    fgets(message, SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';

    srand(time(NULL));
    for(int i = 0; i < strlen(message); i++)
    {
        key[i] = (char)(rand() % 26 + 65);
    }
    key[strlen(message)] = '\0';

    printf("Generated key: %s\n", key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    getchar();

    switch(choice)
    {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void encrypt(char message[], char key[])
{
    for(int i = 0; i < strlen(message); i++)
    {
        message[i] = (((message[i] - 'A') + (key[i] - 'A')) % 26) + 'A';
    }
}

void decrypt(char message[], char key[])
{
    for(int i = 0; i < strlen(message); i++)
    {
        message[i] = (((message[i] - 'A') - (key[i] - 'A') + 26) % 26) + 'A';
    }
}