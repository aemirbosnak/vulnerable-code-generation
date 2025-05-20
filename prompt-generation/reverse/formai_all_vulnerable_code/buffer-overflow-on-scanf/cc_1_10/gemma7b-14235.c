//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medicine item
typedef struct MedicineItem {
    char name[20];
    int quantity;
    float price;
} MedicineItem;

// Define a structure for a customer
typedef struct Customer {
    char name[20];
    int age;
    char address[50];
} Customer;

// Function to add a medicine item
void addItem(MedicineItem *item) {
    printf("Enter the name of the medicine item: ");
    scanf("%s", item->name);
    printf("Enter the quantity of the medicine item: ");
    scanf("%d", &item->quantity);
    printf("Enter the price of the medicine item: ");
    scanf("%f", &item->price);
}

// Function to remove a medicine item
void removeItem(MedicineItem *item) {
    printf("Enter the name of the medicine item to remove: ");
    scanf("%s", item->name);
    item->quantity = 0;
}

// Function to list all medicine items
void listItems(MedicineItem *item) {
    printf("List of medicine items:\n");
    for (int i = 0; item[i].name[0] != '\0'; i++) {
        printf("%s - %d - %.2f\n", item[i].name, item[i].quantity, item[i].price);
    }
}

// Function to add a customer
void addCustomer(Customer *customer) {
    printf("Enter the name of the customer: ");
    scanf("%s", customer->name);
    printf("Enter the age of the customer: ");
    scanf("%d", &customer->age);
    printf("Enter the address of the customer: ");
    scanf("%s", customer->address);
}

// Function to remove a customer
void removeCustomer(Customer *customer) {
    printf("Enter the name of the customer to remove: ");
    scanf("%s", customer->name);
    customer->age = -1;
}

// Function to list all customers
void listCustomers(Customer *customer) {
    printf("List of customers:\n");
    for (int i = 0; customer[i].name[0] != '\0'; i++) {
        printf("%s - %d - %s\n", customer[i].name, customer[i].age, customer[i].address);
    }
}

int main() {
    // Create an array of medicine items
    MedicineItem items[100];
    int i = 0;

    // Create an array of customers
    Customer customers[100];
    int j = 0;

    // Main loop
    while (1) {
        // Display menu options
        printf("Enter 1 to add a medicine item\n");
        printf("Enter 2 to remove a medicine item\n");
        printf("Enter 3 to list all medicine items\n");
        printf("Enter 4 to add a customer\n");
        printf("Enter 5 to remove a customer\n");
        printf("Enter 6 to list all customers\n");
        printf("Enter 7 to exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Switch case to handle user's choice
        switch (choice) {
            case 1:
                addItem(items);
                break;
            case 2:
                removeItem(items);
                break;
            case 3:
                listItems(items);
                break;
            case 4:
                addCustomer(customers);
                break;
            case 5:
                removeCustomer(customers);
                break;
            case 6:
                listCustomers(customers);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}