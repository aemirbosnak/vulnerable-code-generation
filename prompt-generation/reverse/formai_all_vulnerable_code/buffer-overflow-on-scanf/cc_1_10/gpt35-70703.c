//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct record {
    char customer_name[MAX_SIZE];
    int account_number;
    float balance;
};

void print_menu();
void create_record(struct record **, int *);
void display_all_records(struct record *, int);
void display_single_record(struct record *, int);
void deposit_amount(struct record *, int);
void withdraw_amount(struct record *, int);

int main() {
    int num_records = 0;
    struct record *records = NULL;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_record(&records, &num_records);
                break;
            case 2:
                display_all_records(records, num_records);
                break;
            case 3:
                display_single_record(records, num_records);
                break;
            case 4:
                deposit_amount(records, num_records);
                break;
            case 5:
                withdraw_amount(records, num_records);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    free(records);

    return 0;
}

void print_menu() {
    printf("\n1. Create record\n");
    printf("2. Display all records\n");
    printf("3. Display single record\n");
    printf("4. Deposit amount\n");
    printf("5. Withdraw amount\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void create_record(struct record **records, int *num_records) {
    struct record new_record;

    printf("Enter customer name: ");
    scanf("%s", new_record.customer_name);
    printf("Enter account number: ");
    scanf("%d", &new_record.account_number);
    printf("Enter balance: ");
    scanf("%f", &new_record.balance);

    *num_records += 1;

    if (*records == NULL) {
        *records = (struct record *) malloc(sizeof(struct record));
    } else {
        *records = (struct record *) realloc(*records, (*num_records) * sizeof(struct record));
    }

    if (*records == NULL) {
        printf("Memory allocation failed\n");
    } else {
        (*records)[*num_records - 1] = new_record;
        printf("Record created successfully\n");
    }
}

void display_all_records(struct record *records, int num_records) {
    if (num_records == 0) {
        printf("No records found\n");
    } else {
        printf("Customer Name\t\tAccount Number\t\tBalance\n");
        printf("-----------------------------------------------------------\n");

        for (int i = 0; i < num_records; i++) {
            printf("%-20s\t\t%-10d\t\t%.2f\n", records[i].customer_name, records[i].account_number, records[i].balance);
        }
    }
}

void display_single_record(struct record *records, int num_records) {
    int account_number;

    if (num_records == 0) {
        printf("No records found\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("%-20s\t\t%-10d\t\t%.2f\n", records[i].customer_name, records[i].account_number, records[i].balance);
            return;
        }
    }

    printf("No record found with account number %d\n", account_number);
}

void deposit_amount(struct record *records, int num_records) {
    int account_number;
    float amount;

    if (num_records == 0) {
        printf("No records found\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            records[i].balance += amount;

            printf("Deposit successful\n");
            printf("New balance for account %d: %.2f\n", account_number, records[i].balance);

            return;
        }
    }

    printf("No record found with account number %d\n", account_number);
}

void withdraw_amount(struct record *records, int num_records) {
    int account_number;
    float amount;

    if (num_records == 0) {
        printf("No records found\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= records[i].balance) {
                records[i].balance -= amount;

                printf("Withdrawal successful\n");
                printf("New balance for account %d: %.2f\n", account_number, records[i].balance);
            } else {
                printf("Insufficient balance\n");
            }

            return;
        }
    }

    printf("No record found with account number %d\n", account_number);
}