//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEM 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int qty;
    float price;
} Item;

Item items[MAX_ITEM];
int item_count = 0;

void add_item(char *name, int qty, float price) {
    if (item_count >= MAX_ITEM) {
        printf("Item table is full!\n");
        return;
    }
    strcpy(items[item_count].name, name);
    items[item_count].qty = qty;
    items[item_count].price = price;
    item_count++;
}

void print_bill() {
    float total = 0;
    printf("\n=====================\n");
    printf("| C AFE BILLING SYSTEM |\n");
    printf("=====================\n");
    printf("\nITEM\tNAME\tQUANTITY\tPRICE\tTOTAL\n");
    for (int i = 0; i < item_count; i++) {
        float temp = items[i].qty * items[i].price;
        total += temp;
        printf("%d\t%s\t%d\t%.2f\t%.2f\n", i+1, items[i].name, items[i].qty, items[i].price, temp);
    }
    printf("\n=====================\n");
    printf("| TOTAL:\t\t%.2f\n", total);
    printf("=====================\n");
}

int main(int argc, char *argv[]) {
    char line[100];
    char name[MAX_NAME];
    int qty;
    float price;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        sscanf(line, "%s%d%f", name, &qty, &price);
        if (strlen(name) > 0) {
            add_item(name, qty, price);
        }
    }

    print_bill();

    return 0;
}

/* Sample input
Items:
Coffee 3 2.50
Tea 1 1.50
Soda 5 1.00
Burger 2 5.99
Chips 4 1.25
*/