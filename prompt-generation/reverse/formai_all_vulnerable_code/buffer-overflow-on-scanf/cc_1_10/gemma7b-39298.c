//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];

void addItem(char name, float price, int quantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].price = price;
            items[i].quantity = quantity;
            return;
        }
    }

    printf("Error: Item limit reached.\n");
}

void printItems() {
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}

int calculateTotal() {
    int total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            total += items[i].quantity * items[i].price;
        }
    }

    return total;
}

void generateBill() {
    printf("Bill:\n");
    printItems();
    printf("Total: %.2f\n", calculateTotal());
    printf("Payment: ");
    float payment = 0;
    scanf("%f", &payment);
    printf("Change: %.2f\n", payment - calculateTotal());
}

int main() {
    addItem("Coffee", 5.0, 3);
    addItem("Tea", 3.0, 2);
    addItem("Juice", 4.0, 1);

    generateBill();

    return 0;
}