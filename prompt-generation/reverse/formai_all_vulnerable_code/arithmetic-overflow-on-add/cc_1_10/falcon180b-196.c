//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct item{
    char name[MAX];
    float price;
};

struct cart{
    struct item item[10];
    int count;
};

void add_item(struct cart *c){
    int i;
    printf("Enter item name: ");
    scanf("%s",c->item[c->count].name);
    printf("Enter item price: ");
    scanf("%f",&c->item[c->count].price);
    c->count++;
}

void display_cart(struct cart c){
    int i;
    printf("\nCart:\n");
    for(i=0;i<c.count;i++){
        printf("%d. %s - $%.2f\n",i+1,c.item[i].name,c.item[i].price);
    }
}

void calculate_total(struct cart c){
    int i;
    float total=0;
    for(i=0;i<c.count;i++){
        total+=c.item[i].price*c.item[i].price;
    }
    printf("\nTotal: $%.2f\n",total);
}

int main(){
    struct cart cart;
    int choice,i;
    float total=0;
    char ch;

    do{
        printf("\nWelcome to Cafe Billing System\n");
        printf("1. Add item\n");
        printf("2. Display cart\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_item(&cart);
                break;
            case 2:
                display_cart(cart);
                break;
            case 3:
                calculate_total(cart);
                break;
            case 4:
                printf("Thank you for using Cafe Billing System\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c",&ch);

    }while(ch=='y' || ch=='Y');

    return 0;
}