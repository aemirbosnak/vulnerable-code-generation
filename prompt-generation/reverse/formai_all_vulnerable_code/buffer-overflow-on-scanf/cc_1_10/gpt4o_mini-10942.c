//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50
#define FILENAME "passwords.txt"

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void display_menu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add New Account\n");
    printf("2. View All Accounts\n");
    printf("3. Search Account\n");
    printf("4. Delete Account\n");
    printf("5. Exit\n");
    printf("========================\n");
}

void add_account() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", entry.account);
    printf("Enter password: ");
    scanf("%s", entry.password);

    fwrite(&entry, sizeof(PasswordEntry), 1, file);
    fclose(file);

    printf("Account added successfully!\n");
}

void view_accounts() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("\n=== Your Accounts ===\n");
    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        printf("Account: %s, Password: %s\n", entry.account, entry.password);
    }

    fclose(file);
}

void search_account() {
    char search[MAX_LENGTH];
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter account name to search: ");
    scanf("%s", search);
    int found = 0;

    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        if (strcmp(entry.account, search) == 0) {
            printf("Found Account: %s, Password: %s\n", entry.account, entry.password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(file);
}

void delete_account() {
    char delete_account[MAX_LENGTH];
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter account name to delete: ");
    scanf("%s", delete_account);
    int found = 0;

    while (fread(&entry, sizeof(PasswordEntry), 1, file)) {
        if (strcmp(entry.account, delete_account) != 0) {
            fwrite(&entry, sizeof(PasswordEntry), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Account deleted successfully!\n");
    } else {
        printf("Account not found.\n");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                search_account();
                break;
            case 4:
                delete_account();
                break;
            case 5:
                printf("Exiting Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}