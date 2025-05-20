//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void shocked_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("\n%s%s%s", "\033[1;31m", "OMG!", "\033[0m");
    printf("Swapping %d with %d!\n", *a, *b);
}

void shocked_bubble_sort(int arr[], int n) {
    int i, j, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                shocked_swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
    }
}

int main() {
    int arr[MAX];
    int i, n;

    srand(time(NULL));

    printf("\n%s%s%s", "\033[1;31m", "Are you ready for a shocked sorting experience?", "\033[0m");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\n%s%s%s", "\033[1;31m", "Generating random numbers...", "\033[0m");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("\n%s%d%s", "\033[1;31m", arr[i], "\033[0m");
    }

    printf("\n%s%s%s", "\033[1;31m", "Now, let's sort these numbers in shocked way!", "\033[0m");
    shocked_bubble_sort(arr, n);

    printf("\n%s%s%s", "\033[1;31m", "Here is the sorted array:", "\033[0m");
    for (i = 0; i < n; i++) {
        printf("\n%s%d%s", "\033[1;31m", arr[i], "\033[0m");
    }

    return 0;
}