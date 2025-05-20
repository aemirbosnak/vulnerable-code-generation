//FormAI DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10

struct customer {
    char name[50];
    int account_number;
    float balance;
};

struct customer customers[MAX_CUSTOMERS];

int num_customers = 0;

void add_customer() {
    if (num_customers == MAX_CUSTOMERS) {
        printf("Maximum number of customers reached\n");
        return;
    }
    
    struct customer new_customer;
    
    printf("Enter name: ");
    fgets(new_customer.name, 50, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = 0; // Remove new line character
    
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    
    printf("Enter balance: ");
    scanf("%f", &new_customer.balance);
    
    getchar(); // Consume new line character
    
    customers[num_customers] = new_customer;
    num_customers++;
}

void view_customer(int account_number) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Name: %s\n", customers[i].name);
            printf("Account Number: %d\n", customers[i].account_number);
            printf("Balance: %f\n", customers[i].balance);
            return;
        }
    }
    
    printf("Customer with account number %d not found\n", account_number);
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("%f deposited to account number %d\n", amount, account_number);
            return;
        }
    }
    
    printf("Customer with account number %d not found\n", account_number);
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance < amount) {
                printf("Insufficient funds\n");
                return;
            }
            
            customers[i].balance -= amount;
            printf("%f withdrawn from account number %d\n", amount, account_number);
            return;
        }
    }
    
    printf("Customer with account number %d not found\n", account_number);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n*****Banking Record System*****\n");
        printf("1. Add customer\n");
        printf("2. View customer\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                add_customer();
                break;
            }
            case 2: {
                int account_number;
                
                printf("Enter account number: ");
                scanf("%d", &account_number);
                
                view_customer(account_number);
                
                getchar(); // Consume new line character
                break;
            }
            case 3: {
                int account_number;
                float amount;
                
                printf("Enter account number: ");
                scanf("%d", &account_number);
                
                printf("Enter amount: ");
                scanf("%f", &amount);
                
                deposit(account_number, amount);
                
                getchar(); // Consume new line character
                break;
            }
            case 4: {
                int account_number;
                float amount;
                
                printf("Enter account number: ");
                scanf("%d", &account_number);
                
                printf("Enter amount: ");
                scanf("%f", &amount);
                
                withdraw(account_number, amount);
                
                getchar(); // Consume new line character
                break;
            }
            case 5: {
                printf("Exiting program\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    
    return 0;
}