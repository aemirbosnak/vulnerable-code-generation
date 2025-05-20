//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void addItem(char *name, int quantity, double price) {
    int i = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item limit exceeded!\n");
}

void showItems() {
    int i = 0;
    printf("Items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d, $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

double calculateTotal() {
    int i = 0;
    double total = 0.0;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            total += items[i].quantity * items[i].price;
        }
    }

    return total;
}

void generateBill() {
    printf("Bill:\n");
    showItems();
    printf("Total: $%.2lf\n", calculateTotal());
    printf("Payment: $");
    double payment = 0.0;
    scanf("%lf", &payment);
    double change = payment - calculateTotal();
    printf("Change: $%.2lf\n", change);
}

int main() {
    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 1.75);
    addItem("Juice", 2, 2.00);

    generateBill();

    return 0;
}