//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS 100
#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[MAX_CHARS];
    int age;
    float gpa;
} StudentRecord;

// Function to display the menu
void menu() {
    printf("\n==============\n");
    printf("1. Add a record\n");
    printf("2. Update a record\n");
    printf("3. Delete a record\n");
    printf("4. Display all records\n");
    printf("5. Quit program\n");
    printf("==============\n");
}

// Function to add a record to the database
void addRecord(StudentRecord* studentRecords, int* numRecords) {
    StudentRecord newRecord;
    printf("\nEnter the following information:\n");
    printf("ID: ");
    scanf("%d", &newRecord.id);
    printf("Name: ");
    scanf("%s", newRecord.name);
    printf("Age: ");
    scanf("%d", &newRecord.age);
    printf("GPA: ");
    scanf("%f", &newRecord.gpa);
    studentRecords[*numRecords] = newRecord;
    *numRecords += 1;
    printf("Record has been added!\n");
}

// Function to update a record in the database
void updateRecord(StudentRecord* studentRecords, int numRecords) {
    printf("\nEnter the ID of the record you wish to update: ");
    int id;
    scanf("%d", &id);
    bool found = false;
    for (int i = 0; i < numRecords; i++) {
        if (studentRecords[i].id == id) {
            printf("Enter the new information:\n");
            printf("ID: ");
            scanf("%d", &studentRecords[i].id);
            printf("Name: ");
            scanf("%s", studentRecords[i].name);
            printf("Age: ");
            scanf("%d", &studentRecords[i].age);
            printf("GPA: ");
            scanf("%f", &studentRecords[i].gpa);
            printf("Record has been updated!\n");
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

// Function to delete a record from the database
void deleteRecord(StudentRecord* studentRecords, int* numRecords) {
    printf("\nEnter the ID of the record you wish to delete: ");
    int id;
    scanf("%d", &id);
    bool found = false;
    for (int i = 0; i < *numRecords; i++) {
        if (studentRecords[i].id == id) {
            for (int j = i; j < *numRecords - 1; j++) {
                studentRecords[j] = studentRecords[j+1];
            }
            *numRecords -= 1;
            printf("Record has been deleted!\n");
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

// Function to display all records in the database
void displayRecords(StudentRecord* studentRecords, int numRecords) {
    printf("\nID\tName\tAge\tGPA\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t%d\t%.2f\n", studentRecords[i].id, studentRecords[i].name, 
        studentRecords[i].age, studentRecords[i].gpa);
    }
}

int main() {
    StudentRecord studentRecords[MAX_RECORDS];
    int numRecords = 0;
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(studentRecords, &numRecords);
                break;
            case 2:
                updateRecord(studentRecords, numRecords);
                break;
            case 3:
                deleteRecord(studentRecords, &numRecords);
                break;
            case 4:
                displayRecords(studentRecords, numRecords);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}