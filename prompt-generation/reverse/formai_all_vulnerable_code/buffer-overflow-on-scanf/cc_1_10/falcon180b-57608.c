//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    char description[100];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    char address[100];
    int phone;
};

void addItem(struct item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[*numItems].name);
    printf("Enter item description: ");
    scanf("%s", &items[*numItems].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    (*numItems)++;
}

void displayItems(struct item items[], int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %s (%d in stock) - $%.2f\n", i+1, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void addCustomer(struct customer customers[], int *numCustomers) {
    printf("\nEnter customer name: ");
    scanf("%s", &customers[*numCustomers].name);
    printf("Enter customer address: ");
    scanf("%s", &customers[*numCustomers].address);
    printf("Enter customer phone number: ");
    scanf("%d", &customers[*numCustomers].phone);
    (*numCustomers)++;
}

void displayCustomers(struct customer customers[], int numCustomers) {
    printf("\nCustomer List:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s - %s - %d\n", i+1, customers[i].name, customers[i].address, customers[i].phone);
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int numItems = 0;
    struct customer customers[MAX_ITEMS];
    int numCustomers = 0;

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
                addItem(items, &numItems);
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                addCustomer(customers, &numCustomers);
                break;
            case 4:
                displayCustomers(customers, numCustomers);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}