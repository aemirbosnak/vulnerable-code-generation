//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100 // maximum number of records in the system
#define MAX_NAME_LENGTH 50 // maximum length of a name
#define MAX_ACCOUNT_LENGTH 10 // maximum length of an account number

// define a struct to represent a banking record
typedef struct {
    char name[MAX_NAME_LENGTH];
    char account[MAX_ACCOUNT_LENGTH];
    double balance;
} Record;

// define a function to add a record to the system
void addRecord(Record records[], int *numEntries) {
    // check if there is space to add another record
    if (*numEntries >= MAX_ENTRIES) {
        printf("The system is already full.\n");
        return;
    }

    // get user input for the new record
    Record newRecord;
    printf("Enter the name of the account holder: ");
    fgets(newRecord.name, MAX_NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // remove trailing newline
    printf("Enter the account number: ");
    fgets(newRecord.account, MAX_ACCOUNT_LENGTH, stdin);
    newRecord.account[strcspn(newRecord.account, "\n")] = 0; // remove trailing newline
    printf("Enter the current balance: ");
    scanf("%lf", &newRecord.balance);
    getchar(); // consume the newline character left behind by scanf

    // add the new record to the system
    records[*numEntries] = newRecord;
    *numEntries += 1;
    printf("Record added successfully.\n");
}

// define a function to display all the records in the system
void displayRecords(Record records[], int numEntries) {
    printf("Name\tAccount\tBalance\n");
    printf("----\t-------\t-------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\t%.2f\n", records[i].name, records[i].account, records[i].balance);
    }
}

int main() {
    // create an array to hold all the records
    Record records[MAX_ENTRIES];
    int numEntries = 0; // keep track of the number of records currently in the system

    // display the menu and prompt the user for input
    char choice;
    do {
        printf("Menu:\n");
        printf("a. Add a record\n");
        printf("d. Display all records\n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar(); // consume the newline character left behind by scanf

        // carry out the appropriate action based on the user's choice
        switch (choice) {
            case 'a':
                addRecord(records, &numEntries);
                break;
            case 'd':
                displayRecords(records, numEntries);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'q');

    return 0;
}