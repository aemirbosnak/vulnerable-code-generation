//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];

void add_item(char *name, float price, int quantity) {
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

void display_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s: %.2f, %d\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}

void calculate_total(int *total) {
    *total = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            *total += items[i].price * items[i].quantity;
        }
    }
}

void generate_bill() {
    int total = 0;
    calculate_total(&total);

    printf("Bill:\n");
    display_items();
    printf("Total: %.2f\n", total);
    printf("Payment: ");
    float payment = 0;
    scanf("%f", &payment);

    if (payment < total) {
        printf("Insufficient funds.\n");
    } else {
        printf("Change: %.2f\n", payment - total);
    }
}

int main() {
    add_item("Coffee", 2.50, 5);
    add_item("Tea", 3.00, 2);
    add_item("Juice", 4.00, 3);

    generate_bill();

    return 0;
}