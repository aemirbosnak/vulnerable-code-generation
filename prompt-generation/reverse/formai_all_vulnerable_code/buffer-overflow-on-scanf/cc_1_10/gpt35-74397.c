//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Warehouse structure to store inventory data
typedef struct Warehouse {
    char name[20];
    int id;
    int quantity;
} Warehouse;

// Function to add new item to inventory
void addItem(Warehouse* inventory, int* count) {
    int id, quantity;
    char name[20];
    printf("\nEnter item name: ");
    scanf("%s", name);
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    inventory[*count].id = id;
    inventory[*count].quantity = quantity;
    strcpy(inventory[*count].name, name);

    (*count)++;
    printf("\nItem added successfully!\n");
}

// Function to display all items in inventory
void displayInventory(Warehouse* inventory, int count) {
    printf("\n==============================================\n");
    printf("| Item ID |    Item Name    |   Quantity   |\n");
    printf("==============================================\n");

    for(int i=0; i<count; i++) {
        printf("| %7d | %-15s | %11d |\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }

    printf("==============================================\n");
}

int main() {
    int option, count = 0;
    Warehouse inventory[100];

    // Welcome message
    printf("\nWelcome to our Warehouse Management System\n");

    do {
        // Menu
        printf("\n1. Add new item\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        // Perform action based on option
        switch(option) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                printf("\nThank you for using our system!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while(option != 3);

    return 0;
}