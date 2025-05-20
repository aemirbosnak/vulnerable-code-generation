//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Warehouse {
    char name[50];
    int capacity;
    int current_stock;
} Warehouse;

int menu() {
    int choice;
    printf("\nWelcome to Warehouse Management System\n\n");
    printf("1. Add a new warehouse\n");
    printf("2. View all warehouses\n");
    printf("3. Update warehouse stock\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_warehouse(Warehouse *warehouses, int *num_warehouses) {
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[*num_warehouses].name);
    printf("Enter warehouse capacity: ");
    scanf("%d", &warehouses[*num_warehouses].capacity);
    warehouses[*num_warehouses].current_stock = 0;
    (*num_warehouses)++;
}

void view_warehouses(Warehouse *warehouses, int num_warehouses) {
    printf("\nWarehouse Name\tCapacity\tCurrent Stock\n");
    for (int i = 0; i < num_warehouses; i++) {
        printf("%s\t\t%d\t\t%d\n", warehouses[i].name, warehouses[i].capacity, warehouses[i].current_stock);
    }
}

void update_stock(Warehouse *warehouses, int num_warehouses) {
    char name[50];
    int stock;
    printf("Enter warehouse name: ");
    scanf("%s", name);
    for (int i = 0; i < num_warehouses; i++) {
        if (strcmp(name, warehouses[i].name) == 0) {
            printf("Enter new stock: ");
            scanf("%d", &stock);
            if (stock > warehouses[i].capacity) {
                printf("Error: stock exceeds warehouse capacity\n");
            } else {
                warehouses[i].current_stock = stock;
                printf("Stock updated successfully\n");
            }
            return;
        }
    }
    printf("Warehouse not found\n");
}

int main() {
    Warehouse warehouses[10];
    int num_warehouses = 0;
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_warehouse(warehouses, &num_warehouses);
                break;
            case 2:
                view_warehouses(warehouses, num_warehouses);
                break;
            case 3:
                update_stock(warehouses, num_warehouses);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return 0;
}