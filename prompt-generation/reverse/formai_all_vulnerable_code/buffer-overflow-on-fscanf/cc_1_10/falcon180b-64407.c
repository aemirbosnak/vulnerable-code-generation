//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITEMS 1000

struct item {
    int id;
    float price;
    int quantity;
};

void read_items(struct item items[]) {
    FILE *fp = fopen("items.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%d %f %d\n", &items[count].id, &items[count].price, &items[count].quantity)!= EOF) {
        count++;

        if (count >= MAX_ITEMS) {
            printf("Maximum number of items reached.\n");
            fclose(fp);
            exit(1);
        }
    }

    fclose(fp);
}

void calculate_total_price(struct item items[], int n) {
    float total_price = 0.0;

    for (int i = 0; i < n; i++) {
        total_price += items[i].price * items[i].quantity;
    }

    printf("Total price: $%.2f\n", total_price);
}

int main() {
    struct item items[MAX_ITEMS];

    read_items(items);

    int n = 0;
    while (items[n].id!= -1) {
        n++;
    }

    calculate_total_price(items, n);

    return 0;
}