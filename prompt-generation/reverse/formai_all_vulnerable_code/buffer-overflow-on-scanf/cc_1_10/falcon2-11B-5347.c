//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    int item_id = 0;
    char name[50];
    float price;
    int quantity;

    srand(time(NULL));

    while (1) {
        printf("Enter item details (or -1 to quit):\n");
        printf("Item ID: ");
        scanf("%d", &item_id);

        if (item_id == -1)
            break;

        printf("Item name: ");
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Item price: ");
        scanf("%f", &price);

        printf("Item quantity: ");
        scanf("%d", &quantity);

        items[num_items] = (struct item){name, price, quantity};
        num_items++;
    }

    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s (%0.2f) x %d\n", i + 1, items[i].name, items[i].price, items[i].quantity);
    }

    return 0;
}