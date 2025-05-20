//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <string.h>

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

    printf("Error: Item limit reached.\n");
}

void showItems() {
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
    float totalAmount = 0.0f;

    printf("Items:\n");
    showItems();

    printf("\nTotal items: %d", totalItems);
    printf("\nTotal amount: $%.2f", totalAmount);

    printf("\nPayment:\n");
    float payment = 0.0f;
    printf("Enter payment: $");
    scanf("%f", &payment);

    if (payment < totalAmount) {
        printf("Insufficient funds.\n");
    } else {
        printf("Change: $%.2f\n", payment - totalAmount);
    }
}

int main() {
    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 1.20);
    addItem("Juice", 2, 1.80);

    generateBill();

    return 0;
}