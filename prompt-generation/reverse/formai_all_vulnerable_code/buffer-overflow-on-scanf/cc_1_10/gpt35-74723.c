//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <string.h>

// struct for holding product information
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// function to add a new product
void addProduct(struct Product inventory[], int *count) {
    struct Product newProduct;

    // get input from user
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    // set product ID
    newProduct.id = *count + 1;

    // add product to inventory
    inventory[*count] = newProduct;
    *count += 1;

    printf("\nProduct added successfully.\n\n");
}

// function to display inventory
void displayInventory(struct Product inventory[], int count) {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

// function to update a product
void updateProduct(struct Product inventory[], int count) {
    int id;
    int found = 0;

    // get product ID from user
    printf("Enter product ID: ");
    scanf("%d", &id);

    // search for product in inventory
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            // get input from user
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("\nProduct updated successfully.\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n\n");
    }
}

// main function
int main() {
    struct Product inventory[100];
    int count = 0;
    int choice;

    // loop for menu
    while (1) {
        // display menu
        printf("1. Add new product\n");
        printf("2. Display inventory\n");
        printf("3. Update product\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice.\n\n");
        }
    }
}