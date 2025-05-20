//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int i, n, *arr;
    
    printf("Greetings, esteemed user! Welcome to my Sorting program.\n");
    printf("Please input the number of elements you would like to sort: ");
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Oh dear, it seems there has been an error. Goodbye!");
        return 0;
    }
    
    printf("Excellent choice! Now, kindly enter the individual elements:\n");
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, n);
    
    printf("\nMarvelous! The sorted elements are as follows:\n");
    
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    printf("\nThank you for using my program. Have a wonderful day!");
    
    return 0;
}