//Falcon-180B DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, count = 0, flag;
    int arr[10];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    k = rand() % n;

    printf("The original array is:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The sorted array is:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(i = 0; i < n; i++) {
        if(arr[i] == k) {
            count++;
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at position %d.\n", i+1);
    }

    return 0;
}