//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "numbers.txt"

// Function prototypes
void printError(const char *msg);
int readIntegerFromFile(const char *filename);
void processInteger(int value);

int main() {
    int value;

    value = readIntegerFromFile(FILENAME);
    if (value == -1) {
        printError("Failed to read integer from file.");
        return EXIT_FAILURE;
    }

    processInteger(value);

    return EXIT_SUCCESS;
}

void printError(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int readIntegerFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printError("Could not open the file.");
        return -1;
    }

    int value;
    if (fscanf(file, "%d", &value) != 1) {
        printError("Failed to read an integer from the file. Check file format.");
        fclose(file);
        return -1;
    }

    fclose(file);
    return value;
}

void processInteger(int value) {
    if (value < 0) {
        printError("The number is negative. Will not proceed.");
        return;
    }

    printf("Processing number: %d\n", value);
    if (value % 2 == 0) {
        printf("%d is an even number.\n", value);
    } else {
        printf("%d is an odd number.\n", value);
    }

    int factorial = 1;
    for (int i = 1; i <= value; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %d.\n", value, factorial);
}

void handleFileError(FILE *file) {
    if (file) {
        fclose(file);
    }
    printError("An IOError occurred while dealing with the file.");
}

int readMultipleIntegersFromFile(const char *filename, int *arr, size_t *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    size_t count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1) {
        count++;
        if (count >= *size) {
            break; // Prevents buffer overflow
        }
    }

    *size = count;
    fclose(file);
    return 0;
}

void processMultipleIntegers(int *arr, size_t size) {
    if (size == 0) {
        printError("No integers to process.");
        return;
    }

    for (size_t i = 0; i < size; i++) {
        processInteger(arr[i]);
    }
}

int mainAdvanced() {
    const size_t maxIntegers = 100;
    int integers[maxIntegers];
    size_t size = maxIntegers;

    if (readMultipleIntegersFromFile(FILENAME, integers, &size) != 0) {
        printError("Error reading multiple integers from file.");
        return EXIT_FAILURE;
    }

    processMultipleIntegers(integers, size);

    return EXIT_SUCCESS;
}