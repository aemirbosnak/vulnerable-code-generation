//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void search(char **arr, int n, char *key)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], key) == 0)
        {
            printf("Found: %s\n", arr[i]);
            return;
        }
    }

    printf("Not found: %s\n", key);
}

int main()
{
    char **arr = NULL;
    int n = 0;

    // Allocate memory for the array
    arr = (char **)malloc(MAX_SIZE * sizeof(char *));

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create the array
    arr = (char **)realloc(arr, n * sizeof(char *));

    // Get the elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        scanf("%s", arr[i]);
    }

    // Get the key
    char key[MAX_SIZE];
    printf("Enter the key: ");
    scanf("%s", key);

    // Search for the key
    search(arr, n, key);

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}