//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct cafeItem {
    char name[50];
    float price;
    int quantity;
};

struct cafeOrder {
    struct cafeItem items[100];
    int numItems;
    float total;
};

void addCafeItem(struct cafeOrder *order, struct cafeItem item);
void printCafeOrder(struct cafeOrder order);
float calculateCafeTotal(struct cafeOrder order);

int main() {
    struct cafeOrder order;
    order.numItems = 0;
    order.total = 0.0;

    // Add some items to the order
    struct cafeItem item1 = {"Coffee", 2.50, 2};
    addCafeItem(&order, item1);
    struct cafeItem item2 = {"Muffin", 1.75, 1};
    addCafeItem(&order, item2);
    struct cafeItem item3 = {"OJ", 1.50, 3};
    addCafeItem(&order, item3);

    // Print the order
    printCafeOrder(order);

    // Calculate the total
    order.total = calculateCafeTotal(order);

    // Print the total
    printf("Total: $%.2f\n", order.total);

    return 0;
}

void addCafeItem(struct cafeOrder *order, struct cafeItem item) {
    order->items[order->numItems] = item;
    order->numItems++;
}

void printCafeOrder(struct cafeOrder order) {
    printf("Cafe Order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s x %d = $%.2f\n", order.items[i].name, order.items[i].quantity, order.items[i].price * order.items[i].quantity);
    }
}

float calculateCafeTotal(struct cafeOrder order) {
    float total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price * order.items[i].quantity;
    }
    return total;
}