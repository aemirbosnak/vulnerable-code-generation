//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME "futuristic_data.txt"
#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    time_t timestamp;
} Record;

void save_record(Record *record, FILE *file) {
    fwrite(record, sizeof(Record), 1, file);
}

void load_records(FILE *file, Record *records, int *count) {
    *count = 0;
    while (fread(&records[*count], sizeof(Record), 1, file) == 1) {
        (*count)++;
    }
}

void print_record(const Record *record) {
    char buffer[26];
    struct tm* tm_info;
    tm_info = localtime(&record->timestamp);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Name: %s\nDescription: %s\nTimestamp: %s\n\n", record->name, record->description, buffer);
}

void display_records(Record *records, int count) {
    printf("=== Recorded Information ===\n");
    for (int i = 0; i < count; i++) {
        print_record(&records[i]);
    }
}

void add_record(Record *records, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum record limit reached.\n");
        return;
    }
    
    Record new_record;
    printf("Enter name: ");
    fgets(new_record.name, NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0; // Remove the newline character

    printf("Enter description: ");
    fgets(new_record.description, DESCRIPTION_LENGTH, stdin);
    new_record.description[strcspn(new_record.description, "\n")] = 0;

    new_record.timestamp = time(NULL);
    records[(*count)++] = new_record;

    printf("Record added successfully!\n");
}

void remove_record(Record *records, int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the record to remove: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove the newline character

    for (int i = 0; i < *count; ++i) {
        if (strcmp(records[i].name, name) == 0) {
            for (int j = i; j < *count - 1; ++j) {
                records[j] = records[j + 1];
            }
            (*count)--;
            printf("Record removed successfully!\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void save_to_file(Record *records, int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(records, sizeof(Record), count, file);
    fclose(file);
    printf("Records saved to `%s` successfully!\n", FILE_NAME);
}

void load_from_file(Record *records, int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Could not open file for reading");
        exit(EXIT_FAILURE);
    }

    load_records(file, records, count);
    fclose(file);
    printf("Records loaded from `%s` successfully!\n", FILE_NAME);
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;

    load_from_file(records, &count);

    while (1) {
        printf("====== Futuristic Records Management ======\n");
        printf("1. Add Record\n");
        printf("2. Remove Record\n");
        printf("3. Display Records\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                remove_record(records, &count);
                break;
            case 3:
                display_records(records, count);
                break;
            case 4:
                save_to_file(records, count);
                break;
            case 5:
                printf("Exiting the futuristic records system. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}