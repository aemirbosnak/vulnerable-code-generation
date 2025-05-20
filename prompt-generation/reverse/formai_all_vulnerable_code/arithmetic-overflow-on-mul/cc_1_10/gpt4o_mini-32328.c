//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

void printSpiral(int size) {
    int arr[size][size]; // Create a 2D array for the spiral pattern
    int left = 0, right = size - 1, top = 0, bottom = size - 1; // Define boundaries
    int num = 1; // Starting number to fill in the spiral

    // Fill the array in spiral order
    while (num <= size * size) {
        for (int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            arr[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            arr[i][left] = num++;
        }
        left++;
    }

    // Print the spiral pattern
    printf("Here is your Spiral Pattern of Size %d:\n\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", arr[i][j]); // Print each number
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Get the size of the spiral from the user
    printf("✨ Welcome to the Spiral Pattern Generator! ✨\n");
    printf("Enter the size of the spiral (odd number preferred for better effect): ");
    scanf("%d", &size);

    // Validate input size
    if (size < 1) {
        printf("❌ Size must be a positive integer! Please try again.\n");
        return 1; // Exit with an error code
    }

    // Call the function to print the spiral pattern
    printSpiral(size);

    printf("\n🎉 Thank you for using the Spiral Pattern Generator! 🎉\n");
    return 0; // Exit success
}