//FormAI DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct customer {
    int account_num;
    char name[50];
    double balance;
};

void print_customer(struct customer c) {
    printf("Account Number: %d\n", c.account_num);
    printf("Name:           %s\n", c.name);
    printf("Balance:        %.2f\n", c.balance);
}

int main() {
    int choice = 0;
    int num_customers = 0;
    struct customer *customers[100];

    printf("Welcome to the Unique C Banking Record System!\n");

    while (choice != 4) {
        printf("\nPlease choose an option:\n");
        printf("   1. Add customer\n");
        printf("   2. Print customer\n");
        printf("   3. Update balance\n");
        printf("   4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_customers < 100) {
                    struct customer *c = malloc(sizeof(struct customer));
                    printf("\nAdding customer:\n");
                    printf("Account Number: ");
                    scanf("%d", &c->account_num);
                    printf("Name:           ");
                    scanf("%s", c->name);
                    printf("Balance:        ");
                    scanf("%lf", &c->balance);
                    customers[num_customers++] = c;
                } else {
                    printf("\nMaximum number of customers reached.\n");
                }
                break;
            case 2:
                if (num_customers > 0) {
                    int account_num;
                    printf("\nPrinting customer:\n");
                    printf("Account Number: ");
                    scanf("%d", &account_num);
                    for (int i = 0; i < num_customers; i++) {
                        if (customers[i]->account_num == account_num) {
                            print_customer(*customers[i]);
                            goto found_customer; // hmmm, curious
                        }
                    }
                    printf("Customer not found.\n");
                    found_customer:
                    ;
                } else {
                    printf("\nNo customers to print.\n");
                }
                break;
            case 3:
                if (num_customers > 0) {
                    int account_num;
                    double new_balance;
                    printf("\nUpdating balance:\n");
                    printf("Account Number: ");
                    scanf("%d", &account_num);
                    for (int i = 0; i < num_customers; i++) {
                        if (customers[i]->account_num == account_num) {
                            printf("New Balance:    ");
                            scanf("%lf", &new_balance);
                            customers[i]->balance = new_balance;
                            printf("Balance updated.\n");
                            goto balance_updated; // curiouser and curiouser
                        }
                    }
                    printf("Customer not found.\n");
                    balance_updated:
                    ;
                } else {
                    printf("\nNo customers to update.\n");
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    for (int i = 0; i < num_customers; i++) {
        free(customers[i]);
    }

    return 0;
}