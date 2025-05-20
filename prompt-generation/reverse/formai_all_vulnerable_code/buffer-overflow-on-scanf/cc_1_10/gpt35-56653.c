//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// This function generates a random key given its length
void generate_key(char *key, int length)
{
    srand(time(NULL));
    for(int i = 0; i < length; i++)
    {
        key[i] = 'A' + rand() % 26;
    }
    key[length] = '\0'; // add null character to the end of the key
}

// This function encrypts a message using the given key
void encrypt(char *message, char *key)
{
    int message_length = strlen(message);
    int offset = 'A'; // ASCII value of letter 'A' is used as the offset

    for(int i = 0; i < message_length; i++)
    {
        message[i] = ((message[i] - offset + key[i % strlen(key)] - offset) % 26) + offset;
    }
}

// This function decrypts a message using the given key
void decrypt(char *message, char *key)
{
    int message_length = strlen(message);
    int offset = 'A'; // ASCII value of letter 'A' is used as the offset

    for(int i = 0; i < message_length; i++)
    {
        message[i] = ((message[i] - offset - key[i % strlen(key)] + offset + 26) % 26) + offset;
    }
}

int main()
{
    char message[100];
    char key[100];
    int choice;

    printf("Please enter the message that you want to encrypt (maximum 100 characters):\n");
    fgets(message, sizeof(message), stdin);

    printf("Do you want to (1) generate a random key or (2) enter your own key?\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Please enter the length of the key:\n");
        int length;
        scanf("%d", &length);

        generate_key(key, length);
        printf("The key generated is: %s\n", key);
    }
    else if(choice == 2)
    {
        printf("Please enter the key (maximum 100 characters):\n");
        getchar(); // to consume the newline character left in the input buffer
        fgets(key, sizeof(key), stdin);
    }
    else
    {
        printf("Invalid choice. Program will now exit.\n");
        return 0;
    }

    encrypt(message, key);
    printf("The encrypted message is: %s\n", message);

    decrypt(message, key);
    printf("The decrypted message is: %s\n", message);

    return 0;
}