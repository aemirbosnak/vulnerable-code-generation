//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50

// Struct to hold the banking record for each customer
typedef struct {
    char fname[20]; // First name
    char lname[20]; // Last name
    int acc_num; // Account number
    double balance; // Account balance
} Record;

// Function prototypes
void add_record(Record*, int*);
void find_record(Record*, int);
void delete_record(Record*, int*);
void update_record(Record*, int);
void print_all_records(Record*, int);
void print_record(Record*);

int main() {
    Record records[MAX_RECORDS]; // Array to hold all customer records
    int num_records = 0; // Counter for number of records in array
    int option; // User choice for menu selection
    char fname[20], lname[20];
    int acc_num;

    // Display menu of options for user
    do {
        printf("\n\nBanking Record System Menu:\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Delete Record\n");
        printf("4. Update Record\n");
        printf("5. Print All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Add new record
                add_record(records, &num_records);
                break;
            case 2:
                // Find existing record
                printf("Enter first name: ");
                scanf("%s", fname);
                printf("Enter last name: ");
                scanf("%s", lname);
                printf("Enter account number: ");
                scanf("%d", &acc_num);
                find_record(records, num_records);
                break;
            case 3:
                // Delete existing record
                delete_record(records, &num_records);
                break;
            case 4:
                // Update existing record
                update_record(records, num_records);
                break;
            case 5:
                // Print all records
                print_all_records(records, num_records);
                break;
            case 6:
                // Exit program
                printf("Exiting program...\n");
                break;
            default:
                // Invalid selection
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}

void add_record(Record* records, int* num_records) {
    // Check if maximum number of records has been reached
    if (*num_records == MAX_RECORDS) {
        printf("Maximum number of records reached. Cannot add new record.\n");
        return;
    }

    // Get input from user for new record
    printf("Enter first name: ");
    scanf("%s", records[*num_records].fname);
    printf("Enter last name: ");
    scanf("%s", records[*num_records].lname);
    printf("Enter account number: ");
    scanf("%d", &records[*num_records].acc_num);
    printf("Enter balance: ");
    scanf("%lf", &records[*num_records].balance);

    // Increment number of records counter
    (*num_records)++;

    printf("New record added successfully.\n");
}

void find_record(Record* records, int num_records) {
    char fname[20], lname[20];
    int acc_num;
    int found = 0;

    // Get input from user for record to find
    printf("Enter first name: ");
    scanf("%s", fname);
    printf("Enter last name: ");
    scanf("%s", lname);
    printf("Enter account number: ");
    scanf("%d", &acc_num);

    // Loop over all records to find matching record
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].fname, fname) == 0 && strcmp(records[i].lname, lname) == 0 && records[i].acc_num == acc_num) {
            print_record(&records[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

void delete_record(Record* records, int* num_records) {
    char fname[20], lname[20];
    int acc_num;
    int found = 0;

    // Get input from user for record to delete
    printf("Enter first name: ");
    scanf("%s", fname);
    printf("Enter last name: ");
    scanf("%s", lname);
    printf("Enter account number: ");
    scanf("%d", &acc_num);

    // Loop over all records to find matching record
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i].fname, fname) == 0 && strcmp(records[i].lname, lname) == 0 && records[i].acc_num == acc_num) {
            // Shift all records after the one to delete back by one position
            for (int j = i; j < *num_records-1; j++) {
                records[j] = records[j+1];
            }
            (*num_records)--;
            printf("Record deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

void update_record(Record* records, int num_records) {
    char fname[20], lname[20];
    int acc_num;
    double balance;
    int found = 0;

    // Get input from user for record to update
    printf("Enter first name: ");
    scanf("%s", fname);
    printf("Enter last name: ");
    scanf("%s", lname);
    printf("Enter account number: ");
    scanf("%d", &acc_num);

    // Loop over all records to find matching record
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].fname, fname) == 0 && strcmp(records[i].lname, lname) == 0 && records[i].acc_num == acc_num) {
            printf("Enter new balance: ");
            scanf("%lf", &balance);
            records[i].balance = balance;
            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

void print_all_records(Record* records, int num_records) {
    if (num_records == 0) {
        printf("No records to display.\n");
        return;
    }

    for (int i = 0; i < num_records; i++) {
        print_record(&records[i]);
    }
}

void print_record(Record* record) {
    printf("\nFirst Name: %s\n", record->fname);
    printf("Last Name: %s\n", record->lname);
    printf("Account Number: %d\n", record->acc_num);
    printf("Balance: %.2lf\n", record->balance);
}