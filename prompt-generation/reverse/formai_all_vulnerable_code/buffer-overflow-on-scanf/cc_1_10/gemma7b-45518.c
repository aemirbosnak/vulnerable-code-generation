//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[50];
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
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculateTotal(int item_num, float total) {
    for (int i = 0; i < item_num; i++) {
        total += items[i].quantity * items[i].price;
    }

    printf("Total: %.2f\n", total);
}

int main() {
    addItem("Coffee", 5, 2.5);
    addItem("Tea", 3, 2.0);
    addItem("Juice", 2, 3.0);

    displayItems();

    float total = 0.0f;
    calculateTotal(3, total);

    printf("Payment: $");
    float payment = 0.0f;
    scanf("%f", &payment);

    float change = payment - total;

    printf("Change: $%.2f\n", change);

    return 0;
}