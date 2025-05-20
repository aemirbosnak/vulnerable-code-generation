//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Happy Encryption Program
//By Chatbot Happy

int main()
{
    char message[100], key[100], encrypted_message[100], decrypted_message[100];
    int i, j, choice;

    //Taking the message and key input from the user
    printf("Enter the message you want to encrypt: ");
    gets(message);
    printf("Enter the key: ");
    gets(key);

    //Displaying the message and key
    printf("\nYour message: %s\n", message);
    printf("Your key: %s\n", key);

    //Encrypting the message using the key
    for(i=0, j=0; i<strlen(message); i++, j++)
    {
        if(j==strlen(key))
            j = 0;
        encrypted_message[i] = (message[i] + key[j]) % 26 + 'A';
    }
    encrypted_message[i] = '\0'; //Adding null character to indicate the end of string

    //Displaying the encrypted message
    printf("\nYour encrypted message: %s", encrypted_message);

    //Asking the user if they want to decrypt the message
    printf("\n\nDo you want to decrypt the message? (1 for Yes, 0 for No) ");
    scanf("%d", &choice);

    if(choice)
    {
        //Decrypting the message using the key
        for(i=0, j=0; i<strlen(encrypted_message); i++, j++)
        {
            if(j==strlen(key))
                j = 0;
            decrypted_message[i] = (encrypted_message[i] - key[j] + 26) % 26 + 'A';
        }
        decrypted_message[i] = '\0'; //Adding null character to indicate the end of string

        //Displaying the decrypted message
        printf("\nYour decrypted message: %s", decrypted_message);
    }

    printf("\n\nHurray! Your message has been encrypted and decrypted successfully. ");
    printf("Have a happy day!");

    return 0;
}