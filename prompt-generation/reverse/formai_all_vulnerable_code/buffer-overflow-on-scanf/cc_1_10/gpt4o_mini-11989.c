//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(int id, const char *name) {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    database[num_records].id = id;
    strncpy(database[num_records].name, name, NAME_LENGTH);
    num_records++;
    printf("Record added: ID = %d, Name = %s\n", id, name);
}

void delete_record(int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j + 1];
            }
            num_records--;
            printf("Record with ID = %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID = %d not found.\n", id);
}

void display_records() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    printf("Current records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s\n", database[i].id, database[i].name);
    }
}

void show_menu() {
    printf("\nMenu:\n");
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Display Records\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name); // To read string with spaces
                add_record(id, name);
                break;
            case 2:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}