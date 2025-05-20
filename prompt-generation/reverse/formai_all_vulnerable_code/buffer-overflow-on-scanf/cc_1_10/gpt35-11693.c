//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void Bucket_Sort(int array[], int n)
{
    int i, j;
    int count[n]; // Creating n empty buckets

    for(i = 0; i < n; i++) // Initialize count array with 0
    {
        count[i] = 0;
    }

    for(i = 0; i < n; i++) // Increment the count of bucket index
    {
        (count[array[i]])++;
    }

    for(i = 0, j = 0; i < n; i++) // Loop through count array and sort in-place
    {
        for(; count[i] > 0; (count[i])--)
        {
            array[j++] = i;
        }
    }
}

int main()
{
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    Bucket_Sort(arr, n); // Call Bucket Sort function

    printf("\nArray after sorting:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}