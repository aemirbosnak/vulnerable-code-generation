//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float balance;
} account_t;

typedef struct {
    char name[50];
    int id;
} category_t;

typedef struct {
    char description[100];
    float amount;
    int category_id;
} transaction_t;

int main() {
    int num_accounts, num_categories;
    account_t accounts[MAX_ACCOUNTS];
    category_t categories[MAX_CATEGORIES];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int choice;

    do {
        system("clear");
        printf("=== Personal Finance Planner ===\n");
        printf("1. Add Account\n");
        printf("2. Add Category\n");
        printf("3. Add Transaction\n");
        printf("4. View Accounts\n");
        printf("5. View Categories\n");
        printf("6. View Transactions\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts].name);
                accounts[num_accounts].balance = 0.0;
                num_accounts++;
                break;
            case 2:
                printf("Enter category name: ");
                scanf("%s", categories[num_categories].name);
                categories[num_categories].id = num_categories + 1;
                num_categories++;
                break;
            case 3:
                printf("Enter transaction description: ");
                scanf("%s", transactions[num_transactions].description);
                printf("Enter amount: ");
                scanf("%f", &transactions[num_transactions].amount);
                printf("Enter category ID: ");
                scanf("%d", &transactions[num_transactions].category_id);
                num_transactions++;
                break;
            case 4:
                printf("Accounts:\n");
                for(int i=0; i<num_accounts; i++) {
                    printf("%s\n", accounts[i].name);
                }
                break;
            case 5:
                printf("Categories:\n");
                for(int i=0; i<num_categories; i++) {
                    printf("%s\n", categories[i].name);
                }
                break;
            case 6:
                printf("Transactions:\n");
                for(int i=0; i<num_transactions; i++) {
                    printf("%s - $%.2f (%d)\n", transactions[i].description, transactions[i].amount, transactions[i].category_id);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while(1);

    return 0;
}