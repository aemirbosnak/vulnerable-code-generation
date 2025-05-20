//FormAI DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
// Define the maximum number of accounts to be stored in the record system  
#define MAX_ACCOUNTS 100  
  
// Struct for holding the account details  
typedef struct {  
    char name[20];  
    int account_number;  
    float balance;  
} account;  
  
// Declare the array to hold the accounts  
account accounts[MAX_ACCOUNTS];  
  
// Declare the function to display the menu  
void display_menu() {  
    printf("--- Banking Record System ---\n");  
    printf("1. Add an account\n");  
    printf("2. Search an account\n");  
    printf("3. Update an account\n");  
    printf("4. Delete an account\n");  
    printf("5. Display all accounts\n");  
    printf("6. Exit\n\n");  
}  
  
// Declare the function to add an account  
void add_account() {  
    // Declare variables to hold the details of the new account  
    char name[20];  
    int account_number;  
    float balance;  
    
    // Ask the user for the new account details  
    printf("--- Add Account ---\n");  
    printf("Enter name: ");  
    scanf("%s", name);  
    printf("Enter account number: ");  
    scanf("%d", &account_number);  
    printf("Enter balance: ");  
    scanf("%f", &balance);  
    
    // Create a new account struct  
    account new_account;  
    strcpy(new_account.name, name);  
    new_account.account_number = account_number;  
    new_account.balance = balance;  
    
    // Add the new account to the array  
    for (int i = 0; i < MAX_ACCOUNTS; i++) {  
        if (accounts[i].account_number == 0) {  
            accounts[i] = new_account;  
            printf("Account added successfully.\n\n");  
            break;  
        }  
    }  
}  
  
// Declare the function to search for an account  
void search_account() {  
    // Declare a variable to hold the account number to search for  
    int search_account_number;  
    
    // Ask the user for the account number to search for  
    printf("--- Search Account ---\n");  
    printf("Enter account number to search for: ");  
    scanf("%d", &search_account_number);  
    
    // Search for the account  
    int found = 0;  
    for (int i = 0; i < MAX_ACCOUNTS; i++) {  
        if (accounts[i].account_number == search_account_number) {  
            printf("Account found:\n");  
            printf("Name: %s\n", accounts[i].name);  
            printf("Account number: %d\n", accounts[i].account_number);  
            printf("Balance: %.2f\n\n", accounts[i].balance);  
            found = 1;  
            break;  
        }  
    }  
    
    // If the account was not found, let the user know  
    if (!found) {  
        printf("Account not found.\n\n");  
    }  
}  
  
// Declare the function to update an account  
void update_account() {  
    // Declare a variable to hold the account number to update  
    int update_account_number;  
    
    // Ask the user for the account number to update  
    printf("--- Update Account ---\n");  
    printf("Enter account number to update: ");  
    scanf("%d", &update_account_number);  
    
    // Search for the account  
    int found = 0;  
    for (int i = 0; i < MAX_ACCOUNTS; i++) {  
        if (accounts[i].account_number == update_account_number) {  
            // Ask the user for the new details  
            char name[20];  
            float balance;  
            printf("Enter new name: ");  
            scanf("%s", name);  
            printf("Enter new balance: ");  
            scanf("%f", &balance);  
            
            // Update the account details  
            strcpy(accounts[i].name, name);  
            accounts[i].balance = balance;  
            
            printf("Account updated successfully.\n\n");  
            found = 1;  
            break;  
        }  
    }  
    
    // If the account was not found, let the user know  
    if (!found) {  
        printf("Account not found.\n\n");  
    }  
}  
  
// Declare the function to delete an account  
void delete_account() {  
    // Declare a variable to hold the account number to delete  
    int delete_account_number;  
    
    // Ask the user for the account number to delete  
    printf("--- Delete Account ---\n");  
    printf("Enter account number to delete: ");  
    scanf("%d", &delete_account_number);  
    
    // Search for the account  
    int found = 0;  
    for (int i = 0; i < MAX_ACCOUNTS; i++) {  
        if (accounts[i].account_number == delete_account_number) {  
            // Remove the account  
            accounts[i].account_number = 0;  
            accounts[i].balance = 0;  
            strcpy(accounts[i].name, "");  
            
            printf("Account deleted successfully.\n\n");  
            found = 1;  
            break;  
        }  
    }  
    
    // If the account was not found, let the user know  
    if (!found) {  
        printf("Account not found.\n\n");  
    }  
}  
  
// Declare the function to display all accounts  
void display_accounts() {  
    printf("--- All Accounts ---\n");  
    
    // Loop through all accounts and print them  
    for (int i = 0; i < MAX_ACCOUNTS; i++) {  
        if (accounts[i].account_number != 0) {  
            printf("Name: %s\n", accounts[i].name);  
            printf("Account number: %d\n", accounts[i].account_number);  
            printf("Balance: %.2f\n\n", accounts[i].balance);  
        }  
    }  
}  
  
// Main function  
int main() {  
    // Display the menu  
    display_menu();  
    
    // Loop until the user chooses to exit  
    int choice;  
    while (1) {  
        printf("Enter choice: ");  
        scanf("%d", &choice);  
        
        switch (choice) {  
            case 1:  
                add_account();  
                break;  
            case 2:  
                search_account();  
                break;  
            case 3:  
                update_account();  
                break;  
            case 4:  
                delete_account();  
                break;  
            case 5:  
                display_accounts();  
                break;  
            case 6:  
                exit(0);  
            default:  
                printf("Invalid choice. Please try again.\n\n");  
        }  
        
        display_menu();  
    }  
    
    return 0;  
}