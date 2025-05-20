//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to encrypt the message using substitution cipher
void encrypt(char* message, int key)
{
    int length = strlen(message);
    for(int i=0; i<length; i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            message[i] = (message[i]-'a'+key)%26+'a';
        }
        if(message[i]>='A' && message[i]<='Z')
        {
            message[i] = (message[i]-'A'+key)%26+'A';
        }
    }
}

// function to decrypt the message using substitution cipher
void decrypt(char* message, int key)
{
    int length = strlen(message);
    for(int i=0; i<length; i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            message[i] = (message[i]-'a'-key+26)%26+'a';
        }
        if(message[i]>='A' && message[i]<='Z')
        {
            message[i] = (message[i]-'A'-key+26)%26+'A';
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // seed the random number generator with the current time
    srand(time(NULL));

    // randomly generate a salt value between 1000 and 9999
    int salt = rand() % 9000 + 1000;

    // add the salt value to the key
    key += salt;

    // encrypt the message using the key
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    // decrypt the message using the key
    decrypt(message, key-salt);

    printf("Decrypted message: %s\n", message);

    return 0;
}