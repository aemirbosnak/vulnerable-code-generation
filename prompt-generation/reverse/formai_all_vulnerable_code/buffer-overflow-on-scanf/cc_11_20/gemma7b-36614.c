//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int m;
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Get the user input
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the array
    printf("The array is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Convert the array to ASCII art
    printf("The ASCII art is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            switch (arr[i][j])
            {
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("=");
                    break;
                case 2:
                    printf("$");
                    break;
                case 3:
                    printf("@");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}