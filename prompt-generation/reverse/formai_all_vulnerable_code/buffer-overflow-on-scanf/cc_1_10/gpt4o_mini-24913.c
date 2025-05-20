//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Cart;

void addItemToCart(Cart *cart);
void displayCart(Cart cart);
void calculateTotal(Cart cart);
void generateReceipt(Cart cart);

int main() {
    Cart cart;
    cart.itemCount = 0;
    int choice;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add Item to Cart\n");
        printf("2. Display Cart\n");
        printf("3. Calculate Total\n");
        printf("4. Generate Receipt\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItemToCart(&cart);
                break;
            case 2:
                displayCart(cart);
                break;
            case 3:
                calculateTotal(cart);
                break;
            case 4:
                generateReceipt(cart);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addItemToCart(Cart *cart) {
    if (cart->itemCount >= MAX_ITEMS) {
        printf("Cart is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    cart->items[cart->itemCount] = newItem;
    cart->itemCount++;
    printf("Item added to cart!\n");
}

void displayCart(Cart cart) {
    if (cart.itemCount == 0) {
        printf("Your cart is empty.\n");
        return;
    }

    printf("\nItems in Cart:\n");
    for (int i = 0; i < cart.itemCount; i++) {
        printf("%d. %s | Price: %.2f | Quantity: %d\n", i + 1,
               cart.items[i].name, cart.items[i].price, cart.items[i].quantity);
    }
}

void calculateTotal(Cart cart) {
    float total = 0.0;
    for (int i = 0; i < cart.itemCount; i++) {
        total += cart.items[i].price * cart.items[i].quantity;
    }
    printf("Total Amount: %.2f\n", total);
}

void generateReceipt(Cart cart) {
    if (cart.itemCount == 0) {
        printf("Your cart is empty. No receipt can be generated.\n");
        return;
    }

    printf("\nReceipt:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Price", "Quantity");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < cart.itemCount; i++) {
        printf("%-20s %-10.2f %-10d\n", cart.items[i].name,
               cart.items[i].price, cart.items[i].quantity);
    }
    calculateTotal(cart);
    printf("--------------------------------------------------\n");
    printf("Thank you for your visit!\n");
}