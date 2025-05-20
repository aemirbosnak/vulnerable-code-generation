//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct account {
    int account_number;
    char holder_name[50];
    float balance;
};

int main() {
    struct account a[100];
    int choice, count=0, num, i;
    float amount;

    printf("Welcome to the Futuristic Banking Record System\n");

    do {
        printf("\n\nEnter your choice:\n1. Create a new account\n2. Deposit amount\n3. Withdraw amount\n4. Check balance\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &a[count].account_number);

                printf("Enter Holder Name: ");
                scanf("%s", a[count].holder_name);

                printf("Enter Initial Balance: ");
                scanf("%f", &a[count].balance);

                count++;
                printf("\nAccount created successfully!\n");
                break;

            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &num);

                i = 0;
                while (i < count && a[i].account_number != num) {
                    i++;
                }

                if (i == count) {
                    printf("\nAccount not found!\n");
                }
                else {
                    printf("Enter Amount to Deposit: ");
                    scanf("%f", &amount);

                    a[i].balance += amount;
                    printf("\nAmount deposited successfully!\n");
                }
                break;

            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &num);

                i = 0;
                while (i < count && a[i].account_number != num) {
                    i++;
                }

                if (i == count) {
                    printf("\nAccount not found!\n");
                }
                else {
                    printf("Enter Amount to Withdraw: ");
                    scanf("%f", &amount);

                    if (a[i].balance < amount) {
                        printf("\nInsufficient Balance!\n");
                    }
                    else {
                        a[i].balance -= amount;
                        printf("\nAmount withdrawn successfully!\n");
                    }
                }
                break;

            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &num);

                i = 0;
                while (i < count && a[i].account_number != num) {
                    i++;
                }

                if (i == count) {
                    printf("\nAccount not found!\n");
                }
                else {
                    printf("Account Holder Name: %s\n", a[i].holder_name);
                    printf("Account Balance: %.2f\n", a[i].balance);
                }
                break;

            case 5:
                printf("\nThank you for using Futuristic Banking Record System!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while (1);

    return 0;
}