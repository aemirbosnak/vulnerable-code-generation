//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Define the structure of a customer
typedef struct Customer {
    char name[50];
    char address[100];
    char phone[20];
} Customer;

// Define the structure of a sale
typedef struct Sale {
    char date[20];
    char time[20];
    Customer customer;
    Medicine medicine;
    int quantity;
    float total_price;
} Sale;

// Function to add a new medicine to the inventory
void add_medicine(Medicine *inventory, int *num_medicines) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*num_medicines].name);

    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*num_medicines].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*num_medicines].quantity);

    (*num_medicines)++;
}

// Function to sell a medicine
void sell_medicine(Medicine *inventory, int *num_medicines, Sale *sales, int *num_sales) {
    char medicine_name[50];
    int quantity;

    printf("Enter the name of the medicine: ");
    scanf("%s", medicine_name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    // Check if the medicine is in the inventory
    int medicine_index = -1;
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(inventory[i].name, medicine_name) == 0) {
            medicine_index = i;
            break;
        }
    }

    // If the medicine is not in the inventory, print an error message
    if (medicine_index == -1) {
        printf("Medicine not found in the inventory.\n");
        return;
    }

    // Check if the medicine has enough quantity
    if (inventory[medicine_index].quantity < quantity) {
        printf("Insufficient quantity of the medicine.\n");
        return;
    }

    // Update the inventory
    inventory[medicine_index].quantity -= quantity;

    // Add the sale to the sales list
    strcpy(sales[*num_sales].date, "2023-03-08");
    strcpy(sales[*num_sales].time, "10:30:00");
    sales[*num_sales].customer.name[0] = '\0';
    sales[*num_sales].customer.address[0] = '\0';
    sales[*num_sales].customer.phone[0] = '\0';
    sales[*num_sales].medicine = inventory[medicine_index];
    sales[*num_sales].quantity = quantity;
    sales[*num_sales].total_price = quantity * inventory[medicine_index].price;

    (*num_sales)++;
}

// Function to print the inventory
void print_inventory(Medicine *inventory, int num_medicines) {
    printf("Inventory:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to print the sales list
void print_sales(Sale *sales, int num_sales) {
    printf("Sales:\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%s\t%s\t%s\t%s\t%d\t%.2f\n", sales[i].date, sales[i].time, sales[i].customer.name, sales[i].customer.address, sales[i].customer.phone, sales[i].medicine.name, sales[i].quantity, sales[i].total_price);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Medicine inventory[100];
    int num_medicines = 0;

    // Initialize the sales list
    Sale sales[100];
    int num_sales = 0;

    // Add some medicines to the inventory
    add_medicine(inventory, &num_medicines);
    add_medicine(inventory, &num_medicines);
    add_medicine(inventory, &num_medicines);

    // Sell some medicines
    sell_medicine(inventory, &num_medicines, sales, &num_sales);
    sell_medicine(inventory, &num_medicines, sales, &num_sales);

    // Print the inventory
    print_inventory(inventory, num_medicines);

    // Print the sales list
    print_sales(sales, num_sales);

    return 0;
}