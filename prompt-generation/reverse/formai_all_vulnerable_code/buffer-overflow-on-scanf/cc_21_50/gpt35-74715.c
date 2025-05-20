//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct medical{
    int product_id;
    char product_name[50];
    char manufacturer[50];
    int quantity;
    float price;
}m[50];
int main(){
    int choice, i=0, j, product_id, found=0;
    float total_price=0.0;
    while(1){
        printf("\n1. Add product\n2. Display all products\n3. Search a product\n4. Update product\n5. Delete product\n6. Purchase product\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter product id: ");
                scanf("%d", &m[i].product_id);
                printf("\nEnter product name: ");
                scanf("%s", m[i].product_name);
                printf("\nEnter manufacturer name: ");
                scanf("%s", m[i].manufacturer);
                printf("\nEnter quantity: ");
                scanf("%d", &m[i].quantity);
                printf("\nEnter price: ");
                scanf("%f", &m[i].price);
                i++;
                break;
            case 2:
                printf("\nProduct id\tProduct name\tManufacturer\tQuantity\tPrice\n");
                for(j=0;j<i;j++){
                    printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", m[j].product_id, m[j].product_name, m[j].manufacturer, m[j].quantity, m[j].price);
                }
                break;
            case 3:
                printf("\nEnter product id to search: ");
                scanf("%d", &product_id);
                for(j=0;j<i;j++){
                    if(m[j].product_id==product_id){
                        found=1;
                        printf("\nProduct id\tProduct name\tManufacturer\tQuantity\tPrice\n");
                        printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", m[j].product_id, m[j].product_name, m[j].manufacturer, m[j].quantity, m[j].price);
                        break;
                    }
                }
                if(found==0){
                    printf("\nProduct not found!\n");
                }
                break;
            case 4:
                printf("\nEnter product id to update: ");
                scanf("%d", &product_id);
                for(j=0;j<i;j++){
                    if(m[j].product_id==product_id){
                        printf("\nEnter new quantity: ");
                        scanf("%d", &m[j].quantity);
                        printf("\nEnter new price: ");
                        scanf("%f", &m[j].price);
                        printf("\nProduct updated successfully!\n");
                        break;
                    }
                }
                if(j==i){
                    printf("\nProduct not found!\n");
                }
                break;
            case 5:
                printf("\nEnter product id to delete: ");
                scanf("%d", &product_id);
                for(j=0;j<i;j++){
                    if(m[j].product_id==product_id){
                        for(int k=j;k<i-1;k++){
                            m[k]=m[k+1];
                        }
                        i--;
                        printf("\nProduct deleted successfully!\n");
                        break;
                    }
                }
                if(j==i){
                    printf("\nProduct not found!\n");
                }
                break;
            case 6:
                printf("\nEnter product id to purchase: ");
                scanf("%d", &product_id);
                for(j=0;j<i;j++){
                    if(m[j].product_id==product_id){
                        int quantity;
                        printf("\nEnter quantity to purchase: ");
                        scanf("%d", &quantity);
                        if(m[j].quantity<quantity){
                            printf("\nInsufficient quantity available!\n");
                        }
                        else{
                            m[j].quantity-=quantity;
                            total_price+=quantity*m[j].price;
                            printf("\nPurchase successful!\n");
                        }
                        break;
                    }
                }
                if(j==i){
                    printf("\nProduct not found!\n");
                } 
                break;
            case 7:
                printf("\nTotal sales amount: %.2f\nThank you for shopping with us!\n", total_price);
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}