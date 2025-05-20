//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void handle_memory_error(void);
void handle_file_error(FILE *file);
int read_numbers_from_file(const char *filename, int *array, int size);
void calculate_average(int *array, int num_elements, double *average);
void print_numbers(int *array, int num_elements);

int main() {
    int numbers[MAX_SIZE];
    int num_elements = 0;
    double average = 0.0;

    // Read numbers from the input file
    const char *filename = "numbers.txt";
    num_elements = read_numbers_from_file(filename, numbers, MAX_SIZE);

    // Handle file read error or no numbers read
    if (num_elements < 0) {
        fprintf(stderr, "Error reading from file: %s\n", filename);
        return EXIT_FAILURE;
    } else if (num_elements == 0) {
        fprintf(stderr, "No numbers found in the file.\n");
        return EXIT_FAILURE;
    }

    // Print the numbers read from the file
    printf("Numbers read from the file:\n");
    print_numbers(numbers, num_elements);

    // Calculate the average of the numbers
    calculate_average(numbers, num_elements, &average);
    printf("Average: %.2f\n", average);

    return EXIT_SUCCESS;
}

void handle_memory_error(void) {
    fprintf(stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
}

void handle_file_error(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Could not open file.\n");
        exit(EXIT_FAILURE);
    }
}

int read_numbers_from_file(const char *filename, int *array, int size) {
    FILE *file = fopen(filename, "r");
    handle_file_error(file);

    int num_elements = 0;
    while (num_elements < size && fscanf(file, "%d", &array[num_elements]) == 1) {
        num_elements++;
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file.\n");
        fclose(file);
        return -1; // Indicate error
    }

    fclose(file);
    return num_elements; // Return number of elements read
}

void calculate_average(int *array, int num_elements, double *average) {
    if (num_elements <= 0) {
        *average = 0.0; // Handle case where no elements
        return;
    }

    int sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += array[i];
    }
    *average = (double)sum / num_elements;
}

void print_numbers(int *array, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}