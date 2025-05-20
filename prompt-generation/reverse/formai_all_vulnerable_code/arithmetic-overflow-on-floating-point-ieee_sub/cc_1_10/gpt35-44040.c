//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct account{
    char name[50];
    long int acc_num;
    double balance;
}acc;

int main(){
    printf("Welcome to the Banking Record System!\n");
    printf("Enter your name: ");
    scanf("%s", acc.name);
    printf("Enter your account number: ");
    scanf("%ld", &acc.acc_num);
    printf("Enter your balance: ");
    scanf("%lf", &acc.balance);
    printf("\nAccount created successfully!\n\n");
    printf("Name: %s\nAccount Number: %ld\nBalance: $%.2lf\n\n", acc.name, acc.acc_num, acc.balance);
    printf("What would you like to do?\n");
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    int choice = 0;
    scanf("%d", &choice);
    double amount = 0.00;
    switch(choice){
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            acc.balance += amount;
            printf("Deposit of $%.2lf was successful!\n", amount);
            printf("New balance: $%.2lf\n", acc.balance);
            break;
        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if(amount > acc.balance){
                printf("Insufficient funds!\n");
            }
            else{
                acc.balance -= amount;
                printf("Withdrawal of $%.2lf was successful!\n", amount);
                printf("New balance: $%.2lf\n", acc.balance);
            }
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    printf("\nThank you for using the Banking Record System!");
    return 0;
}