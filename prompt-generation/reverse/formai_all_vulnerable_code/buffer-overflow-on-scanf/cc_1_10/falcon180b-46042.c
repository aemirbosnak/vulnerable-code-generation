//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 100
#define MAX_MEDICINE_STOCK 1000
#define MAX_CUSTOMER_NAME 100
#define MAX_CUSTOMER_ADDRESS 200
#define MAX_CUSTOMER_PHONE 20
#define MAX_CUSTOMER_MEDICINE 100

// Structure for medicine
struct medicine {
    char name[MAX_MEDICINE_NAME];
    int stock;
};

// Structure for customer
struct customer {
    char name[MAX_CUSTOMER_NAME];
    char address[MAX_CUSTOMER_ADDRESS];
    char phone[MAX_CUSTOMER_PHONE];
    struct medicine medicine[MAX_CUSTOMER_MEDICINE];
};

// Function to add medicine
void add_medicine(struct medicine *medicine, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", medicine->name);
    printf("Enter medicine stock: ");
    scanf("%d", &medicine->stock);
    printf("Medicine added successfully.\n");
    (*count)++;
}

// Function to display medicine
void display_medicine(struct medicine *medicine, int count) {
    printf("Medicine Name\tStock\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", medicine[i].name, medicine[i].stock);
    }
}

// Function to add customer
void add_customer(struct customer *customer, int *count) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer address: ");
    scanf("%s", customer->address);
    printf("Enter customer phone: ");
    scanf("%s", customer->phone);
    printf("Enter number of medicines: ");
    scanf("%d", &customer->medicine[0].stock);
    for (int i = 0; i < customer->medicine[0].stock; i++) {
        add_medicine(&customer->medicine[i], &customer->medicine[0].stock);
    }
    printf("Customer added successfully.\n");
    (*count)++;
}

// Function to display customer
void display_customer(struct customer *customer, int count) {
    printf("Customer Name\tAddress\tPhone\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\n", customer[i].name, customer[i].address, customer[i].phone);
    }
}

// Main function
int main() {
    int count_medicine = 0, count_customer = 0;
    struct medicine medicine[MAX_MEDICINE_STOCK];
    struct customer customer[MAX_CUSTOMER_NAME];

    // Add medicines
    while (1) {
        printf("Do you want to add more medicines? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
        add_medicine(&medicine[count_medicine], &count_medicine);
    }

    // Add customers
    while (1) {
        printf("Do you want to add more customers? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
        add_customer(&customer[count_customer], &count_customer);
    }

    // Display medicines
    printf("\nMedicines:\n");
    display_medicine(medicine, count_medicine);

    // Display customers
    printf("\nCustomers:\n");
    display_customer(customer, count_customer);

    return 0;
}