//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000
#define MAX_VALUE 1000

// Function to generate a random number between MIN_VALUE and MAX_VALUE
int get_random_number() {
    return (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

// Function to print a unique pattern
void print_pattern(int size) {
    int i, j, k;
    char pattern[size];

    // Initialize the pattern with random values
    for (i = 0; i < size; i++) {
        pattern[i] = get_random_number() % 2 ? 'X' : 'O';
    }

    // Print the pattern in a spiral manner
    for (j = 0; j < size / 2; j++) {
        for (k = 0; k < size - j * 2; k++) {
            if (k % 2 == 0) {
                printf("%c", pattern[k]);
            } else {
                printf("%c%c", pattern[k], pattern[k + 1]);
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    // Ask the user for the size of the pattern
    printf("Enter the size of the pattern (1-1024): ");
    scanf("%d", &size);

    // Print the unique pattern
    print_pattern(size);

    return 0;
}