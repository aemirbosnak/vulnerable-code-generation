//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 30
#define MAX_NUM_ACCOUNTS 100

struct account {
    char url[256];
    char username[256];
    char password[MAX_PASSWORD_LENGTH+1];
};

int num_accounts = 0;
struct account accounts[MAX_NUM_ACCOUNTS];

enum menu_choice {ADD_ACCOUNT=1, VIEW_ACCOUNTS, QUIT};

void print_menu() {
    printf("Password Manager\n"
           "----------------\n"
           "1. Add account\n"
           "2. View accounts\n"
           "3. Quit\n"
           "----------------\n");
}

int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline
    return choice;
}

void add_account() {
    if (num_accounts >= MAX_NUM_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached\n");
        return;
    }
    printf("Enter URL: ");
    fgets(accounts[num_accounts].url, 256, stdin);
    accounts[num_accounts].url[strcspn(accounts[num_accounts].url, "\n")] = '\0'; // remove trailing newline
    printf("Enter username: ");
    fgets(accounts[num_accounts].username, 256, stdin);
    accounts[num_accounts].username[strcspn(accounts[num_accounts].username, "\n")] = '\0'; // remove trailing newline
    printf("Enter password (max length %d): ", MAX_PASSWORD_LENGTH);
    fgets(accounts[num_accounts].password, MAX_PASSWORD_LENGTH+1, stdin);
    accounts[num_accounts].password[strcspn(accounts[num_accounts].password, "\n")] = '\0'; // remove trailing newline
    num_accounts++;
    printf("Account added successfully\n");
}

void view_accounts() {
    if (num_accounts == 0) {
        printf("No accounts to display\n");
        return;
    }
    printf("%-30s %-30s %-30s\n", "URL", "Username", "Password");
    printf("%-30s %-30s %-30s\n", "---", "--------", "--------");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-30s %-30s %-30s\n", accounts[i].url, accounts[i].username, accounts[i].password);
    }
}

void clear_passwords() {
    for (int i = 0; i < num_accounts; i++) {
        memset(accounts[i].password, 0, MAX_PASSWORD_LENGTH+1);
    }
}

int main() {
    int choice;
    do {
        print_menu();
        choice = get_menu_choice();
        switch (choice) {
            case ADD_ACCOUNT:
                add_account();
                break;
            case VIEW_ACCOUNTS:
                view_accounts();
                break;
            case QUIT:
                clear_passwords();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != QUIT);
    return 0;
}