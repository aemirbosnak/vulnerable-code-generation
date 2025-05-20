//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct order{
    int item_code;
    char item_name[50];
    float item_price;
    int item_quantity;
};

int main(){
    int choice, i, j, n, count = 0;
    float total = 0;
    struct order orders[50];
    
    printf("-------------------------\n");
    printf("Welcome to Cafe Billing System\n");
    printf("-------------------------\n\n");
    
    while(1){
        printf("\n1. Add order\n2. Delete order\n3. View order\n4. Generate bill\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                printf("\nEnter number of orders: ");
                scanf("%d", &n);
                printf("\n");
                
                for(i=0; i<n; i++){
                    printf("Enter item code: ");
                    scanf("%d", &orders[count].item_code);
                    printf("Enter item name: ");
                    scanf("%s", orders[count].item_name);
                    printf("Enter item price: ");
                    scanf("%f", &orders[count].item_price);
                    printf("Enter item quantity: ");
                    scanf("%d", &orders[count].item_quantity);
                    
                    count++;
                }
                printf("\nOrder added successfully!\n");
                break;
                
            case 2:
                printf("\nEnter item code to delete: ");
                int del;
                scanf("%d", &del);
                
                for(i=0; i<count; i++){
                    if(orders[i].item_code == del){
                        for(j=i; j<count; j++){
                            orders[j] = orders[j+1];
                        }
                        count--;
                        break;
                    }
                }
                printf("\nOrder deleted successfully!\n");
                break;
                
            case 3:
                printf("\nITEM CODE\tITEM NAME\tITEM PRICE\tITEM QUANTITY\n");
                for(i=0; i<count; i++){
                    printf("%d\t\t%s\t\t%.2f\t\t%d\n", orders[i].item_code, orders[i].item_name, orders[i].item_price, orders[i].item_quantity);
                }
                break;
                
            case 4:
                printf("\n-------------------------\n");
                printf("            BILL            \n");
                printf("-------------------------\n");
                printf("ITEM NAME\tITEM PRICE\tITEM QUANTITY\tTOTAL PRICE\n");
                
                for(i=0; i<count; i++){
                    float price = orders[i].item_price * orders[i].item_quantity;
                    total += price;
                    printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", orders[i].item_name, orders[i].item_price, orders[i].item_quantity, price);
                }
                printf("\nTotal bill: %.2f\n", total);
                break;
                
            case 5:
                printf("\nThank you for using Cafe Billing System!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}