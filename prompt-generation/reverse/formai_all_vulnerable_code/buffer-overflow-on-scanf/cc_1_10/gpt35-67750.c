//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

//Function to sort using bucket sort algorithm
void bucketSort(int arr[], int n)
{
    //Creating a bucket of size 101, because why not?
    int bucket[101][n];
    int count[101] = {0};
 
    // Identifying the range of values present in the array
    int min_val = arr[0];
    int max_val = arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i] < min_val)
            min_val = arr[i];
        else if (arr[i] > max_val)
            max_val = arr[i];
    }
    int range = (max_val - min_val) / 100 + 1;
 
    //Putting elements to be sorted into their respective buckets
    for (int i=0; i<n; i++)
    {
        int j = (arr[i] - min_val) / range;
        bucket[j][count[j]] = arr[i];
        count[j]++;
    }
 
    //Sorting elements in each bucket using Insertion Sort, you can disagree but tell me which is easy?
    for (int i=0; i<101; i++)
    {
        for (int j=0; j<count[i]; j++)
        {
            int k;
            int temp = bucket[i][j];
            for (k=j; k>0 && temp<bucket[i][k-1]; k--)
                bucket[i][k] = bucket[i][k-1];
            bucket[i][k] = temp;
        }
    }
 
    //Putting sorted elements into the original array
    int index = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = bucket[i][j];
}

//Just a funny main function, nothing special, really!
int main()
{
    printf("Welcome to the Bucket Sort festival!!!\n\n");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements (between 0 and 100): ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] < 0 || arr[i] > 100) //We must abide by the rules set!
        {
            printf("Oops! Invalid input. Enter numbers between 0 and 100 only.\n");
            exit(0);
        }
    }
    printf("\nSorting using the mighty bucket sort algorithm...\n\n");
    bucketSort(arr, n);
    printf("Bucket-sorting complete! Here's your sorted array: \n\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\nBucket Sort has done its duty, another successful mission for our army!\n");
    return 0;
}