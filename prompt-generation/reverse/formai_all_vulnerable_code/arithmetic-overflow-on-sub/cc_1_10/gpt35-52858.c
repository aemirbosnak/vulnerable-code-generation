//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void BubbleSort(int[], int);
void SelectionSort(int[], int);
void InsertionSort(int[], int);
void PrintArray(int[], int);

int main()
{
    int arr1[100], arr2[100], arr3[100];
    int n, i;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    srand(time(0));

    printf("\nElements to be sorted: \n");

    for(i=0;i<n;i++)
    {
        arr1[i] = rand()%1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        printf("%d ", arr1[i]);
    }

    printf("\n\nBubble Sort Output:\n");
    BubbleSort(arr1, n);

    printf("\nSelection Sort Output:\n");
    SelectionSort(arr2, n);

    printf("\nInsertion Sort Output:\n");
    InsertionSort(arr3, n);

    return 0;
}

void BubbleSort(int a[], int n)
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

    PrintArray(a, n);
}

void SelectionSort(int a[], int n)
{
    int i, j, temp, min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
        }
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }

    PrintArray(a, n);
}

void InsertionSort(int a[], int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;

        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=temp;
    }

    PrintArray(a, n);
}

void PrintArray(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}