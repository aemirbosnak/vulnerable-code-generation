//FormAI DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[30];
    int age;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

// Hash function to generate index
int hash(int id) {
    return id % MAX_RECORDS;
}

// Insert new record
void insert_record(int id, char name[30], int age) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Can't insert more records\n");
        return;
    }
    int index = hash(id);
    records[index].id = id;
    strcpy(records[index].name, name);
    records[index].age = age;
    num_records++;
    printf("Record inserted successfully!\n");
}

// Search for record by ID
void search_record(int id) {
    int index = hash(id);
    if (records[index].id == id) {
        printf("Record found: ID=%d, Name=%s, Age=%d\n", records[index].id, records[index].name, records[index].age);
    } else {
        printf("Record not found\n");
    }
}

// Delete record by ID
void delete_record(int id) {
    int index = hash(id);
    if (records[index].id == id) {
        records[index].id = -1;
        strcpy(records[index].name, "");
        records[index].age = -1;
        num_records--;
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found\n");
    }
}

// Print all records
void print_records() {
    printf("ID     Name              Age\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].id != -1) {
            printf("%-5d  %-18s %d\n", records[i].id, records[i].name, records[i].age);
        }
    }
}

int main() {
    int choice, id, age;
    char name[30];

    printf("Welcome to RetroDB - A simple database indexing system!\n\n");

    do {
        printf("Menu:\n");
        printf("1. Insert new record\n");
        printf("2. Search for record by ID\n");
        printf("3. Delete record by ID\n");
        printf("4. Print all records\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insert_record(id, name, age);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                search_record(id);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 4:
                print_records();
                break;
            case 5:
                printf("Exiting RetroDB...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 5);

    return 0;
}