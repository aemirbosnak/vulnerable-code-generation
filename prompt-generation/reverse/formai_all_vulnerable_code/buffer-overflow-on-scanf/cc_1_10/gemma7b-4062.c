//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX 100

void palindrome_checker(char **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        char temp = arr[i][0];
        arr[i][0] = arr[j][0];
        arr[j][0] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], arr[i]) == 0)
        {
            printf("The string %s is a palindrome.\n", arr[i]);
        }
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the string: ");
        scanf("%s", arr[i]);
    }

    palindrome_checker(arr, n);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}