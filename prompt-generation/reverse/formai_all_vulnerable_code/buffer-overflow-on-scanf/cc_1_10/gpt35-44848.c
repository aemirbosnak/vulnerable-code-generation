//FormAI DATASET v1.0 Category: Product Inventory System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product_data_t{
    char name[100];
    int quantity;
    float price;
}product_data;

int main(){
    int option, i, count = 0;
    char search_name[100];
    product_data inventory[100];

    printf("Welcome to Product Inventory System\n");

    do{
        printf("\nMenu:\n");
        printf("1. Add Product\n2. Search Product\n3. Display Inventory\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nAdding Product...\n\n");

                printf("Enter Product Name: ");
                scanf(" %[^\n]", inventory[count].name);

                printf("Enter Product Quantity: ");
                scanf("%d", &inventory[count].quantity);

                printf("Enter Product Price: ");
                scanf("%f", &inventory[count].price);

                count++;

                printf("\nProduct Added Successfully!\n");

                break;
            case 2:
                printf("\nSearching Product...\n\n");

                printf("Enter Product Name to Search: ");
                scanf(" %[^\n]", search_name);

                for(i=0; i<count; i++){
                    if(strcmp(inventory[i].name, search_name) == 0){
                        printf("Product Found!\n");
                        printf("Name: %s\n", inventory[i].name);
                        printf("Quantity: %d\n", inventory[i].quantity);
                        printf("Price: %.2f\n", inventory[i].price);
                        break;
                    }
                }

                if(i == count){
                    printf("Product Not Found!\n");
                }

                break;
            case 3:
                printf("\nHere is Your Product Inventory:\n");

                for(i=0; i<count; i++){
                    printf("Product %d:\n", i+1);
                    printf("Name: %s\n", inventory[i].name);
                    printf("Quantity: %d\n", inventory[i].quantity);
                    printf("Price: %.2f\n", inventory[i].price);
                }

                break;
            case 4:
                printf("\nThank You for Using Our Product Inventory System!\n");
                break;
            default:
                printf("\nInvalid Option! Choose Again.\n");
                break;
        }
    }while(option != 4);

    return 0;
}