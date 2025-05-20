//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 100

int main() {
    int i, j, k, n;
    double a[MAX_LENGTH], b[MAX_LENGTH], c[MAX_LENGTH];
    char filename[MAX_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fscanf(input_file, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(input_file, "%lf %lf %lf", &a[i], &b[i], &c[i]);
    }

    fclose(input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    FILE *output_file = fopen(filename, "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) {
            fprintf(output_file, "The equation %lf * x^2 + %lf * x + %lf = 0 has no real roots.\n", a[i], b[i], c[i]);
        } else {
            double discriminant = b[i] * b[i] - 4 * a[i] * c[i];

            if (discriminant < 0) {
                fprintf(output_file, "The equation %lf * x^2 + %lf * x + %lf = 0 has no real roots.\n", a[i], b[i], c[i]);
            } else {
                double root1 = (-b[i] + sqrt(discriminant)) / (2 * a[i]);
                double root2 = (-b[i] - sqrt(discriminant)) / (2 * a[i]);

                fprintf(output_file, "The roots of the equation %lf * x^2 + %lf * x + %lf = 0 are: %lf and %lf\n", a[i], b[i], c[i], root1, root2);
            }
        }
    }

    fclose(output_file);

    return 0;
}