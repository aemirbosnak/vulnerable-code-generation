//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include<stdio.h>

//function for bucket sort
void bucket_sort(int array[], int n)
{
    int i, j, k, buckets[10][10], counter[10];
    for(i = 0; i < 10; i++)
        counter[i] = 0;
    for(i = 0; i < n; i++)
    {
        int index = 10*array[i];
        buckets[index][counter[index]] = array[i];
        counter[index]++;
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < counter[i]; j++)
        {
            for(k = j+1; k < counter[i]; k++)
            {
                if(buckets[i][j] > buckets[i][k])
                {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }
    printf("Bucket Sort Output:\n");
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < counter[i]; j++)
            printf("%d ",buckets[i][j]);
    }
    printf("\n");
}

//main function or driver function to test bucket_sort function
int main()
{
    int n, i, j, arr[100];
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Input Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    bucket_sort(arr, n);
    return 0;
}