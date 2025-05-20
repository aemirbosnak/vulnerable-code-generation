//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 20
#define MAX_NUM_OF_ACCOUNTS 10

typedef struct {
    char* name;
    char* password;
} Account;

Account accounts[MAX_NUM_OF_ACCOUNTS];
int num_of_accounts = 0;

void add_account() {
    char* name = (char*)malloc(sizeof(char) * MAX_PASS_LENGTH);
    char* password = (char*)malloc(sizeof(char) * MAX_PASS_LENGTH);

    printf("Enter account name: ");
    scanf("%s", name);

    printf("Enter account password: ");
    scanf("%s", password);

    accounts[num_of_accounts].name = name;
    accounts[num_of_accounts].password = password;

    num_of_accounts++;
}

void remove_account() {
    int account_index;

    printf("Enter index of account to remove: ");
    scanf("%d", &account_index);

    if (account_index < num_of_accounts && account_index >= 0) {
        free(accounts[account_index].name);
        free(accounts[account_index].password);

        for (int i = account_index; i < num_of_accounts - 1; i++) {
            accounts[i].name = accounts[i + 1].name;
            accounts[i].password = accounts[i + 1].password;
        }

        num_of_accounts--;
        printf("Account removed.\n");
    } else {
        printf("Invalid account index.\n");
    }
}

void list_accounts() {
    printf("%-30s%s\n", "Account Name", "Password");
    for (int i = 0; i < num_of_accounts; i++) {
        printf("%-30s%s\n", accounts[i].name, accounts[i].password);
    }
}

void save_accounts() {
    FILE* f = fopen("passwords.txt", "w");

    for (int i = 0; i < num_of_accounts; i++) {
        fprintf(f, "%s %s\n", accounts[i].name, accounts[i].password);
    }

    fclose(f);

    printf("Accounts saved to file.\n");
}

void load_accounts() {
    FILE* f = fopen("passwords.txt", "r");

    if (f != NULL) {
        char name[MAX_PASS_LENGTH];
        char password[MAX_PASS_LENGTH];

        while (fscanf(f, "%s %s", name, password) == 2 && num_of_accounts < MAX_NUM_OF_ACCOUNTS) {
            accounts[num_of_accounts].name = strdup(name);
            accounts[num_of_accounts].password = strdup(password);

            num_of_accounts++;
        }

        fclose(f);

        printf("Accounts loaded from file.\n");
    } else {
        printf("No accounts found in file.\n");
    }
}

int main() {
    int option = -1;

    printf("Welcome to Password Manager!\n");

    while (option != 0) {
        printf("\nSelect an option:\n");
        printf("1. Add account\n");
        printf("2. Remove account\n");
        printf("3. List accounts\n");
        printf("4. Save accounts to file\n");
        printf("5. Load accounts from file\n");
        printf("0. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                add_account();
                break;
            case 2:
                remove_account();
                break;
            case 3:
                list_accounts();
                break;
            case 4:
                save_accounts();
                break;
            case 5:
                load_accounts();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}