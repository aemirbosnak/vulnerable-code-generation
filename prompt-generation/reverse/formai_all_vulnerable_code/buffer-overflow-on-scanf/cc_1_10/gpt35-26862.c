//FormAI DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defining a structure that holds a product's information*/
struct product{
    char name[50];
    int id;
    int quantity;
    float price;
};

/*Defining a function to add a new product to the inventory */
void add_product(struct product *inventory, int *count){
    printf("Please enter the name of the product:\n");
    scanf("%s", inventory[*count].name);
    printf("Please enter the product ID:\n");
    scanf("%d", &inventory[*count].id);
    printf("Please enter the quantity:\n");
    scanf("%d", &inventory[*count].quantity);
    printf("Please enter the price:\n");
    scanf("%f", &inventory[*count].price);
    printf("Product added successfully.\n");
    (*count)++;
}

/*Defining a function to search for a product in the inventory */
void search_product(struct product *inventory, int count){
    int id_to_find, i;
    printf("Enter the ID of the product you want to find:\n");
    scanf("%d", &id_to_find);
    for(i = 0; i < count; i++){
        if(inventory[i].id == id_to_find){
            printf("Product found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

/*Defining a function to remove a product from the inventory */
void remove_product(struct product *inventory, int *count){
    int id_to_remove, i, found = 0;
    printf("Enter the ID of the product you want to remove:\n");
    scanf("%d", &id_to_remove);
    for(i = 0; i < *count; i++){
        if(inventory[i].id == id_to_remove){
            found = 1;
            *count = *count - 1;
            inventory[i] = inventory[*count];
            printf("Product removed successfully.\n");
            break;
        }
    }

    if(!found){
        printf("Product not found.\n");
    }
}

/*Main function */
int main()
{
    int choice, count = 0;
    struct product *inventory;
    inventory = (struct product*) malloc(sizeof(struct product) * 50); /*Allocating memory for an array of 50 products*/
    while(1){
        printf("\n\nWelcome to the Product Inventory System!\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Remove Product\n");
        printf("4. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_product(inventory, &count);
                    break;
            case 2: search_product(inventory, count);
                    break;
            case 3: remove_product(inventory, &count);
                    break;
            case 4: printf("Exiting program.\n");
                    free(inventory); /* Freeing the dynamically allocated memory*/
                    exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

/* End of program*/