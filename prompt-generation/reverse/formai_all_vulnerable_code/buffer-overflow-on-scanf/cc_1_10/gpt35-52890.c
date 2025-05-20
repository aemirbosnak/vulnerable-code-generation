//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
/*
* Welcome to the Neon Warehouse Management System!
* 
* This program allows warehouse supervisors to manage inventory and track shipments in a Cyberpunk-esque world of neon and technology.
*
* Written by: [Your Name]
* Date: [Current Date]
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 10000

// Define the maximum length of item names
#define MAX_NAME_LENGTH 50

// Define a struct to represent items in the warehouse
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float weight;
    float value;
} Item;

// Define a struct to represent shipments
typedef struct Shipment {
    char destination[MAX_NAME_LENGTH];
    Item items[MAX_ITEMS];
} Shipment;

// Define the contents of the warehouse
Item warehouse[MAX_ITEMS];

// Define the number of items currently in the warehouse
int numItems = 0;

// Define the function prototypes
void addItem();
void removeItem();
void printInventory();
void printShipment(Shipment shipment);
void receiveShipment();
void sendShipment();
bool itemExists(char* name);
int getItemIndex(char* name);

// Define the main function
int main() {

    // Print a welcome message to the user
    printf("Welcome to the Neon Warehouse Management System!\n\n");

    // Define a variable to store the user's choice
    int choice = -1;

    // Keep looping until the user chooses to exit
    while (choice != 0) {

        // Print a menu of options
        printf("Please choose an option:\n");
        printf("1. Add item to warehouse\n");
        printf("2. Remove item from warehouse\n");
        printf("3. Print inventory\n");
        printf("4. Receive shipment\n");
        printf("5. Send shipment\n");
        printf("0. Exit\n");
        
        // Get the user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                receiveShipment();
                break;
            case 5:
                sendShipment();
                break;
            case 0:
                printf("Exiting Neon Warehouse Management System...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }

    return 0;
}

// Function to add an item to the warehouse
void addItem() {

    // Check if the warehouse is at capacity
    if (numItems >= MAX_ITEMS) {
        printf("The warehouse is at maximum capacity. Cannot add more items.\n");
        return;
    }

    // Define variables to store the item's information
    char name[MAX_NAME_LENGTH];
    int quantity;
    float weight;
    float value;

    // Get the item's information from the user
    printf("Please enter the item's name (maximum %d characters):\n", MAX_NAME_LENGTH);
    scanf("%s", name);

    printf("Please enter the item's quantity:\n");
    scanf("%d", &quantity);

    printf("Please enter the item's weight:\n");
    scanf("%f", &weight);

    printf("Please enter the item's value:\n");
    scanf("%f", &value);

    // Check if the item already exists in the warehouse
    if (itemExists(name)) {
        printf("An item with that name already exists in the warehouse. Cannot add item.\n");
        return;
    }

    // Add the item to the warehouse
    Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.weight = weight;
    newItem.value = value;
    warehouse[numItems++] = newItem;

    printf("Item successfully added to the warehouse.\n");

}

// Function to remove an item from the warehouse
void removeItem() {

    // Check if the warehouse is empty
    if (numItems == 0) {
        printf("The warehouse is empty. Nothing to remove.\n");
        return;
    }

    // Define a variable to store the item's name
    char name[MAX_NAME_LENGTH];

    // Get the item's name from the user
    printf("Please enter the item's name to remove (maximum %d characters):\n", MAX_NAME_LENGTH);
    scanf("%s", name);

    // Check if the item exists in the warehouse
    if (!itemExists(name)) {
        printf("An item with that name does not exist in the warehouse. Cannot remove item.\n");
        return;
    }

    // Remove the item from the warehouse
    int index = getItemIndex(name);
    for (int i = index; i < numItems - 1; i++) {
        warehouse[i] = warehouse[i+1];
    }
    numItems--;

    printf("Item successfully removed from the warehouse.\n");

}

// Function to print the current inventory of the warehouse
void printInventory() {

    // Check if the warehouse is empty
    if (numItems == 0) {
        printf("The warehouse is empty. Nothing to print.\n");
        return;
    }

    // Print the inventory header
    printf("Warehouse Inventory:\n");
    printf("Name\tQuantity\tWeight\tValue\n");

    // Loop through the items in the warehouse and print their information
    for (int i = 0; i < numItems; i++) {
        Item item = warehouse[i];
        printf("%s\t%d\t%f\t%f\n", item.name, item.quantity, item.weight, item.value);
    }

}

// Function to print the contents of a shipment
void printShipment(Shipment shipment) {

    // Print the shipment header
    printf("Shipment to %s:\n", shipment.destination);
    printf("Name\tQuantity\tWeight\tValue\n");

    // Loop through the items in the shipment and print their information
    for (int i = 0; i < MAX_ITEMS; i++) {
        Item item = shipment.items[i];
        if (item.quantity > 0) printf("%s\t%d\t%f\t%f\n", item.name, item.quantity, item.weight, item.value);
    }

}

// Function to receive a shipment
void receiveShipment() {

    // Check if the warehouse is at capacity
    if (numItems >= MAX_ITEMS) {
        printf("The warehouse is at maximum capacity. Cannot receive shipment.\n");
        return;
    }

    // Define variables to store the shipment's information
    char destination[MAX_NAME_LENGTH];
    Shipment shipment;

    // Get the shipment's information from the user
    printf("Please enter the shipment's destination (maximum %d characters):\n", MAX_NAME_LENGTH);
    scanf("%s", destination);

    for (int i = 0; i < MAX_ITEMS; i++) {
        shipment.items[i].quantity = 0;
    }

    printf("Please enter the items in the shipment (maximum %d items). When finished, enter 'done'.\n", MAX_ITEMS);
    char input[MAX_NAME_LENGTH];
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "done") == 0) break;
        if (!itemExists(input)) {
            printf("An item with that name does not exist in the warehouse. Cannot add item to shipment.\n");
            continue;
        }
        int index = getItemIndex(input);
        Item item = warehouse[index];
        printf("Please enter the quantity of %s in the shipment:\n", item.name);
        int quantity;
        scanf("%d", &quantity);
        if (quantity > item.quantity) {
            printf("There are only %d %s in the warehouse. Cannot add %d to shipment.\n", item.quantity, item.name, quantity);
            continue;
        }
        item.quantity = quantity;
        shipment.items[index] = item;
    }

    // Print the shipment information
    printShipment(shipment);

}

// Function to send a shipment
void sendShipment() {

    // Check if the warehouse is empty
    if (numItems == 0) {
        printf("The warehouse is empty. Cannot send shipment.\n");
        return;
    }

    // Define variables to store the shipment's information
    char destination[MAX_NAME_LENGTH];
    Shipment shipment;

    // Get the shipment's information from the user
    printf("Please enter the shipment's destination (maximum %d characters):\n", MAX_NAME_LENGTH);
    scanf("%s", destination);

    for (int i = 0; i < MAX_ITEMS; i++) {
        shipment.items[i].quantity = 0;
    }

    printf("Please enter the items in the shipment (maximum %d items). When finished, enter 'done'.\n", MAX_ITEMS);
    char input[MAX_NAME_LENGTH];
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "done") == 0) break;
        if (!itemExists(input)) {
            printf("An item with that name does not exist in the warehouse. Cannot add item to shipment.\n");
            continue;
        }
        int index = getItemIndex(input);
        Item item = warehouse[index];
        printf("Please enter the quantity of %s to send:\n", item.name);
        int quantity;
        scanf("%d", &quantity);
        if (quantity > item.quantity) {
            printf("There are only %d %s in the warehouse. Cannot send %d.\n", item.quantity, item.name, quantity);
            continue;
        }
        item.quantity = quantity;
        shipment.items[index] = item;
    }

    // Print the shipment information
    printShipment(shipment);

}

// Function to check if an item with the given name exists in the warehouse
bool itemExists(char* name) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, warehouse[i].name) == 0) return true;
    }
    return false;
}

// Function to get the index of an item with the given name in the warehouse
int getItemIndex(char* name) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, warehouse[i].name) == 0) return i;
    }
    return -1;
}