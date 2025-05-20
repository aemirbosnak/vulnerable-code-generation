//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 50
#define FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LEN];
} Record;

void createRecord();
void readRecords();
void updateRecord();
void deleteRecord();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("Database Simulation Menu:\n");
        printf("1. Create Record\n");
        printf("2. Read Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                createRecord();
                break;
            case 2:
                readRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void createRecord() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Record record;
    printf("Enter ID: ");
    if (scanf("%d", &record.id) != 1) {
        clearInputBuffer();
        printf("Invalid ID. Record not created.\n");
        fclose(file);
        return;
    }

    clearInputBuffer(); // Clear newline left by scanf
    printf("Enter Name: ");
    fgets(record.name, NAME_LEN, stdin);
    record.name[strcspn(record.name, "\n")] = 0; // Remove newline

    fwrite(&record, sizeof(Record), 1, file);
    fclose(file);
    printf("Record created successfully.\n");
}

void readRecords() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Record record;
    printf("Existing Records:\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("ID: %d, Name: %s\n", record.id, record.name);
    }
    fclose(file);
}

void updateRecord() {
    FILE *file = fopen(FILENAME, "r+b");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int id;
    printf("Enter ID of record to update: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid ID. No record updated.\n");
        fclose(file);
        return;
    }

    Record record;
    int found = 0;
    while (fread(&record, sizeof(Record), 1, file)) {
        if (record.id == id) {
            found = 1;
            printf("Enter new Name: ");
            clearInputBuffer();
            fgets(record.name, NAME_LEN, stdin);
            record.name[strcspn(record.name, "\n")] = 0; // Remove newline
            fseek(file, -sizeof(Record), SEEK_CUR);
            fwrite(&record, sizeof(Record), 1, file);
            printf("Record updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("No record found with ID %d.\n", id);
    }

    fclose(file);
}

void deleteRecord() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Record records[MAX_RECORDS];
    int count = 0;
    while (fread(&records[count], sizeof(Record), 1, file) && count < MAX_RECORDS) {
        count++;
    }
    fclose(file);

    int id;
    printf("Enter ID of record to delete: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid ID. No record deleted.\n");
        return;
    }

    file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (records[i].id != id) {
            fwrite(&records[i], sizeof(Record), 1, file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    if (found) {
        printf("Record with ID %d deleted successfully.\n", id);
    } else {
        printf("No record found with ID %d to delete.\n", id);
    }
}