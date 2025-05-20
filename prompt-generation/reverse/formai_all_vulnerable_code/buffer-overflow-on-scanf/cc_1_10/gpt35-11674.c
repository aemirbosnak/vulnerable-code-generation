//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#define MAX 50

int search(int [], int, int);

int main()
{
    int arr[MAX], n, key, pos;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    pos = search(arr, n, key);

    if(pos == -1)
    {
        printf("The element is not present in the array.\n");
    }
    else
    {
        printf("The element is present at position %d in the array.\n", pos+1);
    }

    return 0;
}

int search(int arr[], int n, int key)
{
    int pos = -1;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            pos = i;
            break;
        }
    }

    return pos;
}