//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product{
    int id;
    char name[20];
    int quantity;
    float price;
} products[100]; //maximum number of products is set to 100

void add_product(){
    static int count = 0; //static variable to keep track of products count
    products[count].id = count+1;

    printf("Enter name of the product: ");
    scanf("%s", products[count].name);
    printf("Enter quantity: ");
    scanf("%d", &products[count].quantity);
    printf("Enter price per item: ");
    scanf("%f", &products[count].price);

    printf("Product added successfully!\n\n");

    count++;
}

void view_product(){
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    if(id <= 0){
        printf("Invalid ID!\n\n");
        return;
    }

    if(id > 100){
        printf("Product not found!\n\n");
        return;
    }

    struct Product p = products[id-1];

    printf("\nProduct ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Quantity: %d\n", p.quantity);
    printf("Price per item: %.2f\n\n", p.price);
}

void search_product(){
    char name[20];
    printf("Enter name of the product: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0; i<100; i++){
        if(strcmp(name, products[i].name) == 0){
            found = 1;
            printf("\nProduct ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price per item: %.2f\n\n", products[i].price);
        }
    }

    if(!found){
        printf("Product not found!\n\n");
    }

}

void delete_product(){
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    if(id <= 0){
        printf("Invalid ID!\n\n");
        return;
    }

    if(id > 100){
        printf("Product not found!\n\n");
        return;
    }

    for(int i=id-1; i<99; i++){
        products[i] = products[i+1];
        products[i].id = i+1;
    }

    printf("\nProduct deleted successfully!\n\n");
}

int main(){
    int choice;
    printf("Welcome to the Product Inventory System!\n\n");

    while(1){
        printf("Available Options:\n");
        printf("1. Add Product\n");
        printf("2. View Product By ID\n");
        printf("3. Search Product By Name\n");
        printf("4. Delete Product By ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                view_product();
                break;
            case 3:
                search_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    return 0;
}