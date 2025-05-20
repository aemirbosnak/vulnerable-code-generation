//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    char warehouse[20] = "ABC Warehouse";
    int item_no = 1;
    char item_name[20];
    int quantity = 0;
    int i, j, k;

    // Create a loop to manage items
    for (i = 0; i < 10; i++) {
        // Get item name and quantity
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Store item information
        item_no++;
        printf("Item No: %d\n", item_no);
        printf("Item Name: %s\n", item_name);
        printf("Quantity: %d\n", quantity);
        printf("\n");
    }

    // Print warehouse information
    printf("Warehouse: %s\n", warehouse);

    // Print item list
    printf("Item List:\n");
    for (j = 0; j < item_no; j++) {
        printf("Item No: %d\n", item_no);
        printf("Item Name: %s\n", item_name);
        printf("Quantity: %d\n", quantity);
        printf("\n");
    }

    // Calculate total quantity
    int total_quantity = 0;
    for (k = 0; k < item_no; k++) {
        total_quantity += quantity;
    }

    // Print total quantity
    printf("Total Quantity: %d\n", total_quantity);

    return 0;
}