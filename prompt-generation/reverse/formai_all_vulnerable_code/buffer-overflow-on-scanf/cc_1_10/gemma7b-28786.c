//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void addItem(char name[], int quantity, float price) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item limit exceeded.\n");
}

void printItems() {
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d, %.2f\n", items[i].name, items[i].quantity, items[i].price);
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
    printf("Total: $%.2f\n", calculateTotal());
    printf("Payment: $");
    float payment = 0;
    scanf("%f", &payment);
    float change = payment - calculateTotal();
    printf("Change: $%.2f\n", change);
}

int main() {
    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 1.75);
    addItem("Juice", 2, 2.00);

    generateBill();

    return 0;
}