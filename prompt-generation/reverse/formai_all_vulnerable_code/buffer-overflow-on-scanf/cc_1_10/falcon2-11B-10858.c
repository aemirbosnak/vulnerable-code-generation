//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int arr[100];
    int i, j, k, m, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
    {
        sum += arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &m);

    for (j = 0; j < n; j++)
    {
        if (arr[j] == m)
        {
            printf("Element found at index %d\n", j + 1);
            break;
        }
    }

    for (k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");

    printf("Enter the element to be replaced: ");
    scanf("%d", &m);
    printf("Enter the new element: ");
    scanf("%d", &arr[m]);

    for (j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}