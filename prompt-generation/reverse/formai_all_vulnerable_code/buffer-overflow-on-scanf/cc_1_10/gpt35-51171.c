//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 50
#define MAX_ACCOUNTS 100

// Structure definition
struct bankRecord {
    char name[MAX_NAME];
    int accountNumber;
    float balance;
};

// Function prototypes 
void addRecord(struct bankRecord accounts[], int *numAccounts);
void displayRecord(struct bankRecord accounts[], int numAccounts);
void searchRecord(struct bankRecord accounts[], int numAccounts, int accountNumber);

int main() {
    // Variable declarations
    struct bankRecord accounts[MAX_ACCOUNTS];
    int numAccounts = 0, option;

    // Menu-driven program
    do {
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                addRecord(accounts, &numAccounts);
                break;
            case 2:
                displayRecord(accounts, numAccounts);
                break;
            case 3:
                if(numAccounts == 0) {
                    printf("There are no records to search.\n");
                } else {
                    int accountNumber;
                    printf("Enter Account Number to search: ");
                    scanf("%d", &accountNumber);
                    searchRecord(accounts, numAccounts, accountNumber);
                }
                break;
            case 4:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid Option. Try Again.\n\n");
                break;
        }
    } while(option != 4);

    return 0;
}

// Function to add a record 
void addRecord(struct bankRecord accounts[], int *numAccounts) {
    // Input details of new record
    printf("Enter Name: ");
    scanf("%s", accounts[*numAccounts].name);
    printf("Enter Account Number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter Balance: ");
    scanf("%f", &accounts[*numAccounts].balance);

    // Increment number of records
    (*numAccounts)++;
    printf("\nRecord added sucessfully.\n\n");
}

// Function to display all records
void displayRecord(struct bankRecord accounts[], int numAccounts) {
    // Display header row
    printf("Name\t\tAccount Number\tBalance\n");

    // Display details of all records
    for(int i=0; i<numAccounts; i++) {
        printf("%s\t%d\t%.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
    printf("\n");
}

// Function to search for a record
void searchRecord(struct bankRecord accounts[], int numAccounts, int accountNumber) {
    // Search for record with given account number
    int foundRecord = 0;
    for(int i=0; i<numAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\nName: %s\nBalance: %.2f\n\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
            foundRecord = 1;
            break;
        }
    }

    // Display message if record not found
    if(!foundRecord) {
        printf("Record not found.\n\n");
    }
}