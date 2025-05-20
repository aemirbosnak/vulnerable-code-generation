//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SIZE 80

//Function to encrypt the message
void encrypt(char message[SIZE],int key)
{
    int i,j;
    for(i=0;i<strlen(message);i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = (message[i] - 65 + key) % 26 + 65;
            }
            else
            {
                message[i] = (message[i] - 97 + key) % 26 + 97;
            }
        }
    }
}

//Function to decrypt the message
void decrypt(char message[SIZE],int key)
{
    int i,j;
    for(i=0;i<strlen(message);i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = (message[i] - 65 - key + 26) % 26 + 65;
            }
            else
            {
                message[i] = (message[i] - 97 - key + 26) % 26 + 97;
            }
        }
    }
}

//Function to generate a key
int generateKey()
{
    int key = rand() % 26;
    return key;
}

//Function to display the menu
void menu()
{
    printf("\n");
    printf("MENU\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("3. Exit\n");
    printf("\n");
}

int main()
{
    char message[SIZE];
    int key,choice;
    srand(time(NULL));

    //Loop until the user chooses to exit
    while(1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);

        //Encrypt the message
        switch(choice)
        {
            case 1:
                printf("\nEnter the message to be encrypted: ");
                scanf("%s",message);
                key = generateKey();
                encrypt(message,key);
                printf("\nEncrypted message: %s\n",message);
                break;

            //Decrypt the message
            case 2:
                printf("\nEnter the message to be decrypted: ");
                scanf("%s",message);
                printf("\nEnter the key: ");
                scanf("%d",&key);
                decrypt(message,key);
                printf("\nDecrypted message: %s\n",message);
                break;

            //Exit the program
            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}