//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define FILENAME "numbers.txt"

// Function prototypes
void read_numbers_from_file(const char *filename, int *numbers, int *count);
void process_numbers(int *numbers, int count);
void handle_error(const char *message);

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;

    // Read numbers from the file
    read_numbers_from_file(FILENAME, numbers, &count);

    // Process the numbers
    process_numbers(numbers, count);

    return 0;
}

void read_numbers_from_file(const char *filename, int *numbers, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Could not open the input file");
    }

    while (*count < MAX_NUMBERS && fscanf(file, "%d", &numbers[*count]) == 1) {
        (*count)++;
    }

    if (!feof(file) && ferror(file)) {
        fclose(file);
        handle_error("Error reading from the input file");
    }

    fclose(file);
    printf("Successfully read %d numbers from %s.\n", *count, filename);
}

void process_numbers(int *numbers, int count) {
    if (count <= 0) {
        handle_error("No numbers to process.");
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    double average = (double)sum / count;

    printf("Processed %d numbers:\n", count);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    // Additional processing example: find max and min
    int max = numbers[0];
    int min = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}