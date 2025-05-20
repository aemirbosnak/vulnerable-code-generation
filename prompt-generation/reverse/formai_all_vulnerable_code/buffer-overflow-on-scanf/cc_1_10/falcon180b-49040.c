//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct item{
    char name[50];
    int price;
};

struct order{
    int num_items;
    struct item items[10];
};

void display_menu(struct item items[], int num_items){
    printf("\nMenu:\n");
    for(int i=0;i<num_items;i++){
        printf("%d. %s - $%d\n",i+1,items[i].name,items[i].price);
    }
}

void take_order(struct order *order){
    int num_items=0;
    while(num_items<10){
        printf("\nEnter the number of the item you want to order or 0 to finish: ");
        scanf("%d",&order->items[num_items].price);
        if(order->items[num_items].price==0){
            break;
        }
        printf("\nEnter the name of the item: ");
        scanf("%s",order->items[num_items].name);
        num_items++;
    }
    order->num_items=num_items;
}

void print_order(struct order order){
    printf("\nYour order:\n");
    for(int i=0;i<order.num_items;i++){
        printf("%s - $%d\n",order.items[i].name,order.items[i].price);
    }
}

int main(){
    struct item items[]={{"Coffee",3},{"Tea",2},{"Cake",5},{"Sandwich",4},{"Pizza",7}};
    int num_items=sizeof(items)/sizeof(items[0]);

    struct order order;
    take_order(&order);

    print_order(order);

    return 0;
}