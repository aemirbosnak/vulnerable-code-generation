//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
// In the wasteland, even our data structures must fight for survival.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A mutated version of the classic bubble sort algorithm, designed to survive the apocalypse.
void postApocalypticBubbleSort(int* arr, int size) {
    int mutated = 1; // The apocalypse has changed our ways.
    while (mutated) {
        mutated = 0; // Assume we're done.
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) { // Brutality prevails.
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                mutated = 1; // The wasteland is relentless.
            }
        }
    }
}

// In a world gone to ruin, even our print statements must adapt.
void printArray(int* arr, int size) {
    printf("From the ashes of civilization:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// The wasteland is unforgiving, and so are our testing routines.
void testSorting() {
    int size;
    printf("Enter the size of your scavenged data set: \n");
    scanf("%d", &size);
    
    int* arr = (int*)malloc(size * sizeof(int));
    
    // Seed our random number generator with the chaos of the apocalypse.
    time_t seed = time(0);
    srand(seed);
    
    // Generate a set of mutated data to sort.
    printf("Generating a radioactive data set:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    printArray(arr, size);
    postApocalypticBubbleSort(arr, size);
    printf("Sorted data, ready for the taking:\n");
    printArray(arr, size);
    
    free(arr);
}

int main() {
    printf("Welcome to the post-apocalyptic sorting facility.\n");
    
    testSorting();
    
    return 0;
}