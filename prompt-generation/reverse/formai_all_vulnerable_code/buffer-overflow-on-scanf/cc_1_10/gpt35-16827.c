//FormAI DATASET v1.0 Category: Scientific ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void reverseArray(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int getSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

float getAverage(int arr[], int size)
{
    float sum = getSum(arr, size);
    return sum / size;
}

int main()
{
    int arr[MAX_SIZE], size, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Select an operation:\n");
    printf("1. Reverse Array\n");
    printf("2. Print Sum of Elements\n");
    printf("3. Print Maximum Element\n");
    printf("4. Print Minimum Element\n");
    printf("5. Print Average of Elements\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        reverseArray(arr, size);
        printf("Reversed Array: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    case 2:
        printf("Sum of Elements: %d", getSum(arr, size));
        break;
    case 3:
        printf("Maximum Element: %d", getMax(arr, size));
        break;
    case 4:
        printf("Minimum Element: %d", getMin(arr, size));
        break;
    case 5:
        printf("Average of Elements: %.2f", getAverage(arr, size));
        break;
    default:
        printf("Invalid Choice!");
        break;
    }

    return 0;
}