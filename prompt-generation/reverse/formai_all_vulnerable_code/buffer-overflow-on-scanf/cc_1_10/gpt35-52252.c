//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include<stdio.h>
#include<string.h>

int main()
{
    // Declare variables
    char userInput[256];
    char sanitizedInput[256];
    int i, j = 0;
    
    printf("Welcome to our happy User Input Sanitizer! Enter your input:\n");
    scanf("%[^\n]s", userInput);
    
    // Loop through the input
    for(i = 0; i < strlen(userInput); i++)
    {
        if(userInput[i] >= 'a' && userInput[i] <= 'z')
        {
            // Convert uppercase to lowercase
            sanitizedInput[j] = userInput[i] + ('A'-'a');
            j++;
        }
        else if(userInput[i] >= 'A' && userInput[i] <= 'Z')
        {
            // Leave uppercase as it is
            sanitizedInput[j] = userInput[i];
            j++;
        }
        else if(userInput[i] >= '0' && userInput[i] <= '9')
        {
            // Leave numbers as it is
            sanitizedInput[j] = userInput[i];
            j++;
        }
        else if(userInput[i] == ' ')
        {
            // Replace spaces with underscore
            sanitizedInput[j] = '_';
            j++;
        }
    }
    
    // Add null terminator at the end of sanitized input
    sanitizedInput[j] = '\0';
    
    // Print original and sanitized input
    printf("\nYour original input: %s\n", userInput);
    printf("Your sanitized input: %s\n", sanitizedInput);
    
    printf("\nYay! Your input has been sanitized and modified to make it more useful. Thank you for using our happy User Input Sanitizer!\n");
    
    return 0;
}