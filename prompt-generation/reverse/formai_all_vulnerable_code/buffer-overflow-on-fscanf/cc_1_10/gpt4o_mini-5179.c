//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define TABLE_NAME "Database"

// Structure to define a record
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Record;

// Function prototypes
void initializeDatabase(Record records[], int *count);
void addRecord(Record records[], int *count);
void displayRecords(Record records[], int count);
void deleteRecord(Record records[], int *count, int id);
void findRecord(Record records[], int count, int id);
void saveRecords(Record records[], int count);
void loadRecords(Record records[], int *count);
int getRecordIndexById(Record records[], int count, int id);

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;
    
    loadRecords(records, &count);

    do {
        printf("\n--- %s Menu ---\n", TABLE_NAME);
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Find Record\n");
        printf("5. Save Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayRecords(records, count);
                break;
            case 3:
                {
                    int id;
                    printf("Enter ID of record to delete: ");
                    scanf("%d", &id);
                    deleteRecord(records, &count, id);
                }
                break;
            case 4:
                {
                    int id;
                    printf("Enter ID of record to find: ");
                    scanf("%d", &id);
                    findRecord(records, count, id);
                }
                break;
            case 5:
                saveRecords(records, count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeDatabase(Record records[], int *count) {
    *count = 0;
}

void addRecord(Record records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full. Can't add more records.\n");
        return;
    }
    Record newRecord;
    newRecord.id = *count + 1; // Assign ID based on current count
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter email: ");
    scanf("%s", newRecord.email);

    records[*count] = newRecord;
    (*count)++;
    printf("Record added successfully! ID: %d\n", newRecord.id);
}

void displayRecords(Record records[], int count) {
    if (count == 0) {
        printf("No records to display!\n");
        return;
    }
    printf("\nRecords:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", records[i].id, records[i].name, records[i].email);
    }
}

void deleteRecord(Record records[], int *count, int id) {
    int index = getRecordIndexById(records, *count, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    records[index] = records[*count - 1]; // Replace with the last record
    (*count)--;
    printf("Record deleted successfully!\n");
}

void findRecord(Record records[], int count, int id) {
    int index = getRecordIndexById(records, count, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    printf("Record found: ID: %d, Name: %s, Email: %s\n", records[index].id, records[index].name, records[index].email);
}

void saveRecords(Record records[], int count) {
    FILE *file = fopen("database.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s\n", records[i].id, records[i].name, records[i].email);
    }
    fclose(file);
    printf("Records saved successfully!\n");
}

void loadRecords(Record records[], int *count) {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        printf("No previous records found, starting fresh.\n");
        initializeDatabase(records, count);
        return;
    }
    
    *count = 0;
    while (fscanf(file, "%d,%49[^,],%49[^\n]\n", &records[*count].id, records[*count].name, records[*count].email) == 3) {
        (*count)++;
    }
    fclose(file);
    printf("%d records loaded successfully!\n", *count);
}

int getRecordIndexById(Record records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}