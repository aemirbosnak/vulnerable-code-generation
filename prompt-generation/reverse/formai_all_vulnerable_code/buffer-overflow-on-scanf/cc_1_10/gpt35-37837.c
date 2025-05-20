//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for the banking record */
struct bankRecord {
    char accountNumber[10];
    char accountHolderName[50];
    float balance;
};

/* Function to print out the menu options */
void printMenu() {
    printf("Welcome to the banking record system!\n");
    printf("1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Display record by account number\n");
    printf("4. Exit\n");
}

/* Function to add a new record */
void addRecord(struct bankRecord bank[], int *numRecords) {
    char temp[50];
    printf("Enter account number: ");
    fflush(stdin);
    fgets(bank[*numRecords].accountNumber, 10, stdin);
    printf("Enter account holder name: ");
    fflush(stdin);
    fgets(bank[*numRecords].accountHolderName, 50, stdin);
    printf("Enter balance: ");
    fflush(stdin);
    fgets(temp, 50, stdin);
    bank[*numRecords].balance = atof(temp);
    (*numRecords)++;
    printf("Record added successfully!\n");
}

/* Function to display all records */
void displayAllRecords(struct bankRecord bank[], int numRecords) {
    int i;
    for (i = 0; i < numRecords; i++) {
        printf("Account number: %s", bank[i].accountNumber);
        printf("Account holder name: %s", bank[i].accountHolderName);
        printf("Balance: $%.2f\n", bank[i].balance);
    }
}

/* Function to display a single record by account number */
void displayRecordByAccountNumber(struct bankRecord bank[], int numRecords) {
    char accountNumber[10];
    int i, found = 0;
    printf("Enter account number: ");
    fflush(stdin);
    fgets(accountNumber, 10, stdin);
    for (i = 0; i < numRecords; i++) {
        if (strcmp(bank[i].accountNumber, accountNumber) == 0) {
            printf("Account number: %s", bank[i].accountNumber);
            printf("Account holder name: %s", bank[i].accountHolderName);
            printf("Balance: $%.2f\n", bank[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

/* Main function to run the program */
int main() {
    struct bankRecord bank[100];
    int option, numRecords = 0;

    do {
        printMenu();
        printf("Enter option: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option) {
            case 1:
                addRecord(bank, &numRecords);
                break;
            case 2:
                displayAllRecords(bank, numRecords);
                break;
            case 3:
                displayRecordByAccountNumber(bank, numRecords);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }

    } while (option != 4);

    return 0;
}