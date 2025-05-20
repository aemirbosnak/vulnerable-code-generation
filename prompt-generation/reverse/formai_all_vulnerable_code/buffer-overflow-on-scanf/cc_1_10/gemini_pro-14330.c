//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Order {
    int id;
    char customerName[50];
    char date[50];
    struct Item items[100];
    int numItems;
    float total;
};

void printMenu() {
    printf("Cafe Billing System\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. Create Order\n");
    printf("5. Update Order\n");
    printf("6. Delete Order\n");
    printf("7. Print Order\n");
    printf("8. Exit\n");
}

void addItem() {
    int id, quantity;
    char name[50];
    float price;
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    // Add the item to the menu
}

void updateItem() {
    int id;
    float price;
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter new item price: ");
    scanf("%f", &price);
    // Update the item in the menu
}

void deleteItem() {
    int id;
    printf("Enter item ID: ");
    scanf("%d", &id);
    // Delete the item from the menu
}

void createOrder() {
    int id, numItems;
    char customerName[50], date[50];
    printf("Enter order ID: ");
    scanf("%d", &id);
    printf("Enter customer name: ");
    scanf("%s", customerName);
    printf("Enter date: ");
    scanf("%s", date);
    printf("Enter number of items: ");
    scanf("%d", &numItems);
    // Create the order
}

void updateOrder() {
    int id;
    printf("Enter order ID: ");
    scanf("%d", &id);
    // Update the order
}

void deleteOrder() {
    int id;
    printf("Enter order ID: ");
    scanf("%d", &id);
    // Delete the order
}

void printOrder() {
    int id;
    printf("Enter order ID: ");
    scanf("%d", &id);
    // Print the order
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                createOrder();
                break;
            case 5:
                updateOrder();
                break;
            case 6:
                deleteOrder();
                break;
            case 7:
                printOrder();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);
    return 0;
}