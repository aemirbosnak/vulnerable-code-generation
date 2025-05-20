//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include<stdio.h>
#include<string.h>
#define MAX_ITEMS 1000

struct Product{
    int id;
    char name[100];
    float price;
    int quantity;
};

typedef struct Product product;

product inventory[MAX_ITEMS];

// Function declarations
void addProduct();
void deleteProduct();
void updateProduct();
void displayProduct();
void displayAll();


int main(){
    int choice;
    printf("\n\n----------- Welcome to the Visionary Product Inventory System ------------\n\n");
    printf("\n\n Menu:");
    printf("\n 1. Add a new product");
    printf("\n 2. Delete a product");
    printf("\n 3. Update a product");
    printf("\n 4. Display a product");
    printf("\n 5. Display all products");
    printf("\n 6. Quit");

    do{
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                displayProduct();
                break;
            case 5:
                displayAll();
                break;
            case 6:
                printf("\n ----------- Thank you for using the Visionary Product Inventory System ------------\n\n");
                break;
            default:
                printf("\n Oops! Invalid Choice. Try again.");
        }

    }while(choice != 6);

    return 0;
}

void addProduct(){
    product newProduct;
    printf("\n\n----- Adding a new product-----\n");
    printf("\nEnter the product ID: ");
    scanf("%d", &newProduct.id);
    printf("\nEnter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("\nEnter the price of the product: ");
    scanf("%f", &newProduct.price);
    printf("\nEnter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);

    inventory[newProduct.id] = newProduct;

    printf("Product added successfully!");
}

void deleteProduct(){
    int idToDelete;
    printf("\n\n----- Deleting a product -----");
    printf("\nEnter the ID of the product to delete: ");
    scanf("%d", &idToDelete);

    if(inventory[idToDelete].id == 0){
        printf("\nProduct not found!\n");
        return;
    }

    inventory[idToDelete].id = 0;
    inventory[idToDelete].name[0] = '\0';
    inventory[idToDelete].price = 0.0;
    inventory[idToDelete].quantity = 0;

    printf("\nProduct deleted successfully!\n");
}

void updateProduct(){
    int idToUpdate;
    printf("\n\n----- Updating a product -----");

    printf("\nEnter the ID of the product to update: ");
    scanf("%d", &idToUpdate);

    if(inventory[idToUpdate].id == 0){
        printf("\nProduct not found!\n");
        return;
    }

    printf("\nEnter the new name of the product: ");
    scanf("%s", inventory[idToUpdate].name);
    printf("\nEnter the new price of the product: ");
    scanf("%f", &inventory[idToUpdate].price);
    printf("\nEnter the new quantity of the product: ");
    scanf("%d", &inventory[idToUpdate].quantity);

    printf("\nProduct updated successfully!\n");
}

void displayProduct(){
    int idToDisplay;
    printf("\n\n----- Displaying a product -----");
    printf("\nEnter the ID of the product to display: ");
    scanf("%d", &idToDisplay);

    if(inventory[idToDisplay].id == 0){
        printf("\nProduct not found!\n");
        return;
    }

    printf("\nProduct ID: %d", inventory[idToDisplay].id);
    printf("\nProduct Name: %s", inventory[idToDisplay].name);
    printf("\nProduct Price: %.2f", inventory[idToDisplay].price);
    printf("\nProduct Quantity: %d", inventory[idToDisplay].quantity);

}

void displayAll(){
    printf("\n\n----- Displaying all products -----");

    for(int i=0; i<MAX_ITEMS; i++){
        if(inventory[i].id != 0){
            printf("\n\nProduct ID: %d", inventory[i].id);
            printf("\nProduct Name: %s", inventory[i].name);
            printf("\nProduct Price: %.2f", inventory[i].price);
            printf("\nProduct Quantity: %d", inventory[i].quantity);
        }
    }
}