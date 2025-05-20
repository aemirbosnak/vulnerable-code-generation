//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int age;
    float salary;
} Record;

int addRecord(Record records[], int count);
int deleteRecord(Record records[], int count);
Record* searchRecordById(Record records[], int count, int id);
int displayRecords(Record records[], int count);
int saveRecords(Record records[], int count);
int loadRecords(Record records[]);

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;

    loadRecords(records);

    do {
        printf("\n********************************************\n");
        printf("             DATABASE SIMULATION\n");
        printf("********************************************\n");
        printf(" 1. Add a new record\n");
        printf(" 2. Delete a record\n");
        printf(" 3. Search for a record\n");
        printf(" 4. Display all records\n");
        printf(" 5. Save current records\n");
        printf(" 6. Exit\n");
        printf("********************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addRecord(records, count);
                break;
            case 2:
                count = deleteRecord(records, count);
                break;
            case 3: {
                int id;
                printf("Enter ID to search for: ");
                scanf("%d", &id);
                Record* record = searchRecordById(records, count, id);
                if (record == NULL) {
                    printf("Record not found.\n");
                } else {
                    printf("Record found:\n");
                    printf("  ID: %d\n", record->id);
                    printf("  Name: %s\n", record->name);
                    printf("  Age: %d\n", record->age);
                    printf("  Salary: %.2f\n", record->salary);
                }
                break;
            }
            case 4:
                displayRecords(records, count);
                break;
            case 5:
                saveRecords(records, count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

int addRecord(Record records[], int count) {
    if (count >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return count;
    }

    Record record;
    printf("Enter record details:\n");
    printf("  ID: ");
    scanf("%d", &record.id);

    if (searchRecordById(records, count, record.id) != NULL) {
        printf("Record with same ID already exists!\n");
        return count;
    }

    printf("  Name: ");
    scanf("%s", record.name);

    printf("  Age: ");
    scanf("%d", &record.age);

    printf("  Salary: ");
    scanf("%f", &record.salary);

    records[count++] = record;
    printf("Record added successfully.\n");
    return count;
}

int deleteRecord(Record records[], int count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Record* record = searchRecordById(records, count, id);
    if (record == NULL) {
        printf("Record not found.\n");
        return count;
    }

    memmove(record, record + 1, (count - 1) * sizeof(Record));
    printf("Record deleted successfully.\n");
    return count - 1;
}

Record* searchRecordById(Record records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }
    return NULL;
}

int displayRecords(Record records[], int count) {
    printf("Total records: %d\n", count);
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
    return count;
}

int saveRecords(Record records[], int count) {
    FILE* fp = fopen("records.dat", "wb");
    if (fp == NULL) {
        printf("Failed to create file for saving records.\n");
        return 0;
    }

    fwrite(records, sizeof(Record), count, fp);
    fclose(fp);
    printf("%d records saved successfully.\n", count);
    return count;
}

int loadRecords(Record records[]) {
    FILE* fp = fopen("records.dat", "rb");
    if (fp == NULL) {
        printf("No saved records found.\n");
        return 0;
    }

    int count = 0;
    while (fread(&records[count], sizeof(Record), 1, fp) == 1) {
        count++;
    }

    fclose(fp);
    printf("%d records loaded successfully.\n", count);
    return count;
}