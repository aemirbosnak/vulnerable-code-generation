//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <string.h>
#define MAX_BUFFER_SIZE 512

void protect(char *str); // Function to protect the text

int main()
{
    char buffer[MAX_BUFFER_SIZE]; // Buffer to hold the input text
    int length; // Length of input text

    // Get input text from user
    printf("Enter the text you want to protect:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    length = strlen(buffer);
    if (buffer[length - 1] == '\n') 
    {
        buffer[length - 1] = '\0';
        length = strlen(buffer);
    }

    // Protect the text
    protect(buffer);

    printf("Protected text:\n%s\n", buffer);

    return 0;
}

// Function to protect the text
void protect(char *str)
{
    int i = 0, j = 0;
    int length = strlen(str);
    char temp[length]; // Temporary buffer to hold the protected text

    // Iterate through each character in the string
    while (str[i] != '\0')
    {
        // Check if character is an alphabet
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            // If alphabet is uppercase, convert to lowercase
            if (str[i] >= 'A' && str[i] <= 'Z') 
            {
                temp[j] = str[i] + 32;
            }
            else 
            {
                temp[j] = str[i];
            }
            j++;
        }
        // If character is not an alphabet, add it as it is to temporary buffer
        else 
        {
            temp[j] = str[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0'; // Add the terminating null character to the end of temporary buffer

    // Copy the temporary buffer to the original buffer
    strcpy(str, temp);
}