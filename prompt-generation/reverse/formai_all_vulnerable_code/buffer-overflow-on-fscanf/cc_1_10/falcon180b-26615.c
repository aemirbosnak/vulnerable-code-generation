//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int num_items;
} Category;

void read_items(Item items[]) {
    FILE *fp;
    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error opening items file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d %f\n", items[i].name, &items[i].quantity, &items[i].price)!= EOF) {
        i++;
    }
    fclose(fp);
}

void read_categories(Category categories[]) {
    FILE *fp;
    fp = fopen("categories.txt", "r");
    if (fp == NULL) {
        printf("Error opening categories file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d\n", categories[i].name, &categories[i].num_items)!= EOF) {
        i++;
    }
    fclose(fp);
}

void display_items(Item items[], int num_items) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void display_categories(Category categories[], int num_categories) {
    printf("Category Name\tNumber of Items\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\t%d\n", categories[i].name, categories[i].num_items);
    }
}

int main() {
    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];

    read_items(items);
    read_categories(categories);

    int choice;
    while (1) {
        printf("1. Display Items\n2. Display Categories\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_items(items, MAX_ITEMS);
                break;
            case 2:
                display_categories(categories, MAX_CATEGORIES);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}