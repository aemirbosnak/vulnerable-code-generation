//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

//Product struct definition
struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

//Global inventory array
struct Product inventory[MAX_PRODUCTS];

//Number of products in the inventory
int numProducts = 0;

//Function prototypes
void addProduct();
void removeProduct();
void displayInventory();
void searchProduct();
float totalPrice();
void updatePrice();

int main() {
    int choice;

    do {
        //Display menu
        printf("\n\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Search Product\n");
        printf("5. Calculate Total Price\n");
        printf("6. Update Price\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        //Read user choice
        scanf("%d", &choice);

        //Process user choice
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                printf("Total price of inventory: $%.2f\n", totalPrice());
                break;
            case 6:
                updatePrice();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

//Function to add a product to the inventory
void addProduct() {
    struct Product newProduct;

    //Read product details from user
    printf("\nEnter product ID: ");
    scanf("%d", &newProduct.id);

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    //Add new product to inventory
    inventory[numProducts++] = newProduct;

    printf("\nProduct added to inventory successfully!\n");
}

//Function to remove a product from the inventory
void removeProduct() {
    int id, found = 0;

    printf("\nEnter product ID to remove: ");
    scanf("%d", &id);

    //Search for product in inventory
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            //Remove product from inventory
            for(int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            numProducts--;
            found = 1;
            printf("\nProduct removed from inventory successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("\nProduct not found in inventory!\n");
    }
}

//Function to display the inventory
void displayInventory() {
    printf("\nPRODUCT INVENTORY\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

//Function to search for a product in the inventory
void searchProduct() {
    int id, found = 0;

    printf("\nEnter product ID to search: ");
    scanf("%d", &id);

    //Search for product in inventory
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            printf("\nProduct found in inventory:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nProduct not found in inventory!\n");
    }
}

//Function to calculate total price of inventory
float totalPrice() {
    float total = 0;

    for(int i = 0; i < numProducts; i++) {
        total += inventory[i].quantity * inventory[i].price;
    }

    return total;
}

//Function to update the price of a product
void updatePrice() {
    int id, found = 0;
    float price;

    printf("\nEnter product ID to update price: ");
    scanf("%d", &id);

    //Search for product in inventory
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            printf("\nEnter new price: ");
            scanf("%f", &price);
            inventory[i].price = price;
            found = 1;
            printf("\nPrice updated successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("\nProduct not found in inventory!\n");
    }
}