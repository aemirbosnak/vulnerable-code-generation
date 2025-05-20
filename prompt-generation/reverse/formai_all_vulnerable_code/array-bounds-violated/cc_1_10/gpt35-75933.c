//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototype
void compress(char *str);

int main()
{
    char str[200]; // Maximum size of string to be compressed
    printf("Enter a string to be compressed: ");
    fgets(str, sizeof(str), stdin);

    // Removing the newline character at the end
    str[strcspn(str, "\n")] = '\0';

    // Calling compress function to compress the string
    compress(str);

    return 0;
}

// Function to compress the given string
void compress(char *str)
{
    int i, j, count;
    int len = strlen(str);
    char compressed[len+1]; // To store the compressed string
    char current_char, str_count[10]; // To store the current character and its count

    // Initializing starting values
    i = 0;
    j = 0;
    current_char = str[0];
    count = 1;
    sprintf(str_count, "%d", count); // Converting the count to string

    while(i < len-1)
    {
        // Checking if the next character is same as current character
        if(str[i+1] == current_char)
        {
            count++;
            sprintf(str_count, "%d", count); // Converting the count to string
        }
        else
        {
            // Adding the current character and its count to the compressed string
            compressed[j] = current_char;
            j++;
            strcat(compressed, str_count);
            j += strlen(str_count);

            // Updating the values for next character
            current_char = str[i+1];
            count = 1;
            sprintf(str_count, "%d", count); // Converting the count to string
        }
        i++;
    }

    // Adding the last character and its count to the compressed string
    compressed[j] = current_char;
    j++;
    strcat(compressed, str_count);
    j += strlen(str_count);
    compressed[j] = '\0';

    printf("The compressed string is: %s\n",compressed);
}