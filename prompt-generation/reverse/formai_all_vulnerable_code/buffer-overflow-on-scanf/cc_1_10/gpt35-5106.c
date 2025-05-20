//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

/* Data structure to hold banking records */
typedef struct {
    char name[50];
    char account_type[20];
    char account_number[20];
    double balance;
} bank_record_t;

/* Function declarations */
int get_choice();
void add_record(bank_record_t records[], int *count);
void edit_record(bank_record_t records[], int count);
void delete_record(bank_record_t records[], int *count);
void display_records(bank_record_t records[], int count);

/* Main function */
int main() {
    bank_record_t records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        choice = get_choice();

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                edit_record(records, count);
                break;
            case 3:
                delete_record(records, &count);
                break;
            case 4:
                display_records(records, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/* Function to get user's choice */
int get_choice() {
    int choice;

    printf("\nWelcome to the Banking Record System\n");
    printf("------------------------------------\n");
    printf("1. Add a New Record\n");
    printf("2. Edit a Record\n");
    printf("3. Delete a Record\n");
    printf("4. Display Records\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    return choice;
}

/* Function to add a new record */
void add_record(bank_record_t records[], int *count) {
    if (*count == MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    bank_record_t new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter account type: ");
    scanf("%s", new_record.account_type);

    printf("Enter account number: ");
    scanf("%s", new_record.account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record.balance);

    records[*count] = new_record;
    (*count)++;

    printf("Record added successfully.\n");
}

/* Function to edit a record */
void edit_record(bank_record_t records[], int count) {
    int index;
    char account_number[20];

    printf("Enter account number to edit: ");
    scanf("%s", account_number);

    /* Search for record with the given account number */
    for (index = 0; index < count; index++) {
        if (strcmp(records[index].account_number, account_number) == 0) {
            break;
        }
    }

    /* If record is not found */
    if (index == count) {
        printf("Record not found.\n");
        return;
    }

    bank_record_t new_record;

    printf("Enter new name (press enter to skip): ");
    getchar(); /* absorb newline */
    fgets(new_record.name, sizeof(new_record.name), stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0; /* remove trailing newline */

    printf("Enter new account type (press enter to skip): ");
    fgets(new_record.account_type, sizeof(new_record.account_type), stdin);
    new_record.account_type[strcspn(new_record.account_type, "\n")] = 0;

    printf("Enter new balance (-1 to skip): ");
    double balance;
    scanf("%lf", &balance);
    if (balance != -1.0) {
        new_record.balance = balance;
    } else {
        new_record.balance = records[index].balance; /* use old balance */
    }

    records[index] = new_record;

    printf("Record edited successfully.\n");
}

/* Function to delete a record */
void delete_record(bank_record_t records[], int *count) {
    int index;
    char account_number[20];

    printf("Enter account number to delete: ");
    scanf("%s", account_number);

    /* Search for record with the given account number */
    for (index = 0; index < *count; index++) {
        if (strcmp(records[index].account_number, account_number) == 0) {
            break;
        }
    }

    /* If record is not found */
    if (index == *count) {
        printf("Record not found.\n");
        return;
    }

    /* Move all records to the left after the one to be deleted */
    for (int i = index; i < *count - 1; i++) {
        records[i] = records[i + 1];
    }

    (*count)--;

    printf("Record deleted successfully.\n");
}

/* Function to display all records */
void display_records(bank_record_t records[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Name\t\tAccount Type\t\tAccount Number\t\tBalance\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s%-24s%-24s%.2lf\n", records[i].name, records[i].account_type, records[i].account_number, records[i].balance);
    }
}