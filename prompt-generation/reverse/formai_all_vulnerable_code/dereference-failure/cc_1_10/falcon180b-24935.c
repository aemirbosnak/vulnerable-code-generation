//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_CHARS 100

struct item {
    char name[MAX_CHARS];
    int price;
};

struct cart {
    struct item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct cart* cart, char* name, int price) {
    int i;
    for (i = 0; i < cart->num_items; i++) {
        if (strcmp(cart->items[i].name, name) == 0) {
            cart->items[i].price = price;
            return;
        }
    }
    strcpy(cart->items[cart->num_items].name, name);
    cart->items[cart->num_items].price = price;
    cart->num_items++;
}

void remove_item(struct cart* cart, int index) {
    if (index >= cart->num_items) {
        printf("Invalid index\n");
        return;
    }
    cart->num_items--;
    while (index < cart->num_items) {
        cart->items[index] = cart->items[index+1];
        index++;
    }
}

void display_cart(struct cart* cart) {
    printf("Cart:\n");
    for (int i = 0; i < cart->num_items; i++) {
        printf("%s - $%d\n", cart->items[i].name, cart->items[i].price);
    }
}

int main() {
    struct cart cart;
    cart.num_items = 0;
    char choice;
    while (1) {
        printf("Cafe Billing System\n");
        printf("1. Add item\n2. Remove item\n3. Display cart\n4. Checkout\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter item name: ");
                char name[MAX_CHARS];
                scanf("%s", name);
                printf("Enter item price: ");
                int price;
                scanf("%d", &price);
                add_item(&cart, name, price);
                break;
            case '2':
                printf("Enter item index to remove: ");
                int index;
                scanf("%d", &index);
                remove_item(&cart, index);
                break;
            case '3':
                display_cart(&cart);
                break;
            case '4':
                printf("Total amount: $%d\n", 0);
                printf("Thank you for your purchase!\n");
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}