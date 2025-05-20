//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define account structure
typedef struct account {
    char name[50];
    int account_number;
    double balance;
} account;

// Read accounts from file
account *read_accounts(char *filename, int *num_accounts) {
    FILE *fp;
    account *accounts;
    int i = 0;

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    // Read number of accounts
    fscanf(fp, "%d", num_accounts);

    // Allocate memory for accounts
    accounts = malloc(*num_accounts * sizeof(account));
    if (accounts == NULL) {
        printf("Error allocating memory for accounts.\n");
        return NULL;
    }

    // Read accounts from file
    while (fscanf(fp, "%s %d %lf", accounts[i].name, &accounts[i].account_number, &accounts[i].balance) != EOF) {
        i++;
    }

    // Close file
    fclose(fp);

    return accounts;
}

// Write accounts to file
void write_accounts(char *filename, account *accounts, int num_accounts) {
    FILE *fp;
    int i;

    // Open file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write number of accounts
    fprintf(fp, "%d\n", num_accounts);

    // Write accounts to file
    for (i = 0; i < num_accounts; i++) {
        fprintf(fp, "%s %d %.2lf\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    // Close file
    fclose(fp);
}

// Create new account
account *create_account(char *name, int account_number, double balance) {
    account *new_account;

    // Allocate memory for new account
    new_account = malloc(sizeof(account));
    if (new_account == NULL) {
        printf("Error allocating memory for new account.\n");
        return NULL;
    }

    // Set account fields
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;

    return new_account;
}

// Deposit money into account
void deposit_money(account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from account
void withdraw_money(account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Transfer money between accounts
void transfer_money(account *from_account, account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Print account details
void print_account(account *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->account_number);
    printf("Balance: %.2lf\n", account->balance);
}

// Main function
int main() {
    int num_accounts = 0;
    account *accounts;
    char filename[] = "accounts.txt";
    int choice;
    char name[50];
    int account_number;
    double balance;
    double amount;
    account *from_account;
    account *to_account;

    // Read accounts from file
    accounts = read_accounts(filename, &num_accounts);
    if (accounts == NULL) {
        return 1;
    }

    // Print accounts
    for (int i = 0; i < num_accounts; i++) {
        print_account(&accounts[i]);
        printf("\n");
    }

    // Get user input
    while (1) {
        printf("Enter a choice:\n");
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Transfer money\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter balance: ");
                scanf("%lf", &balance);

                // Create new account
                account *new_account = create_account(name, account_number, balance);
                if (new_account == NULL) {
                    printf("Error creating new account.\n");
                    return 1;
                }

                // Add new account to array
                accounts = realloc(accounts, (num_accounts + 1) * sizeof(account));
                accounts[num_accounts++] = *new_account;

                // Print new account
                print_account(new_account);
                printf("\n");
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);

                // Find account by account number
                from_account = NULL;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_number) {
                        from_account = &accounts[i];
                        break;
                    }
                }

                if (from_account == NULL) {
                    printf("Account not found.\n");
                    return 1;
                }

                // Deposit money into account
                deposit_money(from_account, amount);

                // Print updated account
                print_account(from_account);
                printf("\n");
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);

                // Find account by account number
                from_account = NULL;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_number) {
                        from_account = &accounts[i];
                        break;
                    }
                }

                if (from_account == NULL) {
                    printf("Account not found.\n");
                    return 1;
                }

                // Withdraw money from account
                withdraw_money(from_account, amount);

                // Print updated account
                print_account(from_account);
                printf("\n");
                break;
            case 4:
                printf("Enter account number to transfer from: ");
                scanf("%d", &account_number);
                printf("Enter account number to transfer to: ");
                scanf("%d", &account_number);
                printf("Enter amount to transfer: ");
                scanf("%lf", &amount);

                // Find accounts by account number
                from_account = NULL;
                to_account = NULL;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].account_number == account_number) {
                        from_account = &accounts[i];
                    } else if (accounts[i].account_number == account_number) {
                        to_account = &accounts[i];
                    }
                }

                if (from_account == NULL || to_account == NULL) {
                    printf("Account not found.\n");
                    return 1;
                }

                // Transfer money between accounts
                transfer_money(from_account, to_account, amount);

                // Print updated accounts
                print_account(from_account);
                printf("\n");
                print_account(to_account);
                printf("\n");
                break;
            case 5:
                // Write accounts to file
                write_accounts(filename, accounts, num_accounts);

                // Free memory
                free(accounts);

                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}