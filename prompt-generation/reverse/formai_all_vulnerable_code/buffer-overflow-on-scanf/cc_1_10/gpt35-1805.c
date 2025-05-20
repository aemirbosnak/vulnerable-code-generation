//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10

// Structure to store the details of an item
struct Item {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

// Function to display the menu options
void printMenu() {
    printf("\n*** C Cafe Billing System ***\n");
    printf("1. Add Item\n");
    printf("2. Update Item Quantity\n");
    printf("3. Generate Bill\n");
    printf("4. Exit\n");
    printf("Enter your choice (1/2/3/4): ");
}

// Function to add an item to the list
void addItem(struct Item items[], int* itemCount) {
    if (*itemCount == MAX_ITEMS) {
        printf("List is full. Cannot add any more items.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter name of item: ");
    scanf("%s", name);

    float price;
    printf("Enter price of item: ");
    scanf("%f", &price);

    int quantity;
    printf("Enter quantity of item: ");
    scanf("%d", &quantity);

    struct Item newItem;
    strcpy(newItem.name, name);
    newItem.price = price;
    newItem.quantity = quantity;
    items[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully!\n");
}

// Function to update the quantity of an existing item
void updateItemQuantity(struct Item items[], int itemCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of item to update quantity: ");
    scanf("%s", name);

    int quantity;
    printf("Enter new quantity of item: ");
    scanf("%d", &quantity);

    int foundItem = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = quantity;
            foundItem = 1;
            printf("Quantity updated successfully!\n");
            break;
        }
    }

    if (!foundItem) {
        printf("Item not found!\n");
    }
}

// Function to generate the bill from the items list
void generateBill(struct Item items[], int itemCount) {
    float total = 0;

    printf("\n\n");
    printf("*************** C Cafe ***************\n");
    printf("Item Name\t\tPrice\t\tQuantity\tTotal\n");
    printf("*****************************************************\n");

    for (int i = 0; i < itemCount; i++) {
        float itemTotal = items[i].price * items[i].quantity;
        printf("%-22s%-16.2f%-16d%-16.2f\n", items[i].name, items[i].price, items[i].quantity, itemTotal);
        total += itemTotal;
    }

    printf("*****************************************************\n");
    printf("\t\t\t\tTotal: %.2f\n", total);
}

int main() {
    // Initialize the items list
    struct Item items[MAX_ITEMS];
    int itemCount = 0;

    // Display the menu and get the user's choice
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add item
                addItem(items, &itemCount);
                break;

            case 2: // Update item quantity
                updateItemQuantity(items, itemCount);
                break;

            case 3: // Generate bill
                generateBill(items, itemCount);
                break;

            case 4: // Exit
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 4);

    printf("Thank you for using C Cafe Billing System!\n");
    return 0;
}