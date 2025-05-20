//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int id;
    char name[50];
    double balance;
};

int main() {
    struct account accounts[10];
    int numAccounts = 10;
    int choice = 0;
    int index = 0;

    while (choice!= 9) {
        printf("1. Add new account\n2. View accounts\n3. Deposit\n4. Withdraw\n5. Transfer\n6. Close account\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account details: ");
                scanf("%d %s %lf", &accounts[index].id, accounts[index].name, &accounts[index].balance);
                index++;
                break;
            case 2:
                if (numAccounts == 0) {
                    printf("No accounts added yet.\n");
                } else {
                    for (int i = 0; i < numAccounts; i++) {
                        printf("%d. %s - %lf\n", i + 1, accounts[i].name, accounts[i].balance);
                    }
                }
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%lf", &accounts[index-1].balance);
                break;
            case 4:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &accounts[index-1].balance);
                break;
            case 5:
                printf("Enter recipient account id: ");
                scanf("%d", &accounts[index-1].id);
                break;
            case 6:
                printf("Enter account id to close: ");
                scanf("%d", &accounts[index-1].id);
                break;
            case 7:
                printf("Thank you for using the banking record system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}