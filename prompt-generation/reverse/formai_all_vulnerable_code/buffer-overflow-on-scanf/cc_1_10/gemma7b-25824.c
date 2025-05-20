//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
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

void displayItems() {
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
    printf("-------------------------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("-------------------------------------------------------------------\n");

    displayItems();

    int total = calculateTotal();
    printf("Total: %.2f\n", total);

    printf("Payment: ");
    float payment = 0;
    scanf("%f", &payment);

    float change = payment - total;
    printf("Change: %.2f\n", change);

    printf("Thank you for your visit to C Cafe!\n");
}

int main() {
    addItem("Coffee", 5.0, 3);
    addItem("Tea", 3.0, 2);
    addItem("Juice", 2.0, 4);

    generateBill();

    return 0;
}