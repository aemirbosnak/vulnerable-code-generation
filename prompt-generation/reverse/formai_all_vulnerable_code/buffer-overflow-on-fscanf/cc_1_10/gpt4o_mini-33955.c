//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record new_record;
    new_record.id = record_count + 1;

    printf("Enter name for record #%d: ", new_record.id);
    scanf(" %[^\n]", new_record.name);
    
    printf("Enter age for record #%d: ", new_record.id);
    scanf("%d", &new_record.age);

    database[record_count] = new_record;
    record_count++;
    printf("Record #%d added!\n", new_record.id);
}

void display_records() {
    if (record_count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\nDisplaying Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Record #%d: Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }
}

void delete_record() {
    int id;
    printf("Enter the record ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > record_count) {
        printf("Invalid ID! No record found with ID %d.\n", id);
        return;
    }

    // Shift the records to fill the gap
    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;
    printf("Record #%d deleted!\n", id);
}

void save_to_file() {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }
    fclose(file);
    printf("Records saved to database.txt\n");
}

void load_from_file() {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("No file found. Starting with an empty database.\n");
        return;
    }

    record_count = 0; // Reset the record count
    while (fscanf(file, "%d %s %d", &database[record_count].id, database[record_count].name, &database[record_count].age) != EOF) {
        record_count++;
    }
    fclose(file);
    printf("Records loaded from database.txt\n");
}

void show_menu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Save Records to File\n");
    printf("5. Load Records from File\n");
    printf("0. Exit\n");
}

int main() {
    int choice;

    load_from_file();

    do {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}