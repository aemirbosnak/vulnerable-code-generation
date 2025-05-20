//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

//Function to initialize the array with random values
void init_array(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

//Function to print the array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Function to sort the array using bitwise operations
void bitwise_sort(int arr[], int size)
{
    int mask = 0x1;
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if ((arr[j] & mask) > (arr[j + 1] & mask))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        mask <<= 1;
    }
}

//Main function
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[MAX_SIZE];
    init_array(arr, size);
    print_array(arr, size);

    bitwise_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}