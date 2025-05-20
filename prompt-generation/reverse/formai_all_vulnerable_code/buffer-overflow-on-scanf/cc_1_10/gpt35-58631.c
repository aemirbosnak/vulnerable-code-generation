//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LENGTH 20

// Account struct
struct Account {
    char name[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH + 1];
};

// Function declarations
void print_menu();
void add_account(struct Account accounts[], int *num_accounts);
void remove_account(struct Account accounts[], int *num_accounts);
void view_accounts(struct Account accounts[], int num_accounts);
void generate_password(char password[]);
void encrypt_password(char password[]);

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int user_choice;

    // Main program loop
    do {
        print_menu();
        scanf("%d", &user_choice);

        switch(user_choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                remove_account(accounts, &num_accounts);
                break;
            case 3:
                view_accounts(accounts, num_accounts);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(user_choice != 4);

    return 0;
}

// Function that prints out the menu options
void print_menu() {
    printf("Password Manager\n");
    printf("----------------\n");
    printf("1. Add account\n");
    printf("2. Remove account\n");
    printf("3. View accounts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function that adds an account to the list
void add_account(struct Account accounts[], int *num_accounts) {
    if(*num_accounts == MAX_ACCOUNTS) {
        printf("Cannot add more accounts. Maximum limit reached.\n");
        return;
    }

    struct Account new_account;
    printf("Enter account name: ");
    scanf("%s", new_account.name);
    printf("Enter username: ");
    scanf("%s", new_account.username);
    generate_password(new_account.password);
    encrypt_password(new_account.password);

    // Add new account to array
    accounts[*num_accounts] = new_account;
    (*num_accounts)++;

    printf("Account created successfully!\n");
}

// Function that removes an account from the list
void remove_account(struct Account accounts[], int *num_accounts) {
    int index;
    int found = 0;
    char account_name[50];

    printf("Enter account name to delete: ");
    scanf("%s", account_name);

    // Find account with matching name and remove it
    for(int i = 0; i < *num_accounts; i++) {
        if(strcmp(accounts[i].name, account_name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if(found) {
        for(int i = index; i < *num_accounts - 1; i++) {
            accounts[i] = accounts[i + 1];
        }
        (*num_accounts)--;
        printf("Account deleted successfully!\n");
    } else {
        printf("Account not found.\n");
    }
}

// Function that displays all the accounts in the list
void view_accounts(struct Account accounts[], int num_accounts) {
    if(num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    for(int i = 0; i < num_accounts; i++) {
        printf("Name: %s\n", accounts[i].name);
        printf("Username: %s\n", accounts[i].username);
        encrypt_password(accounts[i].password);
        printf("Password: %s\n", accounts[i].password);
        printf("----------------\n");
    }
}

// Function that generates a random password
void generate_password(char password[]) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int length = rand() % (MAX_PASSWORD_LENGTH - 8) + 8; // random length between 8 and MAX_PASSWORD_LENGTH
    for(int i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        password[i] = charset[index];
    }
    password[length] = '\0';
}

// Function that encrypts the password using Caesar cipher
void encrypt_password(char password[]) {
    int key = 3; // Caesar cipher key
    for(int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if(c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key) % 26 + 'A';
        }
        password[i] = c;
    }
}