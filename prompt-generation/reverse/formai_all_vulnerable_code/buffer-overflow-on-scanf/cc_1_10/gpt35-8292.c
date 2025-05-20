//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include<stdio.h>
#include<string.h>

// Define a structure to store bank records
struct bankRecord{
    int accountNumber;
    char name[30];
    double balance;
};

// Declare global array of bank records
struct bankRecord allRecords[100];

// Declare global integer variable to keep track of the number of records
int numOfRecords = 0;

// Function to add a new bank record to the system
void addRecord(){
    struct bankRecord newRecord;
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNumber);
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter balance: ");
    scanf("%lf", &newRecord.balance);
    allRecords[numOfRecords] = newRecord;
    numOfRecords++;
    printf("\nRecord added successfully!\n\n");
}

// Function to display all bank records in the system
void displayRecords(){
    printf("\nAll bank records: \n\n");
    for(int i=0; i<numOfRecords; i++){
        printf("Account number: %d\n", allRecords[i].accountNumber);
        printf("Name: %s\n", allRecords[i].name);
        printf("Balance: $%.2lf\n\n", allRecords[i].balance);
    }
}

// Function to search for a specific bank record by account number
void searchRecord(){
    int accountNumber;
    printf("Enter account number to search: ");
    scanf("%d", &accountNumber);
    for(int i=0; i<numOfRecords; i++){
        if(allRecords[i].accountNumber == accountNumber){
            printf("\nRecord found!\n\n");
            printf("Account number: %d\n", allRecords[i].accountNumber);
            printf("Name: %s\n", allRecords[i].name);
            printf("Balance: $%.2lf\n\n", allRecords[i].balance);
            return;
        }
    }
    printf("\nRecord not found!\n\n");
}

int main(){
    int choice = 0;
    while(choice != 4){
        printf("What would you like to do?\n");
        printf("1. Add a new bank record\n");
        printf("2. Display all bank records\n");
        printf("3. Search for a specific bank record\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
    }
    return 0;
}