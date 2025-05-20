//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    char category[30];
    float price;
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} MedicalStore;

// Function to add a product to the store's inventory
void addProduct(MedicalStore *store) {
    if (store->count < MAX_PRODUCTS) {
        Product newProduct;
        printf("\nEnter the name of the medicine (your beloved's name): ");
        scanf(" %[^\n]", newProduct.name);
        printf("Enter the category (like a love letter category): ");
        scanf(" %[^\n]", newProduct.category);
        printf("Enter the price (value of love): ");
        scanf("%f", &newProduct.price);
        printf("Enter the quantity (number of sweet memories): ");
        scanf("%d", &newProduct.quantity);

        store->products[store->count] = newProduct;
        store->count++;
        printf("\nAh! A new love has been added: %s!\n", newProduct.name);
    } else {
        printf("Oh no! The inventory is full of unfulfilled love!\n");
    }
}

// Function to display all products in the store
void displayProducts(MedicalStore *store) {
    printf("\n--- List of Love-potions (Products) ---\n");
    for (int i = 0; i < store->count; i++) {
        printf("Medicine #%d: %s | Category: %s | Price: $%.2f | Quantity: %d\n",
            i + 1, store->products[i].name, store->products[i].category, 
            store->products[i].price, store->products[i].quantity);
    }
}

// Function to search for a product by name
void searchProduct(MedicalStore *store) {
    char searchName[50];
    printf("\nEnter the name of your beloved to find (search medicine): ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < store->count; i++) {
        if (strcasecmp(store->products[i].name, searchName) == 0) {
            printf("Ah! Found your love: %s | Category: %s | Price: $%.2f | Quantity: %d\n",
                store->products[i].name, store->products[i].category, 
                store->products[i].price, store->products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Unfortunately, your love is not here...\n");
    }
}

// Function to purchase a product
void purchaseProduct(MedicalStore *store) {
    char purchaseName[50];
    printf("\nEnter the name of the medicine you wish to purchase (can't part with this love): ");
    scanf(" %[^\n]", purchaseName);

    for (int i = 0; i < store->count; i++) {
        if (strcasecmp(store->products[i].name, purchaseName) == 0) {
            if (store->products[i].quantity > 0) {
                store->products[i].quantity--;
                printf("You successfully purchased %s! One step closer to your love!\n", purchaseName);
            } else {
                printf("Oh no! This love is out of stock!\n");
            }
            return;
        }
    }
    printf("Sadly, we can't fulfill this purchase; Please find another love...\n");
}

int main() {
    MedicalStore store = {.count = 0};
    int choice;
    
    while (1) {
        printf("\n--- Welcome to the Eternal Love Medical Store ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Purchase Product\n");
        printf("5. Exit (Leave your love behind)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&store);
                break;
            case 2:
                displayProducts(&store);
                break;
            case 3:
                searchProduct(&store);
                break;
            case 4:
                purchaseProduct(&store);
                break;
            case 5:
                printf("Thank you for visiting, come back soon to find love again!\n");
                exit(0);
            default:
                printf("Oh dear! That's not an option in this love story.\n");
        }
    }
    
    return 0;
}