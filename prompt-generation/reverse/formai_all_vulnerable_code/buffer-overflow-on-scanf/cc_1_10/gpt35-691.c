//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

struct product{
    int id;
    char name[20];
    int quantity;
};

void addProduct(struct product* products, int* count){
    printf("\n\n---- Add Product ----\n");
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    products[*count].id = *count;

    printf("\nProduct added successfully!\n");
    *count = *count + 1;
}

void displayProducts(struct product* products, int* count){
    printf("\n\n---- Display Products ----\n");
    printf("Product ID\tProduct Name\tProduct Quantity\n");
    for(int i=0; i<*count; i++){
        printf("%d\t\t%s\t\t%d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

void removeProduct(struct product* products, int* count){
    printf("\n\n---- Remove Product ----\n");
    int id;
    printf("Enter product id to remove: ");
    scanf("%d", &id);

    // Find the product with the given id
    int index = -1;
    for(int i=0; i<*count; i++){
        if(products[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("\nProduct not found with the given id: %d\n", id);
        return;
    }

    // Shift the remaining products to the left
    for(int i=index; i<*count-1; i++){
        products[i] = products[i+1];
    }

    *count = *count - 1;
    printf("\nProduct removed successfully!\n");
}

int main(){
    struct product products[100];
    int count = 0;
    int choice;

    while(1){
        printf("\n---- Warehouse Management System ----\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Remove Product\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(products, &count);
                break;

            case 2:
                displayProducts(products, &count);
                break;

            case 3:
                removeProduct(products, &count);
                break;

            case 4:
                printf("\nExiting from the program...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again!\n");
        }
    }
    return 0;
}