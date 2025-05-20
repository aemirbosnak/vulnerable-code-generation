//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void beautify(char **arr, int n)
{
    int i, j, k, l, max_len = 0;

    for (i = 0; i < n; i++)
    {
        int len = strlen(arr[i]);
        if (len > max_len)
            max_len = len;
    }

    for (i = 0; i < n; i++)
    {
        int len = strlen(arr[i]);
        k = max_len - len;
        for (j = 0; j < k; j++)
            arr[i] = strcat(arr[i], " ");
    }

    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
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
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the string: ");
        scanf("%s", arr[i]);
    }

    beautify(arr, n);

    return 0;
}