//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a record
typedef struct {
    int id;
    char name[50];
    float price;
} Record;

// Function to read the data from a file and store it in an array of records
void readData(Record *records, int size, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%d %s %f", &records[count].id, records[count].name, &records[count].price)!= EOF) {
        count++;
    }

    fclose(fp);
}

// Function to print the records in a sorted order
void printRecords(Record *records, int size, int (*compare)(const void *, const void *)) {
    qsort(records, size, sizeof(Record), compare);

    printf("ID\tName\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].price);
    }
}

// Function to compare two records based on their price
int comparePrices(const void *a, const void *b) {
    Record *recordA = (Record *)a;
    Record *recordB = (Record *)b;

    if (recordA->price < recordB->price) {
        return -1;
    } else if (recordA->price > recordB->price) {
        return 1;
    } else {
        return 0;
    }
}

// Function to filter the records based on a given price range
void filterRecords(Record *records, int size, float minPrice, float maxPrice) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (records[i].price >= minPrice && records[i].price <= maxPrice) {
            records[count] = records[i];
            count++;
        }
    }

    size = count;
}

// Function to calculate the total price of the records
float calculateTotalPrice(Record *records, int size) {
    float totalPrice = 0;

    for (int i = 0; i < size; i++) {
        totalPrice += records[i].price;
    }

    return totalPrice;
}

int main() {
    Record records[100];
    int size = 0;

    // Read data from file
    readData(records, 100, "data.txt");
    size = sizeof(records) / sizeof(records[0]);

    // Print records in a sorted order based on price
    printf("Records sorted by price:\n");
    printRecords(records, size, comparePrices);

    // Filter records based on a price range
    float minPrice = 5.0;
    float maxPrice = 10.0;
    filterRecords(records, size, minPrice, maxPrice);
    printf("\nRecords filtered by price range %.2f - %.2f:\n", minPrice, maxPrice);
    printRecords(records, size, comparePrices);

    // Calculate the total price of the records
    float totalPrice = calculateTotalPrice(records, size);
    printf("\nTotal price of the records: $%.2f\n", totalPrice);

    return 0;
}