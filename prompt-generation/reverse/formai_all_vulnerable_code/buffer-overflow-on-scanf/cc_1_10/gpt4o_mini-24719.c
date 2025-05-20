//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char address[ADDRESS_LENGTH];
} Record;

Record records[MAX_RECORDS];
int record_count = 0;

void add_record(int id, char *name, int age, char *address) {
    if (record_count < MAX_RECORDS) {
        records[record_count].id = id;
        strncpy(records[record_count].name, name, NAME_LENGTH);
        records[record_count].age = age;
        strncpy(records[record_count].address, address, ADDRESS_LENGTH);
        record_count++;
        printf("Record added!\n");
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void display_records() {
    printf("\nID\tName\t\tAge\tAddress\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\t%d\t%s\n", records[i].id, records[i].name, records[i].age, records[i].address);
    }
}

void delete_record(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            found = 1;
            for (int j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count--;
            printf("Record deleted!\n");
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void search_record(int id) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            found = 1;
            printf("Record found: ID:%d, Name:%s, Age:%d, Address:%s\n", records[i].id, records[i].name, records[i].age, records[i].address);
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void update_record(int id, char *new_name, int new_age, char *new_address) {
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            found = 1;
            strncpy(records[i].name, new_name, NAME_LENGTH);
            records[i].age = new_age;
            strncpy(records[i].address, new_address, ADDRESS_LENGTH);
            printf("Record updated!\n");
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

void menu() {
    printf("\n====== Database Menu ======\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Search Record\n");
    printf("6. Exit\n");
    printf("============================\n");
}

int main() {
    int choice, id, age;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Address: ");
                scanf("%s", address);
                add_record(id, name, age, address);
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter New Name: ");
                scanf("%s", name);
                printf("Enter New Age: ");
                scanf("%d", &age);
                printf("Enter New Address: ");
                scanf("%s", address);
                update_record(id, name, age, address);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 5:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(id);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}