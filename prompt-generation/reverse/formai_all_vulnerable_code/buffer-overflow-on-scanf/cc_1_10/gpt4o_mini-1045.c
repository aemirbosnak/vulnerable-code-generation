//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void printGreeting() {
    printf("🎉 Welcome to the Cheerful Number Searcher! 🎉\n");
    printf("Let's find your favorite number among your listed favorites!\n");
}

void printGoodbye() {
    printf("🤗 Thank you for using the Cheerful Number Searcher! Goodbye!\n");
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key was found
        }
    }
    return -1; // If not found, return -1
}

void performSearch() {
    int arraySize;

    printf("\nHow many favorite numbers would you like to provide? ");
    scanf("%d", &arraySize);

    if (arraySize <= 0) {
        printf("🙁 Please provide a positive number of favorite numbers!\n");
        return;
    }

    int *favoriteNumbers = (int*)malloc(arraySize * sizeof(int));
    if (favoriteNumbers == NULL) {
        printf("😱 Oops! Memory allocation failed. Please try again later!\n");
        return;
    }

    printf("🌟 Please enter your %d favorite numbers: \n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("Favorite number %d: ", i + 1);
        scanf("%d", &favoriteNumbers[i]);
    }

    int searchKey;
    printf("💡 Now, what number would you like to search for? ");
    scanf("%d", &searchKey);

    int result = linearSearch(favoriteNumbers, arraySize, searchKey);

    if (result != -1) {
        printf("🎈 Hooray! The number %d is found at index %d! 🎈\n", searchKey, result);
    } else {
        printf("😢 Unfortunately, the number %d is not in your favorites. Keep searching! 🌈\n", searchKey);
    }

    free(favoriteNumbers); // Free the allocated memory
}

int main() {
    printGreeting();

    char continueSearching = 'y';
    while (continueSearching == 'y' || continueSearching == 'Y') {
        performSearch();

        printf("🤔 Would you like to search again? (y/n): ");
        scanf(" %c", &continueSearching);
    }

    printGoodbye();
    return 0;
}