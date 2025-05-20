//Gemma-7B DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data mining function
int data_mining(char *data)
{
    // Allocate memory for the data
    char *buffer = malloc(1024);

    // Copy the data from the input to the buffer
    strcpy(buffer, data);

    // Find the position of the first occurrence of the word "apple" in the data
    int position = strstr(buffer, "apple") - buffer;

    // If the word "apple" is found, return its position
    if (position != -1)
    {
        return position;
    }

    // Otherwise, return -1
    return -1;
}

int main()
{
    // Get the data from the user
    char data[1024];
    printf("Enter data: ");
    scanf("%s", data);

    // Call the data mining function
    int position = data_mining(data);

    // If the word "apple" is found, print its position
    if (position != -1)
    {
        printf("The position of the word 'apple' in the data is: %d\n", position);
    }

    // Otherwise, print an error message
    else
    {
        printf("The word 'apple' was not found in the data.\n");
    }

    return 0;
}