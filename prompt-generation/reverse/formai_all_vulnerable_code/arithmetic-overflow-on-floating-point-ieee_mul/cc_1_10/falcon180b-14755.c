//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
    float total_cost;
} item;

void add_item(item *items, int *num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", (*num_items >= MAX_ITEMS? "" : items[*num_items].name));
    printf("Enter the price of the item ($): ");
    scanf("%s", (*num_items >= MAX_ITEMS? "" : items[*num_items].price));
    printf("Enter the quantity: ");
    scanf("%d", &items[*num_items].quantity);
    items[*num_items].total_cost = items[*num_items].quantity * atof(items[*num_items].price);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("Name\tPrice\tQuantity\tTotal Cost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2f\t%d\t$%.2f\n", items[i].name, atof(items[i].price), items[i].quantity, items[i].total_cost);
    }
}

void save_items(item *items, int num_items, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        exit(1);
    }
    fwrite(&num_items, sizeof(int), 1, fp);
    for (int i = 0; i < num_items; i++) {
        fwrite(items[i].name, MAX_NAME_LENGTH, 1, fp);
        fwrite(items[i].price, MAX_PRICE_LENGTH, 1, fp);
        fwrite(&items[i].quantity, sizeof(int), 1, fp);
        fwrite(&items[i].total_cost, sizeof(float), 1, fp);
    }
    fclose(fp);
}

void load_items(item *items, int *num_items, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        exit(1);
    }
    fread(&(*num_items), sizeof(int), 1, fp);
    for (int i = 0; i < *num_items; i++) {
        fread(items[i].name, MAX_NAME_LENGTH, 1, fp);
        fread(items[i].price, MAX_PRICE_LENGTH, 1, fp);
        fread(&items[i].quantity, sizeof(int), 1, fp);
        fread(&items[i].total_cost, sizeof(float), 1, fp);
    }
    fclose(fp);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    display_items(items, num_items);

    char filename[50];
    printf("Enter the name of the file to save to: ");
    scanf("%s", filename);
    save_items(items, num_items, filename);

    printf("Loading saved file...\n");
    load_items(items, &num_items, filename);
    display_items(items, num_items);

    return 0;
}