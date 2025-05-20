//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // surrealistic C product inventory system
    printf("Welcome to our C product inventory system! This is not just any ordinary inventory system \n");
    printf("It is an inventory system unlike any you've seen before\n");
    printf("Here you will find products that are beyond your wildest dreams,\n");
    printf("And just like surrealism, this system will take you on a journey of the subconscious mind\n\n");
    
    // prompt user to input product information
    printf("Please enter the name of the product: \n");
    char name[50];
    scanf("%s", name);
    
    printf("Please enter the price of the product: \n");
    float price;
    scanf("%f", &price);
    
    printf("Please enter the quantity of the product: \n");
    int quantity;
    scanf("%i", &quantity);
    
    // create struct to store product information
    struct Product {
        char name[50];
        float price;
        int quantity;
    };
    
    struct Product product;
    
    // store user input in struct
    strcpy(product.name, name);
    product.price = price;
    product.quantity = quantity;
    
    // display product information in a surreal way
    printf("\nYou have added %i %ss to the inventory \n", quantity, product.name);
    printf("They were priced at $%.2f each, but we can guarantee you that their value is infinite\n\n", product.price);
    printf("The inventory is alive! It is constantly shifting and changing, just like our minds\n");
    printf("Perhaps tomorrow, the same product will have a different price or quantity\n");
    printf("Who knows what path the inventory will take? Only the surreal forces that guide it\n\n");

    // create file to store product information
    FILE *fptr;
    fptr = fopen("product_inventory.txt", "a");
    
    // write product information to file
    fprintf(fptr, "%s, $%.2f, %i\n", product.name, product.price, product.quantity);
    fclose(fptr);
    
    // display products currently in inventory (read from file)
    printf("Here are the current products in the inventory: \n\n");
    fptr = fopen("product_inventory.txt", "r");
    char line[100];
    
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    
    fclose(fptr);
    
    // end program with surreal message
    printf("\nThank you for exploring our surreal C product inventory system\n");
    printf("May your dreams be filled with infinite quantities of surreal products\n");
    printf("The journey of the inventory continues, and so does yours\n");
    printf("Until we meet again, in the world of the subconscious\n");
    printf("GOODBYE AND SURREALIST REGARDS \n");
    
    return 0;
}