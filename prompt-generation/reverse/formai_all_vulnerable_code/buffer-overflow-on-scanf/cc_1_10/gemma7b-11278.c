//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void addItem(char name, int quantity, float price) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item limit reached.\n");
}

void printItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int calculateTotal(int quantity, float price) {
    return quantity * price;
}

void generateBill() {
    int totalItems = 0;
    float totalCost = 0.0f;

    printf("Items:\n");
    printItems();

    printf("\nTotal Items: %d\n", totalItems);
    printf("Total Cost: $%.2f\n", totalCost);

    printf("Payment: $");
    float payment = 0.0f;
    scanf("%f", &payment);

    float change = payment - totalCost;

    printf("Change: $%.2f\n", change);

    system("pause");
}

int main() {
    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 1.25);
    addItem("Juice", 2, 1.50);

    generateBill();

    return 0;
}