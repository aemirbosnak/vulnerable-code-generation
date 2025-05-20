//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct product products[100];
int num_products = 0;

int add_product() {
    printf("Enter name: ");
    scanf("%s", products[num_products].name);
    
    printf("Enter price: $");
    scanf("%f", &products[num_products].price);
    
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
    
    products[num_products].id = num_products + 1;
    num_products++;
    
    return 0;
}

int remove_product() {
    int id;
    printf("Enter product id to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            printf("Product removed.\n");
            return 0;
        }
    }
    
    printf("Product not found.\n");
    return 1;
}

int update_product() {
    int id, choice;
    float f;
    printf("Enter product id to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("1. Name\n2. Price\n3. Quantity\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", products[i].name);
                    break;
                case 2:
                    printf("Enter new price: $");
                    scanf("%f", &f);
                    products[i].price = f;
                    break;
                case 3:
                    printf("Enter new quantity: ");
                    scanf("%d", &products[i].quantity);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            printf("Product updated.\n");
            return 0;
        }
    }
    
    printf("Product not found.\n");
    return 1;
}

int display_products() {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    
    return 0;
}

int main() {
    int choice;
    
    while (1) {
        printf("1. Add product\n2. Remove product\n3. Update product\n4. Display products\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}