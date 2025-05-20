//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

struct menu{
    char item_name[30];
    int price;
};

struct order{
    char item[30];
    int quantity;
};

int main(){

    struct menu item_list[MAX] = {{"Coffee", 50},{"Tea", 20},{"Sandwich", 60},{"Burger", 80},{"Pizza", 200},{"Pasta", 150},{"Noodles", 100},{"Ice cream", 30},{"Juice", 40},{"Cold drinks", 30}};
    struct order customer_order[10];
    int i, j, total_cost=0, choice, quantity, bill_no;
    char name[30];

    printf("*****Welcome to C Cafe Billing System*****\n\n");

    printf("Enter your name: ");
    scanf("%[^\n]s", name);

    printf("\nHello, %s! Please see our menu below:\n\n", name);
    printf("%-15s%-7s\n", "Item Name", "Price");
    for(i=0; i<MAX; i++){
        printf("%-15s%-7d\n", item_list[i].item_name, item_list[i].price);
    }

    printf("\nEnter the Bill Number: ");
    scanf("%d", &bill_no);

    printf("\nHow many different types of items would you like to order? ");
    scanf("%d", &choice);

    for(i=0; i<choice; i++){
        printf("\nEnter the Item Name: ");
        scanf("%s", customer_order[i].item);

        printf("\nEnter the quantity: ");
        scanf("%d", &customer_order[i].quantity);

        for(j=0; j<MAX; j++){

            if(strcmp(item_list[j].item_name, customer_order[i].item) == 0){
                total_cost += item_list[j].price * customer_order[i].quantity;
            }
        }    
    }

    printf("\n\n****Billing****\n\n");
    printf("Name: %s\n\n", name);
    printf("Bill Number: %d\n\n", bill_no);
    printf("%-15s%-10s%-10s\n", "Item", "Quantity", "Price");
    for(i=0; i<choice; i++){
        printf("%-15s%-10d%d\n", customer_order[i].item, customer_order[i].quantity, item_list[i].price * customer_order[i].quantity);
    }
    printf("Total cost: Rs. %d", total_cost);

    return 0;
}