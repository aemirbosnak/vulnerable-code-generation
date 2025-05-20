//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char category[50];
    int quantity;
} product;

int compare_quantity(const void *a, const void *b) {
    product *p1 = (product*)a;
    product *p2 = (product*)b;
    if (p1->quantity < p2->quantity) {
        return -1;
    }
    else if (p1->quantity > p2->quantity) {
        return 1;
    }
    return 0;
}

int main() {
    product items[10];
    int n = 0;

    printf("Enter the category and quantity of items: ");
    while (1) {
        char category[50];
        int quantity;
        fgets(category, sizeof(category), stdin);
        sscanf(category, "%s %d", items[n].category, &items[n].quantity);
        if (items[n].quantity <= 0) {
            printf("Invalid input, please enter a positive number.\n");
        }
        else {
            n++;
        }
        if (n >= 10) {
            break;
        }
    }

    qsort(items, n, sizeof(product), compare_quantity);

    printf("Category\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", items[i].category, items[i].quantity);
    }

    return 0;
}