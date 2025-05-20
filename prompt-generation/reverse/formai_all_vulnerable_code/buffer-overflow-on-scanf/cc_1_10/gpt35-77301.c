//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    char category[20];
    int quantity;
    float price;
} Item;

int numItems = 0;

Item* addItem(Item items[], Item item);
Item* removeItem(Item items[], char name[]);
void displayInventory(Item items[], int numItems);
void searchByCategory(Item items[], char category[], int numItems);
void searchByName(Item items[], char name[], int numItems);

int main()
{
    Item inventory[MAX_ITEMS];
    int choice;
    char name[30], category[20];

    printf("Welcome to the Product Inventory System!\n");
    printf("========================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Search by category\n");
        printf("5. Search by name\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    Item item;
                    printf("\nEnter item name: ");
                    scanf("%s", item.name);
                    printf("Enter item category: ");
                    scanf("%s", item.category);
                    printf("Enter item quantity: ");
                    scanf("%d", &item.quantity);
                    printf("Enter item price: ");
                    scanf("%f", &item.price);

                    Item* updatedItems = addItem(inventory, item);
                    if (updatedItems != NULL) {
                        memcpy(inventory, updatedItems, MAX_ITEMS * sizeof(Item));
                        numItems++;
                    }
                    break;
                }
            case 2:
                {
                    printf("\nEnter item name to remove: ");
                    scanf("%s", name);

                    Item* updatedItems = removeItem(inventory, name);
                    if (updatedItems != NULL) {
                        memcpy(inventory, updatedItems, MAX_ITEMS * sizeof(Item));
                        numItems--;
                    }
                    break;
                }
            case 3:
                displayInventory(inventory, numItems);
                break;
            case 4:
                printf("\nEnter category to search: ");
                scanf("%s", category);
                searchByCategory(inventory, category, numItems);
                break;
            case 5:
                printf("\nEnter name to search: ");
                scanf("%s", name);
                searchByName(inventory, name, numItems);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

Item* addItem(Item items[], Item item) {
    if (numItems == MAX_ITEMS) {
        printf("\nInventory is full!\n");
        return NULL;
    }

    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, item.name) == 0) {
            printf("\nItem with name %s already exists in inventory!\n", item.name);
            return NULL;
        }
    }

    items[numItems] = item;
    printf("\nItem %s added successfully!\n", item.name);
    return items;
}

Item* removeItem(Item items[], char name[]) {
    int i, found = 0;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nItem with name %s not found in inventory!\n", name);
        return NULL;
    }

    for (i = i; i < numItems - 1; i++) {
        items[i] = items[i+1];
    }

    printf("\nItem %s removed successfully!\n", name);
    return items;
}

void displayInventory(Item items[], int numItems) {
    if (numItems == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nInventory:\n");
    printf("|%-30s|%-20s|%-10s|%-10s|\n", "Name", "Category", "Quantity", "Price");
    printf("|------------------------------|--------------------|----------|----------|\n");
    int i;
    for (i = 0; i < numItems; i++) {
        printf("|%-30s|%-20s|%10d|%10.2f|\n", items[i].name, items[i].category, items[i].quantity, items[i].price);
    }
}

void searchByCategory(Item items[], char category[], int numItems) {
    if (numItems == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nResults:\n");
    printf("|%-30s|%-20s|%-10s|%-10s|\n", "Name", "Category", "Quantity", "Price");
    printf("|------------------------------|--------------------|----------|----------|\n");
    int i, found = 0;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].category, category) == 0) {
            printf("|%-30s|%-20s|%10d|%10.2f|\n", items[i].name, items[i].category, items[i].quantity, items[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo items found in category %s!\n", category);
    }
}

void searchByName(Item items[], char name[], int numItems) {
    if (numItems == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\nResults:\n");
    printf("|%-30s|%-20s|%-10s|%-10s|\n", "Name", "Category", "Quantity", "Price");
    printf("|------------------------------|--------------------|----------|----------|\n");
    int i, found = 0;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("|%-30s|%-20s|%10d|%10.2f|\n", items[i].name, items[i].category, items[i].quantity, items[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("\nItem with name %s not found in inventory!\n", name);
    }
}