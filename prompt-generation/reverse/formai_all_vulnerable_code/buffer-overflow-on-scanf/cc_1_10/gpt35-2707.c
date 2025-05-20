//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

/* Function to encrypt a string using modern encryption algorithm */
void encrypt(char message[], int key)
{
    int i;
    int length = strlen(message); // Get length of the input string

    // Iterate over each character in the string
    for(i = 0; i < length; i++)
    {
        // Only encrypt alphabets
        if(isalpha(message[i]))
        {
            int ascii = (int) message[i];

            // Shift the letter by the key value
            ascii += key;

            // If the letter is shifted beyond 'z' or 'Z', wrap it around
            if(islower(message[i]) && ascii > 'z')
            {
                ascii = (ascii - 'a') % 26 + 'a';
            }
            else if(isupper(message[i]) && ascii > 'Z')
            {
                ascii = (ascii - 'A') % 26 + 'A';
            }

            // Replace the original character with the encrypted character
            message[i] = (char) ascii;
        }
    }
}

/* Main function */
int main()
{
    char message[100];
    int key;

    // Prompt for input string and encryption key
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);

    // Call the encrypt function to encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s", message);

    return 0;
}