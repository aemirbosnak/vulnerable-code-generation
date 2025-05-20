//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void add_item(char name[], int quantity, float price) {
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

void print_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int calculate_total(int items_count) {
    float total = 0.0f;
    for (int i = 0; i < items_count; i++) {
        total += items[i].quantity * items[i].price;
    }

    return (int) total;
}

void generate_bill(int total) {
    printf("Bill:\n");
    print_items();
    printf("\nTotal: $%d\n", total);
    printf("Payment: $");
    float payment = 0.0f;
    scanf("%f", &payment);
    printf("Change: $%.2f\n", payment - (float) total);
}

int main() {
    add_item("Coffee", 5, 2.50);
    add_item("Tea", 3, 1.25);
    add_item("Juice", 2, 1.50);

    int total = calculate_total(3);
    generate_bill(total);

    return 0;
}