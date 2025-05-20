//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char address[100];
} Record;

void print_menu() {
    printf("1. Add record\n");
    printf("2. Update record\n");
    printf("3. Delete record\n");
    printf("4. Search record\n");
    printf("5. Print all records\n");
    printf("6. Exit\n");
}

void add_record(Record *db, int *num_records) {
    printf("Enter id: ");
    scanf("%d", &db[*num_records].id);
    printf("Enter name: ");
    scanf("%s", db[*num_records].name);
    printf("Enter address: ");
    scanf("%s", db[*num_records].address);
    (*num_records)++;
}

void update_record(Record *db, int num_records) {
    int id, i;
    printf("Enter id of record to update: ");
    scanf("%d", &id);
    for (i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", db[i].name);
            printf("Enter new address: ");
            scanf("%s", db[i].address);
            return;
        }
    }
    printf("Record not found\n");
}

void delete_record(Record *db, int *num_records) {
    int id, i;
    printf("Enter id of record to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *num_records; i++) {
        if (db[i].id == id) {
            (*num_records)--;
            db[i] = db[*num_records];
            printf("Record deleted\n");
            return;
        }
    }
    printf("Record not found\n");
}

void search_record(Record *db, int num_records) {
    int id, i;
    printf("Enter id of record to search: ");
    scanf("%d", &id);
    for (i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("Record found\n");
            printf("Id: %d, Name: %s, Address: %s\n", db[i].id, db[i].name, db[i].address);
            return;
        }
    }
    printf("Record not found\n");
}

void print_all_records(Record *db, int num_records) {
    int i;
    printf("All records:\n");
    for (i = 0; i < num_records; i++) {
        printf("Id: %d, Name: %s, Address: %s\n", db[i].id, db[i].name, db[i].address);
    }
}

int main() {
    Record *db;
    int num_records = 0;
    int choice;
    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(db, &num_records);
                break;
            case 2:
                update_record(db, num_records);
                break;
            case 3:
                delete_record(db, &num_records);
                break;
            case 4:
                search_record(db, num_records);
                break;
            case 5:
                print_all_records(db, num_records);
                break;
            case 6:
                printf("Exiting\n");
                free(db);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}