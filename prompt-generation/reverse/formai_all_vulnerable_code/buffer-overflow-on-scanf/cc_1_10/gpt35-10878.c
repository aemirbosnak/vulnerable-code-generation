//FormAI DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer record
typedef struct {
    char name[100];
    long int account_number;
    float account_balance;
} Customer;

// Function to add a new record to the database
void add_new_record(Customer* customer_database, int* num_customers) {
    printf("\nEnter the name of the customer: ");
    scanf("%s", customer_database[*num_customers].name);
    
    printf("Enter the account number: ");
    scanf("%ld", &customer_database[*num_customers].account_number);
    
    printf("Enter the account balance: ");
    scanf("%f", &customer_database[*num_customers].account_balance);
    
    *num_customers += 1;
    
    printf("\nRecord added successfully!\n");
}

// Function to delete a record from the database
void delete_record(Customer* customer_database, int* num_customers) {
    long int account_number;
    printf("\nEnter the account number to delete: ");
    scanf("%ld", &account_number);
    
    int record_index = -1;
    for (int i = 0; i < *num_customers; i++) {
        if (customer_database[i].account_number == account_number) {
            record_index = i;
            break;
        }
    }
    
    if (record_index != -1) {
        for (int i = record_index; i < *num_customers - 1; i++) {
            customer_database[i] = customer_database[i+1];
        }
        *num_customers -= 1;
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nRecord not found in the database!\n");
    }
}

// Function to display all records in the database
void display_records(Customer* customer_database, int num_customers) {
    printf("\nAll records in the database:\n");
    printf("Name\t\tAccount Number\t\tAccount Balance\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s\t\t%ld\t\t\t%.2f\n", customer_database[i].name, customer_database[i].account_number, customer_database[i].account_balance);
    }
}

// Main function to run the program
int main() {
    Customer customer_database[100];
    int num_customers = 0;
    
    int choice;
    
    while (1) {
        printf("\n\n------------ Banking Record System Menu ------------\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_new_record(customer_database, &num_customers);
                break;
            case 2:
                delete_record(customer_database, &num_customers);
                break;
            case 3:
                display_records(customer_database, num_customers);
                break;
            case 4:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    }
    
    return 0;
}