//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBERS 100

// Function declarations
void displayMenu();
void addNumber(float* numbers, int* count);
void displayNumbers(float* numbers, int count);
void calculateAverage(float* numbers, int count);
void findMax(float* numbers, int count);
void findMin(float* numbers, int count);
void sortNumbers(float* numbers, int count);
void clearBuffer();

int main() {
    float numbers[MAX_NUMBERS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to Exit: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            case 1:
                addNumber(numbers, &count);
                break;
            case 2:
                displayNumbers(numbers, count);
                break;
            case 3:
                calculateAverage(numbers, count);
                break;
            case 4:
                findMax(numbers, count);
                break;
            case 5:
                findMin(numbers, count);
                break;
            case 6:
                sortNumbers(numbers, count);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Number Management Program ---\n");
    printf("1. Add a number\n");
    printf("2. Display all numbers\n");
    printf("3. Calculate average\n");
    printf("4. Find maximum number\n");
    printf("5. Find minimum number\n");
    printf("6. Sort numbers\n");
}

// Function to add a number to the array
void addNumber(float* numbers, int* count) {
    if (*count < MAX_NUMBERS) {
        float number;
        printf("Enter a number to add: ");
        scanf("%f", &number);
        clearBuffer();
        numbers[*count] = number;
        (*count)++;
        printf("Number %.2f added successfully!\n", number);
    } else {
        printf("Cannot add more numbers. Maximum limit reached.\n");
    }
}

// Function to display all numbers
void displayNumbers(float* numbers, int count) {
    if (count == 0) {
        printf("No numbers to display.\n");
        return;
    }
    printf("Numbers list:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
}

// Function to calculate and display the average
void calculateAverage(float* numbers, int count) {
    if (count == 0) {
        printf("No numbers to calculate average.\n");
        return;
    }
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    printf("Average of the numbers is: %.2f\n", sum / count);
}

// Function to find and display the maximum number
void findMax(float* numbers, int count) {
    if (count == 0) {
        printf("No numbers to find the maximum.\n");
        return;
    }
    float max = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("The maximum number is: %.2f\n", max);
}

// Function to find and display the minimum number
void findMin(float* numbers, int count) {
    if (count == 0) {
        printf("No numbers to find the minimum.\n");
        return;
    }
    float min = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("The minimum number is: %.2f\n", min);
}

// Function to sort and display the numbers
void sortNumbers(float* numbers, int count) {
    if (count == 0) {
        printf("No numbers to sort.\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                float temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    printf("Numbers sorted successfully.\n");
    displayNumbers(numbers, count);
}

// Clear input buffer to avoid unwanted characters in input
void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}