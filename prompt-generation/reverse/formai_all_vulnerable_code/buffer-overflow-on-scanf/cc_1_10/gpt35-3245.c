//FormAI DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_STRING_LENGTH 50

// structure to hold product details
typedef struct {
    int product_id;
    char product_name[MAX_STRING_LENGTH];
    int product_quantity;
    float product_price;
} product_t;

// function to add new product to the inventory
void add_new_product(product_t inventory[], int *num_products) {
    int new_id;
    char new_name[MAX_STRING_LENGTH];
    int new_quantity;
    float new_price;
    
    // get product details from user
    printf("Enter ID of new product: ");
    scanf("%d", &new_id);
    
    printf("Enter name of new product: ");
    scanf("%s", new_name);
    
    printf("Enter quantity of new product: ");
    scanf("%d", &new_quantity);
    
    printf("Enter price of new product: ");
    scanf("%f", &new_price);
    
    // add product details to inventory
    inventory[*num_products].product_id = new_id;
    strcpy(inventory[*num_products].product_name, new_name);
    inventory[*num_products].product_quantity = new_quantity;
    inventory[*num_products].product_price = new_price;
    
    // increment number of products in inventory
    (*num_products)++;
    
    printf("\nNew product added!\n");
}

// function to display all products in the inventory
void display_all_products(product_t inventory[], int num_products) {
    printf("\nPRODUCTS IN INVENTORY\n");
    printf("---------------------\n");
    printf("ID\tName\tQuantity\tPrice\n");
    
    for (int i=0; i<num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].product_id, inventory[i].product_name,
                                        inventory[i].product_quantity, inventory[i].product_price);
    }
}

// function to search for a product by name
void search_for_product(product_t inventory[], int num_products) {
    char search_name[MAX_STRING_LENGTH];
    int found = 0;
    
    // get name of product to search for
    printf("Enter name of product to search for: ");
    scanf("%s", search_name);
    
    // search for product in inventory
    for (int i=0; i<num_products; i++) {
        if (strcmp(inventory[i].product_name, search_name) == 0) {
            // display product details if found
            printf("\nPRODUCT FOUND\n");
            printf("--------------\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].product_id,
                                                                    inventory[i].product_name,
                                                                    inventory[i].product_quantity,
                                                                    inventory[i].product_price);
            found = 1;
            break; // exit loop once product is found
        }
    }
    
    // if product is not found
    if (!found) {
        printf("\nProduct not found!\n");
    }
}

// function to update product quantity in inventory
void update_product_quantity(product_t inventory[], int num_products) {
    int product_id;
    int new_quantity;
    int found = 0;
    
    // get ID of product to update
    printf("Enter ID of product to update: ");
    scanf("%d", &product_id);
    
    // search for product in inventory
    for (int i=0; i<num_products; i++) {
        if (inventory[i].product_id == product_id) {
            // get new quantity and update inventory
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            inventory[i].product_quantity = new_quantity;
            
            printf("\nProduct quantity updated!\n");
            found = 1;
            break; // exit loop once product is found
        }
    }
    
    // if product is not found
    if (!found) {
        printf("\nProduct not found!\n");
    }
}

int main() {
    product_t inventory[MAX_PRODUCTS];
    int num_products = 0;
    int choice;
    
    printf("Welcome to the Happy Product Inventory System!\n");
    printf("**********************************************\n\n");
    
    do {
        printf("Please choose an option:\n");
        printf("1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product by name\n");
        printf("4. Update product quantity in inventory\n");
        printf("5. Quit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_new_product(inventory, &num_products);
                break;
            case 2:
                display_all_products(inventory, num_products);
                break;
            case 3:
                search_for_product(inventory, num_products);
                break;
            case 4:
                update_product_quantity(inventory, num_products);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
        
        printf("\n");
        
    } while (choice != 5);
    
    return 0;
}