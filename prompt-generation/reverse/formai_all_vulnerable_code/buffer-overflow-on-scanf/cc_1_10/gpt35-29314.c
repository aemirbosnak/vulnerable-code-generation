//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void bucketSort(int arr[], int n)
{
    //Creating an array of 10 buckets
    int buckets[10][n];
    int counts[10] = {0};
 
    //Distributing elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = arr[i] / 10;
        buckets[bucket_index][counts[bucket_index]] = arr[i];
        counts[bucket_index]++;
    }
 
    //Sorting elements of each bucket using insertion sort
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }
 
    //Merging all buckets into the original array
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}
 
int main()
{
    printf("----------------------------------------\n");
    printf("            C BUCKET SORT               \n");
    printf("----------------------------------------\n\n");
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
 
    int arr[n];
    srand(time(NULL)); //seeding random number generator
    printf("\nUnsorted Array: [");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; //generating random numbers between 0 to 99
        printf("%d, ", arr[i]);
    }
    printf("]\n\n");
 
    bucketSort(arr, n);
 
    printf("Sorted Array:   [");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n\n");
 
    return 0;
}