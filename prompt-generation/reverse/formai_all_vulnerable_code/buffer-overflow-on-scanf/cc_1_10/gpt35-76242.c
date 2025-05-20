//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

struct customer {
    char name[50];
    int account_num;
    float balance;
};

struct customer_list {
    struct customer customers[MAX_CUSTOMERS];
    int count;
};

void add_customer(struct customer_list *list, char *name, int account_num, float balance) {
    if (list->count >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached\n");
        return;
    }
    
    struct customer new_customer = {0};
    strncpy(new_customer.name, name, 49);
    new_customer.account_num = account_num;
    new_customer.balance = balance;
    
    list->customers[list->count++] = new_customer;
    
    printf("Customer added successfully\n");
}

void show_customer(struct customer_list *list, int account_num) {
    for (int i = 0; i < list->count; i++) {
        if (list->customers[i].account_num == account_num) {
            printf("Name: %s\n", list->customers[i].name);
            printf("Account Number: %d\n", list->customers[i].account_num);
            printf("Balance: $%.2f\n", list->customers[i].balance);
            return;
        }
    }
    printf("Customer with account number %d not found\n", account_num);
}

void make_deposit(struct customer_list *list, int account_num, float amount) {
    for (int i = 0; i < list->count; i++) {
        if (list->customers[i].account_num == account_num) {
            list->customers[i].balance += amount;
            printf("$%.2f deposited to account number %d. New balance: $%.2f\n", amount, account_num, list->customers[i].balance);
            return;
        }
    }
    printf("Customer with account number %d not found\n", account_num);
}

void make_withdrawal(struct customer_list *list, int account_num, float amount) {
    for (int i = 0; i < list->count; i++) {
        if (list->customers[i].account_num == account_num) {
            if (list->customers[i].balance >= amount) {
                list->customers[i].balance -= amount;
                printf("$%.2f withdrawn from account number %d. New balance: $%.2f\n", amount, account_num, list->customers[i].balance);
                return;
            } else {
                printf("Insufficient funds in account number %d\n", account_num);
                return;
            }
        }
    }
    printf("Customer with account number %d not found\n", account_num);
}

void display_menu() {
    printf("\n");
    printf("Customer Banking Record System\n");
    printf("menu:\n");
    printf("1. Add Customer\n");
    printf("2. Show Customer\n");
    printf("3. Make Deposit\n");
    printf("4. Make Withdrawal\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    struct customer_list list = {.count=0};
    
    int choice = 0;
    while (choice != 5) {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1: {
                char name[50];
                int account_num;
                float balance;
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &account_num);
                printf("Enter initial balance: ");
                scanf("%f", &balance);
                printf("\n");
                add_customer(&list, name, account_num, balance);
                break;
            }
            case 2: {
                int account_num;
                printf("Enter account number: ");
                scanf("%d", &account_num);
                printf("\n");
                show_customer(&list, account_num);
                break;
            }
            case 3: {
                int account_num;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &account_num);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                printf("\n");
                make_deposit(&list, account_num, amount);
                break;
            }
            case 4: {
                int account_num;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &account_num);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                printf("\n");
                make_withdrawal(&list, account_num, amount);
                break;
            }
            case 5: {
                printf("Exiting program\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    
    return 0;
}