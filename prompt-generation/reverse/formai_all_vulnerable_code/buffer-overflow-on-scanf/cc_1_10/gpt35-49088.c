//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to check if the input is alphanumeric 
int isAlphanumeric(char c) 
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

//Function to sanitize user input
char* sanitize(char* str) 
{
    int i, j = 0;
    size_t length = strlen(str);
    char* sanitized = (char*)calloc(length, sizeof(char));

    for (i = 0; i < length; i++)
    {
        //If the input is alphanumeric, append it to the sanitized string
        if (isAlphanumeric(str[i]))
        {
            sanitized[j] = str[i];
            j++;
        }
    }

    //Null terminate the final string
    sanitized[j] = '\0';

    return sanitized;
}

int main() 
{
    char* input = (char*)calloc(100, sizeof(char));

    printf("Enter any alphanumeric string:\n");
    scanf("%[^\n]", input);

    //Sanitize the user input
    char* sanitized = sanitize(input);

    printf("Sanitized string:\n%s", sanitized);

    free(input);
    free(sanitized);

    return 0;
}