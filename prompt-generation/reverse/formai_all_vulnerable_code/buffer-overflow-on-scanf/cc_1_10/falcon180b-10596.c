//Falcon-180B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the data structure for each data point
typedef struct {
    int id;
    char name[50];
    int age;
    int income;
} DataPoint;

// Function to compare two data points based on their income
int compare(const void *a, const void *b) {
    DataPoint *p1 = (DataPoint *)a;
    DataPoint *p2 = (DataPoint *)b;
    return (p1->income - p2->income);
}

// Function to print the data points
void printData(DataPoint data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Income: %d\n", data[i].id, data[i].name, data[i].age, data[i].income);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for the data points
    DataPoint data[n];

    // Read the data points from the user
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d", &data[i].id, data[i].name, &data[i].age, &data[i].income);
    }

    // Sort the data points based on their income
    qsort(data, n, sizeof(DataPoint), compare);

    // Print the sorted data points
    printf("Sorted Data:\n");
    printData(data, n);

    // Find the median income
    int medianIncome = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].income == medianIncome) {
            printf("Median income is: %d\n", medianIncome);
            break;
        } else if (data[i].income > medianIncome) {
            medianIncome = data[i].income;
        }
    }

    return 0;
}