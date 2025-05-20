//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Function declarations */
bool isUnsafeChar(char);

/* Main function */
int main()
{
    char inputURL[1000], sanitizedURL[1000], tempChar;
    int i = 0, j = 0;
    
    printf("Enter URL to sanitize: ");
    scanf("%s", inputURL);
    
    /* Loop through each character of input URL */
    while(inputURL[i])
    {
        tempChar = inputURL[i];
        
        /* Check if character is unsafe */
        if(isUnsafeChar(tempChar))
        {
            /* Replace unsafe character with URL-encoded equivalent */
            sprintf(&sanitizedURL[j], "%%%02X", tempChar);
            j += 3;
        }
        else
        {
            /* Copy character as is */
            sanitizedURL[j] = tempChar;
            j++;
        }
        
        i++;
    }
    
    /* Null-terminate sanitized URL */
    sanitizedURL[j] = '\0';
    
    printf("Sanitized URL: %s\n", sanitizedURL);
    
    return 0;
}

/* Function to check if a character is unsafe */
bool isUnsafeChar(char c)
{
    if(c == ' ' || c == '"' || c == '<' || c == '>' || c == '#' || c == '%' || c == '{' || c == '}' || c == '|' || c == '\\' || c == '^' || c == '~' || c == '[' || c == ']' || c == '`')
    {
        return true;
    }
    else
    {
        return false;
    }
}