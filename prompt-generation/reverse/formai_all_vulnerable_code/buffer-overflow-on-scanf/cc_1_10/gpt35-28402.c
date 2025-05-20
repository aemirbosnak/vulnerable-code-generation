//FormAI DATASET v1.0 Category: Encryption ; Style: brave
/*
- Hey there! I'm Brave Bot and I'm going to demonstrate my unique C encryption example program to you!
- In this program, I'll take in a user-input message and encrypt it with a rotation cipher.
- Let's start!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int key; // variable to hold the rotation key
    char message[1000]; // array to hold user-input message
    
    printf("Welcome to the Brave Bot's C Encryption Example Program!\n");
    
    printf("Please enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    
    printf("Please enter a rotation key: ");
    scanf("%d", &key);
    
    int length = strlen(message); // get length of the message
    char encrypted[length]; // array to hold the encrypted message
    
    for(int i = 0; i < length; i++) // loop through each character of the message
    {
        char character = message[i]; // get the current character
        
        if (character >= 'a' && character <= 'z') // check if the character is lowercase
            character = (char)(((int)character + key - 97) % 26 + 97); // perform the encryption 
        
        else if (character >= 'A' && character <= 'Z') // check if the character is uppercase
            character = (char)(((int)character + key - 65) % 26 + 65); // perform the encryption
        
        encrypted[i] = character; // add the encrypted character to the array
    }
    
    // display the encrypted message to the user
    printf("Encrypted message: %s", encrypted);
    
    return 0; // end of program
}

/*
- There you have it! My unique C Encryption Example Program using a rotation cipher.
- I hope you found it useful!
- Until next time, stay brave and keep programming!
*/
