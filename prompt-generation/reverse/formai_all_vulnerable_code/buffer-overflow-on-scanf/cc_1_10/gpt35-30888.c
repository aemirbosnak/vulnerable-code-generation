//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

void add_record(struct bank_record records[], int *size);
void display_records(struct bank_record records[], int size);
void search_record(struct bank_record records[], int size, char name[]);
void update_record(struct bank_record records[], int size, int account_number, float amount);
void delete_record(struct bank_record records[], int *size, int account_number);

int main() {
    struct bank_record records[100];
    int size = 0;
    int choice, account_number;
    char name[50];
    float amount;

    printf("Welcome to Sherlock Bank\n\n");

    do {
        printf("Please choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Search a record by name\n");
        printf("4. Update a record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_record(records, &size);
                break;
            case 2:
                display_records(records, size);
                break;
            case 3:
                printf("Enter the name of the account holder: ");
                scanf("%s", name);
                printf("\n");
                search_record(records, size, name);
                break;
            case 4:
                printf("Enter the account number: ");
                scanf("%d", &account_number);
                printf("Enter the amount to be added: ");
                scanf("%f", &amount);
                printf("\n");
                update_record(records, size, account_number, amount);
                break;
            case 5:
                printf("Enter the account number: ");
                scanf("%d", &account_number);
                printf("\n");
                delete_record(records, &size, account_number);
                break;
            case 6:
                printf("Thank you for choosing Sherlock Bank!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 6);

    return 0;
}

void add_record(struct bank_record records[], int *size) {
    printf("Enter the following details:\n");
    printf("Name: ");
    scanf("%s", records[*size].name);
    printf("Account number: ");
    scanf("%d", &records[*size].account_number);
    printf("Balance: ");
    scanf("%f", &records[*size].balance);
    printf("\nNew record added successfully!\n\n");
    (*size)++;
}

void display_records(struct bank_record records[], int size) {
    if (size == 0) {
        printf("No records found!\n\n");
        return;
    }
    printf("Bank records:\n\n");
    printf("%-20s%-20s%-20s\n", "Name", "Account Number", "Balance");
    for (int i = 0; i < size; i++) {
        printf("%-20s%-20d%-20.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
    printf("\n");
}

void search_record(struct bank_record records[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("%-20s%-20s%-20s\n", "Name", "Account Number", "Balance");
            printf("%-20s%-20d%-20.2f\n", records[i].name, records[i].account_number, records[i].balance);
            printf("\n");
            return;
        }
    }
    printf("Record not found!\n\n");
}

void update_record(struct bank_record records[], int size, int account_number, float amount) {
    for (int i = 0; i < size; i++) {
        if (records[i].account_number == account_number) {
            records[i].balance += amount;
            printf("\nThe new balance is %.2f\n\n", records[i].balance);
            return;
        }
    }
    printf("Record not found!\n\n");
}

void delete_record(struct bank_record records[], int *size, int account_number) {
    for (int i = 0; i < *size; i++) {
        if (records[i].account_number == account_number) {
            for (int j = i; j < *size - 1; j++) {
                records[j] = records[j + 1];
            }
            (*size)--;
            printf("Record deleted successfully!\n\n");
            return;
        }
    }
    printf("Record not found!\n\n");
}