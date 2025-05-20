//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 100

typedef struct item {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct customer {
    char name[50];
    int customerID;
} Customer;

Item items[MAX_ITEMS];
Customer customers[MAX_CUSTOMERS];

int numItems = 0;
int numCustomers = 0;

void addItem() {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    numItems++;
}

void viewItems() {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

void addCustomer() {
    printf("\nEnter customer name: ");
    scanf("%s", customers[numCustomers].name);
    printf("Enter customer ID: ");
    scanf("%d", &customers[numCustomers].customerID);
    numCustomers++;
}

void viewCustomers() {
    printf("\nCustomer List:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s - Customer ID: %d\n", i+1, customers[i].name, customers[i].customerID);
    }
}

void purchaseItem(int customerID) {
    printf("\nEnter item number to purchase: ");
    int itemNum;
    scanf("%d", &itemNum);

    if (itemNum >= 1 && itemNum <= numItems) {
        Item* chosenItem = &items[itemNum-1];
        if (chosenItem->quantity > 0) {
            printf("\nYou have purchased %s for $%.2f.\n", chosenItem->name, chosenItem->price);
            chosenItem->quantity--;
        } else {
            printf("\nSorry, %s is out of stock.\n", chosenItem->name);
        }
    } else {
        printf("\nInvalid item number.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\n===== Welcome to the Medical Store Management System =====\n");
        printf("\n1. Add Item\n2. View Items\n3. Add Customer\n4. View Customers\n5. Purchase Item\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                viewCustomers();
                break;
            case 5:
                printf("\nEnter customer ID: ");
                int customerID;
                scanf("%d", &customerID);
                purchaseItem(customerID);
                break;
            case 6:
                printf("\nThank you for using our system! Have a great day!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}