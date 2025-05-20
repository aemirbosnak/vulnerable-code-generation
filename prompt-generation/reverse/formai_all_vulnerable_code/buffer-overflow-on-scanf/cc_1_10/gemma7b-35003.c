//Gemma-7B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    char **arr = NULL;
    int i, j, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Error: The number of elements exceeds the limit of %d.", MAX);
        return 1;
    }

    arr = (char **)malloc(n * sizeof(char *));

    if (arr == NULL)
    {
        printf("Error: Memory allocation failed.");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));

        if (arr[i] == NULL)
        {
            printf("Error: Memory allocation failed.");
            return 1;
        }
    }

    printf("Enter the elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("The elements are: ");

    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}