//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int id;
    int quantity;
    float price;
};

int n_products = 0;
struct product products[MAX_PRODUCTS];

void add_product() {
    struct product p;

    printf("Name:");
    scanf("%s", p.name);

    printf("ID:");
    scanf("%d", &p.id);

    printf("Quantity:");
    scanf("%d", &p.quantity);

    printf("Price:");
    scanf("%f", &p.price);

    products[n_products] = p;
    n_products++;

    printf("Product added successfully!");
}

void show_products() {
    if(n_products == 0) {
        printf("No products found!");
        return;
    }

    printf("Name\tID\tQuantity\tPrice\n");
    for(int i=0; i<n_products; i++) {
        printf("%s\t%d\t%d\t\t%.2f\n", products[i].name, products[i].id,
               products[i].quantity, products[i].price);
    }
}

void get_product_by_id() {
    int id;
    printf("Enter product ID:");
    scanf("%d", &id);

    for(int i=0; i<n_products; i++) {
        if(products[i].id == id) {
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %f\n", products[i].price);
            return;
        }
    }

    printf("No product found with ID %d\n", id);
}

void update_product() {
    int id;
    printf("Enter product ID to update:");
    scanf("%d", &id);

    for(int i=0; i<n_products; i++) {
        if(products[i].id == id) {
            printf("New Name:");
            scanf("%s", products[i].name);

            printf("New Quantity:");
            scanf("%d", &products[i].quantity);

            printf("New Price:");
            scanf("%f", &products[i].price);

            printf("Product updated successfully!");
            return;
        }
    }

    printf("No product found with ID %d\n", id);
}

void delete_product() {
    int id;
    printf("Enter product ID to delete:");
    scanf("%d", &id);

    for(int i=0; i<n_products; i++) {
        if(products[i].id == id) {
            for(int j=i; j<n_products-1; j++) {
                products[j] = products[j+1];
            }
            n_products--;

            printf("Product deleted successfully!");
            return;
        }
    }

    printf("No product found with ID %d\n", id);
}

int main() {
    int op;

    do {
        printf("\n\n1. Add product\n");
        printf("2. Show products\n");
        printf("3. Get product by ID\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("6. Quit\n");
        printf("\nPlease enter your choice:");

        scanf("%d", &op);

        switch(op) {
            case 1:
                add_product();
                break;
            case 2:
                show_products();
                break;
            case 3:
                get_product_by_id();
                break;
            case 4:
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(op != 6);

    return 0;
}