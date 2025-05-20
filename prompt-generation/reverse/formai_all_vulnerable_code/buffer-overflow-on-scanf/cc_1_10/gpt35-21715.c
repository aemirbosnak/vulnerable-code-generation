//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
// A multiplayer encryption game using C language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to shuffle the characters in a string
void shuffle(char *str)
{
    int len = strlen(str), i;
    for (i = len - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// function for encryption using shuffle and shift technique
void encrypt(char *str, int shift)
{
    shuffle(str);
    int len = strlen(str), i;
    for (i = 0; i < len; i++)
    {
        str[i] = (str[i] + shift) % 256;
    }
}

// main function to run the multiplayer game
int main()
{
    srand(time(0));
    char message[100], copy[100], decrypted[100];
    int shift, choice, i;
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", message);
    strcpy(copy, message);
    printf("Enter a shift value for encryption: ");
    scanf("%d", &shift);
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);
    strcpy(decrypted, message);
    printf("Enter the exact same shift value used for encryption to decrypt the message: ");
    scanf("%d", &shift);
    for (i = 0; i < shift; i++)
    {
        shuffle(decrypted);
    }
    for (i = 0; i < strlen(decrypted); i++)
    {
        decrypted[i] = (decrypted[i] - shift + 256) % 256;
    }
    printf("Decrypted message: %s\n", decrypted);
    printf("Let's play a multiplayer game! One player will encrypt a message and the other will decrypt it.\n");
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Player 1, enter a message to encrypt: ");
        scanf("%[^\n]%*c", message);
        strcpy(copy, message);
        printf("Player 1, enter a shift value for encryption: ");
        scanf("%d", &shift);
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
        printf("Player 2, enter the exact shift value used for encryption to decrypt the message: ");
        scanf("%d", &shift);
        for (i = 0; i < strlen(copy); i++)
        {
            copy[i] = (copy[i] - shift + 256) % 256;
        }
        if (strcmp(copy, message) == 0)
        {
            printf("Player 2 wins!\n");
        }
        else
        {
            printf("Player 1 wins!\n");
        }
    }
    else if (choice == 2)
    {
        printf("Player 1, enter a message to encrypt: ");
        scanf("%[^\n]%*c", message);
        strcpy(copy, message);
        printf("Player 1, enter a shift value for encryption: ");
        scanf("%d", &shift);
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
        printf("Player 2, enter the exact shift value used for encryption to decrypt the message: ");
        scanf("%d", &shift);
        for (i = 0; i < strlen(copy); i++)
        {
            copy[i] = (copy[i] - shift + 256) % 256;
        }
        if (strcmp(copy, message) == 0)
        {
            printf("Player 1 wins!\n");
        }
        else
        {
            printf("Player 2 wins!\n");
        }
    }
    else
    {
        printf("Invalid choice. Please enter 1 for encryption or 2 for decryption.\n");
    }
    return 0;
}