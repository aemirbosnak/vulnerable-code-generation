//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNT_NAME_LENGTH 20
#define MAX_NUM_ACCOUNTS 5

struct Account {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User {
    int num_accounts;
    struct Account accounts[MAX_NUM_ACCOUNTS];
};

// Function declarations
int get_user_choice();
int create_account(struct User *user);
int edit_account(struct User *user);
int delete_account(struct User *user);
void print_accounts(struct User *user);
void generate_password(char *password);

int main() {
    struct User user = {0};
    int choice;

    do {
        choice = get_user_choice();

        switch (choice) {
            case 1:
                create_account(&user);
                break;
            case 2:
                edit_account(&user);
                break;
            case 3:
                delete_account(&user);
                break;
            case 4:
                print_accounts(&user);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}

// Function to display user menu and get user's choice
int get_user_choice() {
    printf("Main Menu:\n");
    printf("1 - Create a new account\n");
    printf("2 - Edit an account\n");
    printf("3 - Delete an account\n");
    printf("4 - Print all accounts\n");
    printf("5 - Exit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n'); // Clear input buffer
    
    return choice;
}

// Function to create a new account for the user
int create_account(struct User *user) {
    if (user->num_accounts >= MAX_NUM_ACCOUNTS) {
        printf("You have reached the maximum number of accounts!");
        return 0;
    }
    
    struct Account new_account;
    printf("Enter account name (up to %d characters): ", MAX_ACCOUNT_NAME_LENGTH);
    fgets(new_account.name, MAX_ACCOUNT_NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline character from name
    
    // Check if an account with this name already exists
    for (int i = 0; i < user->num_accounts; i++) {
        if (strcmp(user->accounts[i].name, new_account.name) == 0) {
            printf("An account with that name already exists!\n");
            return 0;
        }
    }
    
    char password_choice;
    do {
        printf("Generate a random password? (y/n) ");
        scanf("%c", &password_choice);
        while (getchar() != '\n'); // Clear input buffer
        password_choice = tolower(password_choice);
    } while (password_choice != 'y' && password_choice != 'n');
    
    if (password_choice == 'y') {
        generate_password(new_account.password);
    } else {
        printf("Enter password (up to %d characters): ", MAX_PASSWORD_LENGTH);
        fgets(new_account.password, MAX_PASSWORD_LENGTH, stdin);
        new_account.password[strcspn(new_account.password, "\n")] = 0; // Remove newline character from password
    }
    
    user->accounts[user->num_accounts] = new_account;
    user->num_accounts++;
    printf("Account created successfully!\n");
    
    return 1;
}

// Function to edit an existing account for the user
int edit_account(struct User *user) {
    if (user->num_accounts == 0) {
        printf("You have no accounts to edit!\n");
        return 0;
    }
    
    char account_name[MAX_ACCOUNT_NAME_LENGTH];
    printf("Enter the name of the account you want to edit: ");
    fgets(account_name, MAX_ACCOUNT_NAME_LENGTH, stdin);
    account_name[strcspn(account_name, "\n")] = 0; // Remove newline character from name
    
    // Find the account with this name
    int account_index = -1;
    for (int i = 0; i < user->num_accounts; i++) {
        if (strcmp(user->accounts[i].name, account_name) == 0) {
            account_index = i;
            break;
        }
    }
    
    if (account_index == -1) {
        printf("No account found with that name!\n");
        return 0;
    }
    
    char password_choice;
    do {
        printf("Generate a new random password? (y/n) ");
        scanf("%c", &password_choice);
        while (getchar() != '\n'); // Clear input buffer
        password_choice = tolower(password_choice);
    } while (password_choice != 'y' && password_choice != 'n');
    
    if (password_choice == 'y') {
        generate_password(user->accounts[account_index].password);
    } else {
        printf("Enter new password (up to %d characters): ", MAX_PASSWORD_LENGTH);
        fgets(user->accounts[account_index].password, MAX_PASSWORD_LENGTH, stdin);
        user->accounts[account_index].password[strcspn(user->accounts[account_index].password, "\n")] = 0; // Remove newline character from password
    }
    
    printf("Account password updated successfully!\n");
    return 1;
}

// Function to delete an existing account for the user
int delete_account(struct User *user) {
    if (user->num_accounts == 0) {
        printf("You have no accounts to delete!\n");
        return 0;
    }
    
    char account_name[MAX_ACCOUNT_NAME_LENGTH];
    printf("Enter the name of the account you want to delete: ");
    fgets(account_name, MAX_ACCOUNT_NAME_LENGTH, stdin);
    account_name[strcspn(account_name, "\n")] = 0; // Remove newline character from name
    
    // Find the account with this name
    int account_index = -1;
    for (int i = 0; i < user->num_accounts; i++) {
        if (strcmp(user->accounts[i].name, account_name) == 0) {
            account_index = i;
            break;
        }
    }
    
    if (account_index == -1) {
        printf("No account found with that name!\n");
        return 0;
    }
    
    // Shift all accounts after the deleted account to the left
    for (int i = account_index; i < user->num_accounts - 1; i++) {
        user->accounts[i] = user->accounts[i+1];
    }
    user->num_accounts--;
    
    printf("Account deleted successfully!\n");
    return 1;
}

// Function to print all accounts for the user
void print_accounts(struct User *user) {
    if (user->num_accounts == 0) {
        printf("You have no accounts to print!\n");
        return;
    }
    
    printf("Your accounts:\n");
    for (int i = 0; i < user->num_accounts; i++) {
        printf("%s : %s\n", user->accounts[i].name, user->accounts[i].password);
    }
}

// Function to generate a random password and store it in the given buffer
void generate_password(char *password) {
    char alphanumeric[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = rand() % (MAX_PASSWORD_LENGTH - 10 + 1) + 10; // Password length will be between 10 and MAX_PASSWORD_LENGTH characters
    
    for (int i = 0; i < length; i++) {
        password[i] = alphanumeric[rand() % 62];
    }
    password[length] = '\0';
}