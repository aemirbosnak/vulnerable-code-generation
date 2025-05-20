//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//structure to hold product details
struct product{
    char name[100];
    float price;
    int stock;
};

void display_menu(){
    printf("\n");
    printf("************ PRODUCT INVENTORY SYSTEM *************\n");
    printf("                 [1] Add Product\n");
    printf("                 [2] Display Products\n");
    printf("                 [3] Search Product\n");
    printf("                 [4] Remove Product\n");
    printf("                 [5] Exit Program\n");
    printf("***************************************************\n");
    printf("\n");
}

int main(){
    int choice, count=0;
    char confirm;
    struct product products[100];

    printf("Welcome to Product Inventory System!\n");

    //Loop to display menu and take user's choice until exit
    while(1){
        display_menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n");
                printf("************* ADD PRODUCT *************\n");
                printf("Enter product name: ");
                scanf("%s", products[count].name);
                
                printf("Enter product price: ");
                scanf("%f", &products[count].price);
                
                printf("Enter product stock: ");
                scanf("%d", &products[count].stock);

                printf("\nProduct Added Successfully!\n");
                count++;
                break;

            case 2:
                printf("\n");
                printf("************ PRODUCT LIST ************\n");
                printf("No.\tProduct Name\t\tPrice\tStock\n");
                for(int i=0; i<count; i++){
                    printf("%d\t%s\t\t\t%.2f\t%d\n", i+1, products[i].name, products[i].price, products[i].stock);
                }
                printf("\n");
                break;

            case 3:
                printf("\n");
                printf("*********** SEARCH PRODUCT ************\n");
                char search[100];
                printf("Enter product name to search: ");
                scanf("%s", search);
                for(int i=0; i<count; i++){
                    if(strcmp(products[i].name, search)==0){
                        printf("Product found!\n");
                        printf("Product Name: %s\n", products[i].name);
                        printf("Price: %.2f\n", products[i].price);
                        printf("Stock: %d\n", products[i].stock);
                        break;
                    }
                    if(i==count-1){
                        printf("Product not found!\n");
                    }
                }
                printf("\n");
                break;

            case 4:
                printf("\n");
                printf("************ REMOVE PRODUCT **************\n");
                char remove[100];
                printf("Enter product name to remove: ");
                scanf("%s", remove);
                for(int i=0; i<count; i++){
                    if(strcmp(products[i].name, remove)==0){
                        printf("Product found!\n");
                        printf("Product Name: %s\n", products[i].name);
                        printf("Price: %.2f\n", products[i].price);
                        printf("Stock: %d\n", products[i].stock);
                        printf("Are you sure you want to remove this product? (y/n): ");
                        scanf(" %c", &confirm);
                        if(tolower(confirm) == 'y'){
                            for(int j=i; j<count-1; j++){
                                products[j] = products[j+1];
                            }
                            printf("Product removed!\n");
                            count--;
                        }else{
                            printf("Product not removed!\n");
                        }
                        break;
                    }
                    if(i==count-1){
                        printf("Product not found!\n");
                    }
                }
                printf("\n");
                break;

            case 5:
                printf("\nExiting Program..\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice, please enter valid choice (1-5)!\n");
                printf("\n");
                break;
        }
    }
    return 0;
}