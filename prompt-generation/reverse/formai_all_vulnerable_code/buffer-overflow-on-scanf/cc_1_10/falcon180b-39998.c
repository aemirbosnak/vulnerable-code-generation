//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    char address[100];
    int phone;
} customer;

typedef struct {
    char name[50];
    char description[100];
    int quantity;
    float price;
} item;

int numItems = 0;
item items[MAX_ITEMS];

int numCustomers = 0;
customer customers[MAX_CUSTOMERS];

void addItem() {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item description: ");
    scanf("%s", items[numItems].description);

    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);

    numItems++;
}

void displayItems() {
    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %s - %d - %.2f\n", i + 1, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void addCustomer() {
    printf("Enter customer name: ");
    scanf("%s", customers[numCustomers].name);

    printf("Enter customer address: ");
    scanf("%s", customers[numCustomers].address);

    printf("Enter customer phone: ");
    scanf("%d", &customers[numCustomers].phone);

    numCustomers++;
}

void displayCustomers() {
    printf("\nCustomers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s - %s - %d\n", i + 1, customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Add customer\n");
        printf("4. Display customers\n");
        printf("5. Exit\n");
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