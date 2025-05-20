//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct Account {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int count = 0;

void saveToFile() {
    FILE *file = fopen("passwords.txt", "w");
    for (int i = 0; i < count; ++i) {
        fprintf(file, "Website: %s\nUsername: %s\nPassword: %s\n\n", 
                accounts[i].website, accounts[i].username, accounts[i].password);
    }
    fclose(file);
}

void addAccount() {
    if (count < MAX_ACCOUNTS) {
        printf("Enter website: ");
        scanf("%s", accounts[count].website);
        printf("Enter username: ");
        scanf("%s", accounts[count].username);
        printf("Enter password: ");
        scanf("%s", accounts[count].password);
        count++;
        printf("Alas! Your account hath been saved!\n\n");
    } else {
        printf("O woe! Limit of accounts reached!\n");
    }
}

void viewAccounts() {
    if (count == 0) {
        printf("What light from yonder window breaks? No accounts to view!\n");
        return;
    }
    for (int i = 0; i < count; ++i) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", 
               accounts[i].website, accounts[i].username, accounts[i].password);
    }
}

void deleteAccount() {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < count; ++i) {
        if (strcmp(accounts[i].website, website) == 0) {
            for (int j = i; j < count - 1; ++j) {
                accounts[j] = accounts[j + 1]; // shift accounts left
            }
            count--;
            printf("Oh, cruel fate! The account hath been deleted!\n");
            return;
        }
    }
    printf("What heart can bear it? No such account found!\n");
}

void displayMenu() {
    printf("Enter thy choice:\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Save to File\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    printf("Welcome to the Fair Password Keeper! What dost thou desire?\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                saveToFile();
                printf("Verily! Accounts hath been saved to file!\n");
                break;
            case 5:
                printf("Farewell, dear user! Until we meet again!\n");
                break;
            default:
                printf("What jest is this? Choose a valid option!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}