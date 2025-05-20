//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char roomType[20];
    int stayDuration; // in days
    int isCheckedIn;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer limit reached! Cannot add more customers.\n");
        return;
    }
    Customer newCustomer;
    newCustomer.id = customerCount + 1;
    printf("Enter customer name: ");
    scanf(" %[^\n]", newCustomer.name);
    printf("Enter room type (Single/Double/Suite): ");
    scanf(" %[^\n]", newCustomer.roomType);
    printf("Enter stay duration (in days): ");
    scanf("%d", &newCustomer.stayDuration);
    newCustomer.isCheckedIn = 1;
    customers[customerCount++] = newCustomer;
    printf("Customer added successfully with ID: %d\n", newCustomer.id);
}

void viewCustomers() {
    if (customerCount == 0) {
        printf("No customers currently registered.\n");
        return;
    }
    printf("\nRegistered Customers:\n");
    printf("ID\tName\t\tRoom Type\tStay Duration\tChecked In\n");
    for (int i = 0; i < customerCount; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t\t%s\n", 
                customers[i].id, 
                customers[i].name, 
                customers[i].roomType, 
                customers[i].stayDuration, 
                customers[i].isCheckedIn ? "Yes" : "No");
    }
}

void deleteCustomer() {
    int id;
    printf("Enter customer ID to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > customerCount) {
        printf("Invalid ID! No customer found.\n");
        return;
    }
    for (int i = id - 1; i < customerCount - 1; i++) {
        customers[i] = customers[i + 1];
    }
    customerCount--;
    printf("Customer with ID %d deleted successfully!\n", id);
}

void displayMenu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Add Customer\n");
    printf("2. View Customers\n");
    printf("3. Delete Customer\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                deleteCustomer();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}