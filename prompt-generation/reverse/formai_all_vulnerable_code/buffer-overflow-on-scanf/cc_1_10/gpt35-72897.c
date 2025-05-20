//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_ACCOUNTS 10

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} account;

void display_menu();
int choose_option();
void add_account(account list[], int *num_accounts);
void view_accounts(account list[], int num_accounts);
void change_password(account list[], int num_accounts);
void save_accounts(account list[], int num_accounts);

int main() {
    account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;

    while(1) {
        display_menu();
        choice = choose_option();

        switch(choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                view_accounts(accounts, num_accounts);
                break;
            case 3:
                change_password(accounts, num_accounts);
                break;
            case 4:
                save_accounts(accounts, num_accounts);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void display_menu() {
    printf("\nPassword Management\n");
    printf("-----------------------\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Change Password\n");
    printf("4. Save and Exit\n");
}

int choose_option() {
    int choice;

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void add_account(account list[], int *num_accounts) {
    if(*num_accounts == MAX_ACCOUNTS) {
        printf("Account list is full. Cannot add another account.\n");
        return;
    }

    printf("\nEnter username: ");
    scanf("%s", list[*num_accounts].username);

    printf("Enter password: ");
    scanf("%s", list[*num_accounts].password);

    (*num_accounts)++;
}

void view_accounts(account list[], int num_accounts) {
    if(num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("\nAccounts:\n");
    for(int i=0; i<num_accounts; i++) {
        printf("%d. Username: %s, Password: %s\n", i+1, list[i].username, list[i].password);
    }
}

void change_password(account list[], int num_accounts) {
    if(num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    int account_index;
    char new_password[MAX_PASSWORD_LENGTH];

    printf("\nEnter the account index: ");
    scanf("%d", &account_index);
    account_index--;

    if(account_index >= num_accounts) {
        printf("Invalid account index.\n");
        return;
    }

    printf("Enter the new password: ");
    scanf("%s", new_password);

    strcpy(list[account_index].password, new_password);

    printf("Password successfully changed.\n");
}

void save_accounts(account list[], int num_accounts) {
    FILE *file;
    file = fopen("accounts.txt", "w");

    for(int i=0; i<num_accounts; i++) {
        fprintf(file, "%s,%s\n", list[i].username, list[i].password);
    }

    fclose(file);

    printf("Accounts successfully saved.\n");
}