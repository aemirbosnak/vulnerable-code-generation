//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

//Product structure
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

//Global variables
Product products[100];
int numProducts = 0;

//Function to add products to inventory
void addProduct() {
    Product p;
    printf("\nEnter product name: ");
    fflush(stdin);
    gets(p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    p.id = numProducts + 1;
    products[numProducts++] = p;
    printf("\nProduct added successfully!\n\n");
}

//Function to display all products in inventory
void showProducts() {
    if(numProducts == 0) {
        printf("\nInventory is empty\n\n");
        return;
    }
    printf("\nID\tName\tPrice\tQuantity\n");
    for(int i=0; i<numProducts; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

//Function to search for a product by name
void searchProduct() {
    char name[50];
    int found = 0;
    printf("\nEnter product name to search: ");
    fflush(stdin);
    gets(name);
    printf("\nID\tName\tPrice\tQuantity\n");
    for(int i=0; i<numProducts; i++) {
        if(strcmp(products[i].name, name) == 0) {
            printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if(!found) {
        printf("\nProduct not found!\n");
    }
    printf("\n");
}

//Function to sell a product
void sellProduct() {
    int id, quantity;
    printf("\nEnter product ID to sell: ");
    scanf("%d", &id);
    for(int i=0; i<numProducts; i++) {
        if(products[i].id == id) {
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if(products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("\nSold %d units of %s for $%.2f each, Total = $%.2f\n\n", quantity, products[i].name, products[i].price, (quantity * products[i].price));
                return;
            } else {
                printf("\nInsufficient quantity!\n\n");
                return;
            }
        }
    }
    printf("\nProduct not found!\n\n");
}

//Main function
int main() {
    int choice;
    do {
        printf("============= Product Inventory System =============\n");
        printf("1. Add product to inventory\n");
        printf("2. Display all products in inventory\n");
        printf("3. Search for a product by name\n");
        printf("4. Sell a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addProduct(); break;
            case 2: showProducts(); break;
            case 3: searchProduct(); break;
            case 4: sellProduct(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n\n");
        }
    } while(1);
    return 0;
}