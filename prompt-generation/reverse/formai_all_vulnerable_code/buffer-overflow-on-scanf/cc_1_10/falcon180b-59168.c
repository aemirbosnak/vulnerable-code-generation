//Falcon-180B DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_ATTRIBUTES 10

typedef struct {
    char *name;
    int num_attributes;
    double *attributes;
} Item;

typedef struct {
    char *name;
    int num_items;
    Item *items;
} Attribute;

void print_item(Item *item) {
    printf("Item: %s\n", item->name);
    for (int i = 0; i < item->num_attributes; i++) {
        printf("Attribute %d: %.2f\n", i+1, item->attributes[i]);
    }
}

void print_attribute(Attribute *attribute) {
    printf("Attribute: %s\n", attribute->name);
    for (int i = 0; i < attribute->num_items; i++) {
        print_item(attribute->items + i);
    }
}

void read_items(Item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter number of attributes for item %s: ", items[i].name);
        scanf("%d", &items[i].num_attributes);
        items[i].attributes = (double *) malloc(items[i].num_attributes * sizeof(double));
        for (int j = 0; j < items[i].num_attributes; j++) {
            printf("Enter attribute %d for item %s: ", j+1, items[i].name);
            scanf("%lf", &items[i].attributes[j]);
        }
    }
}

void read_attributes(Attribute *attributes, int num_attributes) {
    for (int i = 0; i < num_attributes; i++) {
        printf("Enter name of attribute %d: ", i+1);
        scanf("%s", attributes[i].name);
        attributes[i].num_items = 0;
        attributes[i].items = (Item *) malloc(MAX_ITEMS * sizeof(Item));
    }
}

void add_item_to_attribute(Attribute *attribute, Item *item) {
    attribute->items[attribute->num_items++] = *item;
}

void mine_data(Item *items, Attribute *attributes, int num_items, int num_attributes) {
    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < num_attributes; j++) {
            if (strcmp(items[i].name, attributes[j].items[0].name) == 0) {
                add_item_to_attribute(attributes + j, items + i);
                break;
            }
        }
    }
}

int main() {
    int num_items, num_attributes;
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter number of attributes: ");
    scanf("%d", &num_attributes);

    Item items[MAX_ITEMS];
    Attribute attributes[MAX_ATTRIBUTES];

    read_items(items, num_items);
    read_attributes(attributes, num_attributes);

    mine_data(items, attributes, num_items, num_attributes);

    for (int i = 0; i < num_attributes; i++) {
        print_attribute(attributes + i);
    }

    return 0;
}