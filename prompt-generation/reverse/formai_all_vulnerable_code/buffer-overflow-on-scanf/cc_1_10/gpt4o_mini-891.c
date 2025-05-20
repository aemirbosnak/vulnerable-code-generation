//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define CITY_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char age[AGE_LENGTH];
    char city[CITY_LENGTH];
} Record;

void displayMenu();
void addRecord(Record records[], int* count);
void viewRecords(Record records[], int count);
void searchRecord(Record records[], int count);
void deleteRecord(Record records[], int* count);
int findRecordIndexById(Record records[], int count, int id);

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                viewRecords(records, count);
                break;
            case 3:
                searchRecord(records, count);
                break;
            case 4:
                deleteRecord(records, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Simple C Database Simulation ===\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
}

void addRecord(Record records[], int* count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record newRecord;
    newRecord.id = *count + 1;  // Simple ID based on current count
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter age: ");
    scanf("%s", newRecord.age);
    printf("Enter city: ");
    scanf("%s", newRecord.city);

    records[*count] = newRecord;
    (*count)++;
    printf("Record added successfully!\n");
}

void viewRecords(Record records[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n=== Records ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %s, City: %s\n", records[i].id, records[i].name, records[i].age, records[i].city);
    }
}

void searchRecord(Record records[], int count) {
    if (count == 0) {
        printf("No records to search.\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    int index = findRecordIndexById(records, count, id);

    if (index != -1) {
        printf("Record found! ID: %d, Name: %s, Age: %s, City: %s\n",
               records[index].id, records[index].name, records[index].age, records[index].city);
    } else {
        printf("Record with ID %d not found.\n", id);
    }
}

void deleteRecord(Record records[], int* count) {
    if (*count == 0) {
        printf("No records to delete.\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    int index = findRecordIndexById(records, *count, id);

    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            records[i] = records[i + 1]; // Shift records left
        }
        (*count)--; // Decrease count
        printf("Record deleted successfully!\n");
    } else {
        printf("Record with ID %d not found.\n", id);
    }
}

int findRecordIndexById(Record records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1; // If not found
}