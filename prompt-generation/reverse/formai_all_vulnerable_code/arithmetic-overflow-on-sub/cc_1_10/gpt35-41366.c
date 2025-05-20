//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void quick_sort(int arr[], int lo, int hi);
int binary_search(int arr[], int target, int lo, int hi);

int main(void)
{
    int arr[MAX_SIZE];
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    quick_sort(arr, 0, n - 1);

    int index = binary_search(arr, target, 0, n - 1);

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    return 0;
}

void quick_sort(int arr[], int lo, int hi)
{
    if (lo < hi) {
        int i = lo;
        int j = hi;
        int pivot = arr[(lo + hi) / 2];

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
                j--;
            }
        }

        quick_sort(arr, lo, j);
        quick_sort(arr, i, hi);
    }
}

int binary_search(int arr[], int target, int lo, int hi)
{
    if (lo > hi) {
        return -1;
    }

    int mid = (lo + hi) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binary_search(arr, target, lo, mid - 1);
    } else {
        return binary_search(arr, target, mid + 1, hi);
    }
}