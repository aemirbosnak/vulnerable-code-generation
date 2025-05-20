//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dish{
    char name[50];
    int price;
};

struct order{
    struct dish d;
    int quantity;
};

void printMenu(struct dish menu[], int menuSize){
    printf("\nWelcome to The King's Cafe! Our menu for today:\n");
    printf("-------------------------------------------------\n");
    for(int i=0;i<menuSize;i++){
        printf("%s - %d gold coins\n", menu[i].name, menu[i].price);
    }
    printf("-------------------------------------------------\n");
}

int main(){
    struct dish menu[5] = {{"Roasted Chicken", 10}, {"Potatoes with Gravy", 5}, {"Mushroom Soup", 3}, {"Lamb Chops", 12}, {"Fruit Salad", 4}};    
    int menuSize = 5;
    struct order orderList[10];
    int orderListSize = 0;
    int moneyEarned = 0;
    
    printf("Welcome to The King's Cafe Billing System!\n");
    printf("---------------------------------------------\n");
    while(1){
        printf("\nEnter 1 to view menu, 2 to place order, 3 to view order list, and 4 to exit: ");
        int input;
        scanf("%d", &input);
        if(input == 1){
            printMenu(menu, menuSize);
        }
        else if(input == 2){
            printf("\nEnter the name of the dish you want: ");
            char name[50];
            scanf("%s", name);
            int found = 0;
            for(int i=0;i<menuSize;i++){
                if(strcmp(menu[i].name, name) == 0){
                    printf("\nEnter the quantity: ");
                    int quantity;
                    scanf("%d", &quantity);
                    orderList[orderListSize].d = menu[i];
                    orderList[orderListSize].quantity = quantity;
                    printf("\n%s x %d added to the order list.\n", menu[i].name, quantity);
                    orderListSize++;
                    moneyEarned += menu[i].price * quantity;
                    found = 1;
                }
            }
            if(!found){
                printf("\nSorry, we don't have that in our menu.\n");
            }
        }
        else if(input == 3){
            if(orderListSize == 0){
                printf("\nYour order list is empty.\n");
            }
            else{
                printf("\nYour order list:\n");
                printf("-------------------------------------------------\n");
                for(int i=0;i<orderListSize;i++){
                    printf("%s x %d - %d gold coins\n", orderList[i].d.name, orderList[i].quantity, orderList[i].d.price * orderList[i].quantity);
                }
                printf("-------------------------------------------------\n");
            }
        }
        else if(input == 4){
            printf("\nThank you for visiting! You spent %d gold coins today.\n", moneyEarned);
            break;
        }
        else{
            printf("\nInvalid input, please try again.\n");
        }
    }
    return 0;
}