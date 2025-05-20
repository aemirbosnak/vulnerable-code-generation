//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product {
    int id;
    char name[20];
    int quantity;
    float price;
};

int main() {
    int choice, n = 0;
    struct Product pr[100];

    printf("Welcome to the Product Inventory System\n\n");

    while(1) {
        printf("--------------------\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Edit product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("--------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nAdd product\n");
                printf("Enter product details:\n");
                printf("Product id: ");
                scanf("%d", &pr[n].id);
                printf("Product name: ");
                scanf("%s", pr[n].name);
                printf("Product quantity: ");
                scanf("%d", &pr[n].quantity);
                printf("Product price: ");
                scanf("%f", &pr[n].price);
                n++;
                printf("Product added successfully!\n\n");
                break;
            }
            case 2: {
                printf("\nProduct list\n");
                printf("--------------------\n");
                printf("ID\tName\tQuantity\tPrice\n");
                printf("--------------------\n");

                for(int i=0;i<n;i++) {
                    printf("%d\t%s\t%d\t\t%.2f\n", pr[i].id, pr[i].name, pr[i].quantity, pr[i].price);
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("\nEdit product\n");
                int id;
                printf("Enter product id: ");
                scanf("%d", &id);

                int found = 0;

                for(int i=0;i<n;i++) {
                    if(pr[i].id==id) {
                        printf("Enter new product details:\n");
                        printf("Product id: ");
                        scanf("%d", &pr[i].id);
                        printf("Product name: ");
                        scanf("%s", pr[i].name);
                        printf("Product quantity: ");
                        scanf("%d", &pr[i].quantity);
                        printf("Product price: ");
                        scanf("%f", &pr[i].price);
                        found = 1;
                        printf("Product edited successfully!\n\n");
                        break;
                    }
                }
                if(!found) {
                    printf("Product not found!\n\n");
                }
                break;
            }
            case 4: {
                printf("\nDelete product\n");
                int id;
                printf("Enter product id: ");
                scanf("%d", &id);

                int found = 0;

                for(int i=0;i<n;i++) {
                    if(pr[i].id==id) {
                        found = 1;
                        for(int j=i;j<n-1;j++) {
                            pr[j] = pr[j+1];
                        }
                        n--;
                        printf("Product deleted successfully!\n\n");
                        break;
                    }
                }
                if(!found) {
                    printf("Product not found!\n\n");
                }
                break;
            }
            case 5: {
                printf("\nThank you for using the Product Inventory System!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Please try again.\n\n");
            }
        }
    }

    return 0;
}