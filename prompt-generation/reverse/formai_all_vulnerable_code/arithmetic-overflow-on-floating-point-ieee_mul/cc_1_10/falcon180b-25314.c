//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct item{
    char name[50];
    float price;
    int quantity;
};

struct order{
    int order_id;
    struct item items[100];
    int num_items;
    float total_price;
};

int main(){
    int choice,i,j;
    float amount;
    char ch;
    struct order order;
    FILE *fp;

    fp=fopen("menu.txt","r");

    if(fp==NULL){
        printf("Error opening menu file\n");
        exit(0);
    }

    printf("Welcome to Cafe Billing System\n");
    printf("1. Place order\n");
    printf("2. View order history\n");
    printf("3. Exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter order ID: ");
            scanf("%d",&order.order_id);

            printf("Enter number of items: ");
            scanf("%d",&order.num_items);

            for(i=0;i<order.num_items;i++){
                printf("Enter item name: ");
                scanf("%s",&order.items[i].name);

                printf("Enter item price: ");
                scanf("%f",&order.items[i].price);

                printf("Enter item quantity: ");
                scanf("%d",&order.items[i].quantity);

                order.total_price+=(order.items[i].price*order.items[i].quantity);
            }

            printf("Order placed successfully\n");
            printf("Order ID: %d\n",order.order_id);
            printf("Total price: %.2f\n",order.total_price);
            break;

        case 2:
            printf("Order history:\n");
            fp=fopen("order_history.txt","r");

            if(fp==NULL){
                printf("No order history\n");
                break;
            }

            while(fscanf(fp,"%d %s %f %d",&j,&ch,&amount,&ch)!=EOF){
                printf("Order ID: %d\n",j);
                printf("Item name: %s\n",ch);
                printf("Item price: %.2f\n",amount);
                printf("Item quantity: %d\n",ch);
                printf("Total price: %.2f\n\n",amount*ch);
            }

            fclose(fp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
    }

    return 0;
}