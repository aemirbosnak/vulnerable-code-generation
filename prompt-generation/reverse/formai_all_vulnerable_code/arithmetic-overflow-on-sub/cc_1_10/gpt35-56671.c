//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>

#define MAX 100

// Function to swap two numbers
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Greedy algorithm to find the minimum sum
int min_sum(int arr[], int n)
{
    int sum = 0;
    
    // Sort the array in ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
        }
    }

    // Assign alternate numbers to two groups and find their sum
    for(int i=0;i<n;i+=2)
    {
        int x = arr[i];
        int y = arr[i+1];
        if(i+1 >= n)
        {
            y = 0;
        }
        sum += (x+y);
    }
    return sum;
}

int main()
{
    int n, arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = min_sum(arr,n);
    printf("The minimum sum is: %d\n",sum);
    return 0;
}