//Gemma-7B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str1 = NULL;
    char *str2 = NULL;
    int len1 = 0;
    int len2 = 0;
    char **arr = NULL;
    int i = 0;

    printf("Enter the length of str1: ");
    scanf("%d", &len1);

    str1 = malloc(len1 + 1);
    printf("Enter str1: ");
    scanf("%s", str1);

    printf("Enter the length of str2: ");
    scanf("%d", &len2);

    str2 = malloc(len2 + 1);
    printf("Enter str2: ");
    scanf("%s", str2);

    arr = malloc((len1 + len2) * sizeof(char *));

    for (i = 0; i < len1 + len2; i++)
    {
        arr[i] = malloc(len1 + len2 + 1);
    }

    for (i = 0; i < len1; i++)
    {
        strcpy(arr[i], str1);
    }

    for (i = len1; i < len1 + len2; i++)
    {
        strcpy(arr[i], str2);
    }

    printf("The combined string is:\n");

    for (i = 0; i < len1 + len2; i++)
    {
        printf("%s ", arr[i]);
    }

    printf("\n");

    for (i = 0; i < len1 + len2; i++)
    {
        free(arr[i]);
    }

    free(arr);
    free(str1);
    free(str2);

    return 0;
}