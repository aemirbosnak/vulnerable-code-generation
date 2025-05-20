//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM];

void addItem(char name, int quantity, float price) {
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item limit exceeded.\n");
}

void displayItems() {
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int calculateTotal(int quantity, float price) {
    return quantity * price;
}

void generateBill(char customerName, int total) {
    printf("Bill for %s:\n", customerName);
    printf("----------------------------------------\n");
    printf("Item\tQuantity\tPrice\tTotal\n");
    printf("----------------------------------------\n");
    displayItems();
    printf("Total: %d\n", total);
    printf("Payment: ");
    float payment = 0.0f;
    scanf("%f", &payment);
    printf("Change: %.2f\n", payment - total);
}

int main() {
    addItem("Coffee", 5, 2.50);
    addItem("Tea", 3, 2.00);
    addItem("Juice", 2, 1.50);

    generateBill("John Doe", calculateTotal(2, 2.50) + calculateTotal(1, 2.00) + calculateTotal(1, 1.50));

    return 0;
}