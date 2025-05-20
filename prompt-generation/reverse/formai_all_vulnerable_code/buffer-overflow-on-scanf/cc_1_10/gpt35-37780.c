//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000
#define MAX_NAME_LEN 50

struct customer {
    char name[MAX_NAME_LEN];
    int account_num;
    float balance;
};

struct customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer() {
    if (num_customers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }
    
    struct customer new_customer;
    printf("Enter name: ");
    fgets(new_customer.name, MAX_NAME_LEN, stdin);
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_num);
    printf("Enter balance: ");
    scanf("%f", &new_customer.balance);
    getchar(); // Consume newline character
    
    customers[num_customers] = new_customer;
    num_customers++;
}

void list_customers() {
    if (num_customers == 0) {
        printf("No customers.\n");
        return;
    }
    
    printf("Name\tAccount Number\tBalance\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t%d\t%.2f\n", customers[i].name, customers[i].account_num, customers[i].balance);
    }
}

void deposit() {
    if (num_customers == 0) {
        printf("No customers.\n");
        return;
    }
    
    printf("Enter account number: ");
    int account_num;
    scanf("%d", &account_num);
    
    int customer_index = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_num == account_num) {
            customer_index = i;
            break;
        }
    }
    
    if (customer_index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }
    
    printf("Enter deposit amount: ");
    float deposit_amount;
    scanf("%f", &deposit_amount);
    
    customers[customer_index].balance += deposit_amount;
    
    printf("New balance: %.2f\n", customers[customer_index].balance);
}

void withdraw() {
    if (num_customers == 0) {
        printf("No customers.\n");
        return;
    }
    
    printf("Enter account number: ");
    int account_num;
    scanf("%d", &account_num);
    
    int customer_index = -1;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_num == account_num) {
            customer_index = i;
            break;
        }
    }
    
    if (customer_index == -1) {
        printf("Error: Account number not found.\n");
        return;
    }
    
    printf("Enter withdraw amount: ");
    float withdraw_amount;
    scanf("%f", &withdraw_amount);
    
    if (customers[customer_index].balance < withdraw_amount) {
        printf("Error: Insufficient balance.\n");
        return;
    }
    
    customers[customer_index].balance -= withdraw_amount;
    
    printf("New balance: %.2f\n", customers[customer_index].balance);
}

int main() {
    while (1) {
        printf("1. Add customer\n2. List customers\n3. Deposit\n4. Withdraw\n5. Quit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);
        getchar(); // Consume newline character
        
        switch (option) {
            case 1:
                add_customer();
                break;
            case 2:
                list_customers();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid option.\n");
                break;
        }
    }
    
    return 0;
}