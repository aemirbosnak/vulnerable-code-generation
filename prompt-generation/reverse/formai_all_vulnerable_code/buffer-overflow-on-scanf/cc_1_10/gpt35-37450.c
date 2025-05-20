//FormAI DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Account {
    int id;
    char name[50];
    float balance;
};

int num_accounts = 0;  // number of accounts in the banking record system
struct Account accounts[MAX]; // banking record system database

// print all the accounts in the banking record system
void print_all_accounts() {
    if (num_accounts == 0) {
        printf("\nNo accounts found in the system.\n");
        return;
    }
    printf("\n\n-------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s |\n", "Account ID", "Name", "Balance");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("| %-10d | %-20s | %-10.2f |\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
    printf("-------------------------------------------------------\n");
}

// search for an account in the banking record system by ID
int search_account(int id) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            return i;
        }
    }
    return -1;
}

// add a new account to the banking record system
void add_account() {
    if (num_accounts == MAX) {
        printf("\nError: Maximum number of accounts reached.");
        return;
    }
    printf("\nEnter account details:\n");
    printf("ID: ");
    scanf("%d", &accounts[num_accounts].id);
    if (search_account(accounts[num_accounts].id) != -1) {
        printf("\nError: An account with the ID %d already exists.", accounts[num_accounts].id);
        return;
    }
    printf("Name: ");
    scanf("%s", accounts[num_accounts].name);
    printf("Balance: ");
    scanf("%f", &accounts[num_accounts].balance);
    num_accounts++;
    printf("\nAccount added successfully.\n");
}

// update an existing account in the banking record system
void update_account() {
    int id;
    printf("\nEnter account ID to update: ");
    scanf("%d", &id);
    int index = search_account(id);
    if (index == -1) {
        printf("\nError: Account with ID %d does not exist.", id);
        return;
    }
    printf("\nEnter new account details:\n");
    printf("Name: ");
    scanf("%s", accounts[index].name);
    printf("Balance: ");
    scanf("%f", &accounts[index].balance);
    printf("\nAccount updated successfully.\n");
}

// delete an existing account from the banking record system
void delete_account() {
    int id;
    printf("\nEnter account ID to delete: ");
    scanf("%d", &id);
    int index = search_account(id);
    if (index == -1) {
        printf("\nError: Account with ID %d does not exist.", id);
        return;
    }
    for (int i = index; i < num_accounts - 1; i++) {
        accounts[i] = accounts[i+1];
    }
    num_accounts--;
    printf("\nAccount deleted successfully.\n");
}

int main() {
    int choice;
    while(1) {
        printf("----------------------------------------------------\n");
        printf("          C BANKING RECORD SYSTEM                  \n");
        printf("----------------------------------------------------\n");
        printf("1. View all accounts\n");
        printf("2. Add account\n");
        printf("3. Update account\n");
        printf("4. Delete account\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                print_all_accounts();
                break;
            case 2:
                add_account();
                break;
            case 3:
                update_account();
                break;
            case 4:
                delete_account();
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}