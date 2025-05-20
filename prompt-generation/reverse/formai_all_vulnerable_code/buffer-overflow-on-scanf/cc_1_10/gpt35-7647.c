//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bank account details 
struct Account{
    int account_no;
    char name[50];
    double balance;
};

// Functions to perform various operations on account records
int create_account(struct Account *accounts, int num_accounts);
void view_account(struct Account *accounts, int num_accounts);
void search_account(struct Account *accounts, int num_accounts);
void update_account(struct Account *accounts, int num_accounts);
void delete_account(struct Account *accounts, int num_accounts);

int main(){
    // Variables to hold number of accounts and user's choice
    int num_accounts = 0;
    int choice = 0;
    
    // Create an array of accounts
    struct Account accounts[100];
    
    do{
        // Prompt user to choose an option
        printf("\nPlease choose an option:\n");
        printf("1. Create account\n");
        printf("2. View account\n");
        printf("3. Search account\n");
        printf("4. Update account\n");
        printf("5. Delete account\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        
        // Perform the corresponding action based on the user's choice
        switch(choice){
            case 1:
                num_accounts = create_account(accounts, num_accounts);
                break;
            case 2:
                view_account(accounts, num_accounts);
                break;
            case 3:
                search_account(accounts, num_accounts);
                break;
            case 4:
                update_account(accounts, num_accounts);
                break;
            case 5:
                delete_account(accounts, num_accounts);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while(choice != 6);
    
    return 0;
}

int create_account(struct Account *accounts, int num_accounts){
    // Prompt user to input account details
    printf("\nEnter account details:\n");
    printf("Account number: ");
    scanf("%d", &accounts[num_accounts].account_no);
    printf("Name: ");
    scanf("%s", accounts[num_accounts].name);
    printf("Balance: ");
    scanf("%lf", &accounts[num_accounts].balance);
    
    // Increment number of accounts
    num_accounts++;
    
    return num_accounts;
}

void view_account(struct Account *accounts, int num_accounts){
    // Prompt user to input account number
    int account_no = 0;
    printf("\nEnter account number: ");
    scanf("%d", &account_no);
    
    // Search for the account and print its details
    int i;
    for(i=0; i<num_accounts; i++){
        if(accounts[i].account_no == account_no){
            printf("\nAccount number: %d\n", accounts[i].account_no);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    
    // If account not found, display error message
    printf("\nAccount not found!\n");
}

void search_account(struct Account *accounts, int num_accounts){
    // Prompt user to input search query
    char query[50];
    printf("\nEnter search query: ");
    scanf("%s", query);
    
    // Search for all accounts containing the search query in their name and print their details
    int i;
    for(i=0; i<num_accounts; i++){
        if(strstr(accounts[i].name, query)){
            printf("\nAccount number: %d\n", accounts[i].account_no);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2lf\n", accounts[i].balance);
        }
    }
}

void update_account(struct Account *accounts, int num_accounts){
    // Prompt user to input account number to be updated
    int account_no = 0;
    printf("\nEnter account number to be updated: ");
    scanf("%d", &account_no);
    
    // Search for the account and update its details
    int i;
    for(i=0; i<num_accounts; i++){
        if(accounts[i].account_no == account_no){
            printf("\nEnter new account details:\n");
            printf("Account number: ");
            scanf("%d", &accounts[i].account_no);
            printf("Name: ");
            scanf("%s", accounts[i].name);
            printf("Balance: ");
            scanf("%lf", &accounts[i].balance);
            return;
        }
    }
    
    // If account not found, display error message
    printf("\nAccount not found!\n");
}

void delete_account(struct Account *accounts, int num_accounts){
    // Prompt user to input account number to be deleted
    int account_no = 0;
    printf("\nEnter account number to be deleted: ");
    scanf("%d", &account_no);
    
    // Search for the account and delete it by shifting all subsequent accounts one position to the left
    int i, j;
    for(i=0; i<num_accounts; i++){
        if(accounts[i].account_no == account_no){
            for(j=i; j<num_accounts-1; j++){
                accounts[j] = accounts[j+1];
            }
            num_accounts--;
            printf("\nAccount deleted successfully!\n");
            return;
        }
    }
    
    // If account not found, display error message
    printf("\nAccount not found!\n");
}