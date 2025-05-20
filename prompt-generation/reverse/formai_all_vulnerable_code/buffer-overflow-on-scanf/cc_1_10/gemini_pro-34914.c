//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Structure to store menu items
typedef struct menuitem {
    int sno;
    char name[50];
    float price;
} menuitem;

// Structure to store order items
typedef struct orderitem {
    int sno;
    char name[50];
    float quantity;
    float price;
} orderitem;

// Function to display the menu
void display_menu(menuitem menu[], int size) {
    printf("===================== CAFE BILLING SYSTEM =====================\n");
    printf("\n\t\t\tMENU\n");
    printf("================================================================\n");
    printf("S.No.\tName\t\t\tPrice\n");
    printf("-----  -------------------------  ------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-25s  %.2f\n", menu[i].sno, menu[i].name, menu[i].price);
    }
    printf("================================================================\n");
}

// Function to take order
void take_order(orderitem order[], int *size) {
    int sno, quantity;
    float price;
    char name[50];

    printf("\nEnter the item S.No.: ");
    scanf("%d", &sno);

    printf("\nEnter the item name: ");
    scanf("%s", name);

    printf("\nEnter the quantity: ");
    scanf("%d", &quantity);

    printf("\nEnter the price: ");
    scanf("%f", &price);

    // Add the item to the order
    order[*size].sno = sno;
    strcpy(order[*size].name, name);
    order[*size].quantity = quantity;
    order[*size].price = price;

    (*size)++;
}

// Function to display the order
void display_order(orderitem order[], int size) {
    printf("\n\t\t\tORDER\n");
    printf("================================================================\n");
    printf("S.No.\tName\t\t\tQuantity\tPrice\n");
    printf("-----  -------------------------  --------  ------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-25s  %.2f\t  %.2f\n", order[i].sno, order[i].name, order[i].quantity, order[i].price);
    }
    printf("================================================================\n");
}

// Function to calculate the bill
float calculate_bill(orderitem order[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += order[i].quantity * order[i].price;
    }
    return total;
}

// Main function
int main() {
    // Define the menu
    menuitem menu[] = {
        {1, "Espresso", 3.50},
        {2, "Americano", 4.00},
        {3, "Cappuccino", 4.50},
        {4, "Latte", 5.00},
        {5, "Mocha", 5.50},
        {6, "Hot Chocolate", 5.00},
        {7, "Tea", 3.00},
        {8, "Pastry", 3.50},
        {9, "Muffin", 4.00},
        {10, "Cookie", 2.50}
    };
    int menu_size = sizeof(menu) / sizeof(menuitem);

    // Define the order
    orderitem order[100];
    int order_size = 0;

    int choice;
    do {
        printf("\n1. Display Menu\n2. Take Order\n3. Display Order\n4. Calculate Bill\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_menu(menu, menu_size);
                break;
            case 2:
                take_order(order, &order_size);
                break;
            case 3:
                display_order(order, order_size);
                break;
            case 4:
                printf("\nTotal bill: %.2f\n", calculate_bill(order, order_size));
                break;
            case 5:
                printf("\nThank you for visiting our cafe!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}