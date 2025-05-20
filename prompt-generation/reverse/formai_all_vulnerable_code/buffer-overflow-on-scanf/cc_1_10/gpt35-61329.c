//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main(){
    char customer_name[50];
    int item_code, quantity, price, total = 0;
    char choice;

    printf("\nWelcome to Cafe Billing System\n");
    printf("------------------------------------\n");

    printf("\nEnter your name: ");
    scanf("%s", customer_name);

    do{
        printf("\nEnter the item code (1-5): ");
        scanf("%d", &item_code);

        switch(item_code){
            case 1:
                printf("Item: Espresso\n");
                printf("Price: $3\n");
                price = 3;
                break;

            case 2:
                printf("Item: Cappuccino\n");
                printf("Price: $4\n");
                price = 4;
                break;

            case 3:
                printf("Item: Latte\n");
                printf("Price: $5\n");
                price = 5;
                break;

            case 4:
                printf("Item: Croissant\n");
                printf("Price: $2\n");
                price = 2;
                break;

            case 5:
                printf("Item: Donut\n");
                printf("Price: $2\n");
                price = 2;
                break;

            default:
                printf("Invalid item code. Please try again.\n");
                price = 0;
                break;
        }

        if(price != 0){
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total += price * quantity;
        }

        printf("\nDo you want to order more items? (y/n): ");
        scanf(" %c", &choice);

    }while(choice == 'y' || choice == 'Y');

    printf("\nThank you for ordering from Cafe Billing System\n");
    printf("----------------------------------------------\n");
    printf("\nCustomer Name: %s\n", customer_name);
    printf("\nTotal Amount: $%d\n", total);

    return 0;
}