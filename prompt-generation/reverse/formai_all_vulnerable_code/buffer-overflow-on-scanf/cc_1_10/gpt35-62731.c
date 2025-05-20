//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_COUNT 1000

typedef struct{
    char name[MAX_PRODUCT_NAME_LENGTH];
    int count;
}Product;

Product warehouse[MAX_PRODUCT_COUNT];
int product_count = 0;

void add_product(){
    char product_name[MAX_PRODUCT_NAME_LENGTH];
    int count;

    printf("Enter the product name: ");
    scanf("%s", product_name);

    printf("Enter the product count: ");
    scanf("%d", &count);

    Product product;
    strcpy(product.name, product_name);
    product.count = count;

    warehouse[product_count++] = product;

    printf("\nProduct added successfully!\n\n");
}

void remove_product(){
    if(product_count == 0){
        printf("\nNo products in the warehouse.\n\n");
        return;
    }

    char product_name[MAX_PRODUCT_NAME_LENGTH];

    printf("Enter the product name: ");
    scanf("%s", product_name);

    int i, flag = 0;
    for(i=0;i<product_count;i++){
        if(strcmp(warehouse[i].name, product_name) == 0){
            flag = 1;
            break;
        }
    }

    if(flag){
        printf("\n%d units of %s removed from warehouse.\n\n", warehouse[i].count, product_name);

        int j;
        for(j=i;j<product_count-1;j++){
            warehouse[j] = warehouse[j+1];
        }

        product_count--;
    }
    else{
        printf("\nProduct not found in the warehouse.\n\n");
    }
}

void display_inventory(){
    if(product_count == 0){
        printf("\nNo products in the warehouse.\n\n");
        return;
    }

    printf("\nWarehouse Inventory\n\n");
    printf("  Product Name\t\tCount\n");
    printf("------------------------------\n");

    int i;
    for(i=0;i<product_count;i++){
        printf("  %-20s %d\n", warehouse[i].name, warehouse[i].count);
    }

    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("Warehouse Management System - Options\n");
        printf("1 - Add Product\n");
        printf("2 - Remove Product\n");
        printf("3 - Display Inventory\n");
        printf("4 - Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("\nExiting...Thank you for using Warehouse Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    }

    return 0;
}