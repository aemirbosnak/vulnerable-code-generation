//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define COUNTRY_LENGTH 50
#define FILE_NAME "records.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char country[COUNTRY_LENGTH];
} Record;

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addRecord() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", record.name);
    printf("Enter Country: ");
    scanf(" %[^\n]", record.country);

    fwrite(&record, sizeof(Record), 1, file);
    fclose(file);

    printf("Record added successfully!\n");
}

void displayRecords() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    Record record;
    printf("\nRecords:\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("ID: %d, Name: %s, Country: %s\n", record.id, record.name, record.country);
    }
    fclose(file);
}

void searchRecord() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    Record record;
    int found = 0;
    while (fread(&record, sizeof(Record), 1, file)) {
        if (record.id == searchId) {
            printf("Record found: ID: %d, Name: %s, Country: %s\n", record.id, record.name, record.country);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with ID: %d\n", searchId);
    }

    fclose(file);
}

void deleteRecord() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    Record records[MAX_RECORDS];
    int count = 0;
    while (fread(&records[count], sizeof(Record), 1, file)) {
        count++;
    }
    fclose(file);

    int deleteId;
    printf("Enter ID to delete: ");
    scanf("%d", &deleteId);

    int found = 0;
    file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (records[i].id != deleteId) {
            fwrite(&records[i], sizeof(Record), 1, file);
        } else {
            found = 1;
        }
    }

    fclose(file);

    if (found) {
        printf("Record with ID: %d deleted successfully!\n", deleteId);
    } else {
        printf("No record found with ID: %d\n", deleteId);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}