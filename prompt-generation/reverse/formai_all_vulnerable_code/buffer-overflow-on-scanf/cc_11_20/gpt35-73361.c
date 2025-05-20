//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id; 
    char name[20];
    int quantity;
    float price;
}; 

int main() {

    struct product inventory[50];
    int num_products = 0;
    int choice;
    
    while(1) {
        printf("\n");
        printf("PRODUCT INVENTORY SYSTEM\n");
        printf("-------------------------\n");
        printf("1. Add Product\n");
        printf("2. View Product\n");
        printf("3. Edit Product\n");
        printf("4. Exit System\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                struct product new_product;
                printf("\nEnter Product ID: ");
                scanf("%d", &new_product.id);
                printf("\nEnter Product Name: ");
                scanf("%s", new_product.name);
                printf("\nEnter Product Quantity: ");
                scanf("%d", &new_product.quantity);
                printf("\nEnter Product Price: ");
                scanf("%f", &new_product.price);
                inventory[num_products] = new_product;
                num_products++;
                printf("\nProduct successfully added!\n\n");
                break;
            }
            case 2: {
                if(num_products == 0) {
                    printf("\nThere are no products in the inventory!\n\n");
                    break;
                }
                else {
                    printf("\nEnter Product ID: ");
                    int id_search;
                    int result_found = 0;
                    scanf("%d", &id_search);
                    for(int i = 0; i < num_products; i++) {
                        if(inventory[i].id == id_search) {
                            printf("\nPRODUCT DETAILS\n");
                            printf("----------------\n");
                            printf("Product Name: %s\n", inventory[i].name);
                            printf("Product Quantity: %d\n", inventory[i].quantity);
                            printf("Product Price: %.2f\n\n", inventory[i].price);
                            result_found = 1;
                            break;
                        }
                    }
                    if(result_found == 0) {
                        printf("\nProduct not found!\n\n");
                    }
                    break;
                }
            }
            case 3: {
                if(num_products == 0) {
                    printf("\nThere are no products in the inventory!\n\n");
                    break;
                }
                else {
                    printf("\nEnter Product ID: ");
                    int id_search;
                    int result_found = 0;
                    scanf("%d", &id_search);
                    for(int i = 0; i < num_products; i++) {
                        if(inventory[i].id == id_search) {
                            printf("\nEDIT PRODUCT\n");
                            printf("------------\n");
                            printf("1. Edit Name\n");
                            printf("2. Edit Quantity\n");
                            printf("3. Edit Price\n");
                            printf("\nEnter your choice: ");
                            int edit_choice;
                            scanf("%d", &edit_choice);
                            switch(edit_choice) {
                                case 1: {
                                    printf("\nEnter new product name: ");
                                    scanf("%s", inventory[i].name);
                                    printf("\nProduct name successfully updated!\n\n");
                                    result_found = 1;
                                    break;
                                }
                                case 2: {
                                    printf("\nEnter new product quantity: ");
                                    scanf("%d", &inventory[i].quantity);
                                    printf("\nProduct quantity successfully updated!\n\n");
                                    result_found = 1;
                                    break;
                                }
                                case 3: {
                                    printf("\nEnter new product price: ");
                                    scanf("%f", &inventory[i].price);
                                    printf("\nProduct price successfully updated!\n\n");
                                    result_found = 1;
                                    break;
                                }
                                default: {
                                    printf("\nInvalid choice!\n\n");
                                    result_found = 1;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    if(result_found == 0) {
                        printf("\nProduct not found!\n\n");
                    }
                    break;
                }
            }
            case 4: {
                printf("\nExiting Product Inventory System. Goodbye!\n\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice!\n\n");
                break;
            }
        }
    }
    return 0;
}