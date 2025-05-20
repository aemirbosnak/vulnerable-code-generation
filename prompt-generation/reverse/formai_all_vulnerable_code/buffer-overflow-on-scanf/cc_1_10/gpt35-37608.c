//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct item {
    char name[20];
    int quantity;
    float price;
} Item;

int items_count = 0;
Item items[MAX_ITEMS];

void add_item(char name[], int quantity, float price) {
    if (items_count >= MAX_ITEMS) {
        printf("Maximum number of items exceeded!\n");
        return;
    }

    Item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;

    items[items_count++] = new_item;

    printf("Item added successfully!\n");
}

void display_items() {
    printf("SL. No.\tName\tQuantity\tPrice\n");

    for (int i = 0; i < items_count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

float calculate_total() {
    float total = 0;

    for (int i = 0; i < items_count; i++) {
        total += (items[i].quantity * items[i].price);
    }

    return total;
}

void bill() {
    printf("Enter item name: ");
    char name[20];
    scanf("%s", name);

    for (int i = 0; i < items_count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter quantity: ");
            int quantity;
            scanf("%d", &quantity);

            if (quantity > items[i].quantity) {
                printf("Insufficient stock!\n");
                return;
            }

            float price = quantity * items[i].price;
            printf("Total price: %.2f\n", price);

            items[i].quantity -= quantity;

            return;
        }
    }

    printf("Item not found!\n");
}

int main() {
    int option = 0;

    while (option != 4) {
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Generate a bill\n");
        printf("4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Enter item name, quantity, and price: ");
                char name[20];
                int quantity;
                float price;
                scanf("%s %d %f", name, &quantity, &price);

                add_item(name, quantity, price);
                break;
            }
            case 2: {
                display_items();
                break;
            }
            case 3: {
                bill();
                break;
            }
            case 4: {
                break;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }

        printf("\n");
    }

    printf("Total revenue generated: %.2f\n", calculate_total());

    return 0;
}