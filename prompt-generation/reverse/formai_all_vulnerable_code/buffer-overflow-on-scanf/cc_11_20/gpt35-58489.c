//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[20];
    float price;
    int quantity;
};

int main() {
    int choice, i = 0, id, qty, flag = 0;
    float price;
    char name[20];
    struct product p[100];

    printf("\nWelcome to the Product Inventory System!");
    do {
        printf("\n\nWhat do you want to do?\n1. Add Product\n2. View All Products\n3. Search Product\n4. Update Product\n5. Delete Product\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Product ID: ");
                scanf("%d", &p[i].id);
                printf("Enter Product Name: ");
                scanf("%s", p[i].name);
                printf("Enter Product Price: ");
                scanf("%f", &p[i].price);
                printf("Enter Product Quantity: ");
                scanf("%d", &p[i].quantity);
                i++;
                printf("\nProduct added successfully!\n");
                break;

            case 2:
                if(i==0) {
                    printf("\nNo products found!\n");
                }
                else {
                    printf("\nProducts:\n");
                    for(int j=0;j<i;j++) {
                        printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", p[j].id, p[j].name, p[j].price, p[j].quantity);
                    }
                }
                break;

            case 3:
                printf("\nEnter Product ID to search: ");
                scanf("%d", &id);
                for(int j=0;j<i;j++) {
                    if(p[j].id == id) {
                        printf("\nProduct found!\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", p[j].id, p[j].name, p[j].price, p[j].quantity);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nNo product found!\n");
                }
                break;

            case 4:
                printf("\nEnter Product ID to update: ");
                scanf("%d", &id);
                for(int j=0;j<i;j++) {
                    if(p[j].id == id) {
                        printf("\nEnter new Product Name: ");
                        scanf("%s", p[j].name);
                        printf("Enter new Product Price: ");
                        scanf("%f", &p[j].price);
                        printf("Enter new Product Quantity: ");
                        scanf("%d", &p[j].quantity);
                        printf("\nProduct updated successfully!\n");
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nNo product found!\n");
                }
                break;

            case 5:
                printf("\nEnter Product ID to delete: ");
                scanf("%d", &id);
                for(int j=0;j<i;j++) {
                    if(p[j].id == id) {
                        for(int k=j;k<i;k++) {
                            p[k] = p[k+1];
                        }
                        i--;
                        printf("\nProduct deleted successfully!\n");
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nNo product found!\n");
                }
                break;

            case 6:
                printf("\nThank you for using Product Inventory System!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 6);

    return 0;
}