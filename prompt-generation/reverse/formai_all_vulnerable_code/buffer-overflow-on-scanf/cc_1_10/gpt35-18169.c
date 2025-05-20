//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000

// declare structure for expense record
struct Expense {
    char date[20];
    char category[20];
    float amount;
};

// declare function prototypes
void add_record(struct Expense[], int*);
void display_records(struct Expense[], int);
void filter_records(struct Expense[], int, char[]);
void delete_record(struct Expense[], int*);
void update_record(struct Expense[], int);

int main() {
    struct Expense expenses[MAX_RECORDS]; // initialize array of expense records
    int num_records = 0; // initialize number of records to 0
    int choice = 0; // initialize user choice to 0
    char filter_category[20]; // initialize filter category to empty string

    while (1) {
        printf("\nExpense Tracker Menu\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Filter Records by Category\n");
        printf("4. Delete Record\n");
        printf("5. Update Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        // get user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add record
                add_record(expenses, &num_records);
                break;
            case 2: // display records
                display_records(expenses, num_records);
                break;
            case 3: // filter records
                printf("Enter category to filter: ");
                scanf("%s", filter_category);
                filter_records(expenses, num_records, filter_category);
                break;
            case 4: // delete record
                delete_record(expenses, &num_records);
                break;
            case 5: // update record
                update_record(expenses, num_records);
                break;
            case 6: // exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void add_record(struct Expense expenses[], int* num_records) {
    // check if maximum number of records has been reached
    if (*num_records == MAX_RECORDS) {
        printf("Maximum number of records reached!\n");
        return;
    }

    // get user input
    printf("Enter date (in format dd/mm/yyyy): ");
    scanf("%s", expenses[*num_records].date);
    printf("Enter category: ");
    scanf("%s", expenses[*num_records].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*num_records].amount);

    // increment number of records
    (*num_records)++;

    printf("Record added successfully!\n");
}

void display_records(struct Expense expenses[], int num_records) {
    // check if there are no records
    if (num_records == 0) {
        printf("No records found!\n");
        return;
    }

    // print headers
    printf("%-20s%-20s%-20s\n", "Date", "Category", "Amount");
    printf("-----------------------------------------------\n");

    // loop through expense records and print them
    for (int i = 0; i < num_records; i++) {
        printf("%-20s%-20s%-20.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

void filter_records(struct Expense expenses[], int num_records, char filter_category[]) {
    // check if filter category matches any expense record
    int match_found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(expenses[i].category, filter_category) == 0) {
            match_found = 1;
            break;
        }
    }

    // print filtered results
    if (match_found) {
        printf("%-20s%-20s%-20s\n", "Date", "Category", "Amount");
        printf("-----------------------------------------------\n");

        for (int i = 0; i < num_records; i++) {
            if (strcmp(expenses[i].category, filter_category) == 0) {
                printf("%-20s%-20s%-20.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
            }
        }
    } else {
        printf("No records found with category: %s\n", filter_category);
    }
}

void delete_record(struct Expense expenses[], int* num_records) {
    // check if there are no records
    if (*num_records == 0) {
        printf("No records found!\n");
        return;
    }

    // get user input
    int record_num_to_delete;
    printf("Enter record number to delete (1-%d): ", *num_records);
    scanf("%d", &record_num_to_delete);

    // shift records to remove deleted record
    for (int i = record_num_to_delete - 1; i < *num_records - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    // decrement number of records
    (*num_records)--;

    printf("Record deleted successfully!\n");
}

void update_record(struct Expense expenses[], int num_records) {
    // check if there are no records
    if (num_records == 0) {
        printf("No records found!\n");
        return;
    }

    // get user input
    int record_num_to_update;
    printf("Enter record number to update (1-%d): ", num_records);
    scanf("%d", &record_num_to_update);
    record_num_to_update--;

    // display current record
    printf("Current Record:\n");
    printf("%-20s%-20s%-20s\n", "Date", "Category", "Amount");
    printf("-----------------------------------------------\n");
    printf("%-20s%-20s%-20.2f\n", expenses[record_num_to_update].date, expenses[record_num_to_update].category,
           expenses[record_num_to_update].amount);

    // get user input for new record
    printf("Enter new date (in format dd/mm/yyyy): ");
    scanf("%s", expenses[record_num_to_update].date);
    printf("Enter new category: ");
    scanf("%s", expenses[record_num_to_update].category);
    printf("Enter new amount: ");
    scanf("%f", &expenses[record_num_to_update].amount);

    printf("Record updated successfully!\n");
}