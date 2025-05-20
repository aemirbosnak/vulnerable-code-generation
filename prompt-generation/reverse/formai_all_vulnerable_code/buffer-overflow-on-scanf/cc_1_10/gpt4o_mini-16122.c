//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DATA_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char data[DATA_LENGTH];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record(int id, char *name, char *data) {
    if (record_count < MAX_RECORDS) {
        database[record_count].id = id;
        strncpy(database[record_count].name, name, NAME_LENGTH);
        strncpy(database[record_count].data, data, DATA_LENGTH);
        record_count++;
        printf("Record added: ID=%d, Name=%s\n", id, name);
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void display_records() {
    printf("ID\tName\t\tData\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].data);
    }
}

Record* find_record_by_id(int id) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

void update_record(int id, char *name, char *data) {
    Record *record = find_record_by_id(id);
    if (record) {
        strncpy(record->name, name, NAME_LENGTH);
        strncpy(record->data, data, DATA_LENGTH);
        printf("Record updated: ID=%d, Name=%s\n", id, name);
    } else {
        printf("Record with ID=%d not found.\n", id);
    }
}

void delete_record(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            found = 1;
            for (int j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1];
            }
            record_count--;
            printf("Record with ID=%d deleted.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Record with ID=%d not found.\n", id);
    }
}

void clear_database() {
    record_count = 0;
    printf("Database cleared.\n");
}

int main() {
    int choice, id;
    char name[NAME_LENGTH], data[DATA_LENGTH];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Record by ID\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Clear Database\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: "); scanf("%d", &id);
                printf("Enter Name: "); scanf("%s", name);
                printf("Enter Data: "); scanf(" %[^\n]", data);
                add_record(id, name, data);
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter ID: "); scanf("%d", &id);
                Record *record = find_record_by_id(id);
                if (record) {
                    printf("Record found: ID=%d, Name=%s, Data=%s\n", record->id, record->name, record->data);
                } else {
                    printf("Record with ID=%d not found.\n", id);
                }
                break;
            case 4:
                printf("Enter ID: "); scanf("%d", &id);
                printf("Enter new Name: "); scanf("%s", name);
                printf("Enter new Data: "); scanf(" %[^\n]", data);
                update_record(id, name, data);
                break;
            case 5:
                printf("Enter ID: "); scanf("%d", &id);
                delete_record(id);
                break;
            case 6:
                clear_database();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}