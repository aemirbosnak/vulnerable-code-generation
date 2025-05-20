//FormAI DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct account {
    int acc_no;
    char name[20];
    float balance;
};

int main() {
    int choice, acc_no, found = 0;
    float amount;
    struct account *a;
    int n, i;

    printf("Enter the number of accounts: ");
    scanf("%d", &n);

    // dynamically allocate memory for n accounts
    a = (struct account *)malloc(n * sizeof(struct account));

    // input account details
    for (i = 0; i < n; i++) {
        printf("\nEnter Account No: ");
        scanf("%d", &(a+i)->acc_no);
        printf("Enter Name: ");
        scanf("%s", (a+i)->name);
        printf("Enter Balance: ");
        scanf("%f", &(a+i)->balance);
    }

    do {
        // menu
        printf("\nMENU");
        printf("\n1. Deposit");
        printf("\n2. Withdraw");
        printf("\n3. Display All");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);
        found = 0;

        switch (choice) {
            case 1: // deposit
                printf("\nEnter Account No : ");
                scanf("%d", &acc_no);

                for (i = 0; i < n; i++) {
                    if ((a+i)->acc_no == acc_no) {
                        found = 1;
                        printf("Enter the amount to deposit: ");
                        scanf("%f", &amount);

                        (a+i)->balance += amount;
                        printf("\nDeposit successful!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("\nAccount not found!\n");
                }

                break;

            case 2: // withdraw
                printf("\nEnter Account No : ");
                scanf("%d", &acc_no);

                for (i = 0; i < n; i++) {
                    if ((a+i)->acc_no == acc_no) {
                        found = 1;
                        printf("Enter the amount to withdraw: ");
                        scanf("%f", &amount);

                        if ((a+i)->balance >= amount) {
                            (a+i)->balance -= amount;
                            printf("\nWithdrawal successful!\n");
                        } else {
                            printf("Insufficient balance!\n");
                        }

                        break;
                    }
                }

                if (!found) {
                    printf("\nAccount not found!\n");
                }

                break;

            case 3: // display all
                printf("\nAccount No\tName\t\tBalance\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t\t%s\t\t%.2f\n", (a+i)->acc_no, (a+i)->name, (a+i)->balance);
                }
                break;

            case 4: // exit
                printf("Exiting...");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    // free memory
    free(a);

    return 0;
}