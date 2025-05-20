//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for each product in inventory
struct product {
    char name[50];
    int quantity;
    float price;
};

//Prototype for recursive function
void add_products(struct product* inventory, int num_products);

//Main function
int main() {
    int num_products;

    printf("Enter the number of products in inventory: ");
    scanf("%d", &num_products);

    //Dynamically allocate memory for array of products
    struct product* inventory = (struct product*)malloc(num_products * sizeof(struct product));

    //Call recursive function to add each product to inventory
    add_products(inventory, num_products);

    //Print out each product in inventory
    printf("\nInventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n\n", inventory[i].price);
    }

    //Free dynamically allocated memory
    free(inventory);

    return 0;
}

//Recursive function to add each product to inventory
void add_products(struct product* inventory, int num_products) {
    if (num_products == 0) {
        return;
    }

    //Prompt user for product information
    printf("\nEnter product %d name: ", num_products);
    scanf("%s", inventory[num_products - 1].name);

    printf("Enter product %d quantity: ", num_products);
    scanf("%d", &inventory[num_products - 1].quantity);

    printf("Enter product %d price: ", num_products);
    scanf("%f", &inventory[num_products - 1].price);

    //Call recursive function with one less product to add
    add_products(inventory, num_products - 1);
}