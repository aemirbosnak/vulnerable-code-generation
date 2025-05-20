//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Structure to store the details of a customer
typedef struct customer {
    char name[50];
    char address[100];
    char phone[20];
} customer;

// Structure to store the details of a sale
typedef struct sale {
    char date[20];
    medicine *medicine;
    customer *customer;
    int quantity;
    float total_price;
} sale;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *num_medicines) {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*num_medicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*num_medicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*num_medicines].quantity);

    // Increment the number of medicines in the inventory
    (*num_medicines)++;
}

// Function to sell a medicine
void sell_medicine(medicine *inventory, int *num_medicines, sale *sales, int *num_sales) {
    // Get the name of the medicine to be sold
    char medicine_name[50];
    printf("Enter the name of the medicine to be sold: ");
    scanf("%s", medicine_name);

    // Find the medicine in the inventory
    int medicine_index = -1;
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(inventory[i].name, medicine_name) == 0) {
            medicine_index = i;
            break;
        }
    }

    // If the medicine is not found, print an error message
    if (medicine_index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    // Get the quantity of the medicine to be sold
    int quantity;
    printf("Enter the quantity of the medicine to be sold: ");
    scanf("%d", &quantity);

    // If the quantity is greater than the available quantity, print an error message
    if (quantity > inventory[medicine_index].quantity) {
        printf("Insufficient quantity available.\n");
        return;
    }

    // Get the details of the customer
    customer *customer = malloc(sizeof(customer));
    printf("Enter the name of the customer: ");
    scanf("%s", customer->name);
    printf("Enter the address of the customer: ");
    scanf("%s", customer->address);
    printf("Enter the phone number of the customer: ");
    scanf("%s", customer->phone);

    // Create a new sale record
    sale *new_sale = malloc(sizeof(sale));
    strcpy(new_sale->date, "2023-03-08");
    new_sale->medicine = &inventory[medicine_index];
    new_sale->customer = customer;
    new_sale->quantity = quantity;
    new_sale->total_price = new_sale->quantity * new_sale->medicine->price;

    // Add the new sale to the sales array
    sales[*num_sales] = *new_sale;
    (*num_sales)++;

    // Reduce the quantity of the medicine in the inventory
    inventory[medicine_index].quantity -= quantity;

    // Print the sale receipt
    printf("\nSale Receipt\n");
    printf("-----------------------------------------\n");
    printf("Date: %s\n", new_sale->date);
    printf("Medicine Name: %s\n", new_sale->medicine->name);
    printf("Quantity: %d\n", new_sale->quantity);
    printf("Total Price: %.2f\n", new_sale->total_price);
    printf("-----------------------------------------\n");
}

// Function to print the inventory of medicines
void print_inventory(medicine *inventory, int num_medicines) {
    printf("\nInventory of Medicines\n");
    printf("---------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Medicine Name", "Price", "Quantity");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("| %-20s | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("---------------------------------------------------------\n");
}

// Function to print the list of sales
void print_sales(sale *sales, int num_sales) {
    printf("\nList of Sales\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s | %-10s | %-10s | %-10s |\n", "Date", "Medicine Name", "Customer Name", "Quantity", "Total Price", "Phone Number");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_sales; i++) {
        printf("| %-20s | %-20s | %-20s | %-10d | %-10.2f | %-10s |\n", sales[i].date, sales[i].medicine->name, sales[i].customer->name, sales[i].quantity, sales[i].total_price, sales[i].customer->phone);
    }
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Create an array of medicines
    medicine inventory[100];

    // Initialize the number of medicines to 0
    int num_medicines = 0;

    // Create an array of sales
    sale sales[100];

    // Initialize the number of sales to 0
    int num_sales = 0;

    // Run the main loop
    while (1) {
        // Print the menu
        printf("\nMedical Store Management System\n");
        printf("-----------------------------------------\n");
        printf("1. Add a new medicine\n");
        printf("2. Sell a medicine\n");
        printf("3. Print the inventory of medicines\n");
        printf("4. Print the list of sales\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_medicine(inventory, &num_medicines);
                break;
            case 2:
                sell_medicine(inventory, &num_medicines, sales, &num_sales);
                break;
            case 3:
                print_inventory(inventory, num_medicines);
                break;
            case 4:
                print_sales(sales, num_sales);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}