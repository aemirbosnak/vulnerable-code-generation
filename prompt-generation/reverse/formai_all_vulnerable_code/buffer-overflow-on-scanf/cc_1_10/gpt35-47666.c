//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Product{
    int id;
    char name[50];
    float price;
    char description[200];
    int quantity;
} Product;

Product inventory[100];

int total_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", inventory[total_products].name);

    printf("Enter product price: ");
    scanf("%f", &inventory[total_products].price);

    printf("Enter product description: ");
    scanf("%s", inventory[total_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[total_products].quantity);

    inventory[total_products].id = rand()%1000;

    printf("\nProduct successfully added!\n");
    total_products++;
}

void display_display(int index) {
    printf("ID: %d\n", inventory[index].id);
    printf("Name: %s\n", inventory[index].name);
    printf("Price: %.2f\n", inventory[index].price);
    printf("Description: %s\n", inventory[index].description);
    printf("Quantity: %d\n", inventory[index].quantity);
}

void display_all_products() {
    if(total_products == 0)
        printf("No items in inventory.\n");
    else {
        printf("\nList of all products:\n\n");
        for(int i = 0; i < total_products; i++) {
            display_display(i);
            printf("\n");
        }
    }
}

void search_product() {
    int prod_id;
    printf("Enter the product ID: ");
    scanf("%d", &prod_id);

    int index = -1;

    for(int i = 0; i < total_products; i++) {
        if(inventory[i].id == prod_id) {
            index = i;
            break;
        }
    }

    if(index == -1)
        printf("No product found with ID: %d", prod_id);
    else {
        printf("\nProduct record found!\n\n");
        display_display(index);
    }
}

void update_product() {
    int prod_id;
    printf("Enter the product ID: ");
    scanf("%d", &prod_id);

    int index = -1;

    for(int i = 0; i < total_products; i++) {
        if(inventory[i].id == prod_id) {
            index = i;
            break;
        }
    }

    if(index == -1)
        printf("No product found with ID: %d", prod_id);
    else {
        printf("\nEnter new details of product:\n");

        printf("Enter product name: ");
        scanf("%s", inventory[index].name);

        printf("Enter product price: ");
        scanf("%f", &inventory[index].price);

        printf("Enter product description: ");
        scanf("%s", inventory[index].description);

        printf("Enter product quantity: ");
        scanf("%d", &inventory[index].quantity);

        printf("\nProduct successfully updated!\n");
    }
}

void delete_product() {
    int prod_id;
    printf("Enter the product ID: ");
    scanf("%d", &prod_id);

    int index = -1;

    for(int i = 0; i < total_products; i++) {
        if(inventory[i].id == prod_id) {
            index = i;
            break;
        }
    }

    if(index == -1)
        printf("No product found with ID: %d", prod_id);
    else {
        for(int i = index; i < total_products - 1; i++)
            inventory[i] = inventory[i+1];

        total_products--;

        printf("\nProduct successfully deleted!\n");
    }
}

int main(void) {

    printf("\n\n*******************************************\n");
    printf("\t WELCOME TO THE SURREAL INVENTORY SYSTEM");
    printf("\n*******************************************\n\n");

    int choice;

    do {
        printf("\n\nEnter your choice:\n");
        printf("1.Add product\n");
        printf("2.Display all products\n");
        printf("3.Search product\n");
        printf("4.Update product\n");
        printf("5.Delete product\n");
        printf("6.Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_all_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                printf("\n\nThank you for using the Surreal Inventory System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 6);

    return 0;
}