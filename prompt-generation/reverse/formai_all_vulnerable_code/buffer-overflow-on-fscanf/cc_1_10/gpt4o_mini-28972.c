//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 256

typedef struct {
    int id;
    char name[MAX_LENGTH];
    float value;
} Record;

void load_data(const char *filename, Record records[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%d,%255[^,],%f", &records[*count].id, records[*count].name, &records[*count].value) != EOF) {
        (*count)++;
        if (*count >= MAX_RECORDS) {
            printf("Maximum record limit reached.\n");
            break;
        }
    }

    fclose(file);
}

void display_data(const Record records[], int count) {
    printf("ID\tName\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].value);
    }
}

float calculate_average_value(const Record records[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += records[i].value;
    }
    return sum / count;
}

void filter_by_value(const Record records[], int count, float threshold) {
    printf("\nRecords with value above %.2f:\n", threshold);
    printf("ID\tName\tValue\n");
    for (int i = 0; i < count; i++) {
        if (records[i].value > threshold) {
            printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].value);
        }
    }
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;

    // Load data from CSV (id,name,value)
    load_data("data.csv", records, &count);

    // Display all loaded data
    display_data(records, count);

    // Calculate and display average value
    float average = calculate_average_value(records, count);
    printf("\nAverage value: %.2f\n", average);

    // Filter records by a specific threshold
    float threshold = average; // filter above average for demonstration
    filter_by_value(records, count, threshold);

    return 0;
}