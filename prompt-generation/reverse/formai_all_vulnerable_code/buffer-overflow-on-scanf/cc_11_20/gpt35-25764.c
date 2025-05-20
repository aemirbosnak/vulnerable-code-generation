//FormAI DATASET v1.0 Category: Modern Encryption ; Style: happy
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Welcome to the Happy Encryption Program!\n");
    char message[100];
    printf("Enter the message you want to encrypt: ");
    fgets(message,100,stdin);
    int key;
    printf("Enter the encryption key (an integer between 1 and 26): ");
    scanf("%d",&key);
    printf("Great! We are now encrypting your message...\n\n");
    char encrypted[100];
    int i;
    for(i=0;i<strlen(message);i++)
    {
        if(message[i]>='a' && message[i]<='z')
        {
            encrypted[i] = ((message[i]-'a'+key)%26)+'a';
        }
        else if(message[i]>='A' && message[i]<='Z')
        {
            encrypted[i] = ((message[i]-'A'+key)%26)+'A';
        }
        else
        {
            encrypted[i] = message[i];
        }
    }
    printf("Your encrypted message is: %s\n",encrypted);
    printf("Would you like to decrypt your message? (Y/N): ");
    char choice;
    scanf(" %c",&choice);
    if(choice=='Y' || choice=='y')
    {
        printf("Excellent choice! We will now decrypt your message...\n\n");
        char decrypted[100];
        int i;
        for(i=0;i<strlen(encrypted);i++)
        {
            if(encrypted[i]>='a' && encrypted[i]<='z')
            {
                decrypted[i] = (((encrypted[i]-'a'-key)+26)%26)+'a';
            }
            else if(encrypted[i]>='A' && encrypted[i]<='Z')
            {
                decrypted[i] = (((encrypted[i]-'A'-key)+26)%26)+'A';
            }
            else
            {
                decrypted[i] = encrypted[i];
            }
        }
        printf("Your decrypted message is: %s\n",decrypted);
    }
    printf("Thank you for using the Happy Encryption Program. Have a great day!\n");
    return 0;
}