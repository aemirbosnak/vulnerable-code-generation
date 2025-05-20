//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int ID;
    char name[MAX_NAME_LENGTH];
    float balance;
} BankRecord;

BankRecord records[MAX_RECORDS];
int record_count = 0;

void add_record(int id, const char *name, float balance) {
    if (record_count >= MAX_RECORDS) {
        printf("Error: Maximum records limit reached.\n");
        return;
    }
    records[record_count].ID = id;
    strncpy(records[record_count].name, name, MAX_NAME_LENGTH - 1);
    records[record_count].balance = balance;
    record_count++;
    printf("Record added successfully.\n");
}

void display_records() {
    if (record_count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\nBank Records:\n");
    for (int i = 0; i < record_count; ++i) {
        printf("ID: %d | Name: %s | Balance: %.2f\n", records[i].ID, records[i].name, records[i].balance);
    }
}

void update_balance(int id, float amount) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].ID == id) {
            records[i].balance += amount;
            printf("Balance updated successfully for ID: %d\n", id);
            return;
        }
    }
    printf("Error: Record not found with ID: %d\n", id);
}

void delete_record(int id) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].ID == id) {
            for (int j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Error: Record not found to delete with ID: %d\n", id);
}

void search_record(int id) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].ID == id) {
            printf("Record found: ID: %d | Name: %s | Balance: %.2f\n", records[i].ID, records[i].name, records[i].balance);
            return;
        }
    }
    printf("Error: Record not found with ID: %d\n", id);
}

void menu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Update Balance\n");
    printf("4. Delete Record\n");
    printf("5. Search Record\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];
    float balance;

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);  // Read string with spaces
                printf("Enter Balance: ");
                scanf("%f", &balance);
                add_record(id, name, balance);
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter ID to update balance: ");
                scanf("%d", &id);
                printf("Enter amount to add/subtract: ");
                scanf("%f", &balance);
                update_balance(id, balance);
                break;
            case 4:
                printf("Enter ID to delete record: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 5:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(id);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}