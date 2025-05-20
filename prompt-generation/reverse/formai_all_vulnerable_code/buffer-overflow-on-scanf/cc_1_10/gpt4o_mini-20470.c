//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Alas! The inventory doth overflow!\n");
        return;
    }
    
    Product newProduct;
    printf("Enter the name of the product, o fairest merchant:\n");
    scanf("%s", newProduct.name);

    printf("How many units dost thou possess of %s?\n", newProduct.name);
    scanf("%d", &newProduct.quantity);

    printf("What cost shall be set upon this cherished item?\n");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Oh joyful day! The product %s hath been added to our realm of wares!\n", newProduct.name);
}

void viewProducts() {
    if (productCount == 0) {
        printf("Alas, our inventory is bare, like the heart of Romeo awaiting Juliet's embrace.\n");
        return;
    }

    printf("Lo, behold the inventory of treasured goods:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: %s\nQuantity: %d\nPrice: $%.2f\n",
               i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Seek ye for a product most dear, speak its name:\n");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Eureka! Found %s in our inventory:\nQuantity: %d\nPrice: $%.2f\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Oh cruel fate! The product named %s is not amidst our cherished treasures.\n", searchName);
    }
}

void displayMenu() {
    printf("\nWelcome to the grand inventory of Verona's merchants!\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Search for a Product\n");
    printf("4. Exit\n");
    printf("Choose thine option, noble one:\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Farewell, dear merchant! May your wares ever prosper!\n");
                break;
            default:
                printf("Oh no! Such an option is not worthy; try again!\n");
        }
    } while (choice != 4);

    return 0;
}