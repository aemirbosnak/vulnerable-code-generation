//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_STR_LEN 100

typedef struct {
    char name[MAX_STR_LEN];
    int quantity;
    float price;
} Item;

void readItems(Item items[]) {
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open items.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %f\n", items[count].name, &items[count].quantity, &items[count].price) == 3) {
        count++;
        if (count == MAX_ITEMS) {
            printf("Error: Too many items in items.txt\n");
            exit(1);
        }
    }

    fclose(fp);
}

void displayItems(Item items[]) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0]!= '\0') {
            printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void searchItem(Item items[], char search[]) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, search) == 0) {
            printf("Item found:\n");
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    Item items[MAX_ITEMS];
    readItems(items);
    displayItems(items);

    char search[MAX_STR_LEN];
    printf("Enter item name to search: ");
    scanf("%s", search);
    searchItem(items, search);

    return 0;
}