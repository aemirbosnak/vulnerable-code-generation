//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_PASSWORD 50

typedef struct {
    char name[50];
    char username[50];
    char password[MAX_PASSWORD];
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

int validatePassword(char *password) {
    int len = strlen(password);
    int upper = 0, lower = 0, digit = 0;
    
    if (len < 8 || len > MAX_PASSWORD) {
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
        }
    }
    
    return upper && lower && digit;
}

void addAccount() {
    Account acc;
    
    printf("Enter name: ");
    fgets(acc.name, 50, stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // remove the newline character
    
    printf("Enter username: ");
    fgets(acc.username, 50, stdin);
    acc.username[strcspn(acc.username, "\n")] = '\0'; // remove the newline character
    
    char password[MAX_PASSWORD];
    do {
        printf("Enter password (at least 8 characters and must contain both upper and lower case letters and digits): ");
        fgets(password, MAX_PASSWORD, stdin);
        password[strcspn(password, "\n")] = '\0'; // remove the newline character
    } while (!validatePassword(password));
    
    strcpy(acc.password, password);
    
    accounts[numAccounts++] = acc;
    
    printf("Account added successfully.\n");
}

void listAccounts() {
    printf("List of accounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d. Name: %s, Username: %s\n", i + 1, accounts[i].name, accounts[i].username);
    }
}

void searchAccounts() {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the newline character
    
    int count = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Name: %s, Username: %s, Password: %s\n", accounts[i].name, accounts[i].username, accounts[i].password);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No accounts found with name: %s\n", name);
    }
}

int main() {
    int option;
    do {
        printf("\nPassword Management\n");
        printf("1. Add Account\n");
        printf("2. List Accounts\n");
        printf("3. Search Accounts\n");
        printf("4. Exit\n");
        
        printf("Enter option: ");
        scanf("%d", &option);
        getchar(); // remove the newline character left by scanf
        
        switch (option) {
            case 1:
                addAccount();
                break;
            case 2:
                listAccounts();
                break;
            case 3:
                searchAccounts();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}