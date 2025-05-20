//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50

// Item struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Item;

// Order struct
typedef struct {
    Item item;
    int quantity;
} Order;

// Global array of items
Item items[MAX_ITEMS];

// Global array of orders
Order orders[MAX_ITEMS];
int num_orders = 0;

// Function to display the menu and get user's selection
int display_menu() {
    int option = -1;
    printf("\nMenu:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            break;
        }
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
    printf("%d. Finish Order\n", MAX_ITEMS + 1);
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}

// Function to add an item to the menu
void add_item() {
    char name[MAX_NAME_LENGTH];
    double price;
    printf("\nEnter the name of the item: ");
    scanf("%s", name);
    printf("Enter the price of the item: ");
    scanf("%lf", &price);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].price = price;
            printf("Item added successfully!\n");
            return;
        }
    }
    printf("Sorry, the menu is full and no more items can be added.\n");
}

// Function to remove an item from the menu
void remove_item() {
    char name[MAX_NAME_LENGTH];
    printf("\nEnter the name of the item that you want to remove: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].name[0] = '\0';
            items[i].price = 0;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to get the index of an item in the menu
int get_item_index(char name[MAX_NAME_LENGTH]) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to place an order
void place_order() {
    int option = 0;
    char name[MAX_NAME_LENGTH];
    int quantity;
    do {
        option = display_menu();
        if (option >= 1 && option <= MAX_ITEMS) {
            printf("\nEnter the quantity: ");
            scanf("%d", &quantity);
            int index = get_item_index(items[option-1].name);
            if (index != -1) {
                strcpy(orders[num_orders].item.name, items[index].name);
                orders[num_orders].item.price = items[index].price;
                orders[num_orders].quantity = quantity;
                printf("Order placed successfully!\n");
                num_orders++;
            } else {
                printf("Sorry, the item you selected is not on the menu.\n");
            }
        } else if (option != MAX_ITEMS + 1) {
            printf("Invalid option. Try again.\n");
        }
    } while (option != MAX_ITEMS + 1);
}

// Function to calculate the total bill
double calculate_bill() {
    double total = 0;
    for (int i = 0; i < num_orders; i++) {
        total += orders[i].item.price * orders[i].quantity;
    }
    return total;
}

// Function to display the bill
void display_bill() {
    double total = calculate_bill();
    printf("\n\nBill:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%s x %d - %.2f\n", orders[i].item.name, orders[i].quantity,
               orders[i].item.price * orders[i].quantity);
    }
    printf("\nTotal bill: $%.2f\n", total);
}

// Main function
int main() {
    int option = 0;
    while (option != 4) {
        printf("\nC Cafe Billing System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Place Order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                place_order();
                display_bill();
                num_orders = 0;
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    return 0;
}