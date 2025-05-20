//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[20];
    int code;
    float price;
    int qty;
} p[50];

int choice(int count);
void addProduct(int count);
void viewProducts(int count);
void updateProductPrice(int count);
void deleteProduct(int count);

int main() {

    int count = 0;
    int option;

    do {
        printf("\n\n\t\tPRODUCT INVENTORY SYSTEM\n\n");

        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product Price\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n\n");

        printf("Choose an option (1-5): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addProduct(count);
                count++;
                break;
            case 2:
                viewProducts(count);
                break;
            case 3:
                updateProductPrice(count);
                break;
            case 4:
                deleteProduct(count);
                count--;
                break;
            case 5:
                printf("\n\n\t\tExiting Program...\n\n");
                exit(0);
            default:
                printf("\n\n\t\tInvalid Option! Try Again.\n\n");
        }
    } while(choice(count));

    return 0;
}

int choice(int count) {
    if(count == 0) {
        printf("\n\nThere are no products in the inventory! Please add products.\n\n");
        return 1;
    }
    else
        return 1;
}

void addProduct(int count) {
    printf("\n\nEnter Product Name: ");
    scanf("%s", &p[count].name);

    printf("Enter Product Code: ");
    scanf("%d", &p[count].code);

    printf("Enter Product Price: ");
    scanf("%f", &p[count].price);

    printf("Enter Product Quantity: ");
    scanf("%d", &p[count].qty);

    printf("\nProduct Added Successfully.\n\n");
}

void viewProducts(int count) {
    printf("\n\n\t\tPRODUCT LIST\n\n");
    printf("Product Name\tProduct Code\tProduct Price\tProduct Quantity\n");

    for(int i=0; i<count; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%d\n", p[i].name, p[i].code, p[i].price, p[i].qty);
    }
}

void updateProductPrice(int count) {
    int code;
    float new_price;

    printf("\n\nEnter Product Code to update price: ");
    scanf("%d", &code);

    for(int i=0; i<count; i++) {
        if(code == p[i].code) {
            printf("Enter New Product Price: ");
            scanf("%f", &new_price);

            p[i].price = new_price;
            printf("\nProduct Price Updated Successfully.\n\n");
            return;
        }
    }
    printf("\n\nProduct Does Not Exist in Inventory.\n\n");
}

void deleteProduct(int count) {
    int code;
    printf("\n\nEnter Product Code to Delete: ");
    scanf("%d", &code);

    for(int i=0; i<count; i++) {
        if(code == p[i].code) {
            for(int j=i; j<count-1; j++) {
                p[j] = p[j+1];
            }
            printf("\nProduct Deleted Successfully.\n\n");
            return;
        }
    }
    printf("\n\nProduct Does Not Exist in Inventory.\n\n");
}