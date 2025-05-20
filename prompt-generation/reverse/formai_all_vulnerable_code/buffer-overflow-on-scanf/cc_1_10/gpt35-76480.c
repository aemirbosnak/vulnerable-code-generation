//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

typedef struct product {
    char name[50];
    int stock;
    float price;
}Product;

void addProduct(Product *inventory, int *count) {
    printf("Enter product name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter product stock: ");
    scanf("%d", &inventory[*count].stock);
    printf("Enter product price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
}

void editProduct(Product *inventory, int count, char *name) {
    int i;
    for(i=0;i<count;i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            int choice;
            printf("1. Edit name\n");
            printf("2. Edit stock\n");
            printf("3. Edit price\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", inventory[i].name);
                    break;
                case 2:
                    printf("Enter new stock: ");
                    scanf("%d", &inventory[i].stock);
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].price);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            return;
        }
    }
    printf("Product not found\n");
}

void displayProducts(Product *inventory, int count) {
    int i;
    printf("Name\tStock\tPrice\n");
    for(i=0;i<count;i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

int main() {
    Product inventory[100];
    int count = 0;
    int choice;
    char name[50];
    while(1) {
        printf("1. Add product\n");
        printf("2. Edit product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                editProduct(inventory, count, name);
                break;
            case 3:
                displayProducts(inventory, count);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}