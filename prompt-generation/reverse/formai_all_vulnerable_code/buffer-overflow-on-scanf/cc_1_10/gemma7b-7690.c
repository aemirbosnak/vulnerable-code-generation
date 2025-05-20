//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data mining function
int data_mining(char **arr, int n)
{
    int i, j, k, max_occurences = 0, current_occurences = 0;
    char **word_array = NULL;
    word_array = malloc(n * sizeof(char *));

    // Iterate over the array of strings
    for (i = 0; i < n; i++)
    {
        // Tokenize the string into words
        char *word = strtok(arr[i], " ");

        // Iterate over the words
        while (word)
        {
            // Check if the word is already in the word_array
            int found = 0;
            for (j = 0; j < current_occurences; j++)
            {
                if (strcmp(word, word_array[j]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            // If the word is not found, add it to the word_array and update the current_occurences
            if (!found)
            {
                word_array[current_occurences++] = word;
                max_occurences++;
            }
        }

        word = strtok(NULL, " ");
    }

    // Free the memory allocated for the word_array
    free(word_array);

    return max_occurences;
}

int main()
{
    char **arr = NULL;
    int n = 0;

    // Get the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Allocate memory for the strings
    arr = malloc(n * sizeof(char *));

    // Get the strings
    printf("Enter the strings: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(100 * sizeof(char));
        scanf("%[^\n]%*c", arr[i]);
    }

    // Data mining
    int max_occurences = data_mining(arr, n);

    // Print the maximum occurrences
    printf("The maximum occurrences are: %d", max_occurences);

    // Free the memory allocated for the strings
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}