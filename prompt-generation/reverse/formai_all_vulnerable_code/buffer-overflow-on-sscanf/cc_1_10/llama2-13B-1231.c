//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 1000
#define MAX_FEATURES 10

// Structure to store a single record
typedef struct {
    int age;
    int income;
    char gender[10];
    char education[10];
} record_t;

// Array to store all records
record_t records[MAX_RECORDS];

// Function to read records from a file
void read_records(const char* file_name) {
    FILE* file = fopen(file_name, "r");
    char line[100];
    int i = 0;

    while (fgets(line, 100, file) != NULL) {
        // Parse the line and store the values in the record structure
        sscanf(line, "%d %d %s %s", &records[i].age, &records[i].income, records[i].gender, records[i].education);
        i++;
    }

    fclose(file);
}

// Function to calculate the average income for each gender
void calculate_average_income(const char* file_name) {
    int i = 0;
    int total_income = 0;
    char gender[10];

    // Read records from the file
    read_records(file_name);

    // Calculate the average income for each gender
    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(records[i].gender, "Male") == 0) {
            total_income += records[i].income;
        } else if (strcmp(records[i].gender, "Female") == 0) {
            total_income += records[i].income;
        }
    }

    // Print the average income for each gender
    printf("Average income for Male: %d\n", total_income / (int)strcspn(records[i].gender, "Male"));
    printf("Average income for Female: %d\n", total_income / (int)strcspn(records[i].gender, "Female"));
}

int main() {
    calculate_average_income("data.txt");
    return 0;
}