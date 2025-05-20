//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine item
typedef struct medicine_item {
    char name[50];
    int quantity;
    float price;
} medicine_item;

// Define the structure of a customer
typedef struct customer {
    char name[50];
    char address[100];
    int phone_number;
} customer;

// Function to add a medicine item to the inventory
void add_medicine(medicine_item *item) {
    printf("Enter the name of the medicine item: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the medicine item: ");
    scanf("%d", &item->quantity);

    printf("Enter the price of the medicine item: ");
    scanf("%f", &item->price);
}

// Function to remove a medicine item from the inventory
void remove_medicine(medicine_item *item) {
    printf("Enter the name of the medicine item you want to remove: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the medicine item you want to remove: ");
    scanf("%d", &item->quantity);
}

// Function to search for a medicine item
void search_medicine(medicine_item *item) {
    printf("Enter the name of the medicine item you are searching for: ");
    scanf("%s", item->name);

    printf("Results:\n");
    for (int i = 0; i < item->quantity; i++) {
        printf("%s - %d - %.2f\n", item->name, item->quantity, item->price);
    }
}

// Function to add a customer to the database
void add_customer(customer *customer) {
    printf("Enter the name of the customer: ");
    scanf("%s", customer->name);

    printf("Enter the address of the customer: ");
    scanf("%s", customer->address);

    printf("Enter the phone number of the customer: ");
    scanf("%d", &customer->phone_number);
}

// Function to remove a customer from the database
void remove_customer(customer *customer) {
    printf("Enter the name of the customer you want to remove: ");
    scanf("%s", customer->name);

    printf("Enter the phone number of the customer you want to remove: ");
    scanf("%d", &customer->phone_number);
}

// Function to search for a customer
void search_customer(customer *customer) {
    printf("Enter the name of the customer you are searching for: ");
    scanf("%s", customer->name);

    printf("Results:\n");
    for (int i = 0; i < customer->phone_number; i++) {
        printf("%s - %s - %d\n", customer->name, customer->address, customer->phone_number);
    }
}

int main() {
    // Create an array of medicine items
    medicine_item items[100];

    // Create an array of customers
    customer customers[100];

    // Menu options
    int menu_choice;

    // Loop until the user chooses to exit
    while (menu_choice != 4) {
        // Display the menu options
        printf("Please select an option:\n");
        printf("1. Add a medicine item\n");
        printf("2. Remove a medicine item\n");
        printf("3. Search for a medicine item\n");
        printf("4. Exit\n");

        // Get the user's choice
        scanf("%d", &menu_choice);

        // Switch case to handle the user's choice
        switch (menu_choice) {
            case 1:
                add_medicine(&items[0]);
                break;
            case 2:
                remove_medicine(&items[0]);
                break;
            case 3:
                search_medicine(&items[0]);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}