//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_BARCODE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int barcode;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int barcode, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Database is full.\n");
        return;
    }
    strcpy(items[num_items].name, name);
    items[num_items].barcode = barcode;
    items[num_items].price = price;
    num_items++;
}

void scan_barcode(int barcode) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].barcode == barcode) {
            printf("Scanned item: %s\n", items[i].name);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }
    printf("Item not found with barcode: %d\n", barcode);
}

int main() {
    char name[MAX_NAME_LEN];

    add_item("Apple", 12345, 0.5);
    add_item("Banana", 23456, 0.3);
    add_item("Orange", 34567, 0.7);

    while (1) {
        printf("Scan barcode or type 'exit' to quit: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        int barcode;
        sscanf(name, "%*s %d", &barcode);
        scan_barcode(barcode);
    }

    return 0;
}