//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define structure for product
struct product{
    char name[20];
    int id;
    float cost;
    int quantity;
};

//function to display the menu
void display_menu() {
    printf("\n");
    printf("Enter 1 to add a new product \n");
    printf("Enter 2 to display all products \n");
    printf("Enter 3 to search for a product by ID \n");
    printf("Enter 4 to search for a product by name \n");
    printf("Enter 5 to update product details \n");
    printf("Enter 6 to delete a product \n");
    printf("Enter 7 to exit the program \n");
    printf("\n");
}

//function to add a new product
void add_product(struct product products[], int *product_count) {
    printf("Enter the name of the product: ");
    scanf("%s", products[*product_count].name);

    printf("Enter the id of the product: ");
    scanf("%d", &products[*product_count].id);

    printf("Enter the cost of the product: ");
    scanf("%f", &products[*product_count].cost);

    printf("Enter the quantity of the product: ");
    scanf("%d", &products[*product_count].quantity);

    (*product_count)++;
    printf("Product added successfully! \n");
}

//function to display all products
void display_products(struct product products[], int product_count) {
    printf("------------------------------------------------------------------------\n");
    printf("| %-5s| %-20s| %-10s| %-10s|\n", "ID", "Name", "Cost", "Quantity");
    printf("------------------------------------------------------------------------\n");

    for(int i = 0; i < product_count; i++) {
        printf("| %-5d| %-20s| %-10.2f| %-10d|\n", products[i].id, products[i].name, products[i].cost, products[i].quantity);
    }

    printf("------------------------------------------------------------------------\n");
}

//function to search for a product by id
void search_by_id(struct product products[], int product_count) {
    int id;

    printf("Enter the id to search for: ");
    scanf("%d", &id);

    for(int i = 0; i < product_count; i++) {
        if(products[i].id == id) {
            printf("------------------------------------------------------------------------\n");
            printf("| %-5s| %-20s| %-10s| %-10s|\n", "ID", "Name", "Cost", "Quantity");
            printf("------------------------------------------------------------------------\n");
            printf("| %-5d| %-20s| %-10.2f| %-10d|\n", products[i].id, products[i].name, products[i].cost, products[i].quantity);
            printf("------------------------------------------------------------------------\n");
            return;
        }
    }

    printf("Product not found! \n");
}

//function to search for a product by name
void search_by_name(struct product products[], int product_count) {
    char name[20];

    printf("Enter the name to search for: ");
    scanf("%s", name);

    for(int i = 0; i < product_count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            printf("------------------------------------------------------------------------\n");
            printf("| %-5s| %-20s| %-10s| %-10s|\n", "ID", "Name", "Cost", "Quantity");
            printf("------------------------------------------------------------------------\n");
            printf("| %-5d| %-20s| %-10.2f| %-10d|\n", products[i].id, products[i].name, products[i].cost, products[i].quantity);
            printf("------------------------------------------------------------------------\n");
            return;
        }
    }

    printf("Product not found! \n");
}

//function to update product details
void update_product(struct product products[], int product_count) {
    int id;

    printf("Enter the id of the product to update: ");
    scanf("%d", &id);

    for(int i = 0; i < product_count; i++) {
        if(products[i].id == id) {
            printf("Enter the name of the product: ");
            scanf("%s", products[i].name);

            printf("Enter the cost of the product: ");
            scanf("%f", &products[i].cost);

            printf("Enter the quantity of the product: ");
            scanf("%d", &products[i].quantity);

            printf("Product updated successfully! \n");
            return;
        }
    }

    printf("Product not found! \n");
}

//function to delete a product
void delete_product(struct product products[], int *product_count) {
    int id;

    printf("Enter the id of the product to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < *product_count; i++) {
        if(products[i].id == id) {
            for(int j = i; j < *product_count - 1; j++) {
                products[j] = products[j+1];
            }

            (*product_count)--;
            printf("Product deleted successfully! \n");
            return;
        }
    }

    printf("Product not found! \n");
}

int main() {
    int choice, product_count = 0;
    struct product products[100];

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(products, &product_count);
                break;
            
            case 2:
                display_products(products, product_count);
                break;
            
            case 3:
                search_by_id(products, product_count);
                break;
            
            case 4:
                search_by_name(products, product_count);
                break;
            
            case 5:
                update_product(products, product_count);
                break;
            
            case 6:
                delete_product(products, &product_count);
                break;
            
            case 7:
                printf("Exiting the program... \n");
                exit(0);
                break;

            default:
                printf("Invalid choice! \n");
                break;
        }
    }

    return 0;
}