//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct menu {
    int item_id;
    char item_name[20];
    int item_price;
};

void show_menu(struct menu *m,int n){
    printf("--------------------------------------------------\n");
    printf("|%-10s|%-20s|%-10s|\n","Item ID","Item Name","Price");
    printf("--------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("|%-10d|%-20s|%-10d|\n",m[i].item_id,m[i].item_name,m[i].item_price);
    }
    printf("--------------------------------------------------\n");
}

int get_item_price(struct menu *m, int item_id,int n){
    for(int i=0;i<n;i++){
        if(m[i].item_id==item_id){
            return m[i].item_price;
        }
    }
    return 0;
}

int main(){
    struct menu m[5]={
        {1001,"Coffee Latte",120},
        {1002,"Cappuccino",100},
        {1003,"Iced Coffee",150},
        {1004,"Hot Chocolate",110},
        {1005,"Muffin",70},
    };
    
    int choice=0,quantity=0;
    int total=0;
    int item_price=0;
    
    printf("Welcome to C Cafe Billing System!\n");
    while(1){
        show_menu(m,5);
        printf("\nEnter Item ID to order(Enter 0 to generate bill): ");
        scanf("%d",&choice);
        if(choice==0){
            printf("\nTotal Bill: %d\n",total);
            printf("\nThank you for visiting us!\n");
            break;
        }
        printf("\nEnter Quantity: ");
        scanf("%d",&quantity);
        item_price=get_item_price(m,choice,5);
        if(item_price==0){
            printf("\nInvalid Choice! Please select a valid item ID from the menu.\n\n");
        }else{
            total+=item_price*quantity;
            printf("\n%d %s added to cart. Total: %d\n\n",quantity,m[choice-1001].item_name,total);
        }
    }
    return 0;
}