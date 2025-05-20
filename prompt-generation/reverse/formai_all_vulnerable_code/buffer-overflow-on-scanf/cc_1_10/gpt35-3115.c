//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
// C Banking Record System
// A program that allows users to create a bank record, 
// update an existing record and display all records

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for bank record
struct bank_record {
    char name[50];
    char account_no[20];
    float balance;
};

// Function prototype for option menu
void option_menu();

// Main function
int main()
{
    int choice, num_records = 0, found = 0;
    struct bank_record records[100];

    printf("********** Welcome to the Banking Record System ***********\n\n");

    while (1) {
        option_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Creating a new record
            printf("\n**** Creating a new record ****\n");
            printf("Enter name: ");
            scanf("%s", records[num_records].name);
            printf("Enter account number: ");
            scanf("%s", records[num_records].account_no);
            printf("Enter balance: ");
            scanf("%f", &records[num_records].balance);
            num_records++;
            printf("*** Record created successfully ***\n\n");
            break;

        case 2:
            // Updating an existing record
            found = 0;
            printf("\n**** Updating an existing record ****\n");
            printf("Enter account number: ");
            char update_acc_no[20];
            scanf("%s", update_acc_no);

            for (int i = 0; i < num_records; i++) {
                if (strcmp(update_acc_no, records[i].account_no) == 0) {
                    found = 1;
                    printf("Enter new balance: ");
                    scanf("%f", &records[i].balance);
                    printf("*** Record updated successfully ***\n\n");
                    break;
                }
            }

            if (!found) {
                printf("*** Account number not found ***\n\n");
            }
            break;

        case 3:
            // Display all records
            printf("\n**** Displaying all records ****\n");
            if (num_records == 0) {
                printf("\n*** No records found ***\n\n");
            }
            for (int i = 0; i < num_records; i++) {
                printf("Name: %s\n", records[i].name);
                printf("Account number: %s\n", records[i].account_no);
                printf("Balance: %.2f\n\n", records[i].balance);
            }
            break;

        case 4:
            // Exiting the program
            printf("\n********** Thank you for using the Banking Record System **********\n\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n\n");
            break;
        }
    }
}

// Function definition for option menu
void option_menu()
{
    printf("****** MENU ******\n");
    printf("1. Create a new record\n");
    printf("2. Update an existing record\n");
    printf("3. Display all records\n");
    printf("4. Exit\n");
}