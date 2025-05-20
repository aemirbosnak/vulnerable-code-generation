//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASS_LENGTH 20
#define MAX_ACCOUNTS 10

typedef struct {
    char account_name[50];
    char password[MAX_PASS_LENGTH+1];
} Account;

void generatePassword(char password[]);
void addAccount(Account accounts[], int *num_accounts);
void viewAccounts(Account accounts[], int num_accounts);
void saveAccounts(Account accounts[], int num_accounts);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;

    // Load accounts from file
    FILE *fp;
    fp = fopen("accounts.bin", "rb");
    if (fp != NULL) {
        fread(&num_accounts, sizeof(int), 1, fp);
        fread(accounts, sizeof(Account), num_accounts, fp);
        fclose(fp);
    }

    // Main menu loop
    do {
        printf("\nC Password Manager\n");
        printf("1. Add an account\n");
        printf("2. View accounts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accounts, &num_accounts);
                break;
            case 2:
                viewAccounts(accounts, num_accounts);
                break;
            case 3:
                // Save accounts to file
                saveAccounts(accounts, num_accounts);
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

void generatePassword(char password[]) {
    int i;
    char character;
    srand(time(NULL));
    for (i = 0; i < MAX_PASS_LENGTH; i++) {
        character = rand() % 94 + 33; // ASCII 33 to 126
        password[i] = character;
    }
    password[MAX_PASS_LENGTH] = '\0';
}

void addAccount(Account accounts[], int *num_accounts) {
    Account new_account;
    char ans;

    printf("\nEnter account name: ");
    scanf("%s", new_account.account_name);

    generatePassword(new_account.password);
    printf("Generated password: %s\n", new_account.password);

    printf("Do you want to save this account? (Y/N): ");
    scanf(" %c", &ans);
    if (ans == 'Y' || ans == 'y') {
        accounts[*num_accounts] = new_account;
        *num_accounts += 1;
        printf("Account saved successfully!\n");
    } else {
        printf("Account not saved.\n");
    }
}

void viewAccounts(Account accounts[], int num_accounts) {
    int i;
    printf("\nAccounts:\n");
    for (i = 0; i < num_accounts; i++) {
        printf("%s - %s\n", accounts[i].account_name, accounts[i].password);
    }
}

void saveAccounts(Account accounts[], int num_accounts) {
    FILE *fp;
    fp = fopen("accounts.bin", "wb");
    fwrite(&num_accounts, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(Account), num_accounts, fp);
    fclose(fp);
}