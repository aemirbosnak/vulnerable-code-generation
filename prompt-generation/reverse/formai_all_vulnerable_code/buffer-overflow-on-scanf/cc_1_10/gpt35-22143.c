//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

/* Define product struct */
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

/* Define function prototypes */
void displayMenu();
void addProduct(Product inventory[], int count);
void removeProduct(Product inventory[], int count);
void updateProduct(Product inventory[], int count);
void displayInventory(Product inventory[], int count);

/* main function */
int main() {
    /* Define inventory array */
    Product inventory[100];
    int count = 0;

    /* Define variables for user input */
    int choice;

    /* Display menu and get user choice */
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            /* Add product */
            case 1:
                addProduct(inventory, count);
                count++;
                break;

            /* Remove product */
            case 2:
                removeProduct(inventory, count);
                count--;
                break;

            /* Update product */
            case 3:
                updateProduct(inventory, count);
                break;

            /* Display inventory */
            case 4:
                displayInventory(inventory, count);
                break;

            /* Invalid choice */
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

/* Function to display menu */
void displayMenu() {
    printf("Product Inventory System\n");
    printf("-------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

/* Function to add product */
void addProduct(Product inventory[], int count) {
    Product product;

    /* Get user input for product */
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    /* Assign product id */
    product.id = count + 1;

    /* Add product to inventory */
    inventory[count] = product;

    printf("Product added successfully.\n\n");
}

/* Function to remove product */
void removeProduct(Product inventory[], int count) {
    int id, i, found = 0;

    /* Get user input for product id */
    printf("Enter product id: ");
    scanf("%d", &id);

    /* Search for product with id */
    for(i = 0; i < count; i++) {
        if(inventory[i].id == id) {
            found = 1;
            break;
        }
    }

    /* Remove product from inventory */
    if(found) {
        for(; i < count - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        printf("Product removed successfully.\n\n");
    } else {
        printf("Product not found.\n\n");
    }
}

/* Function to update product */
void updateProduct(Product inventory[], int count) {
    int id, i, found = 0;
    char name[50];
    float price;
    int quantity;

    /* Get user input for product id */
    printf("Enter product id: ");
    scanf("%d", &id);

    /* Search for product with id */
    for(i = 0; i < count; i++) {
        if(inventory[i].id == id) {
            found = 1;
            break;
        }
    }

    /* Update product in inventory */
    if(found) {
        /* Get user input for new product information */
        printf("Enter new product name (or press enter to keep current name): ");
        getchar();
        fgets(name, 50, stdin);
        if(strlen(name) > 1) {
            name[strlen(name)-1] = '\0';
            strcpy(inventory[i].name, name);
        }
        printf("Enter new product price (or press enter to keep current price): ");
        char temp[10];
        fgets(temp, 10, stdin);
        if(strlen(temp) > 1) {
            sscanf(temp, "%f", &price);
            inventory[i].price = price;
        }
        printf("Enter new product quantity (or press enter to keep current quantity): ");
        fgets(temp, 10, stdin);
        if(strlen(temp) > 1) {
            sscanf(temp, "%d", &quantity);
            inventory[i].quantity = quantity;
        }

        printf("Product updated successfully.\n\n");
    } else {
        printf("Product not found.\n\n");
    }
}

/* Function to display inventory */
void displayInventory(Product inventory[], int count) {
    int i;

    printf("Product Inventory\n");
    printf("-----------------\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------\n");
    for(i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
}