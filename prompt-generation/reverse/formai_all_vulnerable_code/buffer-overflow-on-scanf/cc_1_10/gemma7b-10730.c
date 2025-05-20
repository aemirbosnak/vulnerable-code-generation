//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void initializeItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }
}

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
    printf("-----------------------\n");
    printf("C Cafe Billing System\n");
    printf("-----------------------\n");

    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }

    printf("\nTotal: %.2f\n", calculateTotal());

    printf("\nPayment: ");
    float payment = 0.0f;
    scanf("%f", &payment);

    float change = payment - calculateTotal();

    printf("\nChange: %.2f\n", change);

    printf("Thank you for your visit!\n");
}

int main() {
    initializeItems();

    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 2.00);
    addItem("Juice", 2, 1.50);

    generateBill();

    return 0;
}