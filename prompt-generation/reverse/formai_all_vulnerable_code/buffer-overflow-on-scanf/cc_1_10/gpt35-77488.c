//FormAI DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to represent bank account information
struct BankRecord {
    char name[50];
    int accountNo;
    float balance;
};

//Function to add a new bank record to the system
void addRecord(struct BankRecord *bankRecords, int recordCount) {

    //Get record details from user
    printf("Enter name: ");
    scanf("%s", bankRecords[recordCount].name);
    printf("Enter account number: ");
    scanf("%d", &bankRecords[recordCount].accountNo);
    printf("Enter balance: ");
    scanf("%f", &bankRecords[recordCount].balance);

    //Increment record count
    recordCount++;

    //Print confirmation message
    printf("Record added successfully.\n");

}

//Function to display all bank records in the system
void displayRecords(struct BankRecord *bankRecords, int recordCount) {
    int i;

    //Print header row
    printf("%-20s %-20s %-20s\n", "Name", "Account No.", "Balance");

    //Print each record
    for(i=0; i<recordCount; i++) {
        printf("%-20s %-20d %-20.2f\n", bankRecords[i].name, bankRecords[i].accountNo, bankRecords[i].balance);
    }
}

int main() {

    //Initialize variables
    char option;
    struct BankRecord *bankRecords;
    int recordCount = 0, i;

    //Allocate space for bank records array
    bankRecords = (struct BankRecord *) malloc(sizeof(struct BankRecord) * 10);

    //Main menu loop
    do {
        //Print menu options
        printf("\n\n");
        printf("Welcome to the Banking Record System.\n");
        printf("1. Add New Record\n");
        printf("2. Display All Records\n");
        printf("Q. Quit\n");
        printf("Enter Option: ");

        //Get user option
        scanf(" %c", &option);

        switch(option) {
            case '1':
                addRecord(bankRecords, recordCount);
                break;
            case '2':
                displayRecords(bankRecords, recordCount);
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while(option!='q' && option!='Q');

    //Free allocated memory
    free(bankRecords);

    return 0;
}