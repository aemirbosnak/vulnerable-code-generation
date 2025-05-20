//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define PASSWORD_LENGTH 20
#define USERNAME_LENGTH 30

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void welcome_message() {
    printf("Welcome, brave adventurer, to the Realm of Passwords!\n");
    printf("Here you can store and manage your treasures (passwords).\n");
    printf("Now, let us begin our quest.\n\n");
}

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Alas! You cannot add more accounts. The realm is full!\n");
        return;
    }

    printf("Enter the username for the new account: ");
    char username[USERNAME_LENGTH];
    scanf("%s", username);
    
    printf("Enter the password for the new account: ");
    char password[PASSWORD_LENGTH];
    scanf("%s", password);
    
    strcpy(accounts[account_count].username, username);
    strcpy(accounts[account_count].password, password);
    account_count++;
    
    printf("A new account has been forged! Username: %s\n", username);
    printf("Password has been hidden away in the depths of the realm.\n\n");
}

void view_accounts() {
    printf("Behold the list of your accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account %d: Username: %s, Password: %s\n", i+1, accounts[i].username, accounts[i].password);
    }
    printf("\n");
}

void delete_account() {
    printf("Enter the index of the account to delete (1 to %d): ", account_count);
    int index;
    scanf("%d", &index);
    
    if (index < 1 || index > account_count) {
        printf("Beware, you have entered an invalid index!\n");
        return;
    }

    for (int i = index - 1; i < account_count - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    account_count--;
    printf("The account has been vanquished from existence!\n\n");
}

void save_accounts_to_file() {
    FILE *file = fopen("accounts.txt", "w");
    if (!file) {
        printf("Alas! The treasure could not be saved!\n");
        return;
    }
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %s\n", accounts[i].username, accounts[i].password);
    }
    fclose(file);
    printf("Your accounts have been safely stored in the ancient scrolls!\n\n");
}

void load_accounts_from_file() {
    FILE *file = fopen("accounts.txt", "r");
    if (!file) {
        printf("No ancient scrolls found. Starting fresh!\n");
        return;
    }
    while (fscanf(file, "%s %s", accounts[account_count].username, accounts[account_count].password) == 2 && account_count < MAX_ACCOUNTS) {
        account_count++;
    }
    fclose(file);
    printf("The ancient scrolls have been read, and your accounts have returned!\n\n");
}

int main() {
    welcome_message();
    load_accounts_from_file();

    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Save Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                save_accounts_to_file();
                break;
            case 5:
                printf("Farewell, brave adventurer. Until we meet again!\n");
                break;
            default:
                printf("That choice is not recognized in this realm.\n\n");
        }
    } while (choice != 5);

    return 0;
}