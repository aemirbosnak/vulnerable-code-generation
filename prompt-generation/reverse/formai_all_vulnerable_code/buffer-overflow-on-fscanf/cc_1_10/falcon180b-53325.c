//Falcon-180B DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    double price;
} item;

void read_items(item* items) {
    FILE* fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open items file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %lf\n", items[count].name, &items[count].quantity, &items[count].price) == 3 && count < MAX_ITEMS) {
        count++;
    }

    fclose(fp);
}

void calculate_total_price(item* items, int num_items) {
    double total_price = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_price += items[i].quantity * items[i].price;
    }

    printf("Total price: $%.2lf\n", total_price);
}

int main() {
    item items[MAX_ITEMS];

    read_items(items);

    int num_items = 0;
    while (strcmp(items[num_items].name, "")!= 0) {
        num_items++;
    }

    calculate_total_price(items, num_items);

    return 0;
}