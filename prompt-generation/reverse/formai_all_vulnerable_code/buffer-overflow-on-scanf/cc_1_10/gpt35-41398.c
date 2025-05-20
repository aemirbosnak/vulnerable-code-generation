//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

void displayWarehouse(Item *items, int count);
void addItem(Item *items, int *count);
void sellItem(Item *items, int count);
float calculateRevenue(Item *items, int count);

int main() {
    Item items[100];
    int count = 0;

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Display warehouse inventory\n");
        printf("2. Add item to inventory\n");
        printf("3. Sell item from inventory\n");
        printf("4. Show total revenue\n");
        printf("5. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayWarehouse(items, count);
                break;
            case 2:
                addItem(items, &count);
                break;
            case 3:
                sellItem(items, count);
                break;
            case 4:
                printf("Total revenue: $%.2f\n", calculateRevenue(items, count));
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayWarehouse(Item *items, int count) {
    printf("Name\tQuantity\tPrice\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-16d$%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("\n");
}

void addItem(Item *items, int *count) {
    printf("Enter name of item to add:\n");
    scanf("%s", items[*count].name);
    printf("Enter quantity to add:\n");
    scanf("%d", &items[*count].quantity);
    printf("Enter price per item:\n");
    scanf("%f", &items[*count].price);
    (*count)++;
    printf("\n");
}

void sellItem(Item *items, int count) {
    printf("Enter name of item to sell:\n");
    char itemName[20];
    scanf("%s", itemName);

    for (int i = 0; i < count; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            int quantity;
            printf("Enter quantity to sell:\n");
            scanf("%d", &quantity);

            if (quantity > items[i].quantity) {
                printf("Error: insufficient quantity in inventory.\n\n");
                return;
            }

            items[i].quantity -= quantity;
            printf("Sold %d %s for $%.2f each.\n\n", quantity, items[i].name, items[i].price);
            return;
        }
    }

    printf("Error: item not found in inventory.\n\n");
}

float calculateRevenue(Item *items, int count) {
    float revenue = 0;
    for (int i = 0; i < count; i++) {
        revenue += items[i].quantity * items[i].price;
    }
    return revenue;
}