//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 20

struct MenuItem {
    char name[50];
    float price;
    int quantity;
};

struct Order {
    int tableNumber;
    int itemCount;
    struct MenuItem items[MAX_ITEMS];
    float total;
};

void printMenu() {
    printf("---------------------------------------\n");
    printf("|               MENU                  |\n");
    printf("---------------------------------------\n");
    printf("| Item Name                |   Price  |\n");
    printf("---------------------------------------\n");
    printf("| 1. Cafe Latte            |  $4.50   |\n");
    printf("| 2. Cappuccino            |  $3.50   |\n");
    printf("| 3. Espresso              |  $2.00   |\n");
    printf("| 4. Americano             |  $2.50   |\n");
    printf("| 5. Mocha                 |  $4.00   |\n");
    printf("| 6. Hot Chocolate         |  $3.00   |\n");
    printf("---------------------------------------\n");
}

void printOrder(struct Order order) {
    printf("---------------------------------------\n");
    printf("Table Number: %d\n", order.tableNumber);
    printf("---------------------------------------\n");
    printf("| Quantity |    Item Name    |   Price  |\n");
    printf("---------------------------------------\n");
    for(int i = 0; i < order.itemCount; i++) {
        printf("|    %2d    | %-15s|  $%-5.2f |\n", order.items[i].quantity, order.items[i].name, order.items[i].price);
    }
    printf("---------------------------------------\n");
    printf("|                      Total: $%-5.2f |\n", order.total);
    printf("---------------------------------------\n");
}

int main(void) {
    struct MenuItem menu[] = {
        {"Cafe Latte", 4.50},
        {"Cappuccino", 3.50},
        {"Espresso", 2.00},
        {"Americano", 2.50},
        {"Mocha", 4.00},
        {"Hot Chocolate", 3.00}
    };

    int tableNumber;
    printf("Please enter table number: ");
    scanf("%d", &tableNumber);

    printMenu();

    struct Order currentOrder;
    currentOrder.tableNumber = tableNumber;
    currentOrder.itemCount = 0;
    currentOrder.total = 0;

    int choice = 0;
    while(choice != 9) {
        printf("Enter item number (1-6) or 9 to finish order: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 6) {
            printf("Invalid choice. Please enter a number between 1 and 6 or 9 to finish order.\n");
            continue;
        }
        struct MenuItem item = menu[choice - 1];
        printf("Enter quantity: ");
        scanf("%d", &item.quantity);
        currentOrder.items[currentOrder.itemCount++] = item;

        float itemTotal = item.quantity * item.price;
        currentOrder.total += itemTotal;

        printf("%dx %s added to order. Total cost: $%.2f\n", item.quantity, item.name, itemTotal);
    }

    printOrder(currentOrder);

    return 0;
}