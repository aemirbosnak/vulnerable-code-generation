//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct account {
    int account_number;
    char name[50];
    float balance;
};

int main() {
    int n, i, j, choice;
    float amount;
    struct account *ptr = NULL;
    printf("Enter the number of accounts: ");
    scanf("%d", &n);

    ptr = (struct account *) malloc (n * sizeof(struct account));

    if(ptr == NULL) {
        printf("Memory is not allocated!");
        return 0;
    }

    for(i=0; i<n; i++) {
        printf("Enter the account number of account %d: ", i+1);
        scanf("%d", &(ptr+i)->account_number);

        printf("Enter the name of account %d: ", i+1);
        scanf("%s", (ptr+i)->name);

        printf("Enter the balance of account %d: ", i+1);
        scanf("%f", &(ptr+i)->balance);
    }

    printf("Select an option:\n 1. View Accounts\n 2. Deposit\n 3. Withdraw\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: printf("Account Number\tName\tBalance\n");
                for(i=0; i<n; i++) {
                    printf("%d\t\t%s\t%.2f\n", (ptr+i)->account_number, (ptr+i)->name, (ptr+i)->balance);
                }
                break;

        case 2: printf("Enter the account number where the amount should be deposited: ");
                scanf("%d", &j);

                for(i=0; i<n; i++) {
                    if((ptr+i)->account_number == j) {
                        printf("Enter the amount to be deposited: ");
                        scanf("%f", &amount);
                        (ptr+i)->balance += amount;
                        printf("Deposited successfully!\nUpdated balance: %.2f\n", (ptr+i)->balance);
                        break;
                    }
                }
                if(i == n) {
                    printf("No such account number found!\n");
                }
                break;

        case 3: printf("Enter the account number where the amount should be withdrawn: ");
                scanf("%d", &j);

                for(i=0; i<n; i++) {
                    if((ptr+i)->account_number == j) {
                        printf("Enter the amount to be withdrawn: ");
                        scanf("%f", &amount);
                        if(amount > (ptr+i)->balance) {
                            printf("Insufficient balance! Try again.\n");
                        } else {
                            (ptr+i)->balance -= amount;
                            printf("Withdrawn successfully!\nUpdated balance: %.2f\n", (ptr+i)->balance);
                        }
                        break;
                    }
                }
                if(i == n) {
                    printf("No such account number found!\n");
                }
                break;

        default: printf("Invalid option!");
    }
    
    free(ptr);
    return 0;
}