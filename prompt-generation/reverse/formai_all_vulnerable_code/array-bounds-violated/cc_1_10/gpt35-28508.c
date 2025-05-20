//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 10
#define MAX_MEDICINES 20

typedef struct {
    int id;
    char name[20];
    char contact[10];
    char address[30];
} Customer;

typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Medicine;

Customer customers[MAX_CUSTOMERS];
Medicine medicines[MAX_MEDICINES];

int num_customers = 0;
int num_medicines = 0;

// Function to add a new customer
void add_customer() {
    Customer customer;
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer contact: ");
    scanf("%s", customer.contact);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    customer.id = num_customers + 1;
    customers[num_customers++] = customer;
    printf("Customer added successfully!\n");
}

// Function to add a new medicine
void add_medicine() {
    Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    medicine.id = num_medicines + 1;
    medicines[num_medicines++] = medicine;
    printf("Medicine added successfully!\n");
}

// Function to display all customers
void display_customers() {
    printf("Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%d. %s %s %s\n", customers[i].id, customers[i].name, customers[i].contact, customers[i].address);
    }
}

// Function to display all medicines
void display_medicines() {
    printf("Medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s %d %.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to sell medicine to customer
void sell_medicine() {
    int customer_id, medicine_id, quantity;
    printf("Enter customer id: ");
    scanf("%d", &customer_id);
    printf("Enter medicine id: ");
    scanf("%d", &medicine_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    Customer customer;
    Medicine medicine;
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].id == customer_id) {
            customer = customers[i];
            break;
        }
    }
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == medicine_id) {
            medicine = medicines[i];
            break;
        }
    }
    if (quantity > medicine.quantity) {
        printf("Not enough stock!\n");
        return;
    }
    printf("Customer: %s %s\n", customer.name, customer.contact);
    printf("Medicine: %s\n", medicine.name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", quantity * medicine.price);
    medicine.quantity -= quantity;
    medicines[medicine_id - 1] = medicine;
    printf("Medicine sold successfully!\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("Medicine Store Management System\n");
        printf("1. Add Customer\n2. Add Medicine\n3. Display Customers\n4. Display Medicines\n5. Sell Medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                add_medicine();
                break;
            case 3:
                display_customers();
                break;
            case 4:
                display_medicines();
                break;
            case 5:
                sell_medicine();
                break;
            case 6:
                printf("Thank you for using Medicine Store Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}