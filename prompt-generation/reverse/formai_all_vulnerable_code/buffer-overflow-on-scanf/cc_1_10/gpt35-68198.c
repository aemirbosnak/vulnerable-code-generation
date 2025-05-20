//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>

// Define maximum number of warehouses
#define MAX_WAREHOUSES 10

// Define Warehouse structure
typedef struct {
    char name[30];
    int products_count;
} Warehouse;

// Define global variable for storing all warehouses
Warehouse warehouses[MAX_WAREHOUSES];

int main() {
    int warehouses_count = 0;

    printf("Welcome to the Warehouse Management System!\n");

    // Add a new warehouse
    printf("Enter the name of the new warehouse: ");
    scanf("%29s", warehouses[warehouses_count].name);
    printf("Enter the number of products in the new warehouse: ");
    scanf("%d", &warehouses[warehouses_count].products_count);
    warehouses_count++;

    // Display all warehouses
    printf("All Warehouses:\n");
    for (int i = 0; i < warehouses_count; i++) {
        printf("Warehouse #%d:\n", i + 1);
        printf("Name: %s\n", warehouses[i].name);
        printf("Number of products: %d\n", warehouses[i].products_count);
    }

    // Update a warehouse
    printf("Enter the number of the warehouse you want to update: ");
    int update_index;
    scanf("%d", &update_index);
    update_index--;
    printf("Enter the new number of products in warehouse %d: ", update_index + 1);
    scanf("%d", &warehouses[update_index].products_count);

    // Display updated warehouse
    printf("Warehouse #%d has been updated.\n", update_index + 1);
    printf("Name: %s\n", warehouses[update_index].name);
    printf("Number of products: %d\n", warehouses[update_index].products_count);

    // Delete a warehouse
    printf("Enter the number of the warehouse you want to delete: ");
    int delete_index;
    scanf("%d", &delete_index);
    delete_index--;
    for (int i = delete_index; i < warehouses_count - 1; i++) {
        warehouses[i] = warehouses[i + 1];
    }
    warehouses_count--;

    // Display all warehouses
    printf("All Warehouses:\n");
    for (int i = 0; i < warehouses_count; i++) {
        printf("Warehouse #%d:\n", i + 1);
        printf("Name: %s\n", warehouses[i].name);
        printf("Number of products: %d\n", warehouses[i].products_count);
    }

    printf("Thank you for using the Warehouse Management System.\n");

    return 0;
}