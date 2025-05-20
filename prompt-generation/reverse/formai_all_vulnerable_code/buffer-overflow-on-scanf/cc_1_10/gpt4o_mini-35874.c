//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

// Function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print stars
void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}

// Function to print the upper part of the diamond
void printUpperDiamond(int height) {
    for (int i = 0; i < height; i++) {
        printSpaces(height - i - 1);
        printStars(2 * i + 1);
        printf("\n");
    }
}

// Function to print the lower part of the diamond
void printLowerDiamond(int height) {
    for (int i = height - 1; i > 0; i--) {
        printSpaces(height - i);
        printStars(2 * i - 1);
        printf("\n");
    }
}

// Function to print complete diamond
void printDiamond(int height) {
    printUpperDiamond(height);
    printLowerDiamond(height);
}

// Function to get height from the user
int getHeightFromUser() {
    int height;
    printf("Enter the height of the diamond (an integer greater than 0): ");
    scanf("%d", &height);
    return height;
}

// Function to validate height
int validateHeight(int height) {
    if (height > 0) {
        return 1; // valid height
    }
    return 0; // invalid height
}

// Main function - entry point of the program
int main() {
    int height;

    height = getHeightFromUser();

    // Validate the user input
    while (!validateHeight(height)) {
        printf("Please enter a valid height (greater than 0): ");
        scanf("%d", &height);
    }

    printf("\nHere is your diamond pattern:\n\n");
    printDiamond(height);

    return 0;
}