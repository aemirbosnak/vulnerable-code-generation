//FormAI DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100

// Structure to hold customer information
typedef struct Customer {
    char name[50];
    int account_number;
    float balance;
} Customer;

// Function declarations
void add_customer(Customer[], int*);
void view_customer_info(Customer);
void view_all_customers(Customer[], int);
void deposit(Customer[], int);
void withdraw(Customer[], int);
void remove_customer(Customer[], int*);

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    int choice;
    do {
        printf("\n\n------BANKING RECORD SYSTEM------");
        printf("\n1. Add customer");
        printf("\n2. View customer information");
        printf("\n3. View all customers");
        printf("\n4. Deposit money");
        printf("\n5. Withdraw money");
        printf("\n6. Remove customer");
        printf("\n7. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(customers, &num_customers);
                break;
            case 2: {
                int acc_num;
                printf("Enter account number: ");
                scanf("%d", &acc_num);
                for (int i = 0; i < num_customers; i++) {
                    if (customers[i].account_number == acc_num) {
                        view_customer_info(customers[i]);
                        break;
                    } else if (i == num_customers - 1) {
                        printf("Customer not found.");
                    }
                }
                break;
            }
            case 3:
                view_all_customers(customers, num_customers);
                break;
            case 4:
                deposit(customers, num_customers);
                break;
            case 5:
                withdraw(customers, num_customers);
                break;
            case 6:
                remove_customer(customers, &num_customers);
                break;
            case 7:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.");
        }
    } while (choice != 7);

    return 0;
}

// Function to add a customer
void add_customer(Customer customers[], int *num_customers) {
    Customer new_customer;
    printf("\nEnter customer name: ");
    scanf("%s", &new_customer.name);
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    printf("Enter initial balance: ");
    scanf("%f", &new_customer.balance);

    customers[*num_customers] = new_customer;
    (*num_customers)++;
}

// Function to view customer information
void view_customer_info(Customer customer) {
    printf("\nCustomer name: %s", customer.name);
    printf("\nAccount number: %d", customer.account_number);
    printf("\nBalance: $%.2f", customer.balance);
}

// Function to view all customers
void view_all_customers(Customer customers[], int num_customers) {
    printf("\n\nCUSTOMER LIST\n");
    for (int i = 0; i < num_customers; i++) {
        view_customer_info(customers[i]);
        printf("\n\n");
    }
}

// Function to deposit money
void deposit(Customer customers[], int num_customers) {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == acc_num) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("New balance: $%.2f", customers[i].balance);
            break;
        } else if (i == num_customers - 1) {
            printf("Customer not found.");
        }
    }
}

// Function to withdraw money
void withdraw(Customer customers[], int num_customers) {
    int acc_num;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == acc_num) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (customers[i].balance < amount) {
                printf("Insufficient balance.");
            } else {
                customers[i].balance -= amount;
                printf("New balance: $%.2f", customers[i].balance);
            }
            break;
        } else if (i == num_customers - 1) {
            printf("Customer not found.");
        }
    }
}

// Function to remove a customer
void remove_customer(Customer customers[], int *num_customers) {
    int acc_num;
    printf("Enter account number: ");
    scanf("%d", &acc_num);
    for (int i = 0; i < *num_customers; i++) {
        if (customers[i].account_number == acc_num) {
            for (int j = i; j < *num_customers - 1; j++) {
                customers[j] = customers[j+1];
            }
            printf("\nCustomer removed.");
            (*num_customers)--;
            break;
        } else if (i == *num_customers - 1) {
            printf("Customer not found.");
        }
    }
}