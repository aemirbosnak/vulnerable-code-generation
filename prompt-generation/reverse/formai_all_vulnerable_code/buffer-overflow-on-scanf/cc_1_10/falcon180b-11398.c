//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 80
#define ENCRYPT 1
#define DECRYPT 0

//function to encrypt the message
void encrypt(char message[], int key, int mode)
{
    int i, j;
    for(i=0; message[i]!='\0'; i++)
    {
        if(mode==ENCRYPT)
        {
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] = message[i] + key - 65;
                }
                else
                {
                    message[i] = message[i] + key - 97;
                }
            }
        }
        else if(mode==DECRYPT)
        {
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] = message[i] - key - 65;
                }
                else
                {
                    message[i] = message[i] - key - 97;
                }
            }
        }
    }
}

int main()
{
    char message[LENGTH], key;
    int mode, i;

    //get the message from the user
    printf("Enter the message to be encrypted or decrypted: ");
    scanf("%[^\n]", message);

    //get the key from the user
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    //get the mode from the user
    printf("Enter 1 to encrypt the message or 0 to decrypt the message: ");
    scanf("%d", &mode);

    //encrypt or decrypt the message
    encrypt(message, key, mode);

    //print the encrypted or decrypted message
    printf("\nThe message after %s is: %s", mode==ENCRYPT?"encryption":"decryption", message);

    return 0;
}