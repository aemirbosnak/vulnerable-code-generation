//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // Maximum number of characters to read and write

// Function to compress a given string using run-length encoding algorithm
void compress(char* str)
{
    int count, i, j;
    int len = strlen(str);

    // Create a new array to store the compressed string
    char* res = (char*)malloc(sizeof(char) * (len * 2 + 1));
    int res_index = 0;

    // Traverse the string and count the consecutive identical characters
    for (i = 0; i < len; i++)
    {
        count = 1;
        while (i < len - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        // Store the count and the character in the result array
        res[res_index++] = count + '0';
        res[res_index++] = str[i];
    }

    // Add the null character at the end of the compressed string
    res[res_index] = '\0';

    // Print the original and compressed strings
    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", res);

    // Free the memory allocated to the result array
    free(res);
}

// Function to decompress a given string using run-length decoding algorithm
void decompress(char* str)
{
    int count, i, j, k;
    int len = strlen(str);

    // Create a new array to store the decompressed string
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int res_index = 0;

    // Traverse the string and get the count and the character of each run
    for (i = 0; i < len; i += 2)
    {
        count = str[i] - '0';
        for (j = 0; j < count; j++)
        {
            res[res_index++] = str[i + 1];
        }
    }

    // Add the null character at the end of the decompressed string
    res[res_index] = '\0';

    // Print the original and decompressed strings
    printf("Compressed string: %s\n", str);
    printf("Decompressed string: %s\n", res);

    // Free the memory allocated to the result array
    free(res);
}

// Main function
int main()
{
    char str[MAX];
    int choice;

    // Get the input string from the user
    printf("Enter a string (maximum %d characters): ", MAX - 1);
    fgets(str, MAX, stdin);

    // Remove the newline character at the end of the input string
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    // Display the menu to the user
    do
    {
        printf("\nMENU:\n1. Compress string\n2. Decompress string\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                compress(str);
                break;

            case 2:
                decompress(str);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}