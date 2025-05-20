//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: surprised
// C Database Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[30];
    char address[50];
} Record;

void print_record(Record *record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
}

void add_record(Record *records, int *num_records) {
    if (*num_records >= MAX_RECORDS) {
        printf("Database is full\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &records[*num_records].id);
    printf("Enter name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter address: ");
    scanf("%s", records[*num_records].address);

    *num_records += 1;
}

void delete_record(Record *records, int *num_records) {
    int id;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *num_records; i++) {
        if (records[i].id == id) {
            for (int j = i; j < *num_records - 1; j++) {
                records[j] = records[j + 1];
            }
            *num_records -= 1;
            break;
        }
    }
}

void update_record(Record *records, int *num_records) {
    int id;

    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < *num_records; i++) {
        if (records[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", records[i].name);
            printf("Enter new address: ");
            scanf("%s", records[i].address);
            break;
        }
    }
}

void search_record(Record *records, int *num_records) {
    int id;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < *num_records; i++) {
        if (records[i].id == id) {
            print_record(&records[i]);
            break;
        }
    }
}

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    int choice;

    while (1) {
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Update record\n");
        printf("4. Search record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_record(records, &num_records);
            break;
        case 2:
            delete_record(records, &num_records);
            break;
        case 3:
            update_record(records, &num_records);
            break;
        case 4:
            search_record(records, &num_records);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}