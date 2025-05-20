//Falcon-180B DATASET v1.0 Category: Data mining ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of each data point
typedef struct {
    int id;
    char name[50];
    int age;
    double salary;
} DataPoint;

// Function to load data from a CSV file
int load_data(char* filename, DataPoint* data, int max_rows) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    int row_count = 0;
    while (row_count < max_rows && fscanf(fp, "%d,%s,%d,%lf\n", &data[row_count].id, data[row_count].name, &data[row_count].age, &data[row_count].salary) == 4) {
        row_count++;
    }

    fclose(fp);
    return 0;
}

// Function to sort the data by salary in descending order
void sort_data(DataPoint* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[j].salary > data[i].salary) {
                DataPoint temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Function to print the top 10 highest paid employees
void print_top_10(DataPoint* data, int n) {
    printf("Top 10 highest paid employees:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d. %s (%d years old) - $%.2lf\n", i + 1, data[i].name, data[i].age, data[i].salary);
    }
}

int main() {
    const int MAX_ROWS = 1000;
    DataPoint data[MAX_ROWS];

    // Load data from a CSV file
    load_data("employees.csv", data, MAX_ROWS);

    // Sort the data by salary in descending order
    sort_data(data, MAX_ROWS);

    // Print the top 10 highest paid employees
    print_top_10(data, MAX_ROWS);

    return 0;
}