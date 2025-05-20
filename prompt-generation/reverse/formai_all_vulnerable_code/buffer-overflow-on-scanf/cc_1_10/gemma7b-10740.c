//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void shock(char *arr, int n)
{
    int i, j, k, l, found = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                for (l = 0; l < n; l++)
                {
                    if (arr[i] == arr[j] && arr[i] == arr[k] && arr[i] == arr[l] && i != j && i != k && i != l)
                    {
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    if (found)
    {
        printf("Shock! Duplicates found.\n");
    }
    else
    {
        printf("No duplicates found.\n");
    }
}

int main()
{
    char arr[MAX];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    scanf("%s", arr);

    shock(arr, n);

    return 0;
}