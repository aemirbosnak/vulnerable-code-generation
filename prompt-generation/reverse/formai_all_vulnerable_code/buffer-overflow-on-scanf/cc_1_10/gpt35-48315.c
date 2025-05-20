//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

struct Item {
    char name[MAX_NAME_LENGTH];
    int id;
    int quantity;
    float weight;
};

int n_items = 0;
struct Item items[MAX_ITEMS];

void addItem() {
    if(n_items >= MAX_ITEMS) {
        printf("No more space in the warehouse!\n");
        return;
    }
    struct Item item;
    printf("Enter the name of the item: ");
    scanf("%s", item.name);
    printf("Enter the id of the item: ");
    scanf("%d", &item.id);
    printf("Enter the quantity of the item: ");
    scanf("%d", &item.quantity);
    printf("Enter the weight of the item: ");
    scanf("%f", &item.weight);
    items[n_items++] = item;
    printf("Item added successfully!\n");
}

void removeItem() {
    int id;
    printf("Enter the id of the item to remove: ");
    scanf("%d", &id);
    int index = -1;
    for(int i = 0; i < n_items; i++) {
        if(items[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Item with id %d not found!\n", id);
    }
    else {
        for(int i = index; i < n_items - 1; i++) {
            items[i] = items[i+1];
        }
        n_items--;
        printf("Item with id %d removed successfully!\n", id);
    }
}

void displayItems() {
    if(n_items == 0) {
        printf("No items in the warehouse right now.\n");
        return;
    }
    printf("The items in the warehouse are:\n");
    printf("Name\tId\tQuantity\tWeight\n");
    for(int i = 0; i < n_items; i++) {
        printf("%s\t%d\t%d\t%.2f\n", items[i].name, items[i].id, items[i].quantity, items[i].weight);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nWarehouse management system\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}