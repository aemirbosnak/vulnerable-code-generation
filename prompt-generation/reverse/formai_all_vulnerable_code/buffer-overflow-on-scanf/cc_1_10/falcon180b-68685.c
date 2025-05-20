//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    char address[100];
    int phone;
} Customer;

Item items[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];

void addItem() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            printf("Enter item name: ");
            scanf("%s", items[i].name);
            printf("Enter item quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter item price: ");
            scanf("%f", &items[i].price);
            break;
        }
    }
}

void displayItems() {
    int i;
    printf("\nItem List:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%-20s %10d $%8.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void addCustomer() {
    int i;
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].name[0] == '\0') {
            printf("Enter customer name: ");
            scanf("%s", customers[i].name);
            printf("Enter customer address: ");
            scanf("%s", customers[i].address);
            printf("Enter customer phone number: ");
            scanf("%d", &customers[i].phone);
            break;
        }
    }
}

void displayCustomers() {
    int i;
    printf("\nCustomer List:\n");
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].name[0]!= '\0') {
            printf("%-20s %s %10d\n", customers[i].name, customers[i].address, customers[i].phone);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n2. Display items\n3. Add customer\n4. Display customers\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                displayCustomers();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}