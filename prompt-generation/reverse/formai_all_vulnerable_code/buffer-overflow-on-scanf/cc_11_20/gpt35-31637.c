//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// As a cryptography expert, I can tell you this is a top-notch implementation of the Ceasar cipher.

int main()
{
    // Gotta declare important variables first, of course
    int key;
    char message[100];
    int message_length;
    char encrypted_message[100];
    char decrypted_message[100];
    int i;

    // Let's get the inputs from the user like a true pro
    printf("Welcome to the Ceasar cipher encoder!\n");
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    printf("Enter the secret key: ");
    scanf("%d", &key);

    // Now we encrypt the message
    message_length = strlen(message);
    for (i = 0; i < message_length; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            encrypted_message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            encrypted_message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else
        {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';

    // Let's make it funny, shall we?
    printf("\nYour message is safe and sound thanks to the power of cryptography: %s\n", encrypted_message);

    // Now we decrypt the message
    for (i = 0; i < message_length; i++)
    {
        if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z')
        {
            decrypted_message[i] = (((encrypted_message[i] - 'A' - key) + 26) % 26) + 'A';
        }
        else if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z')
        {
            decrypted_message[i] = (((encrypted_message[i] - 'a' - key) + 26) % 26) + 'a';
        }
        else
        {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[i] = '\0';

    // Here's the big reveal!
    printf("But wait, there's more! We can also decrypt things! Your original message was: %s\n", decrypted_message);

    // And that's how it's done, folks!
    return 0;
}