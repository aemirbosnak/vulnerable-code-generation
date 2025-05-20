//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_number;
    double balance;
};

typedef struct bank_record BankRecord;

void display_menu();
void create_record(BankRecord *records, int *num_records);
void display_records(BankRecord *records, int num_records);
int find_record(BankRecord *records, int num_records, int account_number);
void update_record(BankRecord *records, int num_records);
void delete_record(BankRecord *records, int *num_records);

int main() {
    int choice;
    int num_records = 0;
    BankRecord records[100];

    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                update_record(records, num_records);
                break;
            case 4:
                delete_record(records, &num_records);
                break;
            case 5:
                printf("Thank you for using the banking record system!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}

void display_menu() {
    printf("\n\n********** BANKING RECORD SYSTEM **********\n");
    printf("\n1. Create a new record");
    printf("\n2. Display all records");
    printf("\n3. Update an existing record");
    printf("\n4. Delete an existing record");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

void create_record(BankRecord *records, int *num_records) {
    BankRecord new_record;
    printf("\nEnter the name of the customer: ");
    scanf("%s", new_record.name);
    printf("Enter the account number: ");
    scanf("%d", &new_record.account_number);
    printf("Enter the account balance: ");
    scanf("%lf", &new_record.balance);
    records[*num_records] = new_record;
    *num_records += 1;
}

void display_records(BankRecord *records, int num_records) {
    if (num_records == 0) {
        printf("\nThere are no records to display.\n");
    } else {
        printf("\n\n********** BANKING RECORDS **********\n");
        for (int i = 0; i < num_records; i++) {
            printf("\nName: %s", records[i].name);
            printf("\nAccount Number: %d", records[i].account_number);
            printf("\nAccount Balance: %.2lf\n", records[i].balance);
        }
    }
}

int find_record(BankRecord *records, int num_records, int account_number) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}

void update_record(BankRecord *records, int num_records) {
    int account_number, index;
    double new_balance;
    printf("\nEnter the account number of the record you want to update: ");
    scanf("%d", &account_number);
    index = find_record(records, num_records, account_number);
    if (index == -1) {
        printf("\nRecord not found.\n");
    } else {
        printf("\nEnter the new balance for the record: ");
        scanf("%lf", &new_balance);
        records[index].balance = new_balance;
        printf("\nRecord updated successfully.\n");
    }
}

void delete_record(BankRecord *records, int *num_records) {
    int account_number, index;
    printf("\nEnter the account number of the record you want to delete: ");
    scanf("%d", &account_number);
    index = find_record(records, *num_records, account_number);
    if (index == -1) {
        printf("\nRecord not found.\n");
    } else {
        for (int i = index; i < *num_records - 1; i++) {
            records[i] = records[i+1];
        }
        *num_records -= 1;
        printf("\nRecord deleted successfully.\n");
    }
}