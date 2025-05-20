//FormAI DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 1000

// Structure to hold customer information
typedef struct {
    char name[100];
    int account_no;
    float balance;
} Customer;

// Function declarations
void add_customer_record(Customer customer);
void display_customer_records();
void update_customer_balance(int account_no, float amount);

// Global variables
Customer records[MAX_RECORDS];
int num_records = 0;

int main() {
    int choice;
    do {
        printf("\n1. Add a new customer record\n2. Display all customer records\n3. Update customer balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Customer customer;
                printf("Enter customer name: ");
                scanf("%s", customer.name);
                printf("Enter account number: ");
                scanf("%d", &customer.account_no);
                printf("Enter balance: ");
                scanf("%f", &customer.balance);
                add_customer_record(customer);
                break;
            }
            case 2: {
                display_customer_records();
                break;
            }
            case 3: {
                int account_no;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &account_no);
                printf("Enter amount to add/subtract: ");
                scanf("%f", &amount);
                update_customer_balance(account_no, amount);
                break;
            }
            case 4: {
                printf("Exiting program...");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}

void add_customer_record(Customer customer) {
    if (num_records >= MAX_RECORDS) {
        printf("Maximum number of records reached. Cannot add new record.");
        return;
    }
    records[num_records] = customer;
    num_records++;
    printf("Record added successfully.");
}

void display_customer_records() {
    if (num_records == 0) {
        printf("No records found.");
        return;
    }
    printf("Customer records:\n");
    printf("Name\tAccount No.\tBalance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\t\t%f\n", records[i].name, records[i].account_no, records[i].balance);
    }
}

void update_customer_balance(int account_no, float amount) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_no == account_no) {
            records[i].balance += amount;
            printf("Balance updated successfully.");
            return;
        }
    }
    printf("No customer record found with account number %d.", account_no);
}