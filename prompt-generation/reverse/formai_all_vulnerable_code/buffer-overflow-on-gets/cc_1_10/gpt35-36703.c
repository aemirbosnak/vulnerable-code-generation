//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include<stdio.h>
#include<stdlib.h> 
#include<ctype.h> 

#define KEY 5 //define key value

void encrypt(char* message, int key); //define function prototype
void decrypt(char* message, int key);

int main()
{
    char message[100];
    int choice;
    printf("\nEnter the message : ");
    gets(message);

    printf("\n1.Encrypt the message \n2.Decrypt the message");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            encrypt(message,KEY); //calling encrypt function
            printf("\nEncrypted message is: %s\n", message);
            break;

        case 2:
            decrypt(message,KEY);  //calling decrypt function
            printf("\nDecrypted message is: %s\n", message);
            break;

        default:
            printf("\nInvalid Choice.\n");
            exit(0);
    }
    return 0;
}

void encrypt(char* message, int key)
{
    char ch;
    int i;
    for(i=0; message[i] != '\0'; i++)
    {
        ch = message[i];  
        if(islower(ch))  
            message[i] = ((ch-97+key)%26)+97; 
        else if(isupper(ch))
            message[i] = ((ch-65+key)%26)+65;  
    }
}

void decrypt(char* message, int key)
{
    char ch;
    int i;
    for(i=0; message[i] != '\0'; i++)
    {
        ch = message[i];  
        if(islower(ch))
            message[i] = (((ch-97-key)+26)%26)+97; 
        else if(isupper(ch))
            message[i] = (((ch-65-key)+26)%26)+65;  
    }
}