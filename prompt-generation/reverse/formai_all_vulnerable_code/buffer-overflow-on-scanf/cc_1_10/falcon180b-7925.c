//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include<stdio.h>
#include<string.h>

//Function to encrypt the message
void encrypt(char message[], char key[])
{
    int i,j;
    int len = strlen(message);

    //Encrypting the message
    for(i=0;i<len;i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] + (key[i%strlen(key)]-'A');
                if(message[i]>'Z')
                {
                    message[i] = message[i] - 26;
                }
            }
            else
            {
                message[i] = message[i] + (key[i%strlen(key)]-'a');
                if(message[i]>'z')
                {
                    message[i] = message[i] - 26;
                }
            }
        }
    }
}

//Function to decrypt the message
void decrypt(char message[], char key[])
{
    int i,j;
    int len = strlen(message);

    //Decrypting the message
    for(i=0;i<len;i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] - (key[i%strlen(key)]-'A');
                if(message[i]<65)
                {
                    message[i] = message[i] + 26;
                }
            }
            else
            {
                message[i] = message[i] - (key[i%strlen(key)]-'a');
                if(message[i]<97)
                {
                    message[i] = message[i] + 26;
                }
            }
        }
    }
}

//Main function
int main()
{
    char message[100],key[100];

    //Taking input from user
    printf("Enter the message to be encrypted: ");
    scanf("%s",message);
    printf("Enter the key to be used for encryption: ");
    scanf("%s",key);

    //Encrypting the message
    encrypt(message,key);
    printf("Encrypted message: %s\n",message);

    //Decrypting the message
    decrypt(message,key);
    printf("Decrypted message: %s\n",message);

    return 0;
}