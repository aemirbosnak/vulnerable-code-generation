//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    long int account_number;
    long int balance;
} record_t;

record_t records[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Record capacity reached.\n");
        return;
    }
    record_t new_record;
    printf("Enter name:\n");
    fgets(new_record.name, MAX_NAME_LENGTH, stdin);
    printf("Enter address:\n");
    fgets(new_record.address, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter account number:\n");
    scanf("%ld", &new_record.account_number);
    printf("Enter balance:\n");
    scanf("%ld", &new_record.balance);
    getchar(); // eat new line char
    records[num_records] = new_record;
    num_records++;
}

void display_records() {
    if (num_records == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("%-15s%-30s%-20s%-20s\n", "Name", "Address", "Account Number", "Balance");
    for (int i = 0; i < num_records; i++) {
        printf("%-15s%-30s%-20ld%-20ld\n", records[i].name, records[i].address, 
            records[i].account_number, records[i].balance);
    }
}

int search_record_by_name(const char* name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0)
            return i;
    }
    return -1; // not found
}

void update_record() {
    if (num_records == 0) {
        printf("No records to update.\n");
        return;
    }
    printf("Enter name to update:\n");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    int index = search_record_by_name(name);
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }
    printf("Enter new name (or press enter to keep current name):\n");
    fgets(records[index].name, MAX_NAME_LENGTH, stdin);
    printf("Enter new address (or press enter to keep current address):\n");
    fgets(records[index].address, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter new account number (or press enter to keep current account number):\n");
    char buffer[MAX_NAME_LENGTH];
    fgets(buffer, MAX_NAME_LENGTH, stdin);
    if (buffer[0] != '\n')
        sscanf(buffer, "%ld", &records[index].account_number);
    printf("Enter new balance (or press enter to keep current balance):\n");
    fgets(buffer, MAX_NAME_LENGTH, stdin);
    if (buffer[0] != '\n')
        sscanf(buffer, "%ld", &records[index].balance);
}

int main() {
    int choice = -1;
    while (choice != 4) {
        printf("\nBanking Record System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Update Record\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4):\n");
        scanf("%d", &choice);
        getchar(); // eat new line char
        printf("\n");
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                update_record();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}