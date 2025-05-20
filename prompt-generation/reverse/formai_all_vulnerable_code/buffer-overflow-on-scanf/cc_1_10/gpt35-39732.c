//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <string.h>

// Define maximum number of records
#define MAX_RECORDS 100

// Define structure for medicine record
typedef struct MedicineRecord {
    int id;
    char name[50];
    float price;
} MedicineRecord;

// Define global variables
int num_records = 0;
MedicineRecord records[MAX_RECORDS];

// Function prototypes
void displayMenu();
void addRecord();
void updateRecord();
void removeRecord();
void displayRecords();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                updateRecord();
                break;
            case 3:
                removeRecord();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("***************\n");
    printf("MEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("***************\n");
    printf("1. Add record\n");
    printf("2. Update record\n");
    printf("3. Remove record\n");
    printf("4. Display records\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

void addRecord() {
    if (num_records == MAX_RECORDS) {
        printf("Maximum number of records reached. No more records can be added.\n");
        return;
    }

    MedicineRecord record;
    printf("Enter medicine ID: ");
    scanf("%d", &record.id);
    printf("Enter medicine name: ");
    fflush(stdin);
    gets(record.name);
    printf("Enter medicine price: ");
    scanf("%f", &record.price);

    records[num_records] = record;
    num_records++;

    printf("Record added successfully!\n");
}

void updateRecord() {
    int id, index = -1;
    printf("Enter ID of record to update: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
        return;
    }

    MedicineRecord record = records[index];

    printf("Enter new medicine ID (or enter 0 to keep the same): ");
    scanf("%d", &record.id);
    printf("Enter new medicine name (or enter 'same' to keep the same): ");
    fflush(stdin);
    gets(record.name);
    printf("Enter new medicine price (or enter -1 to keep the same): ");
    scanf("%f", &record.price);

    if (record.id == 0)
        record.id = records[index].id;
    if (record.price == -1)
        record.price = records[index].price;
    if (strcmp(record.name, "same") == 0)
        strcpy(record.name, records[index].name);

    records[index] = record;

    printf("Record updated successfully!\n");
}

void removeRecord() {
    int id, index = -1;
    printf("Enter ID of record to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
        return;
    }

    for (int i = index; i < num_records-1; i++) {
        records[i] = records[i+1];
    }
    num_records--;

    printf("Record removed successfully!\n");
}

void displayRecords() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s, Price: %.2f\n", records[i].id, records[i].name, records[i].price);
    }
}