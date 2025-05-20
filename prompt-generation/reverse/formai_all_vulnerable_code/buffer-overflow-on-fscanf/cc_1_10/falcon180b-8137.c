//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 100

struct item {
    char name[50];
    int price;
    int quantity;
};

struct customer {
    char name[50];
    int customer_id;
};

struct order {
    int order_id;
    int customer_id;
    struct item items[10];
    int num_items;
};

int main() {
    FILE *fp;
    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening items file.\n");
        exit(1);
    }

    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (fscanf(fp, "%s %d %d", items[num_items].name, &items[num_items].price, &items[num_items].quantity)!= EOF) {
        num_items++;
    }

    fclose(fp);

    printf("Available items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%d (%d in stock)\n", items[i].name, items[i].price, items[i].quantity);
    }

    return 0;
}