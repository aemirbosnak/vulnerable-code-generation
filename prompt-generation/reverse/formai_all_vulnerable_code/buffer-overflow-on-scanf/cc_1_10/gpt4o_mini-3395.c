//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 100

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry password_list[MAX_ACCOUNTS];
int count = 0;

void add_password() {
    if (count >= MAX_ACCOUNTS) {
        printf("Password storage full!\n");
        return;
    }
    
    printf("Account: ");
    scanf("%s", password_list[count].account);
    printf("Password: ");
    scanf("%s", password_list[count].password);
    count++;
    printf("Password added successfully.\n");
}

void view_passwords() {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }
    
    printf("Stored passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Account: %s, Password: %s\n", password_list[i].account, password_list[i].password);
    }
}

void delete_password() {
    if (count == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char account[MAX_LENGTH];
    printf("Account to delete: ");
    scanf("%s", account);

    for (int i = 0; i < count; i++) {
        if (strcmp(password_list[i].account, account) == 0) {
            for (int j = i; j < count - 1; j++) {
                password_list[j] = password_list[j + 1];
            }
            count--;
            printf("Password for account '%s' deleted successfully.\n", account);
            return;
        }
    }
    printf("Account not found.\n");
}

void display_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}