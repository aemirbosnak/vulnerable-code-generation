//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[20];
    char address[50];
} Record;

void add(Record *records, int *size);
void removeRecord(Record *records, int *size);
void search(Record *records, int size);
void printAll(Record *records, int size);

int main() {
    Record records[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("\n========================\n");
        printf("1. Add a record\n");
        printf("2. Remove a record\n");
        printf("3. Search for a record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(records, &size);
                break;
            case 2:
                removeRecord(records, &size);
                break;
            case 3:
                search(records, size);
                break;
            case 4:
                printAll(records, size);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add(Record *records, int *size) {
    Record newRecord;
    printf("\nEnter the details for the new record.\n");
    printf("ID: ");
    scanf("%d", &newRecord.id);
    printf("Name: ");
    scanf("%s", newRecord.name);
    printf("Address: ");
    scanf("%s", newRecord.address);
    records[*size] = newRecord;
    *size += 1;
    printf("Record added successfully!\n");
}

void removeRecord(Record *records, int *size) {
    int id;
    printf("\nEnter the ID of the record to remove: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (records[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                records[j] = records[j + 1];
            }
            *size -= 1;
            printf("Record removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d was not found.\n", id);
    }
}

void search(Record *records, int size) {
    int id;
    printf("\nEnter the ID of the record to search for: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (records[i].id == id) {
            printf("\nRecord found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d was not found.\n", id);
    }
}

void printAll(Record *records, int size) {
    if (size == 0) {
        printf("\nNo records found.\n");
    } else {
        printf("\nAll records:\n");
        for (int i = 0; i < size; i++) {
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("\n");
        }
    }
}