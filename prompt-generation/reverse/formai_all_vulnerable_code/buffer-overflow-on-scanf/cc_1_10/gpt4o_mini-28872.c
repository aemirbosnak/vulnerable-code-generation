//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 200
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
} Record;

void write_records_to_file(const char* filename, Record records[], int count) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(records, sizeof(Record), count, file);
    fclose(file);
}

int read_records_from_file(const char* filename, Record records[]) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file for reading");
        return 0;
    }
    int count = fread(records, sizeof(Record), MAX_RECORDS, file);
    fclose(file);
    return count;
}

void display_records(Record records[], int count) {
    printf("\nRecords:\n");
    printf("ID\tName\t\tDescription\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", records[i].id, records[i].name, records[i].description);
    }
}

void add_record(Record records[], int* count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum record limit reached.\n");
        return;
    }
    Record new_record;
    new_record.id = *count + 1;
    printf("Enter name: ");
    fgets(new_record.name, MAX_NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0;  // Remove newline
    printf("Enter description: ");
    fgets(new_record.description, MAX_DESC_LENGTH, stdin);
    new_record.description[strcspn(new_record.description, "\n")] = 0;  // Remove newline

    records[*count] = new_record;
    (*count)++;
}

void delete_record(Record records[], int* count, int id) {
    for (int i = 0; i < *count; i++) {
        if (records[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            (*count)--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Save Records\n");
    printf("5. Load Records\n");
    printf("6. Exit\n");
}

int main() {
    Record records[MAX_RECORDS];
    int record_count = 0;
    int choice;
    const char* filename = "records.dat";

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline after the choice

        switch (choice) {
            case 1:
                add_record(records, &record_count);
                break;
            case 2:
                display_records(records, record_count);
                break;
            case 3:
                printf("Enter ID of record to delete: ");
                int id_to_delete;
                scanf("%d", &id_to_delete);
                delete_record(records, &record_count, id_to_delete);
                break;
            case 4:
                write_records_to_file(filename, records, record_count);
                printf("Records saved to %s\n", filename);
                break;
            case 5:
                record_count = read_records_from_file(filename, records);
                printf("%d records loaded from %s\n", record_count, filename);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}