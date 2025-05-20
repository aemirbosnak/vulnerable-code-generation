//FormAI DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    int account_number;
    double balance;
    Date last_transaction;
} Account;

// Declare Functions

void display_menu();
void add_account();
void search_account();
void display_account(Account account);
void display_all_accounts();
void update_account();
void delete_account();
void update_last_transaction(Account* account);
void save_to_file();
void read_from_file();
int get_account_index(int account_number);

// Define global variables

Account accounts[1000];
int num_of_accounts = 0;

// Main function

int main() {
    int choice;
    read_from_file();

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                display_all_accounts();
                break;
            case 4:
                update_account();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                save_to_file();
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input! Try again.\n");
        }
    }
}

// Display menu function

void display_menu() {
    printf("\n------ Banking Record System Menu ------\n\n");
    printf("1. Add Account\n");
    printf("2. Search Account\n");
    printf("3. Display All Accounts\n");
    printf("4. Update Account\n");
    printf("5. Delete Account\n");
    printf("6. Exit\n");
    printf("\n");
}

// Add account function

void add_account() {
    Account new_account;
    printf("\nEnter Account Name: ");
    fgets(new_account.name, 50, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0;
    printf("Enter Account Number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter Account Balance: ");
    scanf("%lf", &new_account.balance);
    printf("Enter Last Transaction Date (dd mm yyyy): ");
    scanf("%d %d %d", &new_account.last_transaction.day, &new_account.last_transaction.month, &new_account.last_transaction.year);
    while (getchar() != '\n');

    accounts[num_of_accounts] = new_account;
    num_of_accounts++;

    printf("Account added successfully!\n");
}

// Search account function

void search_account() {
    int account_number, account_index;
    printf("\nEnter Account Number to search: ");
    scanf("%d", &account_number);

    account_index = get_account_index(account_number);

    if (account_index == -1) {
        printf("Account not found!\n");
    } else {
        display_account(accounts[account_index]);
    }
}

// Display account function

void display_account(Account account) {
    printf("\nAccount Name: %s\n", account.name);
    printf("Account Number: %d\n", account.account_number);
    printf("Account Balance: %.2lf\n", account.balance);
    printf("Last Transaction Date: %d/%d/%d\n", account.last_transaction.day, account.last_transaction.month, account.last_transaction.year);
}

// Display all accounts function

void display_all_accounts() {
    if (num_of_accounts == 0) {
        printf("No accounts to display!\n");
    } else {
        printf("\n---------- Accounts ----------\n\n");
        for (int i = 0; i < num_of_accounts; i++) {
            display_account(accounts[i]);
            printf("\n");
        }
    }
}

// Update account function

void update_account() {
    int account_number, account_index;
    printf("\nEnter Account Number to update: ");
    scanf("%d", &account_number);

    account_index = get_account_index(account_number);

    if (account_index == -1) {
        printf("Account not found!\n");
    } else {
        printf("\nEnter new Account Name: ");
        fgets(accounts[account_index].name, 50, stdin);
        accounts[account_index].name[strcspn(accounts[account_index].name, "\n")] = 0;
        printf("Enter new Account Number: ");
        scanf("%d", &accounts[account_index].account_number);
        printf("Enter new Account Balance: ");
        scanf("%lf", &accounts[account_index].balance);
        printf("Enter new Last Transaction Date (dd mm yyyy): ");
        scanf("%d %d %d", &accounts[account_index].last_transaction.day, &accounts[account_index].last_transaction.month, &accounts[account_index].last_transaction.year);
        while (getchar() != '\n');

        update_last_transaction(&accounts[account_index]);

        printf("Account updated successfully!\n");
    }
}

// Delete account function

void delete_account() {
    int account_number, account_index;
    printf("\nEnter Account Number to delete: ");
    scanf("%d", &account_number);

    account_index = get_account_index(account_number);

    if (account_index == -1) {
        printf("Account not found!\n");
    } else {
        for (int i = account_index + 1; i < num_of_accounts; i++) {
            accounts[i - 1] = accounts[i];
        }
        num_of_accounts--;

        printf("Account deleted successfully!\n");
    }
}

// Update last transaction function

void update_last_transaction(Account* account) {
    Date today;
    printf("Enter today's Date (dd mm yyyy): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);
    while (getchar() != '\n');

    if (today.year > account->last_transaction.year) {
        account->last_transaction = today;
    } else if (today.year == account->last_transaction.year && today.month > account->last_transaction.month) {
        account->last_transaction = today;
    } else if (today.year == account->last_transaction.year && today.month == account->last_transaction.month && today.day > account->last_transaction.day) {
        account->last_transaction = today;
    }
}

// Save to file function

void save_to_file() {
    FILE *fptr;

    fptr = fopen("banking_records.txt", "w");

    for (int i = 0; i < num_of_accounts; i++) {
        fprintf(fptr, "%s;%d;%.2lf;%d-%d-%d\n", accounts[i].name, accounts[i].account_number, accounts[i].balance, accounts[i].last_transaction.day, accounts[i].last_transaction.month, accounts[i].last_transaction.year);
    }

    fclose(fptr);

    printf("Data saved successfully!\n");
}

// Read from file function

void read_from_file() {
    FILE *fptr;
    char line[100];
    char *token;

    fptr = fopen("banking_records.txt", "r");

    if (fptr == NULL) {
        return;
    }

    while (fgets(line, 100, fptr)) {
        line[strcspn(line, "\n")] = 0;
        
        Account account;

        token = strtok(line, ";");
        strcpy(account.name, token);

        token = strtok(NULL, ";");
        account.account_number = atoi(token);

        token = strtok(NULL, ";");
        account.balance = atof(token);

        token = strtok(NULL, ";");
        sscanf(token, "%d-%d-%d", &account.last_transaction.day, &account.last_transaction.month, &account.last_transaction.year);

        accounts[num_of_accounts] = account;
        num_of_accounts++;
    }

    fclose(fptr);
}

// Get account index function

int get_account_index(int account_number) {
    for (int i = 0; i < num_of_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}