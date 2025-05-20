//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold product details
struct product {
    int id;
    char name[100];
    float price;
    int quantity;
};

//global variables
struct product products[100];
int product_count = 0;

//function to add a product
void add_product() {
    //creating a new product instance
    struct product p;
    p.id = product_count + 1;

    //taking input from user
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    //adding product to array
    products[product_count] = p;
    product_count++;

    printf("\nProduct added successfully!\n");
}

//function to search a product by ID
void search_product() {
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    //searching for product in array
    int i, found = 0;
    for(i=0; i<product_count; i++) {
        if(products[i].id == id) {
            found = 1;
            printf("\nProduct details:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            break;
        }
    }

    if(!found)
        printf("\nProduct not found!\n");
}

//function to display all products
void display_products() {
    if(product_count == 0) {
        printf("\nNo products found!\n");
        return;
    }

    printf("\nAll products:\n");
    int i;
    for(i=0; i<product_count; i++) {
        printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

//function to update a product's price
void update_price() {
    int id;
    float new_price;
    printf("Enter product ID: ");
    scanf("%d", &id);

    //searching for product in array
    int i, found = 0;
    for(i=0; i<product_count; i++) {
        if(products[i].id == id) {
            found = 1;
            printf("Enter new price: ");
            scanf("%f", &new_price);
            products[i].price = new_price;
            printf("\nPrice updated successfully!\n");
            break;
        }
    }

    if(!found)
        printf("\nProduct not found!\n");
}

//function to update a product's quantity
void update_quantity() {
    int id, new_quantity;
    printf("Enter product ID: ");
    scanf("%d", &id);

    //searching for product in array
    int i, found = 0;
    for(i=0; i<product_count; i++) {
        if(products[i].id == id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            products[i].quantity = new_quantity;
            printf("\nQuantity updated successfully!\n");
            break;
        }
    }

    if(!found)
        printf("\nProduct not found!\n");
}

//main function
int main() {
    int choice;
    while(1) {
        printf("\n\nC Product Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Search a product\n");
        printf("3. Display all products\n");
        printf("4. Update a product's price\n");
        printf("5. Update a product's quantity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                update_price();
                break;
            case 5:
                update_quantity();
                break;
            case 6:
                printf("\nExiting program...\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}