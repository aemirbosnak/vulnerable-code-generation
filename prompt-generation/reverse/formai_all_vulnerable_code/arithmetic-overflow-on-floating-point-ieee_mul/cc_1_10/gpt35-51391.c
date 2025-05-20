//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

float calcTotal(int quantity, float price){
    return (quantity*price);
}

int main(){
    int i, choice, quantity, numItems = 0;
    float total = 0, price;
    char itemName[20];
    
    while(1){
        printf("\nWelcome to Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. View bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                numItems++;
                printf("\nEnter item name: ");
                scanf("%s", &itemName);
                printf("Enter item price: ");
                scanf("%f", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                total += calcTotal(quantity, price);
                break;
            case 2:
                if(numItems == 0){
                    printf("\nNo items added yet!\n");
                }else{
                    printf("\n     ------BILL------\n");
                    printf("Item name\tPrice\tQuantity\tTotal\n");
                    for(i=0; i<numItems; i++){
                        printf("%s\t\t%.2f\t%d\t\t%.2f\n", itemName, price, quantity, calcTotal(quantity, price));
                    }
                    printf("\nGrand total: %.2f\n", total);
                }
                break;
            case 3:
                printf("\nThank you for using Cafe Billing System.\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}