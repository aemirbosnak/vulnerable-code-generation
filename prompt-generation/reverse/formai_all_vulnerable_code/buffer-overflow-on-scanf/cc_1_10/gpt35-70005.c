//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct order{
    int order_no;
    char item_name[30];
    int quantity;
    float price;
};

float calculateBill(struct order o[], int size){
    float total = 0;
    for(int i=0;i<size;i++){
        total += (o[i].quantity * o[i].price);
    }
    return total;
}

int main(){
    printf("Welcome to the Café Amour!\n");
    printf("Here, everything is flavored with love!\n");

    struct order orders[50];
    int order_no = 1; //To keep track of order number
    int count = 0; //To keep track of number of orders

    int choice;
    do{
        printf("----------------------\n");
        printf("Choose an option:\n");
        printf("1. Place an order\n");
        printf("2. Generate bill\n");
        printf("3. Exit\n");
        printf("----------------------\n");

        printf("Your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("\nEnter details of order %d\n",order_no);

                strcpy(orders[count].item_name,"Love Mocha"); //Hardcoded item name
                orders[count].price = 4.50; //Hardcoded item price
                orders[count].order_no = order_no;

                printf("\nHow many cups would you like?: ");
                scanf("%d",&orders[count].quantity);

                printf("\nAdded 'Love Mocha' to order %d\n",order_no);

                count++; //increment count to add to new order
                order_no++; //increment order number
                break;
            }
            
            case 2:{
                printf("\n----------------------\n");
                printf("        Bill\n");
                printf("----------------------\n");
                printf("Order No\tItem Name\tQuantity\tPrice\n");
                for(int i=0;i<count;i++){
                    printf("%d\t\t%s\t\t%d\t\t%.2f\n",orders[i].order_no,orders[i].item_name,orders[i].quantity,orders[i].price);
                }
                printf("----------------------\n");
                printf("Total\t\t\t\t\t%.2f\n",calculateBill(orders,count));
                printf("Thank you for visiting Café Amour!\n");
                printf("We hope you felt the love in our food and services!\n");
                printf("----------------------\n");
                break;
            }

            case 3:
                printf("Goodbye. Come back soon to Café Amour!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 3);

    return 0;
}