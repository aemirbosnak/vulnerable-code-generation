//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define FILENAME "data_records.txt"

typedef struct {
    int id;
    char name[30];
    float score;
} Record;

void addRecord();
void displayRecords();
void deleteRecord();
void updateRecord();

int main() {
    int choice;
    while (1) {
        printf("\n--- Record Management Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Update Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addRecord() {
    FILE *file;
    Record record;

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Score: ");
    scanf("%f", &record.score);

    fprintf(file, "%d %s %f\n", record.id, record.name, record.score);
    fclose(file);
    printf("Record added successfully!\n");
}

void displayRecords() {
    FILE *file;
    Record record;

    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Records ---\n");
    while (fscanf(file, "%d %s %f", &record.id, record.name, &record.score) != EOF) {
        printf("ID: %d, Name: %s, Score: %.2f\n", record.id, record.name, record.score);
    }
    fclose(file);
}

void deleteRecord() {
    FILE *file, *tempFile;
    Record record;
    int idToDelete;
    int found = 0;

    file = fopen(FILENAME, "r");
    tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID of record to delete: ");
    scanf("%d", &idToDelete);

    while (fscanf(file, "%d %s %f", &record.id, record.name, &record.score) != EOF) {
        if (record.id != idToDelete) {
            fprintf(tempFile, "%d %s %f\n", record.id, record.name, record.score);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Record with ID %d deleted successfully!\n", idToDelete);
    } else {
        printf("Record with ID %d not found!\n", idToDelete);
    }
}

void updateRecord() {
    FILE *file, *tempFile;
    Record record;
    int idToUpdate;
    int found = 0;

    file = fopen(FILENAME, "r");
    tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID of record to update: ");
    scanf("%d", &idToUpdate);

    while (fscanf(file, "%d %s %f", &record.id, record.name, &record.score) != EOF) {
        if (record.id == idToUpdate) {
            found = 1;
            printf("Current Name: %s, Current Score: %.2f\n", record.name, record.score);
            printf("Enter new Name: ");
            scanf("%s", record.name);
            printf("Enter new Score: ");
            scanf("%f", &record.score);
        }
        fprintf(tempFile, "%d %s %f\n", record.id, record.name, record.score);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Record with ID %d updated successfully!\n", idToUpdate);
    } else {
        printf("Record with ID %d not found!\n", idToUpdate);
    }
}