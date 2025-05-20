//Falcon-180B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_ATTRIBUTES 10
#define MAX_ATTRIBUTE_VALUE_LENGTH 100

typedef struct {
    char attributeName[MAX_ATTRIBUTE_VALUE_LENGTH];
    int attributeValue;
} AttributeValuePair;

typedef struct {
    AttributeValuePair attributes[MAX_ATTRIBUTES];
    int itemId;
} Item;

void readItems(Item *items, int numItems, FILE *fp) {
    for (int i = 0; i < numItems; i++) {
        fscanf(fp, "Item %d\n", &items[i].itemId);
        int numAttributes = 0;
        fscanf(fp, "Number of attributes: %d\n", &numAttributes);
        for (int j = 0; j < numAttributes; j++) {
            fscanf(fp, "Attribute %s: %d\n", items[i].attributes[j].attributeName, &items[i].attributes[j].attributeValue);
        }
    }
}

void printItems(Item *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", items[i].itemId);
        for (int j = 0; j < items[i].attributes[j].attributeValue; j++) {
            printf("Attribute %s: %d\n", items[i].attributes[j].attributeName, items[i].attributes[j].attributeValue);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems;

    FILE *fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open items.txt\n");
        return 1;
    }

    fscanf(fp, "Number of items: %d\n", &numItems);
    if (numItems > MAX_ITEMS) {
        printf("Error: too many items\n");
        return 1;
    }

    readItems(items, numItems, fp);

    fclose(fp);

    printItems(items, numItems);

    return 0;
}