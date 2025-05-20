//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10];
    int n, i, j, temp;

    printf("Hello there! I am a cheerful sorting program. Let's sort some numbers!\n");
    printf("How many numbers would you like to sort? Please enter a number between 2 and 10: ");
    scanf("%d", &n);

    if (n < 2 || n > 10) {
        printf("Oops! That is an invalid input. Please run the program again and enter a valid number between 2 and 10.\n");
        return 0;
    }

    printf("Great! Please enter %d numbers one by one: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nAwesome! Here are your unsorted numbers: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nNow, let's sort them using bubble sort algorithm.");

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n\nHere are your sorted numbers: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nYay! We did it. Hope you enjoyed sorting your numbers with me. Have a nice day!\n");

    return 0;
}