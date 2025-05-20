//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WATERMARK "This is a secret message" // The #define directive is used to create a macro

int main()
{
    char str[1000], buffer[1000]; // declare two arrays to store the user's message and the modified message
    int choice, length, i, j;
    
    printf("Please enter a message to encode with a digital watermark: ");
    fgets(str, 1000, stdin); // read in the user's message
    
    length = strlen(str); // find the length of the message
    
    printf("\nPlease choose a paranoid digital watermark encoding method:\n");
    printf("1. Random insertion of the watermark\n");
    printf("2. Reversal of message with watermark embedded\n");
    printf("3. Bitwise XOR encryption of watermark\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice); // read in the user's choice
    
    switch (choice)
    {
        case 1:
            srand(time(NULL)); // initialize the random number generator with the current time
            j = 0; // set the index of the watermark insertions to 0
            
            for (i = 0; i < length; i++)
            {
                buffer[i] = str[i]; // copy the character from the user's message to the modified message
                
                if (i % 10 == 0 && j < strlen(WATERMARK)) // insert the watermark every 10 characters
                {
                    buffer[i] = WATERMARK[j++]; // insert the next character from the watermark
                }
                
                if (j == strlen(WATERMARK)) // if the entire watermark has been inserted, stop inserting
                {
                    break;
                }
            }
            
            printf("\nThe digital watermark has been inserted randomly into the message:\n");
            printf("%s\n", buffer);
            break;
        
        case 2:
            for (i = length - 1, j = 0; i >= 0 && j < strlen(WATERMARK); i--, j++)
            {
                buffer[i] = WATERMARK[j]; // insert the watermark by reversing the message
            }
            
            for (i = 0; i < length; i++)
            {
                buffer[i + strlen(WATERMARK)] = str[i]; // copy the remaining characters from the user's message
            }
            
            printf("\nThe digital watermark has been embedded by reversing the message:\n");
            printf("%s\n", buffer);
            break;
        
        case 3:
            for (i = 0; i < length && i < strlen(WATERMARK); i++)
            {
                buffer[i] = str[i] ^ WATERMARK[i]; // encrypt the watermark using bitwise XOR
            }
            
            for (i = strlen(WATERMARK); i < length; i++)
            {
                buffer[i] = str[i]; // copy the remaining characters from the user's message
            }
            
            printf("\nThe digital watermark has been encrypted using bitwise XOR:\n");
            printf("%s\n", buffer);
            break;
        
        default:
            printf("Invalid choice. Please try again.\n");
            return 1;
    }
    
    return 0;
}