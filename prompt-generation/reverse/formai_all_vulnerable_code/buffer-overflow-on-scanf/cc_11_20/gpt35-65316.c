//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

struct Product{
    int id;
    char name[20];
    float price;
    int quantity;
};

int main(){
    int option, numProducts = 0;
    struct Product products[50];

    printf("Welcome to the Product Inventory System!\n");

    while(1){
        printf("\nPlease choose an option:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. View All Products\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:{
                // Add Product
                printf("\nEnter Product ID: ");
                scanf("%d", &products[numProducts].id);

                printf("Enter Product Name: ");
                scanf("%s", products[numProducts].name);

                printf("Enter Product Price: ");
                scanf("%f", &products[numProducts].price);

                printf("Enter Product Quantity: ");
                scanf("%d", &products[numProducts].quantity);

                printf("\nProduct Added Successfully!\n");

                numProducts++;
                break;
            }
            case 2:{
                // Remove Product
                int idToRemove;
                printf("\nEnter Product ID to remove: ");
                scanf("%d", &idToRemove);

                int foundIndex = -1;
                for(int i=0;i<numProducts;i++){
                    if(products[i].id == idToRemove){
                        foundIndex = i;
                        break;
                    }
                }

                if(foundIndex == -1){
                    printf("\nProduct not found with id %d\n", idToRemove);
                    break;
                }

                for(int i=foundIndex;i<numProducts-1;i++){
                    products[i] = products[i+1];
                }

                printf("\nProduct Removed Successfully!\n");

                numProducts--;
                break;
            }
            case 3:{
                // Update Product
                int idToUpdate;
                printf("\nEnter Product ID to update: ");
                scanf("%d", &idToUpdate);

                int foundIndex = -1;
                for(int i=0;i<numProducts;i++){
                    if(products[i].id == idToUpdate){
                        foundIndex = i;
                        break;
                    }
                }

                if(foundIndex == -1){
                    printf("\nProduct not found with id %d\n", idToUpdate);
                    break;
                }

                printf("\nEnter New Product Name: ");
                scanf("%s", products[foundIndex].name);

                printf("Enter New Product Price: ");
                scanf("%f", &products[foundIndex].price);

                printf("Enter New Product Quantity: ");
                scanf("%d", &products[foundIndex].quantity);

                printf("\nProduct Updated Successfully!\n");
                break;
            }
            case 4:{
                // View All Products
                printf("\n%-10s %-20s %-10s %-10s\n", "ID", "NAME", "PRICE", "QUANTITY");
                for(int i=0;i<numProducts;i++){
                    printf("%-10d %-20s %-10.2f %-10d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                }
                break;
            }
            case 5:{
                // Exit
                printf("\nExiting Product Inventory System...\n");
                exit(0);
            }
            default:{
                printf("\nInvalid Option!\n");
            }
        }
    }

    return 0;
}