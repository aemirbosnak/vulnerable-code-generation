//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Post-Apocalyptic Warehouse Management System!\n");
    
    // Create a struct to represent a warehouse
    struct Warehouse {
        char name[50];
        int capacity;
        int items[10];
    };
    
    // Create a warehouse and initialize it
    struct Warehouse warehouse = { "Post-Apocalyptic Warehouse", 100, {0} };
    
    // Print the warehouse's name and capacity
    printf("Warehouse Name: %s\n", warehouse.name);
    printf("Warehouse Capacity: %d\n", warehouse.capacity);
    
    // Add items to the warehouse
    int item_count = 0;
    while (item_count < 10) {
        printf("Enter item name (%d/%d): ", item_count + 1, 10);
        char item_name[50];
        scanf("%s", item_name);
        int quantity = 0;
        while (quantity < 100) {
            printf("Enter quantity (%d/%d): ", quantity + 1, 100);
            int quantity_input;
            scanf("%d", &quantity_input);
            warehouse.items[item_count] += quantity_input;
            quantity += quantity_input;
        }
        item_count++;
    }
    
    // Print the items in the warehouse
    printf("Items in Warehouse:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", warehouse.items[i], warehouse.items[i]);
    }
    
    // Print the total quantity of each item in the warehouse
    printf("\nTotal Quantity of Each Item:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", warehouse.items[i], warehouse.items[i]);
    }
    
    // Print the warehouse's name and capacity again
    printf("Warehouse Name: %s\n", warehouse.name);
    printf("Warehouse Capacity: %d\n", warehouse.capacity);
    
    // Free memory for the warehouse
    free(warehouse.items);
    
    // End of program
    printf("End of Program\n");
    return 0;
}