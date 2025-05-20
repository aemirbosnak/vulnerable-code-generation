//FormAI DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int customer_id = 0; // to assign unique customer IDs
int record_count = 0; // to count the total number of records in the system

// Struct to hold the customer's information
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
    float balance;
} customer;

// Function to add a new customer record to the system
void add_customer(customer *customers) {
    customers[customer_id].id = customer_id; // assign unique ID to customer
    printf("Enter customer name: ");
    gets(customers[customer_id].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[customer_id].age);
    getchar(); // to consume the newline character
    printf("Enter customer address: ");
    gets(customers[customer_id].address);
    printf("Enter opening balance: ");
    scanf("%f", &customers[customer_id].balance);
    getchar(); // to consume the newline character
    record_count++;
    customer_id++;
}

// Function to display the details of a single customer record
void show_customer(customer *customers, int customer_id) {
    printf("ID: %d\n", customers[customer_id].id);
    printf("Name: %s\n", customers[customer_id].name);
    printf("Age: %d\n", customers[customer_id].age);
    printf("Address: %s\n", customers[customer_id].address);
    printf("Balance: $%.2f\n", customers[customer_id].balance);
}

// Function to display all the customer records in the system
void show_all_customers(customer *customers) {
    if (record_count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("Total number of records: %d\n", record_count);
    for (int i = 0; i < record_count; i++) {
        show_customer(customers, i);
    }
}

// Function to perform a transaction (deposit/withdrawal) on a customer's account
void perform_transaction(customer *customers, int customer_id, char *transaction_type, float amount) {
    if (strcmp(transaction_type, "deposit") == 0) {
        customers[customer_id].balance += amount;
        printf("$%.2f has been deposited to customer '%s' account.\n", amount, customers[customer_id].name);
    } else if (strcmp(transaction_type, "withdrawal") == 0) {
        if (amount > customers[customer_id].balance) {
            printf("Insufficient balance in customer '%s' account. Transaction cancelled.\n", customers[customer_id].name);
            return;
        }
        customers[customer_id].balance -= amount;
        printf("$%.2f has been withdrawn from customer '%s' account.\n", amount, customers[customer_id].name);
    }
}

int main() {
    customer customers[50];
    char menu_choice;
    do {
        printf("\n******** BANKING RECORD SYSTEM ********\n");
        printf("1. Add new customer record\n");
        printf("2. View details of a customer record\n");
        printf("3. View all customer records\n");
        printf("4. Perform a transaction\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        menu_choice = getchar();
        getchar(); // to consume the newline character
        switch (menu_choice) {
            case '1':
                add_customer(customers);
                break;
            case '2': {
                int id;
                printf("Enter customer ID: ");
                scanf("%d", &id);
                getchar(); // to consume the newline character
                if (id < 0 || id >= record_count) {
                    printf("Invalid customer ID.\n");
                    break;
                }
                show_customer(customers, id);
                break;
            }
            case '3':
                show_all_customers(customers);
                break;
            case '4': {
                int id;
                char transaction_type[20];
                float amount;
                printf("Enter customer ID: ");
                scanf("%d", &id);
                getchar(); // to consume the newline character
                if (id < 0 || id >= record_count) {
                    printf("Invalid customer ID.\n");
                    break;
                }
                printf("Enter transaction type (deposit/withdrawal): ");
                gets(transaction_type);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                getchar(); // to consume the newline character
                perform_transaction(customers, id, transaction_type, amount);
                break;
            }
            case '5':
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose between 1-5.\n");
                break;
        }
    } while (1);
    return 0;
}