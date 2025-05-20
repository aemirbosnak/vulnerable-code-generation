//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_CATEGORY 50
#define MAX_QUANTITY 100
#define MAX_PRICE 100

struct item {
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
};

struct cart {
    int num_items;
    struct item items[MAX_ITEMS];
};

struct cart* create_cart() {
    struct cart* cart = (struct cart*) malloc(sizeof(struct cart));
    cart->num_items = 0;
    return cart;
}

void add_item_to_cart(struct cart* cart, struct item item) {
    if (cart->num_items >= MAX_ITEMS) {
        printf("Cart is full. Can't add more items.\n");
        return;
    }
    cart->items[cart->num_items++] = item;
}

void remove_item_from_cart(struct cart* cart, int index) {
    if (index < 0 || index >= cart->num_items) {
        printf("Invalid index.\n");
        return;
    }
    cart->num_items--;
    for (int i = index; i < cart->num_items; i++) {
        cart->items[i] = cart->items[i+1];
    }
}

void print_cart(struct cart* cart) {
    printf("Cart:\n");
    for (int i = 0; i < cart->num_items; i++) {
        printf("%d. %s - %s - %d units - $%.2f\n", i+1, cart->items[i].name, cart->items[i].category, cart->items[i].quantity, cart->items[i].price);
    }
}

void main() {
    struct cart* cart = create_cart();

    // Add items to cart
    struct item item1 = {"Acetaminophen", "Pain Relief", 20, 5.99};
    struct item item2 = {"Ibuprofen", "Pain Relief", 30, 6.99};
    add_item_to_cart(cart, item1);
    add_item_to_cart(cart, item2);

    // Print cart
    print_cart(cart);

    // Remove item from cart
    remove_item_from_cart(cart, 0);

    // Print cart again
    print_cart(cart);

    // Free memory
    free(cart);
}