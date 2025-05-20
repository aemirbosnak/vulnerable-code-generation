//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX 1000
#define CHAR_SIZE 100

struct account {
    char name[CHAR_SIZE];
    int balance;
};

int main() {
    int choice;
    struct account account[MAX];
    int count = 0;
    int i;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please choose an option:\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", account[count].name);
                account[count].balance = 0;
                printf("Account created successfully!\n");
                count++;
                break;
            case 2:
                printf("Enter account name: ");
                scanf("%s", account[count].name);
                printf("Enter deposit amount: ");
                scanf("%d", &account[count].balance);
                printf("Deposit successful!\n");
                count++;
                break;
            case 3:
                printf("Enter account name: ");
                scanf("%s", account[count].name);
                printf("Enter withdrawal amount: ");
                scanf("%d", &account[count].balance);
                printf("Withdrawal successful!\n");
                count++;
                break;
            case 4:
                printf("Enter account name: ");
                scanf("%s", account[count].name);
                printf("Current balance: %d\n", account[count].balance);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf("%s", account[count].name);
        if (tolower(account[count].name[0]) == 'n') {
            printf("Exiting...\n");
            choice = 5;
        }
    }

    return 0;
}