//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main()
{
    int i;
    int j;
    int n;
    int k;
    int sum;
    int max;
    int min;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array are: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Enter the index of the element to be searched: ");
    scanf("%d", &k);

    printf("The element %d is present at index %d\n", k, k);

    printf("\n");

    sum = 0;
    for(i=0; i<n; i++)
    {
        sum += arr[i];
    }

    printf("The sum of all elements of the array is: %d\n", sum);

    max = arr[0];
    min = arr[0];

    for(i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("The maximum element in the array is: %d\n", max);

    printf("The minimum element in the array is: %d\n", min);

    return 0;
}