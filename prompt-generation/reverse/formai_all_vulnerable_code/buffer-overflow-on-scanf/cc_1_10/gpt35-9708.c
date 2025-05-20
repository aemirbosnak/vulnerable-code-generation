//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of items in inventory

// Structure for each item in inventory
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Array to store all the items in inventory
struct Item inventory[MAX_SIZE];

// Counter to keep track of number of items in inventory
int count = 0;

// Function to add a new item to inventory
void addItemToInventory() {
    system("CLS");
    printf("********** Add Item To Inventory **********\n\n");

    if(count >= MAX_SIZE){
        printf("ERROR! Inventory is full.\n");
        printf("*************************************\n");
        return;
    }

    inventory[count].id = count + 1;
    printf("Item ID: %d\n", inventory[count].id);

    printf("Enter name of item: ");
    scanf("%s", inventory[count].name);
    
    printf("Enter quantity: ");
    scanf("%d", &inventory[count].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[count].price);

    printf("\nItem added successfully!\n");
    printf("*************************************\n");

    count++;
}

// Function to display the entire inventory
void displayInventory() {
    system("CLS");
    printf("********** Inventory **********\n\n");

    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("*************************************\n");
}

// Function to search and display an item by ID
void searchItemByID() {
    system("CLS");
    printf("********** Search Item By ID **********\n\n");

    int searchID, found = 0;
    printf("Enter ID to search for: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; ++i) {
        if (inventory[i].id == searchID) {
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("ERROR! Item ID not found.\n");
    }

    printf("*************************************\n");
}

// Function to search and display an item by name
void searchItemByName() {
    system("CLS");
    printf("********** Search Item By Name **********\n\n");

    char searchName[50];
    int found = 0;
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; ++i) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }

    if(!found){
        printf("ERROR! Item name not found.\n");
    }

    printf("*************************************\n");
}

// Function to update an existing item in inventory
void updateItem() {
    system("CLS");
    printf("********** Update Item **********\n\n");

    int updateID, found = 0;
    printf("Enter ID of item to update: ");
    scanf("%d", &updateID);

    for (int i = 0; i < count; ++i) {
        if (inventory[i].id == updateID) {
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);

            printf("Enter new name of item: ");
            scanf("%s", inventory[i].name);

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("\nItem updated successfully!\n");
            printf("*************************************\n");
            found = 1;
            break;
        }
    }

    if(!found){
        printf("ERROR! Item ID not found.\n");
        printf("*************************************\n");
    }
}

// Function to delete an existing item from inventory
void deleteItem() {
    system("CLS");
    printf("********** Delete Item **********\n\n");

    int deleteID, found = 0;
    printf("Enter ID of item to delete: ");
    scanf("%d", &deleteID);

    for (int i = 0; i < count; ++i) {
        if (inventory[i].id == deleteID) {
            for (int j = i; j < count - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            found = 1;
            printf("\nItem deleted successfully!\n");
            printf("*************************************\n");
            break;
        }
    }

    if(!found){
        printf("ERROR! Item ID not found.\n");
        printf("*************************************\n");
    }
}

// Main function to display inventory options and call appropriate functions
int main() {
    int option;

    // Infinite loop until user quits
    while (1) {
        printf("********** C Product Inventory System **********\n\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item By ID\n");
        printf("4. Search Item By Name\n");
        printf("5. Update Item\n");
        printf("6. Delete Item\n");
        printf("7. Quit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                addItemToInventory();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItemByID();
                break;
            case 4:
                searchItemByName();
                break;
            case 5:
                updateItem();
                break;
            case 6:
                deleteItem();
                break;
            case 7:
                printf("Thank you for using C Product Inventory System. Goodbye!\n");
                exit(0);
            default:
                printf("ERROR! Invalid option selected.\n");
                break;
        }
    }
    return 0;
}