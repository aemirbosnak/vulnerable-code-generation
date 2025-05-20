//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

//Defining the surreal structure of the product
struct product{
    int id;
    char* name;
    char* description;
    float price;
    int quantity;
};

//Function for creating a new product
struct product* createProduct(int id, char* name, char* description, float price, int quantity){
    struct product* newProduct = (struct product*) malloc(sizeof(struct product));
    newProduct->id = id;
    newProduct->name = name;
    newProduct->description = description;
    newProduct->price = price;
    newProduct->quantity = quantity;
    return newProduct;
}

int main(){
    int productCount = 0;
    char* productName;
    char* productDescription;
    float productPrice;
    int productQuantity;

    printf("Welcome to the Surrealist Product Inventory System\n");
    printf("How many products would you like to add?\n");
    scanf("%d", &productCount);

    struct product* inventory[productCount]; //Creating an array of surreal products

    for(int i = 0; i < productCount; i++){
        printf("\nProduct %d - Enter the following details:\n", i+1);

        printf("Name: ");
        scanf("%s", productName);

        printf("Description: ");
        scanf("%s", productDescription);

        printf("Price: ");
        scanf("%f", &productPrice);

        printf("Quantity: ");
        scanf("%d", &productQuantity);

        inventory[i] = createProduct(i+1, productName, productDescription, productPrice, productQuantity);
        printf("\nProduct added to inventory!\n");
    }

    printf("\n\nThe Surrealist Inventory System currently lists the following products:\n");

    //Printing the surreal product inventory
    for(int i = 0; i < productCount; i++){
        printf("ID: %d\n", inventory[i]->id);
        printf("Name: %s\n", inventory[i]->name);
        printf("Description: %s\n", inventory[i]->description);
        printf("Price: %.2f\n", inventory[i]->price);
        printf("Quantity: %d\n", inventory[i]->quantity);
        printf("--------------------\n");
    }

    printf("\nThank you for using the Surrealist Product Inventory System!\n");

    return 0;
}