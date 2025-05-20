//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int acc_no;
    char name[50];
    float balance;
};

typedef struct customer Customer;

void display_menu() {
    printf("Welcome to XYZ Bank\n");
    printf("1. Open Account\n");
    printf("2. View Account\n");
    printf("3. Update Account\n");
    printf("4. Close Account\n");
    printf("5. Exit\n");
}

void open_account(Customer *cust) {
    printf("Enter Account Number: ");
    scanf("%d", &cust->acc_no);
    printf("Enter Name: ");
    scanf("%s", cust->name);
    printf("Enter Initial Balance: ");
    scanf("%f", &cust->balance);
    printf("\nAccount created successfully!\n\n");
}

void view_account(Customer *cust) {
    printf("Account Number: %d\n", cust->acc_no);
    printf("Name: %s\n", cust->name);
    printf("Balance: %.2f\n\n", cust->balance);
}

void update_account(Customer *cust) {
    float amount;
    int choice;
    printf("1. Deposit\n");
    printf("2. Withdrawal\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter Deposit Amount: ");
        scanf("%f", &amount);
        cust->balance += amount;
        printf("Deposit successful!\n");
    }
    else if (choice == 2) {
        printf("Enter Withdrawal Amount: ");
        scanf("%f", &amount);
        if (amount > cust->balance) {
            printf("Insufficient Balance!\n");
            return;
        }
        cust->balance -= amount;
        printf("Withdrawal successful!\n");
    }

    printf("Updated Account Details:\n");
    view_account(cust);
}

void close_account(Customer *cust) {
    memset(cust, 0, sizeof(Customer));
    printf("Account Closed Successfully!\n");
}

int main() {
    Customer cust;
    int choice;
    while(1) {
        display_menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                open_account(&cust);
                break;
            case 2:
                view_account(&cust);
                break;
            case 3:
                update_account(&cust);
                break;
            case 4:
                close_account(&cust);
                break;
            case 5:
                printf("Thank you for banking with us!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}