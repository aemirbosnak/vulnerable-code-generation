//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define PASSWORD_LENGTH 32
#define USERNAME_LENGTH 32

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("The shelter's memory unit is full!\n");
        return;
    }
    
    printf("Enter username: ");
    scanf("%s", accounts[account_count].username);
    
    printf("Enter password: ");
    scanf("%s", accounts[account_count].password);
    
    account_count++;
    printf("Account added successfully. We live to fight another day!\n");
}

void list_accounts() {
    printf("\n** Accounts List **\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account %d: %s\n", i + 1, accounts[i].username);
    }
    printf("\n");
}

void secure_delete() {
    int index;
    printf("Enter account number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > account_count) {
        printf("Invalid account number!\n");
        return;
    }
    
    for (int i = index - 1; i < account_count - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    
    account_count--;
    printf("The account has been vaporized from existence! We hide no secrets.\n");
}

void save_to_file() {
    FILE *file = fopen("accounts.txt", "w");
    if (!file) {
        printf("Failed to connect to the memory server!\n");
        return;
    }
    
    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s:%s\n", accounts[i].username, accounts[i].password);
    }
    
    fclose(file);
    printf("Data has been secured in the bunker!\n");
}

void load_from_file() {
    FILE *file = fopen("accounts.txt", "r");
    if (!file) {
        printf("No backup found! We must start fresh.\n");
        return;
    }
    
    while (fscanf(file, "%31[^:]:%31s\n", accounts[account_count].username, accounts[account_count].password) != EOF) {
        account_count++;
        if (account_count >= MAX_ACCOUNTS) {
            printf("Reached maximum accounts. Shelter’s memory unit can’t hold any more!\n");
            break;
        }
    }
    
    fclose(file);
    printf("Data recovered from the ruins. Hope still exists!\n");
}

void print_help() {
    printf("Post-Apocalyptic Password Management System:\n");
    printf("1. Add Account\n");
    printf("2. List Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Save Accounts\n");
    printf("5. Load Accounts\n");
    printf("6. Help\n");
    printf("7. Exit\n");
}

int main() {
    load_from_file();      // Load existing accounts, if any
    while (1) {
        print_help();
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                list_accounts();
                break;
            case 3:
                secure_delete();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                print_help();
                break;
            case 7:
                printf("Exiting... Never forget the past!\n");
                exit(0);
            default:
                printf("Invalid choice! Choose wisely or risk extinction!\n");
        }
    }
    
    return 0;
}