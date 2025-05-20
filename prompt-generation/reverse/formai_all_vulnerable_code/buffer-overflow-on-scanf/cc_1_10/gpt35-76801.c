//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 1000 // Maximum number of products that inventory system can store

typedef struct{
    int id;
    char name[50];
    int quantity;
    float price;
} Product; // Product struct that holds information for each inventory item

int numProducts = 0; // Number of products currently stored in inventory
Product inventory[MAX_PRODUCTS]; // Array of products to store inventory

// Function to add products to the inventory
void addProduct(){
    printf("\nEnter details of the product to add:");
    printf("\nEnter product ID (integer): ");
    scanf("%d", &inventory[numProducts].id);
    printf("Enter product name (max 50 characters): ");
    scanf("%s", inventory[numProducts].name);
    printf("Enter product quantity (integer): ");
    scanf("%d", &inventory[numProducts].quantity);
    printf("Enter product price (float): ");
    scanf("%f", &inventory[numProducts].price);

    numProducts++;
    printf("Product added successfully!\n\n");
}

// Function to display all products in the inventory
void displayInventory(){
    printf("\n---------------------------");
    printf("\n|  ID  |   Name    |  Quantity  |  Price  |");
    printf("\n---------------------------");
    for(int i=0; i<numProducts; i++){
        printf("\n| %4d | %9s | %10d | $%6.2f |", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n---------------------------\n\n");
}

// Function to search for a product in the inventory by ID
void searchProduct(){
    int id;
    printf("\nEnter product ID to search for: ");
    scanf("%d", &id);

    for(int i=0; i<numProducts; i++){
        if(inventory[i].id == id){
            printf("\nProduct found:");
            printf("\nID: %d", inventory[i].id);
            printf("\nName: %s", inventory[i].name);
            printf("\nQuantity: %d", inventory[i].quantity);
            printf("\nPrice: $%.2f\n\n", inventory[i].price);
            return;
        }
    }
    printf("\nProduct not found!\n\n");
}

// Function to remove a product from the inventory by ID
void removeProduct(){
    int id, index = -1;
    printf("\nEnter product ID to remove: ");
    scanf("%d", &id);

    for(int i=0; i<numProducts; i++){
        if(inventory[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("\nProduct not found!\n\n");
    }
    else{
        for(int i=index; i<numProducts-1; i++){
            inventory[i] = inventory[i+1];
        }
        numProducts--;
        printf("\nProduct removed successfully!\n\n");
    }
}

// Main function
int main(){
    int choice;
    char ch;

    do{
        printf("\n*****************");
        printf("\n*** Main Menu ***");
        printf("\n*****************");
        printf("\n1. Add product");
        printf("\n2. Display inventory");
        printf("\n3. Search product");
        printf("\n4. Remove product");
        printf("\n5. Quit");
        printf("\nEnter your choice (1-5): ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }

        // Wait for user input to continue
        printf("\nPress enter to continue...");
        while((ch = getchar()) != '\n' && ch != EOF);

    }while(choice != 5);

    return 0;
}