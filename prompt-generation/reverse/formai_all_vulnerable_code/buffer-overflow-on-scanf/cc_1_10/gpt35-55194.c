//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct record {
    char name[20];
    int account_no;
    double balance;
};

void update_balance(struct record *r) {
    double amount;
    printf("Enter the amount to update balance: ");
    scanf("%lf", &amount);
    r->balance += amount;
}

void display(struct record r) {
    printf("Name: %s\n", r.name);
    printf("Account Number: %d\n", r.account_no);
    printf("Balance: %lf\n", r.balance);
}

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    struct record *r = (struct record *)malloc(n * sizeof(struct record));

    for (int i = 0; i < n; i++) {
        printf("Record %d:\n", i+1);
        printf("Enter the name: ");
        scanf("%s", r[i].name);
        printf("Enter the account number: ");
        scanf("%d", &r[i].account_no);
        printf("Enter the balance: ");
        scanf("%lf", &r[i].balance);
    }

    int choice, acc;
    do {
        printf("Select an option:\n");
        printf("1. Update Balance\n");
        printf("2. Display Record\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the account number: ");
                scanf("%d", &acc);
                for (int i = 0; i < n; i++) {
                    if (r[i].account_no == acc) {
                        update_balance(&r[i]);
                        break;
                    }
                }
                break;
            case 2:
                printf("Enter the account number: ");
                scanf("%d", &acc);
                for (int i = 0; i < n; i++) {
                    if (r[i].account_no == acc) {
                        display(r[i]);
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 3);

    free(r);
    return 0;
}