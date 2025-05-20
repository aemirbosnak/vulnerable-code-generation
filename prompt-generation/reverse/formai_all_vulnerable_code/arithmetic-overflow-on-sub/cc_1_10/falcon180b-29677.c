//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct menu{
    char name[20];
    int price;
};

struct bill{
    int num_items;
    struct menu items[MAX];
};

void add_item(struct bill* bill){
    int i=0;
    printf("\nEnter the name of the item: ");
    scanf("%s",bill->items[i].name);
    printf("Enter the price of the item: ");
    scanf("%d",&bill->items[i].price);
    i++;
    bill->num_items=i;
}

void display_bill(struct bill bill){
    int i;
    printf("\nBill:\n");
    for(i=0;i<bill.num_items;i++){
        printf("\nItem %d: %s - %d\n",i+1,bill.items[i].name,bill.items[i].price);
    }
    printf("\nTotal Bill: %d\n",bill.items[bill.num_items-1].price*bill.num_items);
}

int main(){
    struct bill bill;
    int choice;
    do{
        printf("\n\nWelcome to the Cafe Billing System\n");
        printf("\n1. Add an item to the bill\n");
        printf("2. Display the bill\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_item(&bill);
                break;
            case 2:
                display_bill(bill);
                break;
            case 3:
                printf("\nThank you for visiting our cafe!");
                break;
            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=3);
    return 0;
}