//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 25  // Maximum size of each string in the dataset
#define MAX_LINES 500  // Maximum number of lines in the dataset

// Struct for each record in the dataset
struct record {
    char name[MAX_LENGTH];
    int age;
    float salary;
};

// Struct for the index
struct index {
    char name[MAX_LENGTH];
    int lineNumber;
};

// Function to add a record to the dataset and update the index
void addRecord(struct record *data, struct index *idx, int *lines) {
    // Read input from user
    printf("\nEnter name, age, and salary, separated by spaces: ");
    char tempName[MAX_LENGTH];
    scanf("%s", tempName);
    int tempAge;
    float tempSalary;
    scanf("%d %f", &tempAge, &tempSalary);
    
    // Add record to dataset
    struct record newRecord;
    strcpy(newRecord.name, tempName);
    newRecord.age = tempAge;
    newRecord.salary = tempSalary;
    data[*lines] = newRecord;
    
    // Update index
    struct index newIndex;
    strcpy(newIndex.name, tempName);
    newIndex.lineNumber = *lines;
    idx[*lines] = newIndex;
    (*lines)++;
}

// Function to display all records in the dataset
void displayRecords(struct record *data, int lines) {
    printf("\nDataset:");
    for (int i = 0; i < lines; i++) {
        printf("\n%s, %d, $%.2f", data[i].name, data[i].age, data[i].salary);
    }
}

// Function to search for a record by name using the index
void searchByName(struct record *data, struct index *idx, int lines) {
    // Read input from user
    printf("\nEnter name to search for: ");
    char searchName[MAX_LENGTH];
    scanf("%s", searchName);
    
    // Search for record in index
    int found = 0;
    for (int i = 0; i < lines; i++) {
        if (strcmp(searchName, idx[i].name) == 0) {
            found = 1;
            printf("\n%s, %d, $%.2f", data[idx[i].lineNumber].name, data[idx[i].lineNumber].age, data[idx[i].lineNumber].salary);
        }
    }
    if (!found) {
        printf("\nRecord not found.");
    }
}

// Main function
int main() {
    // Declare dataset and index
    struct record data[MAX_LINES];
    struct index idx[MAX_LINES];
    int lines = 0;
    
    // Menu loop
    while (1) {
        printf("\n\n1. Add record\n2. Display all records\n3. Search by name\n4. Quit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(data, idx, &lines);
                break;
            case 2:
                displayRecords(data, lines);
                break;
            case 3:
                searchByName(data, idx, lines);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.");
        }
    }
    
    return 0;
}