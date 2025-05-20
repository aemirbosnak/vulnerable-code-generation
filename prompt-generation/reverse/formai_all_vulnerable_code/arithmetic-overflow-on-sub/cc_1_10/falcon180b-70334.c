//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000

int main() {
    int numbers[MAX_NUMBERS];
    int i, j;
    int temp;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}