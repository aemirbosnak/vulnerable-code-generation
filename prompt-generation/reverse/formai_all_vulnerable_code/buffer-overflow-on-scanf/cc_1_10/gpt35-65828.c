//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
/*******************************************************
 * C BANKING RECORD SYSTEM                             *
 *                                                     *
 * Description: A program to store and display banking *
 *              records for customers.                  *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for customer records
struct customer {
    char name[50];
    char account_no[20];
    float balance;
};

// Create an array to hold customer records
struct customer records[100];

// Declare function to add new customer record
void add_customer() {
    int i;
    // Loop through array to find first empty slot
    for (i = 0; i < 100; i++) {
        if (strlen(records[i].name) == 0) {
            // Get details from user
            printf("\nEnter customer name: ");
            scanf("%s", records[i].name);
            printf("Enter account number: ");
            scanf("%s", records[i].account_no);
            printf("Enter opening balance: ");
            scanf("%f", &records[i].balance);
            printf("\nNew customer added successfully!\n");
            return;
        }
    }
    printf("\nError: Maximum number of customers reached!\n");
}

// Declare function to display all customer records
void display_all() {
    int i;
    printf("\n%-20s %-20s %s\n", "Name", "Account Number", "Balance");
    for (i = 0; i < 100; i++) {
        if (strlen(records[i].name) > 0) {
            printf("%-20s %-20s $%.2f\n", records[i].name, records[i].account_no, records[i].balance);
        }
    }
}

// Declare function to search for customer record by account number
void search_by_account() {
    char account_no[20];
    int i;
    // Get account number from user
    printf("\nEnter account number: ");
    scanf("%s", account_no);
    // Loop through array to find matching record
    for (i = 0; i < 100; i++) {
        if (strcmp(records[i].account_no, account_no) == 0) {
            printf("\n%-20s %-20s %s\n", "Name", "Account Number", "Balance");
            printf("%-20s %-20s $%.2f\n", records[i].name, records[i].account_no, records[i].balance);
            return;
        }
    }
    printf("\nError: Customer record not found!\n");
}

// Declare function to delete customer record
void delete_customer() {
    char account_no[20];
    int i;
    // Get account number from user
    printf("\nEnter account number: ");
    scanf("%s", account_no);
    // Loop through array to find matching record
    for (i = 0; i < 100; i++) {
        if (strcmp(records[i].account_no, account_no) == 0) {
            // Delete record
            strcpy(records[i].name, "");
            strcpy(records[i].account_no, "");
            records[i].balance = 0.0;
            printf("\nCustomer record deleted successfully!\n");
            return;
        }
    }
    printf("\nError: Customer record not found!\n");
}

// Declare function to update customer record
void update_customer() {
    char account_no[20];
    int i;
    // Get account number from user
    printf("\nEnter account number: ");
    scanf("%s", account_no);
    // Loop through array to find matching record
    for (i = 0; i < 100; i++) {
        if (strcmp(records[i].account_no, account_no) == 0) {
            // Get new balance from user
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("\nCustomer record updated successfully!\n");
            return;
        }
    }
    printf("\nError: Customer record not found!\n");
}

int main() {
    int choice;
    // Loop to display menu and get user input
    while (1) {
        printf("\n1. Add new customer");
        printf("\n2. Display all customers");
        printf("\n3. Search customer by account number");
        printf("\n4. Delete customer");
        printf("\n5. Update customer record");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                display_all();
                break;
            case 3:
                search_by_account();
                break;
            case 4:
                delete_customer();
                break;
            case 5:
                update_customer();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}