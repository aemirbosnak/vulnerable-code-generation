//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define FILENAME "grades.txt"

// Function declarations
void readGrades(float grades[], int *count);
void calculateStatistics(float grades[], int count, float *average, float *highest, float *lowest, int *passedCount, int *failedCount);
void printStatistics(float average, float highest, float lowest, int passed, int failed);

int main() {
    float grades[MAX_STUDENTS];
    int count = 0;
    float average = 0.0, highest = 0.0, lowest = 100.0;
    int passedCount = 0, failedCount = 0;

    // Step 1: Read grades from a file
    readGrades(grades, &count);

    // Step 2: Calculate statistics
    calculateStatistics(grades, count, &average, &highest, &lowest, &passedCount, &failedCount);

    // Step 3: Print statistics
    printStatistics(average, highest, lowest, passedCount, failedCount);

    return 0;
}

void readGrades(float grades[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%f", &grades[*count]) != EOF && *count < MAX_STUDENTS) {
        (*count)++;
    }
    
    fclose(file);
}

void calculateStatistics(float grades[], int count, float *average, float *highest, float *lowest, int *passedCount, int *failedCount) {
    float sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += grades[i];
        if (grades[i] > *highest) {
            *highest = grades[i];
        }
        if (grades[i] < *lowest) {
            *lowest = grades[i];
        }

        if (grades[i] >= 60) {
            (*passedCount)++;
        } else {
            (*failedCount)++;
        }
    }

    if (count > 0) {
        *average = sum / count;
    }
}

void printStatistics(float average, float highest, float lowest, int passed, int failed) {
    printf("Grade Statistics:\n");
    printf("Average grade: %.2f\n", average);
    printf("Highest grade: %.2f\n", highest);
    printf("Lowest grade: %.2f\n", lowest);
    printf("Number of students passed: %d\n", passed);
    printf("Number of students failed: %d\n", failed);
}