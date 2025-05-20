//Falcon-180B DATASET v1.0 Category: Error handling ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Function to check if the given string is a valid integer or not
int isInteger(char *str)
{
    int i, len = strlen(str);

    for(i=0; i<len; i++)
    {
        if(!isdigit(str[i]))
        {
            printf("Error: Invalid input\n");
            exit(0);
        }
    }

    return 1;
}

//Function to swap two elements of an array
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Function to sort an array in ascending order using bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//Function to find the median of an array
double findMedian(int arr[], int n)
{
    int i;
    double median;

    if(n%2 == 0)
    {
        median = (arr[n/2] + arr[n/2-1])/2.0;
    }
    else
    {
        median = arr[n/2];
    }

    return median;
}

int main()
{
    int n, i, arr[MAX];
    char str[MAX];

    //Taking input from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%s", str);

        //Checking if the input is a valid integer or not
        if(!isInteger(str))
        {
            printf("Error: Invalid input\n");
            exit(0);
        }

        arr[i] = atoi(str);
    }

    //Sorting the array in ascending order
    bubbleSort(arr, n);

    //Finding the median of the array
    double median = findMedian(arr, n);

    //Displaying the sorted array and the median
    printf("Sorted array in ascending order:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMedian of the array: %.2f\n", median);

    return 0;
}