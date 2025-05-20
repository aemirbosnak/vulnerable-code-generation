//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 10

// Function to generate a random integer between 1 and 10
int get_random_int(void) {
    return (rand() % 10) + 1;
}

// Function to print a pattern of asterisks based on a given length
void print_pattern(int length) {
    for (int i = 0; i < length; i++) {
        printf("* ");
    }
    printf("\n");
}

// Function to print a statistical report of the pattern
void print_stats(int length) {
    int avg_length = length;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < length; i++) {
        sum += get_random_int();
        count++;
    }

    avg_length = sum / count;

    printf("Statistical Report for Pattern of Length %d:\n", length);
    printf("Average Length: %d\n", avg_length);
    printf("Sum: %d\n", sum);
    printf("Count: %d\n", count);
}

int main() {
    int length;

    // Get the length of the pattern from the user
    printf("Enter the length of the pattern: ");
    scanf("%d", &length);

    // Print the pattern
    print_pattern(length);

    // Print the statistical report
    print_stats(length);

    return 0;
}