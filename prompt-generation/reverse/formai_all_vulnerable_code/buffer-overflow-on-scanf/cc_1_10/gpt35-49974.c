//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int id;
    char name[50];
    double balance;
};

int num_accounts = 0;
struct account accounts[100];

void add_account() {
    struct account new_account;
    printf("Enter account ID: ");
    scanf("%d", &new_account.id);
    printf("Enter account name: ");
    scanf("%s", new_account.name);
    printf("Enter account balance: ");
    scanf("%lf", &new_account.balance);
    
    accounts[num_accounts] = new_account;
    num_accounts++;
    printf("Account added successfully.\n");
}

void view_accounts() {
    printf("ID      Name               Balance\n");
    printf("---------------------------------\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-7d %-18s %.2lf\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

void find_account() {
    int search_id;
    printf("Enter account ID to search for: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == search_id) {
            printf("ID: %d, Name: %s, Balance: %.2lf\n", accounts[i].id, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found.\n");
}

int main() {
    int choice;
  
    do {
        printf("Banking Record System\n");
        printf("----------------------\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Find Account\n");
        printf("0. Exit\n");
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
                find_account();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}