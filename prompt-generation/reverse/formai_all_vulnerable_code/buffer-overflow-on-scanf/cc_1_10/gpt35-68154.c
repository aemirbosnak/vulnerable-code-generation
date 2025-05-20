//FormAI DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[50];
    int account_number;
    float balance;
};

void print_account(struct account user) {
    printf("\nName: %s\nAccount Number: %d\nBalance: %.2f\n", user.name, user.account_number, user.balance);
}

int main() {
    int choice;
    int num_accounts = 0;
    struct account accounts[1000];

    // options menu
    while (choice != 4) {
        printf("Welcome to the Banking Record System\n");
        printf("1. Add account\n");
        printf("2. Remove account\n");
        printf("3. View accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // add account
        if (choice == 1) {
            struct account new_user;
            printf("Enter name: ");
            scanf("%s", new_user.name);
            printf("Enter account number: ");
            scanf("%d", &new_user.account_number);
            printf("Enter balance: ");
            scanf("%f", &new_user.balance);
            accounts[num_accounts] = new_user;
            num_accounts++;
        }

        // remove account
        else if (choice == 2) {
            int remove_num;
            printf("Enter account number to remove: ");
            scanf("%d", &remove_num);
            int found = 0;
            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == remove_num) {
                    for (int j = i; j < num_accounts - 1; j++) {
                        accounts[j] = accounts[j + 1];
                    }
                    num_accounts--;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Account not found.\n");
            }
            else {
                printf("Account successfully removed.\n");
            }
        }

        // view accounts
        else if (choice == 3) {
            if (num_accounts > 0) {
                printf("Accounts:\n");
                for (int i = 0; i < num_accounts; i++) {
                    print_account(accounts[i]);
                }
            }
            else {
                printf("No accounts found.\n");
            }
        }

        // exit
        else if (choice == 4) {
            printf("Goodbye!\n");
            return 0;
        }

        // invalid choice
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}