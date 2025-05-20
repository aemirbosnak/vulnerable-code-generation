//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct item {
    int id;
    char name[50];
    int quantity;
    int location_x, location_y;
};

void add_item(struct item *inventory, int size) {
    int id, quantity;
    char name[50];
    printf("Enter item id: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);
    srand(time(NULL));
    inventory[size].id = id;
    strcpy(inventory[size].name, name);
    inventory[size].quantity = quantity;
    inventory[size].location_x = rand() % 100;
    inventory[size].location_y = rand() % 100;
    printf("Item added successfully!\n\n");
}

void print_inventory(struct item *inventory, int size) {
    printf("Inventory:\n\n");
    printf("%-10s %-20s %-10s %-10s %-10s\n\n", "ID", "Name", "Quantity", "Location X", "Location Y");
    for(int i=0; i<size; i++) {
        printf("%-10d %-20s %-10d %-10d %-10d\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].location_x, inventory[i].location_y);
    }
    printf("\n");
}

int main() {
    struct item inventory[100];
    int size = 0;
    while(1) {
        printf("Menu:\n\n");
        printf("1. Add item\n");
        printf("2. View inventory\n");
        printf("3. Exit\n\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(inventory, size);
                size++;
                break;
            case 2:
                print_inventory(inventory, size);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}