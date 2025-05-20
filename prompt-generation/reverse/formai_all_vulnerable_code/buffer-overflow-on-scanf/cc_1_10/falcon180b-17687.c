//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    float price;
    int quantity;
};

void read_items(struct item items[]) {
    int i = 0;
    printf("Enter the number of items: ");
    scanf("%d", &i);

    for (int j = 0; j < i; j++) {
        printf("Enter the name of item %d: ", j+1);
        scanf("%s", items[j].name);
        printf("Enter the price of item %d: ", j+1);
        scanf("%f", &items[j].price);
        printf("Enter the quantity of item %d: ", j+1);
        scanf("%d", &items[j].quantity);
    }
}

void display_items(struct item items[]) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}

void calculate_total(struct item items[]) {
    float total = 0.0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            total += items[i].price * items[i].quantity;
        }
    }
    printf("Total amount: %.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    read_items(items);
    display_items(items);
    calculate_total(items);

    return 0;
}