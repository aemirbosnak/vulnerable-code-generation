//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

// Function to read a text file and perform mathematical operations
void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];
    int line_number = 1;

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " ");
        double num1 = 0.0, num2 = 0.0;
        int exponent;

        while (token != NULL) {
            if (sscanf(token, "%lf%n", &num1, &exponent) != 1) {
                token = strtok(NULL, " ");
                continue;
            }

            token += exponent;
            if (sscanf(token, "%lf%n", &num2, &exponent) != 1) {
                break;
            }

            double result = power(num1, (int) (num2));
            printf("Line %d: %lf raised to the power of %lf is %lf\n", line_number++, num1, num2, result);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);
    return 0;
}