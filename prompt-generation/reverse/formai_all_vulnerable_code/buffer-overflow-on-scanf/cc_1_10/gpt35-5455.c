//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum capacity of the warehouse
#define MAX_CAPACITY 1000

// Structure to store information of an item in the warehouse
typedef struct {
    char id[10];
    char name[50];
    double price;
} Item;

// Function to search for an item in the warehouse by its ID
int searchItemById(Item items[], int itemCount, char *id) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    // Declare variables
    Item items[MAX_CAPACITY];
    int itemCount = 0;
    char choice;
    char id[10];
    int index;
    
    // Loop to display menu and get input from user
    while (1) {
        // Display menu options
        printf("Enter choice:\n");
        printf("1. Add item\n");
        printf("2. Search item\n");
        printf("3. Remove item\n");
        printf("4. Display all items\n");
        printf("5. Exit\n");
        scanf(" %c", &choice);
        
        // Perform action based on user input
        switch (choice) {
            case '1': // Add item
                // Check if warehouse is full
                if (itemCount >= MAX_CAPACITY) {
                    printf("Warehouse is full!\n");
                    break;
                }
                // Get item information from user
                printf("Enter item ID (max 10 char): ");
                scanf("%s", items[itemCount].id);
                printf("Enter item name (max 50 char): ");
                scanf(" %[^\n]", items[itemCount].name);
                printf("Enter item price: ");
                scanf("%lf", &items[itemCount].price);
                // Increment item count
                itemCount++;
                printf("Item added successfully!\n");
                break;
            case '2': // Search item
                // Get item ID from user
                printf("Enter item ID to search: ");
                scanf("%s", id);
                // Search for item in warehouse
                index = searchItemById(items, itemCount, id);
                if (index == -1) {
                    printf("Item not found!\n");
                } else {
                    // Display item information
                    printf("ID: %s\n", items[index].id);
                    printf("Name: %s\n", items[index].name);
                    printf("Price: %.2lf\n", items[index].price);
                }
                break;
            case '3': // Remove item
                // Get item ID from user
                printf("Enter item ID to remove: ");
                scanf("%s", id);
                // Search for item in warehouse
                index = searchItemById(items, itemCount, id);
                if (index == -1) {
                    printf("Item not found!\n");
                } else {
                    // Remove item by shifting all items after it one position to the left
                    for (int i = index; i < itemCount-1; i++) {
                        strcpy(items[i].id, items[i+1].id);
                        strcpy(items[i].name, items[i+1].name);
                        items[i].price = items[i+1].price;
                    }
                    // Decrement item count
                    itemCount--;
                    printf("Item removed successfully!\n");
                }
                break;
            case '4': // Display all items
                // Check if warehouse is empty
                if (itemCount == 0) {
                    printf("Warehouse is empty!\n");
                    break;
                }
                // Display information of all items in the warehouse
                for (int i = 0; i < itemCount; i++) {
                    printf("ID: %s\n", items[i].id);
                    printf("Name: %s\n", items[i].name);
                    printf("Price: %.2lf\n", items[i].price);
                    printf("\n");
                }
                break;
            case '5': // Exit program
                printf("Thank you for using the warehouse management system!\n");
                exit(0);
            default: // Invalid input
                printf("Invalid input! Please try again.\n");
        }
    }
    return 0;
}