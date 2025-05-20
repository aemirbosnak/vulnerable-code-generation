//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEMS];

void manage_warehouse() {
    int i;
    system("clear");

    // Print inventory
    printf("Inventory:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s: %d units, $%.2lf per unit\n", items[i].name, items[i].quantity, items[i].price);
        }
    }

    // Add item
    printf("\nEnter item name: ");
    scanf("%s", items[MAX_ITEMS - 1].name);
    printf("Enter quantity: ");
    scanf("%d", &items[MAX_ITEMS - 1].quantity);
    printf("Enter price per unit: ");
    scanf("%lf", &items[MAX_ITEMS - 1].price);

    // Save changes
    FILE *fp = fopen("warehouse.txt", "w");
    fprintf(fp, "%d", MAX_ITEMS);
    for (i = 0; i < MAX_ITEMS; i++) {
        fprintf(fp, "\n%s\n%d\n%.2lf", items[i].name, items[i].quantity, items[i].price);
    }
    fclose(fp);

    // Display confirmation
    printf("\nItem added successfully!\n");
}

int main() {
    manage_warehouse();

    return 0;
}