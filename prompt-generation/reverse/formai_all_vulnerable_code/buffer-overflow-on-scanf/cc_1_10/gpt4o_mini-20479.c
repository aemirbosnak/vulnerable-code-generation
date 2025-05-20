//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function declarations
void add_account();
void view_accounts();
void generate_password(char *password, int length);
void encrypt_password(char *password);
void decrypt_password(char *password);
void save_accounts();
void load_accounts();
void display_banner();

int main() {
    load_accounts();
    int choice;
    
    display_banner();

    while (1) {
        printf("\n1. Add Account\n2. View Accounts\n3. Save & Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                save_accounts();
                printf("Exiting the program. A splendid day to you!\n");
                return 0; // Escape the infinite loop and exit
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void display_banner() {
    printf("====================================\n");
    printf("  SHERLOCK'S PASSWORD MANAGEMENT \n");
    printf("====================================\n");
}

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    printf("Enter website name: ");
    scanf("%s", accounts[account_count].website);
    
    printf("Enter username: ");
    scanf("%s", accounts[account_count].username);

    char password[MAX_LENGTH];
    printf("Do you want a randomly generated password? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y') {
        generate_password(password, 12);
        printf("Generated password: %s\n", password);
    } else {
        printf("Enter password: ");
        scanf("%s", password);
    }

    encrypt_password(password);
    strcpy(accounts[account_count].password, password);
    account_count++;
    printf("Account added successfully.\n");
}

void view_accounts() {
    printf("-------- Registered Accounts --------\n");
    for (int i = 0; i < account_count; i++) {
        char decrypted_password[MAX_LENGTH];
        strcpy(decrypted_password, accounts[i].password);
        decrypt_password(decrypted_password); // Decrypt the password for display
        
        printf("Website: %s, Username: %s, Password: %s\n", 
                accounts[i].website, 
                accounts[i].username, 
                decrypted_password);
    }
    printf("------------------------------------\n");
}

void generate_password(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        password[i] = charset[key];
    }
    password[length] = '\0';
}

void encrypt_password(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 3; // Simple Caesar cipher
    }
}

void decrypt_password(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 3; // Reverse the Caesar cipher
    }
}

void save_accounts() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file != NULL) {
        fwrite(accounts, sizeof(Account), account_count, file);
        fclose(file);
        printf("Accounts saved successfully!\n");
    } else {
        printf("Error saving accounts.\n");
    }
}

void load_accounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file != NULL) {
        account_count = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
        fclose(file);
    }
}