//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_SUPPLIERS 20
#define MAX_CUSTOMERS 50

typedef struct medicine {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct supplier {
    char name[50];
    char contact[20];
} Supplier;

typedef struct customer {
    char name[50];
    char address[100];
} Customer;

Medicine medicines[MAX_MEDICINES];
Supplier suppliers[MAX_SUPPLIERS];
Customer customers[MAX_CUSTOMERS];
int num_medicines = 0, num_suppliers = 0, num_customers = 0;

void add_medicine() {
    if (num_medicines == MAX_MEDICINES) {
        printf("Medicine inventory is full.\n");
        return;
    }
    printf("Enter medicine name: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter stock: ");
    scanf("%d", &medicines[num_medicines].stock);
    printf("Enter price: ");
    scanf("%f", &medicines[num_medicines].price);
    num_medicines++;
}

void add_supplier() {
    if (num_suppliers == MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }
    printf("Enter supplier name: ");
    scanf("%s", suppliers[num_suppliers].name);
    printf("Enter contact number: ");
    scanf("%s", suppliers[num_suppliers].contact);
    num_suppliers++;
}

void add_customer() {
    if (num_customers == MAX_CUSTOMERS) {
        printf("Customer list is full.\n");
        return;
    }
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter address: ");
    scanf("%s", customers[num_customers].address);
    num_customers++;
}

void display_medicines() {
    int i;
    printf("\nCurrent medicine inventory:\n");
    for (i = 0; i < num_medicines; i++) {
        printf("%d. %s - Stock: %d, Price: %.2f\n", i+1, medicines[i].name, medicines[i].stock, medicines[i].price);
    }
}

void main_menu() {
    int choice;
    while (1) {
        printf("\n---- C Medical Store Management System ----\n");
        printf("1. Add Medicine\n2. Add Supplier\n3. Add Customer\n4. Display Medicines\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_medicine(); break;
            case 2: add_supplier(); break;
            case 3: add_customer(); break;
            case 4: display_medicines(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    main_menu();
    return 0;
}