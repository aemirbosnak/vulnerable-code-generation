//Gemma-7B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **arr = NULL;
    int i = 0, j = 0, k = 0, n = 0, max_size = MAX;

    // Allocate memory for the array
    arr = (char **)malloc(max_size * sizeof(char *));

    // Get the number of lines in the text file
    FILE *fp = fopen("text.txt", "r");
    fscanf(fp, "%d", &n);
    fclose(fp);

    // Read the text file and store it in the array
    fp = fopen("text.txt", "r");
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
        fscanf(fp, "%s", arr[i]);
    }
    fclose(fp);

    // Find the maximum length of a sentence in the text file
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] == '.' || arr[i][j] == '!' || arr[i][j] == '?')
            {
                if (j - k + 1 > max_size)
                {
                    max_size = j - k + 1;
                }
                k = j + 1;
            }
        }
    }

    // Print the maximum length of a sentence
    printf("The maximum length of a sentence in the text file is: %d", max_size);

    // Free the memory allocated for the array
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}