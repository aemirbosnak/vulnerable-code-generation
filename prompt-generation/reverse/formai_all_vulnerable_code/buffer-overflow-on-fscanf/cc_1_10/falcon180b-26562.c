//Falcon-180B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_SUPPLIERS 10

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int num_items;
    float total_price;
} Supplier;

void read_items(Item* items, int* num_items) {
    FILE* fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items.txt\n");
        exit(1);
    }

    *num_items = 0;
    while (fscanf(fp, "%s %d %f\n", items[*num_items].name, &items[*num_items].quantity, &items[*num_items].price)!= EOF) {
        (*num_items)++;
    }

    fclose(fp);
}

void read_suppliers(Supplier* suppliers, int* num_suppliers) {
    FILE* fp = fopen("suppliers.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open suppliers.txt\n");
        exit(1);
    }

    *num_suppliers = 0;
    while (fscanf(fp, "%s %d %f\n", suppliers[*num_suppliers].name, &suppliers[*num_suppliers].num_items, &suppliers[*num_suppliers].total_price)!= EOF) {
        (*num_suppliers)++;
    }

    fclose(fp);
}

void calculate_profit(Item* items, Supplier* suppliers, int num_items, int num_suppliers, float* total_profit) {
    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < num_suppliers; j++) {
            if (strcmp(items[i].name, suppliers[j].name) == 0) {
                suppliers[j].total_price += items[i].price * items[i].quantity;
                break;
            }
        }
    }

    *total_profit = 0;
    for (int i = 0; i < num_suppliers; i++) {
        *total_profit += suppliers[i].total_price;
    }
}

int main() {
    Item items[MAX_ITEMS];
    Supplier suppliers[MAX_SUPPLIERS];
    int num_items, num_suppliers;

    read_items(items, &num_items);
    read_suppliers(suppliers, &num_suppliers);

    float total_profit;
    calculate_profit(items, suppliers, num_items, num_suppliers, &total_profit);

    printf("Total profit: $%.2f\n", total_profit);

    return 0;
}