//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

int main(){
    int choice, i, n=0, pid, qty, flag=0;
    float total=0;
    Product products[100];

    while (1) {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Buy\n");
        printf("4. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Product
                printf("\nEnter Product ID: ");
                scanf("%d", &products[n].id);
                printf("Enter Product Name: ");
                fflush(stdin);
                scanf("%[^\n]s", &products[n].name);
                printf("Enter Product Price: ");
                scanf("%f", &products[n].price);
                printf("Enter Stock Quantity: ");
                scanf("%d", &products[n].stock);
                n++; // Increment product count
                break;

            case 2: // View Inventory
                printf("\n id \t\t Name \t\t Price \t\t Stock ");
                printf("\n----------------------------------------------------------------------");
                for (i=0; i<n; i++) {
                    printf("\n %d \t\t %s \t\t %.2f \t\t %d ", products[i].id, products[i].name, products[i].price, products[i].stock);
                }
                printf("\n");
                break;

            case 3: // Buy
                printf("\nEnter Product ID: ");
                scanf("%d", &pid);
                printf("Enter Quantity: ");
                scanf("%d", &qty);

                for (i=0; i<n; i++) {
                    if (products[i].id == pid) {
                        flag = 1;

                        if (products[i].stock < qty) {
                            printf("\nInsufficient stock. Only %d available.", products[i].stock);
                        }
                        else {
                            printf("\nPurchase successful. Total cost is %.2f", products[i].price * qty);

                            // Update stock count
                            products[i].stock -= qty;

                            // Update total sales
                            total += products[i].price * qty;
                        }

                        break;
                    }
                }

                if (flag == 0) {
                    printf("\nProduct not found.");
                }

                break;

            case 4: // Exit
                printf("\nTotal Sales: %.2f", total);
                printf("\nThanks for using our Product Inventory System!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}