//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
} Order;

void displayMenu(Item menu[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void placeOrder(Order order[], int *size) {
    printf("Order placed successfully!\n");
    printf("Order details:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d. %s - %d items - $%.2f\n", i+1, order[i].name, order[i].quantity, order[i].price * order[i].quantity);
    }
}

int main() {
    Item menu[] = {
        {1, "Coffee", 3.50},
        {2, "Tea", 2.50},
        {3, "Cake", 4.50},
        {4, "Sandwich", 5.50},
        {5, "Pasta", 6.50}
    };

    int size = sizeof(menu) / sizeof(menu[0]);

    Order order[10];
    int orderSize = 0;

    while (1) {
        displayMenu(menu, size);

        printf("\nEnter 0 to place an order or any other key to continue browsing:\n");
        scanf("%d", &orderSize);

        if (orderSize == 0) {
            break;
        }

        printf("Enter item name:\n");
        scanf("%s", order[orderSize-1].name);

        printf("Enter item quantity:\n");
        scanf("%d", &order[orderSize-1].quantity);

        for (int i = 0; i < size; i++) {
            if (strcmp(menu[i].name, order[orderSize-1].name) == 0) {
                order[orderSize-1].price = menu[i].price;
                break;
            }
        }

        orderSize++;
    }

    placeOrder(order, &orderSize);

    return 0;
}