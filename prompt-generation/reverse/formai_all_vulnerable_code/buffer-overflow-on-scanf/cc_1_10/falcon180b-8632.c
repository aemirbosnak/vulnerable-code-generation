//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the maximum size of the pattern
#define MAX_SIZE 50

// Function to print the pattern
void print_pattern(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random pattern of given size
void generate_random_pattern(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (get_random_number(0, 1) == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size;

    // Get the size of the pattern from the user
    printf("Enter the size of the pattern (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check if the size is valid
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    // Print the pattern
    print_pattern(size);

    // Generate a random pattern
    printf("\nRandom Pattern:\n");
    generate_random_pattern(size);

    return 0;
}