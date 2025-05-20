//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_NUMBERS 100
#define ERROR_LOG "error_log.txt"

void log_error(const char *message) {
    FILE *log_file = fopen(ERROR_LOG, "a");
    if (log_file) {
        fprintf(log_file, "Error: %s\n", message);
        fclose(log_file);
    } else {
        perror("Unable to open error log");
    }
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    log_error(message);
}

int read_numbers(const char *filename, int *numbers, size_t *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error("File not found or cannot be opened");
        return -1;
    }

    size_t n = 0;
    while (n < MAX_NUMBERS && fscanf(file, "%d", &numbers[n]) == 1) {
        n++;
    }

    if (ferror(file)) {
        handle_error("Error reading numbers from file");
        fclose(file);
        return -1;
    }

    fclose(file);
    *count = n;
    return 0;
}

double calculate_average(int *numbers, size_t count) {
    if (count == 0) {
        handle_error("Division by zero, no numbers to average");
        return 0.0; // Return 0.0, but log error
    }

    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return (double)sum / count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        handle_error("Usage: ./error_handling_program <filename>");
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int numbers[MAX_NUMBERS];
    size_t count = 0;

    if (read_numbers(filename, numbers, &count) != 0) {
        return EXIT_FAILURE;
    }

    double average = calculate_average(numbers, count);
    if (count > 0) {
        printf("Sum: %d, Average: %.2f\n", 
               (int) (average * count), average);
    } else {
        printf("No numbers provided to calculate.\n");
    }

    return EXIT_SUCCESS;
}