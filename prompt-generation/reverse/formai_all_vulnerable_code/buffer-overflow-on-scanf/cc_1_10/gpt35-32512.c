//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Account;

int main() {
    int choice, count = 0, i, acc_num;
    Account accounts[100];
    char search_name[50];

    printf("Welcome to the Banking Record System! How may I assist you?\n");
    printf("1. Add an account\n2. Search for an account\n3. View all accounts\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Adding an account...\n");

                printf("Enter name: ");
                scanf("%s", accounts[count].name);

                printf("Enter account number: ");
                scanf("%d", &accounts[count].account_number);

                printf("Enter balance: ");
                scanf("%f", &accounts[count].balance);

                printf("Account added successfully!\n");

                count++;
                break;

            case 2:
                printf("Search for an account...\n");

                printf("Enter account number: ");
                scanf("%d", &acc_num);

                for (i = 0; i < count; i++) {
                    if (accounts[i].account_number == acc_num) {
                        printf("Account found!\n");
                        printf("Name: %s\nAccount number: %d\nBalance: $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
                        break;
                    }
                }

                if (i == count) {
                    printf("Account not found.\n");
                }
                break;

            case 3:
                printf("View all accounts...\n");

                for (i = 0; i < count; i++) {
                    printf("Name: %s\nAccount number: %d\nBalance: $%.2f\n\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
                }
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}