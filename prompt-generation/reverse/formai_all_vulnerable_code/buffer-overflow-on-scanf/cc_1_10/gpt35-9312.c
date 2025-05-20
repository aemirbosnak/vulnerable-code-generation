//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Welcome to my Bucket Sort!\n");
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number to sort!\n");
        return 0;
    }

    // Getting input elements
    int arr[n];
    printf("Enter %d elements to sort: ", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Creating buckets
    int maxVal = arr[0];
    for (int i=1; i<n; i++) {
        if (maxVal < arr[i]) {
            maxVal = arr[i];
        }
    }
    int bucket[maxVal+1];

    // Number of elements in each bucket
    for (int i=0; i<maxVal+1; i++) {
        bucket[i] = 0;
    }
    for (int i=0; i<n; i++) {
        bucket[arr[i]]++;
    }

    // Sorting elements
    int sortedArr[n];
    int index = 0;
    for (int i=0; i<maxVal+1; i++) {
        int count = bucket[i];
        while(count--) {
            sortedArr[index++] = i;
        }
    }

    printf("\nSorted list is: ");
    for (int i=0; i<n; i++) {
        printf("%d ", sortedArr[i]);
    }

    printf("\nHope you enjoyed the sorting process!");

    return 0;
}