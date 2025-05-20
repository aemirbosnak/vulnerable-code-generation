//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
/*
* The following is a modern encryption program
* Written in a Romeo and Juliet style
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the original string
void encrypt(char *original, char *encrypted, int key)
{
    int length = strlen(original);
    
    for (int i = 0; i < length; i++)
    {
        if (isalpha(original[i]))
        {
            if (islower(original[i]))
            {
                encrypted[i] = (((original[i] - 97) + key) % 26) + 97;
            }
            else
            {
                encrypted[i] = (((original[i] - 65) + key) % 26) + 65;
            }
        }
        else
        {
            encrypted[i] = original[i];
        }
    }
}

int main()
{
    char original[512];
    char encrypted[512];
    int key;
    
    printf("Oh apostrophe, wherefore art thou, Romeo?\n");
    printf("Please enter the plaintext to encrypt: ");
    fgets(original, sizeof(original), stdin);
    printf("What light through yonder window breaks?\n");
    printf("Please enter the encryption key: ");
    scanf("%d", &key);
    
    // Strip newline character from "original" string
    original[strcspn(original, "\n")] = 0;
    
    // Encrypt original string and print the result
    encrypt(original, encrypted, key);
    
    printf("But soft! What light through yonder window breaks?\n");
    printf("The encrypted string is: %s\n", encrypted);
    
    return 0;
}