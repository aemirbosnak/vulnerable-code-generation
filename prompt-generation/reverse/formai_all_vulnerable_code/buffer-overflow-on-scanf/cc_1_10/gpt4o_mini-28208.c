//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 100
#define ACCOUNT_LENGTH 20

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float balance;
    char account_number[ACCOUNT_LENGTH];
} Customer;

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void add_customer();
void display_customers();
void update_balance();
void save_to_file();
void load_from_file();
void menu();

int main() {
    load_from_file();
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n==== Banking Record System ====\n");
        printf("1. Add Customer\n");
        printf("2. Display All Customers\n");
        printf("3. Update Customer Balance\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                display_customers();
                break;
            case 3:
                update_balance();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                printf("Exiting the banking system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

void add_customer() {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("Customer limit reached! Cannot add more customers.\n");
        return;
    }
    Customer new_customer;
    new_customer.id = customer_count + 1; // Start IDs from 1
    printf("Enter customer name: ");
    getchar(); // clear the input buffer
    fgets(new_customer.name, NAME_LENGTH, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = 0; // remove newline
    printf("Enter account number: ");
    fgets(new_customer.account_number, ACCOUNT_LENGTH, stdin);
    new_customer.account_number[strcspn(new_customer.account_number, "\n")] = 0; // remove newline
    new_customer.balance = 0.0;

    customers[customer_count] = new_customer;
    customer_count++;
    printf("Customer added successfully!\n");
}

void display_customers() {
    if (customer_count == 0) {
        printf("No customers to display.\n");
        return;
    }
    printf("\nList of Customers:\n");
    printf("%-5s %-30s %-15s %-20s\n", "ID", "Name", "Balance", "Account Number");
    for (int i = 0; i < customer_count; i++) {
        printf("%-5d %-30s $%-14.2f %-20s\n", customers[i].id, customers[i].name, customers[i].balance, customers[i].account_number);
    }
}

void update_balance() {
    int id;
    float amount;
    printf("Enter customer ID to update balance: ");
    scanf("%d", &id);

    if (id < 1 || id > customer_count) {
        printf("Invalid customer ID!\n");
        return;
    }

    printf("Enter amount to add (negative for withdrawal): ");
    scanf("%f", &amount);
    customers[id - 1].balance += amount;
    printf("Balance updated successfully! New balance: $%.2f\n", customers[id - 1].balance);
}

void save_to_file() {
    FILE *file = fopen("customers.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(customers, sizeof(Customer), customer_count, file);
    fclose(file);
    printf("Customers saved to file successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("customers.dat", "rb");
    if (file == NULL) {
        printf("No saved file found, starting fresh.\n");
        return;
    }
    customer_count = fread(customers, sizeof(Customer), MAX_CUSTOMERS, file);
    fclose(file);
    printf("Loaded %d customers from file.\n", customer_count);
}