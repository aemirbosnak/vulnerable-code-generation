//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum name and code length
#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10

// Define a struct for storing the details of a medicine
struct Medicine {
    char code[MAX_CODE_LENGTH];
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

// Define a struct for storing the details of a customer
struct Customer {
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    long long int phone;
};

// Define a struct for storing the details of a sale
struct Sale {
    struct Customer customer;
    struct Medicine medicine;
    int quantity;
    float total_price;
};

// Define a function for adding a new medicine
void add_medicine(struct Medicine *medicines, int *num_medicines) {
    // Ask the user for the details of the medicine
    printf("Enter the code of the medicine: ");
    scanf("%s", medicines[*num_medicines].code);
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[*num_medicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    
    // Increment the number of medicines
    (*num_medicines)++;
    
    // Print a success message
    printf("Medicine added successfully!\n");
}

// Define a function for searching for a medicine by its code
int search_medicine(struct Medicine *medicines, int num_medicines, char *code) {
    // Loop through the medicines to find the one with the matching code
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            // Return the index of the matching medicine
            return i;
        }
    }
    
    // Return -1 if the medicine was not found
    return -1;
}

// Define a function for displaying all the medicines
void display_medicines(struct Medicine *medicines, int num_medicines) {
    // Print the header row
    printf("%-10s %-30s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");
    
    // Loop through the medicines to print their details
    for (int i = 0; i < num_medicines; i++) {
        printf("%-10s %-30s %-10.2f %-10d\n", medicines[i].code, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Define a function for adding a new customer
void add_customer(struct Customer *customers, int *num_customers) {
    // Ask the user for the details of the customer
    printf("Enter the name of the customer: ");
    scanf("%s", customers[*num_customers].name);
    printf("Enter the address of the customer: ");
    scanf("%s", customers[*num_customers].address);
    printf("Enter the phone number of the customer: ");
    scanf("%lld", &customers[*num_customers].phone);
    
    // Increment the number of customers
    (*num_customers)++;
    
    // Print a success message
    printf("Customer added successfully!\n");
}

// Define a function for placing a new sale
void place_sale(struct Sale *sales, int *num_sales, struct Customer *customers, int num_customers, struct Medicine *medicines, int num_medicines) {
    // Ask the user for the details of the sale
    printf("Enter the name of the customer: ");
    char customer_name[MAX_NAME_LENGTH];
    scanf("%s", customer_name);
    int customer_index = -1;
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].name, customer_name) == 0) {
            customer_index = i;
            break;
        }
    }
    if (customer_index == -1) {
        printf("Customer not found!\n");
        return;
    }
    struct Customer customer = customers[customer_index];
    
    printf("Enter the code of the medicine: ");
    char medicine_code[MAX_CODE_LENGTH];
    scanf("%s", medicine_code);
    int medicine_index = search_medicine(medicines, num_medicines, medicine_code);
    if (medicine_index == -1) {
        printf("Medicine not found!\n");
        return;
    }
    struct Medicine medicine = medicines[medicine_index];
    
    printf("Enter the quantity of the medicine: ");
    int quantity;
    scanf("%d", &quantity);
    if (quantity > medicine.quantity) {
        printf("Not enough medicine in stock!\n");
        return;
    }
    
    float total_price = quantity * medicine.price;
    
    // Add the sale to the list of sales
    struct Sale sale = {customer, medicine, quantity, total_price};
    sales[*num_sales] = sale;
    (*num_sales)++;
    
    // Decrement the quantity of the medicine in stock
    medicines[medicine_index].quantity -= quantity;
    
    // Print a success message
    printf("Sale placed successfully!\n");
}

int main() {
    // Define an array to store the medicines
    struct Medicine medicines[100];
    int num_medicines = 0;
    
    // Define an array to store the customers
    struct Customer customers[100];
    int num_customers = 0;
    
    // Define an array to store the sales
    struct Sale sales[100];
    int num_sales = 0;
    
    // Loop until the user chooses to exit
    while (1) {
        // Display the menu
        printf("\nMedical Store Management System\n");
        printf("1. Add new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Display all medicines\n");
        printf("4. Add new customer\n");
        printf("5. Place a new sale\n");
        printf("6. Display all sales\n");
        printf("7. Exit\n");
        
        // Ask the user for their choice
        int choice;
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        // Perform the corresponding action based on the user's choice
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                printf("Enter the code of the medicine: ");
                char code[MAX_CODE_LENGTH];
                scanf("%s", code);
                int index = search_medicine(medicines, num_medicines, code);
                if (index == -1) {
                    printf("Medicine not found!\n");
                } else {
                    printf("Details of the medicine:\n");
                    printf("Code: %s\n", medicines[index].code);
                    printf("Name: %s\n", medicines[index].name);
                    printf("Price: %.2f\n", medicines[index].price);
                    printf("Quantity: %d\n", medicines[index].quantity);
                }
                break;
            case 3:
                display_medicines(medicines, num_medicines);
                break;
            case 4:
                add_customer(customers, &num_customers);
                break;
            case 5:
                place_sale(sales, &num_sales, customers, num_customers, medicines, num_medicines);
                break;
            case 6:
                printf("%-30s %-30s %-10s %-10s %-10s\n", "Customer Name", "Medicine Name", "Price", "Quantity", "Total");
                for (int i = 0; i < num_sales; i++) {
                    printf("%-30s %-30s %-10.2f %-10d %-10.2f\n", sales[i].customer.name, sales[i].medicine.name, sales[i].medicine.price, sales[i].quantity, sales[i].total_price);
                }
                break;
            case 7:
                printf("Thank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}