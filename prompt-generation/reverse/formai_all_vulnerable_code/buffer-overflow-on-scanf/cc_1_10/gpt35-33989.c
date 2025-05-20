//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include<stdio.h>
#include<string.h>

// Structure to store individual product details
struct Product{
    char name[20]; // Name of the Product
    int quantity; // Quantity of the product in Stock
    float price; // Unit price of the product
};

// Function to add a new product to the Stock
void addProduct(struct Product stock[], int *stockSize){
    char name[20];
    int quantity;
    float price;
    printf("Enter the name of the product: ");
    fflush(stdin);
    scanf("%[^\n]", name);
    printf("Enter the quantity of the product: ");
    scanf("%d",&quantity);
    printf("Enter the price of the product: ");
    scanf("%f",&price);
    strcpy(stock[*stockSize].name, name);
    stock[*stockSize].quantity = quantity;
    stock[*stockSize].price = price;
    (*stockSize)++;
    printf("Product added successfully!\n\n");
}

// Function to remove a product from the Stock
void removeProduct(struct Product stock[], int *stockSize){
    char name[20];
    int found = 0; // To keep track if the product is found or not
    printf("Enter the name of the product to remove: ");
    fflush(stdin);
    scanf("%[^\n]", name);
    for(int i=0; i<*stockSize; i++){
        if(strcmp(stock[i].name, name) == 0){
            for(int j=i+1; j<*stockSize; j++){
                // Shift all the elements to the left
                strcpy(stock[j-1].name, stock[j].name);
                stock[j-1].quantity = stock[j].quantity;
                stock[j-1].price = stock[j].price;
            }
            (*stockSize)--;
            printf("Product removed successfully!\n\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Product not found in the Stock!\n\n");
    }
}

// Function to update the price of a product
void updatePrice(struct Product stock[], int stockSize){
    char name[20];
    int found = 0; // To keep track if the product is found or not
    float newPrice;
    printf("Enter the name of the product to update the price: ");
    fflush(stdin);
    scanf("%[^\n]", name);
    for(int i=0; i<stockSize; i++){
        if(strcmp(stock[i].name, name) == 0){
            printf("Enter the new price of the product: ");
            scanf("%f",&newPrice);
            stock[i].price = newPrice;
            printf("Price updated successfully!\n\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Product not found in the Stock!\n\n");
    }
}

// Function to display all the products in the Stock
void displayStock(struct Product stock[], int stockSize){
    printf("\n------------------------\n");
    printf("| Product Name | Quantity | Price |\n");
    printf("------------------------\n");
    for(int i=0; i<stockSize; i++){
        printf("| %-12s | %-8d | %-5.2f |\n", stock[i].name, stock[i].quantity, stock[i].price);
        printf("------------------------\n");
    }
    printf("\n");
}

int main(){
    struct Product stock[50];
    int stockSize = 0; // To keep track of the number of products in the Stock
    int choice;
    while(1){
        printf("1. Add a new product\n");
        printf("2. Remove a product\n");
        printf("3. Update the price of a product\n");
        printf("4. Display all the products in the Stock\n");
        printf("5. Quit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addProduct(stock, &stockSize);
                break;
            case 2:
                removeProduct(stock, &stockSize);
                break;
            case 3:
                updatePrice(stock, stockSize);
                break;
            case 4:
                displayStock(stock, stockSize);
                break;
            case 5:
                printf("Thank you for using the Warehouse Management System!");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}