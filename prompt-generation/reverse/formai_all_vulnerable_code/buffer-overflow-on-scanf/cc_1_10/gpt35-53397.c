//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store bank record
struct bankRecord {
    char name[20];
    int account_num;
    float balance;
};

//Function to get new account details
void newAccount(struct bankRecord *record) {
    printf("\nEnter name: ");
    scanf("%s", record->name);
    printf("\nEnter account number: ");
    scanf("%d", &(record->account_num));
    printf("\nEnter balance: ");
    scanf("%f", &(record->balance));
}

//Function to display an account's details
void displayAccount(struct bankRecord record) {
    printf("\nName: %s\nAccount number: %d\nBalance: $%.2f", record.name, record.account_num, record.balance);
}

//Function to search for an account by account number
void searchAccount(struct bankRecord records[], int total_accounts) {
    int account_num, i;
    printf("\nEnter account number to search: ");
    scanf("%d", &account_num);
    for(i=0; i<total_accounts; i++) {
        if(records[i].account_num == account_num) {
            displayAccount(records[i]);
            return;
        }
    }
    printf("\nAccount not found!");
}

//Function to display all accounts' details
void displayAllAccounts(struct bankRecord records[], int total_accounts) {
    int i;
    for(i=0; i<total_accounts; i++) {
        displayAccount(records[i]);
        printf("\n------------------");
    }
}

//Function to update an account's balance
void updateBalance(struct bankRecord records[], int total_accounts) {
    int account_num, i;
    float new_balance;
    printf("\nEnter account number to update balance: ");
    scanf("%d", &account_num);
    for(i=0; i<total_accounts; i++) {
        if(records[i].account_num == account_num) {
            printf("\nEnter new balance: ");
            scanf("%f", &new_balance);
            records[i].balance = new_balance;
            printf("\nBalance updated!\n");
            return;
        }
    }
    printf("\nAccount not found!");
}

//Main function
int main() {
    int choice, total_accounts=0, i;
    struct bankRecord *records;
    printf("Welcome to MyBanking Record System!\n");
    while(1) {
        printf("\n1. Add new account\n2. Search for an account\n3. Display all accounts\n4. Update account balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                //Allocate memory for new record
                records = realloc(records, (total_accounts+1)*sizeof(struct bankRecord));
                newAccount(&records[total_accounts]); //Get new account details
                total_accounts++; //Increase total number of accounts
                break;
            case 2:
                searchAccount(records, total_accounts); //Search for an account by account number
                break;
            case 3:
                displayAllAccounts(records, total_accounts); //Display all accounts' details
                break;
            case 4:
                updateBalance(records, total_accounts); //Update an account's balance
                break;
            case 5:
                printf("\nThank you for using MyBanking Record System!");
                free(records); //Free the dynamically allocated memory before exiting
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}