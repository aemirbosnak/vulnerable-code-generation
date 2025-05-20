//Falcon-180B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE *file;
    char filename[100];
    char line[100];
    char delimiter = ',';
    int count = 0;
    int max_count = 10;
    int numbers[max_count];

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        count++;
        if (count > max_count) {
            printf("Error: too many lines in file\n");
            exit(1);
        }
        // Parse line into numbers
        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (count >= max_count) {
                printf("Error: too many numbers in line\n");
                exit(1);
            }
            numbers[count] = atoi(token);
            count++;
            token = strtok(NULL, &delimiter);
        }
    }

    // Close file
    fclose(file);

    // Calculate sum of numbers
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    // Print results
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", (float)sum / count);

    return 0;
}