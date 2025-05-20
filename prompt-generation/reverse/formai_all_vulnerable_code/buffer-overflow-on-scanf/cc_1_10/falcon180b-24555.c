//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
    float discount;
} DiscountedItem;

void addItem(Item* order, char* name, int quantity, float price) {
    strcpy(order->name, name);
    order->quantity = quantity;
    order->price = price;
}

void addDiscountedItem(DiscountedItem* order, char* name, int quantity, float price, float discount) {
    strcpy(order->name, name);
    order->quantity = quantity;
    order->price = price;
    order->discount = discount;
}

float calculateTotal(Item* order) {
    return order->quantity * order->price;
}

float calculateTotalDiscounted(DiscountedItem* order) {
    float total = order->quantity * order->price;
    if (order->discount > 0) {
        total -= total * order->discount;
    }
    return total;
}

int main() {
    int choice;
    do {
        printf("C Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Add discounted item\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Item order;
            char name[50];
            int quantity;
            float price;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);

            addItem(&order, name, quantity, price);
            printf("Item added successfully!\n");
            break;
        }
        case 2: {
            DiscountedItem order;
            char name[50];
            int quantity;
            float price;
            float discount;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            printf("Enter discount: ");
            scanf("%f", &discount);

            addDiscountedItem(&order, name, quantity, price, discount);
            printf("Discounted item added successfully!\n");
            break;
        }
        case 3: {
            char name[50];
            printf("Enter item name: ");
            scanf("%s", name);

            Item* order = malloc(sizeof(Item));
            strcpy(order->name, name);
            order->quantity = 1;
            order->price = 0;

            float total = calculateTotal(order);
            printf("Total: $%.2f\n", total);
            break;
        }
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}