//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int quantity;
    double price;
    int category;
} Item;

typedef struct {
    char name[20];
    int count;
} Category;

void read_items(Item items[], int *num_items) {
    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items file.\n");
        exit(1);
    }

    *num_items = 0;
    while (fscanf(fp, "%s %d %lf %d", items[*num_items].name, &items[*num_items].quantity, &items[*num_items].price, &items[*num_items].category)!= EOF) {
        (*num_items)++;
    }

    fclose(fp);
}

void read_categories(Category categories[], int num_categories) {
    FILE *fp = fopen("categories.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open categories file.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < num_categories; i++) {
        fscanf(fp, "%s", categories[i].name);
    }

    fclose(fp);
}

void calculate_totals(Item items[], Category categories[], int num_items, int num_categories) {
    int i, j;
    double total_sales = 0.0;

    for (i = 0; i < num_items; i++) {
        for (j = 0; j < num_categories; j++) {
            if (items[i].category == categories[j].count) {
                total_sales += items[i].price * items[i].quantity;
                break;
            }
        }
    }

    printf("Total sales: $%.2lf\n", total_sales);
}

int main() {
    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];
    int num_items = 0, num_categories = 0;

    read_items(items, &num_items);
    read_categories(categories, num_categories);

    calculate_totals(items, categories, num_items, num_categories);

    return 0;
}