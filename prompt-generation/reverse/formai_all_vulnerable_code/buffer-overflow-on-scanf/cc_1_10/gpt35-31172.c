//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <string.h>

/*
This is a program for managing a product inventory system. It allows the user to input and view products in the inventory,
as well as search for products by name or ID. 
*/

// Define a struct to hold product information
typedef struct {
    int id;
    char name[50];
    double price;
    int quantity;
} Product;

// Define an array of Product structs to hold inventory
Product inventory[100];
// Initialize current number of products in inventory to 0
int numProducts = 0;

// Function to add a product to the inventory
void addProduct() {
    // Prompt user for product information
    printf("\nEnter product name: ");
    scanf("%s", inventory[numProducts].name);

    printf("Enter product ID: ");
    scanf("%d", &inventory[numProducts].id);

    printf("Enter product price: $");
    scanf("%lf", &inventory[numProducts].price);

    printf("Enter quantity of product: ");
    scanf("%d", &inventory[numProducts].quantity);

    // Increment number of products in inventory
    numProducts++;
}

// Function to display all products in the inventory
void viewProducts() {
    printf("\nID\tName\t\tPrice\tQuantity\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t$%0.2lf\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("--------------------------------------------\n");
}

// Function to search for a product by name
void searchByName() {
    char searchName[50];
    printf("\nEnter product name to search for: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            printf("\nID\tName\t\tPrice\tQuantity\n");
            printf("--------------------------------------------\n");
            printf("%d\t%s\t$%0.2lf\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("--------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}

// Function to search for a product by ID
void searchByID() {
    int searchID;
    printf("\nEnter product ID to search for: ");
    scanf("%d", &searchID);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (searchID == inventory[i].id) {
            printf("\nID\tName\t\tPrice\tQuantity\n");
            printf("--------------------------------------------\n");
            printf("%d\t%s\t$%0.2lf\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("--------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}

int main() {
    int choice;

    do {
        // Prompt user for choice
        printf("\n1. Add product\n2. View products\n3. Search by name\n4. Search by ID\n5. Quit\n\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchByID();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}