//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    printf("🎉 Starting the Bubble Sort! 🎉\n");
    
    for (i = 0; i < n - 1; i++) {
        printf("🐢 Pass %d: [", i + 1);
        for (j = 0; j < n; j++) {
            printf(" %d", arr[j]);
        }
        printf(" ]\n");

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("✨ Swapped %d and %d! ✨\n", arr[j], arr[j + 1]);
            }
        }
    }
    printf("🏁 Sorting Complete! The sorted array is: [");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}

// Function to get user input for array
void getInput(int arr[], int n) {
    printf("🤗 Let's create your array! How many elements? ");
    scanf("%d", &n);
    printf("🎈 Now, please enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int arr[100]; // Array to hold the elements
    int n = 0;    // Number of elements

    getInput(arr, n); // Call the function to get user input
    bubbleSort(arr, n); // Call the bubble sort function

    printf("🎊 Thank you for using the Bubble Sort program! 🎊\n");
    return 0;
}