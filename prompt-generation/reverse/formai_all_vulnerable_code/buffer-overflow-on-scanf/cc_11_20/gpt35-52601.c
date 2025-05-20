//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, i = 0, j;
    struct product inventory[50];
    char search[50];
    
    printf("Welcome to the Exciting C Product Inventory System!\n");
    
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a Product\n");
        printf("2. Remove a Product\n");
        printf("3. Search for a Product\n");
        printf("4. Display the Inventory\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the name of the product: ");
                scanf("%s", inventory[i].name);
                printf("Enter the quantity of the product: ");
                scanf("%d", &inventory[i].quantity);
                printf("Enter the price of the product: ");
                scanf("%f", &inventory[i].price);
                printf("Product added successfully!\n");
                i++;
                break;
            case 2:
                printf("\nEnter the name of the product to remove: ");
                scanf("%s", search);
                j = 0;
                while(j < i && strcmp(search, inventory[j].name) != 0) {
                    j++;
                }
                if(j == i) {
                    printf("Product not found!\n");
                } else {
                    printf("%s removed successfully!\n", inventory[j].name);
                    i--;
                    for(; j < i; j++) {
                        strcpy(inventory[j].name, inventory[j+1].name);
                        inventory[j].quantity = inventory[j+1].quantity;
                        inventory[j].price = inventory[j+1].price;
                    }
                }
                break;
            case 3:
                printf("\nEnter the name of the product to search for: ");
                scanf("%s", search);
                j = 0;
                while(j < i && strcmp(search, inventory[j].name) != 0) {
                    j++;
                }
                if(j == i) {
                    printf("Product not found!\n");
                } else {
                    printf("\nProduct Found:\n");
                    printf("Name: %s\n", inventory[j].name);
                    printf("Quantity: %d\n", inventory[j].quantity);
                    printf("Price: $%.2f\n", inventory[j].price);
                }
                break;
            case 4:
                printf("\nCurrent Inventory:\n");
                if(i == 0) {
                    printf("No products in inventory!\n");
                } else {
                    for(j = 0; j < i; j++) {
                        printf("Product %d:\n", j+1);
                        printf("Name: %s\n", inventory[j].name);
                        printf("Quantity: %d\n", inventory[j].quantity);
                        printf("Price: $%.2f\n\n", inventory[j].price);
                    }
                }
                break;
            case 5:
                printf("\nThank you for using the Exciting C Product Inventory System!\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}