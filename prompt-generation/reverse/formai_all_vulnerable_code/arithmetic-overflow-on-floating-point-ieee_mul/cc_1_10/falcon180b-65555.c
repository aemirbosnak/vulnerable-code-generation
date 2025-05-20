//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[50];
    double balance;
    double interest_rate;
    time_t last_update;
} Account;

int main() {
    Account accounts[10];
    int num_accounts = 0;
    int choice;
    double amount;
    time_t current_time;

    srand(time(NULL));
    current_time = time(NULL);

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account Balance\n");
        printf("5. View Account Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_accounts == 10) {
                printf("Sorry, you can only create up to 10 accounts.\n");
            } else {
                printf("Enter account name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter starting balance: ");
                scanf("%lf", &accounts[num_accounts].balance);
                printf("Enter interest rate (%): ");
                scanf("%lf", &accounts[num_accounts].interest_rate);
                accounts[num_accounts].last_update = current_time;
                num_accounts++;
            }
            break;
        case 2:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Enter deposit amount: ");
            scanf("%lf", &amount);
            accounts[0].balance += amount;
            accounts[0].last_update = current_time;
            break;
        case 3:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Enter withdrawal amount: ");
            scanf("%lf", &amount);
            if (amount > accounts[0].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[0].balance -= amount;
                accounts[0].last_update = current_time;
            }
            break;
        case 4:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Current balance: $%.2lf\n", accounts[0].balance);
            break;
        case 5:
            printf("Enter account name: ");
            scanf("%s", accounts[0].name);
            printf("Current interest rate: %.2lf%%\n", accounts[0].interest_rate * 100);
            break;
        case 6:
            printf("Thank you for using Personal Finance Planner.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 6);

    return 0;
}