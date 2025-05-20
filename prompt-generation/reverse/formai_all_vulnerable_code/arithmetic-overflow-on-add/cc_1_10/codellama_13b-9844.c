//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: inquisitive
/*
 * C Data Mining Example Program
 * Inquisitive Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structure for a record
typedef struct {
    char name[100];
    int age;
    char gender;
    char hobby[50];
    char location[50];
} Record;

// Define data structure for a dataset
typedef struct {
    Record records[100];
    int num_records;
} Dataset;

// Function to read a record from a file
void read_record(FILE *fp, Record *record) {
    fscanf(fp, "%s %d %c %s %s", record->name, &record->age, &record->gender, record->hobby, record->location);
}

// Function to print a record
void print_record(Record *record) {
    printf("%s (%d) %c %s %s\n", record->name, record->age, record->gender, record->hobby, record->location);
}

// Function to print a dataset
void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_records; i++) {
        print_record(&dataset->records[i]);
    }
}

// Function to filter records based on age
void filter_by_age(Dataset *dataset, int min_age, int max_age) {
    for (int i = 0; i < dataset->num_records; i++) {
        if (dataset->records[i].age < min_age || dataset->records[i].age > max_age) {
            // Remove record from dataset
            dataset->num_records--;
            for (int j = i; j < dataset->num_records; j++) {
                dataset->records[j] = dataset->records[j + 1];
            }
        }
    }
}

// Function to filter records based on gender
void filter_by_gender(Dataset *dataset, char gender) {
    for (int i = 0; i < dataset->num_records; i++) {
        if (dataset->records[i].gender != gender) {
            // Remove record from dataset
            dataset->num_records--;
            for (int j = i; j < dataset->num_records; j++) {
                dataset->records[j] = dataset->records[j + 1];
            }
        }
    }
}

// Function to filter records based on hobby
void filter_by_hobby(Dataset *dataset, char *hobby) {
    for (int i = 0; i < dataset->num_records; i++) {
        if (strcmp(dataset->records[i].hobby, hobby) != 0) {
            // Remove record from dataset
            dataset->num_records--;
            for (int j = i; j < dataset->num_records; j++) {
                dataset->records[j] = dataset->records[j + 1];
            }
        }
    }
}

// Function to filter records based on location
void filter_by_location(Dataset *dataset, char *location) {
    for (int i = 0; i < dataset->num_records; i++) {
        if (strcmp(dataset->records[i].location, location) != 0) {
            // Remove record from dataset
            dataset->num_records--;
            for (int j = i; j < dataset->num_records; j++) {
                dataset->records[j] = dataset->records[j + 1];
            }
        }
    }
}

int main() {
    // Create a dataset
    Dataset dataset;
    dataset.num_records = 0;

    // Read data from a file
    FILE *fp = fopen("data.txt", "r");
    while (fscanf(fp, "%s %d %c %s %s", dataset.records[dataset.num_records].name, &dataset.records[dataset.num_records].age, &dataset.records[dataset.num_records].gender, dataset.records[dataset.num_records].hobby, dataset.records[dataset.num_records].location) != EOF) {
        dataset.num_records++;
    }
    fclose(fp);

    // Print the original dataset
    print_dataset(&dataset);

    // Filter the dataset based on age
    filter_by_age(&dataset, 18, 30);

    // Filter the dataset based on gender
    filter_by_gender(&dataset, 'M');

    // Filter the dataset based on hobby
    filter_by_hobby(&dataset, "reading");

    // Filter the dataset based on location
    filter_by_location(&dataset, "New York");

    // Print the filtered dataset
    print_dataset(&dataset);

    return 0;
}