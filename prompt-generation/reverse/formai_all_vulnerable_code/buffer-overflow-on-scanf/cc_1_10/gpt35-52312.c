//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

// Item structure
typedef struct {
    char name[20];
    int quantity;
    double price;
} Item;

// Function to add an item to the menu
void addItem(Item *menu, int *numItems) {
    // Check if there is space left in the menu
    if (*numItems == MAX_ITEMS) {
        printf("Error: Menu full\n");
        return;
    }
    
    Item item;
    
    printf("Enter name of the item: ");
    scanf("%s", item.name);
    printf("Enter quantity of the item: ");
    scanf("%d", &item.quantity);
    printf("Enter price of the item: ");
    scanf("%lf", &item.price);
    
    // Add the item to the end of the array
    menu[*numItems] = item;
    
    printf("Item successfully added to the menu\n");
    (*numItems)++;
}

// Function to print the menu
void printMenu(Item *menu, int numItems) {
    printf("Menu\n");
    printf("----\n");
    
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%.2lf\n", menu[i].name, menu[i].quantity, menu[i].price);
    }
}

// Function to search for an item in the menu
int searchItem(Item *menu, int numItems, char *name) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Function to place an order
void placeOrder(Item *menu, int numItems) {
    char name[20];
    int quantity;
    int index;
    double total = 0;
    
    printf("Enter the name of the item: ");
    scanf("%s", name);
    
    index = searchItem(menu, numItems, name);
    
    if (index == -1) {
        printf("Error: Item not found\n");
        return;
    }
    
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    
    if (quantity > menu[index].quantity) {
        printf("Error: Quantity not available\n");
        return;
    }
    
    // Update the quantity of the item in the menu
    menu[index].quantity -= quantity;
    
    // Calculate the total price of the order
    total = quantity * menu[index].price;
    
    printf("Order placed successfully\n");
    printf("Total: %.2lf\n", total);
}

int main() {
    Item menu[MAX_ITEMS];
    int numItems = 0;
    int choice = 0;
    
    printf("Welcome to the Cafe Billing System\n");
    
    while (1) {
        printf("\nMain Menu\n");
        printf("---------\n");
        printf("1. Add item to menu\n");
        printf("2. Print menu\n");
        printf("3. Place order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(menu, &numItems);
                break;
            case 2:
                printMenu(menu, numItems);
                break;
            case 3:
                placeOrder(menu, numItems);
                break;
            case 4:
                printf("Thank you for using Cafe Billing System\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}