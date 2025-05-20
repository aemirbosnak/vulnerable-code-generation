//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 500
#define MAX_LENGTH 256

// Structure to hold the data
typedef struct DataPoint {
    char category[MAX_LENGTH];
    float value;
} DataPoint;

// Function prototypes
void load_data(const char *filename, DataPoint data[], int *count);
void analyze_data(DataPoint data[], int count);
void print_summary(DataPoint data[], int count);

int main(int argc, char *argv[]) {
    // Check if the filename is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <datafile>\n", argv[0]);
        return 1;
    }

    DataPoint data[MAX_LINES];
    int count = 0;

    // Load data from the file
    load_data(argv[1], data, &count);

    // Analyze the loaded data
    analyze_data(data, count);

    // Print a summary of the analysis
    print_summary(data, count);

    return 0;
}

void load_data(const char *filename, DataPoint data[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(data[*count].category, MAX_LENGTH, file)) {
        data[*count].category[strcspn(data[*count].category, "\n")] = 0; // Remove trailing newline
        if (fscanf(file, "%f", &data[*count].value) != 1) {
            fprintf(stderr, "Error reading value for %s\n", data[*count].category);
            break;
        }
        (*count)++;
        if (*count >= MAX_LINES) break; // Avoid overflow
    }

    fclose(file);
}

void analyze_data(DataPoint data[], int count) {
    float sum = 0, max = -1e6, min = 1e6;
    int category_count = 0;
    char unique_categories[MAX_LINES][MAX_LENGTH];
    float category_sum[MAX_LINES] = {0};

    for (int i = 0; i < count; i++) {
        sum += data[i].value;
        if (data[i].value > max) max = data[i].value;
        if (data[i].value < min) min = data[i].value;

        // Check for unique categories
        int found = 0;
        for (int j = 0; j < category_count; j++) {
            if (strcmp(data[i].category, unique_categories[j]) == 0) {
                category_sum[j] += data[i].value;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique_categories[category_count], data[i].category);
            category_sum[category_count] += data[i].value;
            category_count++;
        }
    }

    printf("Data Analysis Complete:\n");
    printf("Total Sum: %.2f\n", sum);
    printf("Maximum Value: %.2f\n", max);
    printf("Minimum Value: %.2f\n", min);
    printf("Number of Unique Categories: %d\n", category_count);
}

void print_summary(DataPoint data[], int count) {
    printf("\nSummary of Data Points:\n");
    printf("Category\tValue\n");
    printf("-----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\n", data[i].category, data[i].value);
    }
    printf("-----------------------\n");
}