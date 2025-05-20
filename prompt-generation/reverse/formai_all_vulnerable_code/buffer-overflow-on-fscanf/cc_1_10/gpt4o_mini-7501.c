//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FEATURES 10
#define MAX_FIELD_SIZE 50

typedef struct {
    char features[MAX_FEATURES][MAX_FIELD_SIZE];
    float value; // E.g. for numerical data like sales figures, prices etc.
} Record;

void read_data(const char *filename, Record records[], int *num_records) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    *num_records = 0;
    while (*num_records < MAX_RECORDS && fscanf(file, "%[^,],%f\n", records[*num_records].features[0], &records[*num_records].value) == 2) {
        for (int i = 1; i < MAX_FEATURES; i++) {
            fscanf(file, "%[^,],", records[*num_records].features[i]);
        }
        (*num_records)++;
    }
    
    fclose(file);
}

void print_data(Record records[], int num_records) {
    printf("Loaded Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d: %s | Value: %.2f\n", i + 1, records[i].features[0], records[i].value);
        for (int j = 1; j < MAX_FEATURES; j++) {
            printf("Feature[%d]: %s ", j, records[i].features[j]);
        }
        printf("\n");
    }
}

void analyze_data(Record records[], int num_records) {
    float total_value = 0.0;
    for (int i = 0; i < num_records; i++) {
        total_value += records[i].value;
    }

    float average_value = total_value / num_records;
    printf("Total Value: %.2f\n", total_value);
    printf("Average Value: %.2f\n", average_value);
}

void filter_data(Record records[], int num_records, float threshold) {
    printf("Records with values higher than %.2f:\n", threshold);
    for (int i = 0; i < num_records; i++) {
        if (records[i].value > threshold) {
            printf("Record %d: %s | Value: %.2f\n", i + 1, records[i].features[0], records[i].value);
            for (int j = 1; j < MAX_FEATURES; j++) {
                printf("Feature[%d]: %s ", j, records[i].features[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    Record records[MAX_RECORDS];
    int num_records;

    const char *datafile = "data.txt"; // Replace with your data file path
    read_data(datafile, records, &num_records);
    
    print_data(records, num_records);
    analyze_data(records, num_records);
    
    float threshold;
    printf("Enter a value threshold for filtering: ");
    scanf("%f", &threshold);
    filter_data(records, num_records, threshold);

    return 0;
}