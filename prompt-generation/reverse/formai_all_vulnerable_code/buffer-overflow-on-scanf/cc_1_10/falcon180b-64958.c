//Falcon-180B DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle an array
void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand_num(0, n - 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Before shuffling
    printf("Before shuffling:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Shuffle the array
    shuffle(arr, n);

    // After shuffling
    printf("After shuffling:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}