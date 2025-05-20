//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, input) != NULL) {
        char *line = strdup(buffer);
        if (line == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        char *value = strtok(line, " ");
        if (value == NULL) {
            fprintf(stderr, "Invalid input: %s\n", line);
            free(line);
            continue;
        }

        char *unit = strtok(NULL, " ");
        if (unit == NULL) {
            fprintf(stderr, "Invalid input: %s\n", line);
            free(line);
            continue;
        }

        if (strcmp(unit, "meters") == 0) {
            double meters = atof(value);
            double feet = meters * 3.28084;
            fprintf(output, "%.2f feet\n", feet);
        } else if (strcmp(unit, "feet") == 0) {
            double feet = atof(value);
            double meters = feet / 3.28084;
            fprintf(output, "%.2f meters\n", meters);
        } else if (strcmp(unit, "miles") == 0) {
            double miles = atof(value);
            double kilometers = miles * 1.60934;
            fprintf(output, "%.2f kilometers\n", kilometers);
        } else if (strcmp(unit, "kilometers") == 0) {
            double kilometers = atof(value);
            double miles = kilometers / 1.60934;
            fprintf(output, "%.2f miles\n", miles);
        } else {
            fprintf(stderr, "Invalid unit: %s\n", unit);
        }

        free(line);
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}