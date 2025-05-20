//FormAI DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct product {
    char name[20];
    int quantity;
    float price;
};

int main() {
    int option, n=0;
    struct product inv[50];
    
    printf("Welcome to the Product Inventory System!\n\n");
    do {
        printf("1. Add product\n");
        printf("2. Update product quantity\n");
        printf("3. Update product price\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n\n");
        
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            
            case 1:
                if(n==50) {
                    printf("\nCannot add more products. Maximum limit reached!\n\n");
                    break;
                }
                
                printf("\nEnter product name: ");
                scanf("%s", inv[n].name);
                
                printf("Enter product quantity: ");
                scanf("%d", &inv[n].quantity);
                
                printf("Enter product price: ");
                scanf("%f", &inv[n].price);
                
                printf("\nProduct added successfully!\n\n");
                n++;
                break;
                
            case 2:
                if(n==0) {
                    printf("\nInventory is empty. Cannot update product quantity.\n\n");
                    break;
                }
                
                int p, q;
                printf("\nEnter product name: ");
                scanf("%s", &p);
                
                for(int i=0; i<n; i++) {
                    if(strcmp(inv[i].name, p)==0) {
                        printf("Enter updated quantity: ");
                        scanf("%d", &q);
                        inv[i].quantity = q;
                        printf("\nProduct quantity updated successfully!\n\n");
                        break;
                    }
                    if(i==n-1)
                        printf("\nProduct not found in inventory.\n\n");
                }
                break;
                
            case 3:
                if(n==0) {
                    printf("\nInventory is empty. Cannot update product price.\n\n");
                    break;
                }
                
                float new_price;
                printf("\nEnter product name: ");
                scanf("%s", &p);
                
                for(int i=0; i<n; i++) {
                    if(strcmp(inv[i].name, p)==0) {
                        printf("Enter updated price: ");
                        scanf("%f", &new_price);
                        inv[i].price = new_price;
                        printf("\nProduct price updated successfully!\n\n");
                        break;
                    }
                    if(i==n-1)
                        printf("\nProduct not found in inventory.\n\n");
                }
                break;
                
            case 4:
                if(n==0) {
                    printf("\nInventory is empty. No products to display.\n\n");
                    break;
                }
                
                printf("\n%-10s%-10s%-10s\n", "Name", "Quantity", "Price");
                
                for(int i=0; i<n; i++) {
                    printf("%-10s%-10d%-10.2f\n", inv[i].name, inv[i].quantity, inv[i].price);
                }
                printf("\n");
                break;
                
            case 5:
                printf("\nThank you for using the Product Inventory System!\n\n");
                exit(0);
                
            default:
                printf("\nInvalid option! Please try again.\n\n");
                
        }
    } while(option!=5);
    
    return 0;
}