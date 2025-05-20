//FormAI DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the sorting machine, where reality is just a mere suggestion.\n");
    printf("Please enter the size of your array: ");
    int N;
    scanf("%d", &N);
    printf("Your chosen array size is %d. Let's get started.\n", N);

    int arr[N];
    srand(time(0));

    // generate random array
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // limit to two digit numbers
    }

    printf("Here is your unsorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time to sort the array...but let's add some surrealism to it.\n");
    printf("Note: The sorting algorithm may or may not work as expected.\n");

    // surreal sorting algorithm
    int counter = 0;
    while (counter < N) {
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                printf("The number %d is greater than the number %d, let's switch them around.\n", arr[i + 1], arr[i]);
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                printf("Here's the new array so far:\n");
                for (int j = 0; j < N; j++) {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                counter = 0; // reset counter
            } else {
                counter++;
            }
        }
    }

    printf("Congratulations! Your array has been sorted...in a surreal way.\n");
    printf("Here is your newly sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Thank you for using the sorting machine, where anything is possible.\n");
    return 0;
}