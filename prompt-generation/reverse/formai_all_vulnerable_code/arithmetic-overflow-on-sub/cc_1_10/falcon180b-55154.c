//Falcon-180B DATASET v1.0 Category: Sorting ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SIZE 10

struct node
{
    int data;
    int priority;
};

void swap(struct node *x, struct node *y)
{
    struct node temp = *x;
    *x = *y;
    *y = temp;
}

int partition(struct node arr[], int low, int high)
{
    struct node pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].priority > pivot.priority)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct node arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(struct node arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i].data);
    }
}

int main()
{
    struct node arr[SIZE];
    int i, j, k, n, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].data);
        arr[i].priority = rand() % 100;
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array using Quick Sort:\n");
    printArray(arr, n);
    return 0;
}