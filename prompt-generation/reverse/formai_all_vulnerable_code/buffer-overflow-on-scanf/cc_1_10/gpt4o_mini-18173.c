//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30
#define ADDR_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[ADDR_LENGTH];
} Record;

void menu() {
    printf("\n=== Record Management System ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Update Record by ID\n");
    printf("5. Delete Record by ID\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void addRecord(FILE *file) {
    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    getchar(); // Consume newline
    fgets(record.name, NAME_LENGTH, stdin);
    record.name[strcspn(record.name, "\n")] = 0; // Remove newline
    printf("Enter Address: ");
    fgets(record.address, ADDR_LENGTH, stdin);
    record.address[strcspn(record.address, "\n")] = 0; // Remove newline

    fseek(file, 0, SEEK_END);
    fwrite(&record, sizeof(Record), 1, file);
    printf("Record added successfully!\n");
}

void displayRecords(FILE *file) {
    Record record;
    fseek(file, 0, SEEK_SET);
    printf("\n=== List of Records ===\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("ID: %d, Name: %s, Address: %s\n", record.id, record.name, record.address);
    }
    printf("=======================\n");
}

void searchRecord(FILE *file) {
    int id, found = 0;
    Record record;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    fseek(file, 0, SEEK_SET);
    
    while (fread(&record, sizeof(Record), 1, file)) {
        if (record.id == id) {
            printf("Record Found: ID: %d, Name: %s, Address: %s\n", record.id, record.name, record.address);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void updateRecord(FILE *file) {
    int id, found = 0;
    Record record;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(Record), 1, file)) {
        if (record.id == id) {
            found = 1;
            printf("Updating Record: ID: %d, Name: %s, Address: %s\n", record.id, record.name, record.address);
            printf("Enter new Name: ");
            getchar(); // Consume newline
            fgets(record.name, NAME_LENGTH, stdin);
            record.name[strcspn(record.name, "\n")] = 0; // Remove newline
            printf("Enter new Address: ");
            fgets(record.address, ADDR_LENGTH, stdin);
            record.address[strcspn(record.address, "\n")] = 0; // Remove newline
            
            fseek(file, -sizeof(Record), SEEK_CUR);
            fwrite(&record, sizeof(Record), 1, file);
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found for update.\n", id);
    }
}

void deleteRecord(FILE *file) {
    int id, found = 0;
    Record record;
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        return;
    }
    
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    fseek(file, 0, SEEK_SET);

    while (fread(&record, sizeof(Record), 1, file)) {
        if (record.id == id) {
            printf("Record with ID %d deleted successfully!\n", id);
            found = 1;
            continue; // Skip the record to delete it
        }
        fwrite(&record, sizeof(Record), 1, tempFile);
    }

    fclose(tempFile);
    fclose(file);
    remove("records.dat");
    rename("temp.dat", "records.dat");
    file = fopen("records.dat", "ab+");
    if (!file) {
        printf("Error reopening records file.\n");
    }

    if (!found) {
        printf("Record with ID %d not found for deletion.\n", id);
    }
}

int main() {
    FILE *file = fopen("records.dat", "ab+");
    if (!file) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecords(file);
                break;
            case 3:
                searchRecord(file);
                break;
            case 4:
                updateRecord(file);
                break;
            case 5:
                deleteRecord(file);
                break;
            case 6:
                fclose(file);
                printf("Exiting the program.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}