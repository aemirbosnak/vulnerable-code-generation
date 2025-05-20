//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 20
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void display_menu() {
    printf("\nAvailable Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f\n", i + 1, items[i].name, items[i].price);
    }
}

void order_item() {
    if (num_items == 0) {
        printf("No items available to order.\n");
        return;
    }

    printf("Enter item number to order: ");
    int item_num;
    scanf("%d", &item_num);

    if (item_num < 1 || item_num > num_items) {
        printf("Invalid item number.\n");
        return;
    }

    printf("Enter quantity: ");
    int quantity;
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Invalid quantity.\n");
        return;
    }

    items[item_num - 1].quantity += quantity;
}

void display_bill() {
    printf("\nYour Bill:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %.2f x %d = %.2f\n", items[i].name, items[i].price, items[i].quantity, items[i].price * items[i].quantity);
    }

    printf("\nTotal: %.2f\n", 0.0f); // Uncomment this line to display the total bill
}

int main() {
    int choice;

    do {
        system("clear");
        display_menu();
        printf("\n1. Add Item\n2. Order Item\n3. Display Bill\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item(); break;
            case 2: order_item(); break;
            case 3: display_bill(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}