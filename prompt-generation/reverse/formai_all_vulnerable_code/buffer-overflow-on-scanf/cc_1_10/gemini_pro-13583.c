//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// An array of happy numbers
int happy_numbers[] = {
    1, 7, 10, 13, 19, 23, 28, 31, 34, 44, 49, 58, 68, 70, 79, 82,
    86, 91, 94, 97, 100
};

// The size of the happy numbers array
int happy_numbers_size = sizeof(happy_numbers) / sizeof(happy_numbers[0]);

// Print a happy face
void print_happy_face() {
    printf(" :) ");
}

// Print a sad face
void print_sad_face() {
    printf(" :( ");
}

// Check if a number is happy
int is_happy(int number) {
    // Check if the number is in the happy numbers array
    for (int i = 0; i < happy_numbers_size; i++) {
        if (happy_numbers[i] == number) {
            return 1;
        }
    }

    // If the number is not in the happy numbers array, check if it is a happy number
    int sum_of_squares = 0;
    while (number > 0) {
        int digit = number % 10;
        sum_of_squares += digit * digit;
        number /= 10;
    }

    if (sum_of_squares == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Find the first happy number in a range of numbers
int find_first_happy_number(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (is_happy(i)) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    // Print a happy face
    print_happy_face();

    // Get the start and end of the range of numbers to search
    int start, end;
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    // Find the first happy number in the range
    int first_happy_number = find_first_happy_number(start, end);

    // Print the first happy number
    if (first_happy_number == -1) {
        printf("No happy numbers found in the range %d to %d\n", start, end);
        print_sad_face();
    } else {
        printf("The first happy number in the range %d to %d is %d\n", start, end, first_happy_number);
        print_happy_face();
    }

    return 0;
}