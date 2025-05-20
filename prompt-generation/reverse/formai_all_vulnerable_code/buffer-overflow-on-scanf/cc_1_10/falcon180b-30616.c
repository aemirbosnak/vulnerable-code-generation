//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX_ITEMS 100
#define MAX_NAME_LEN 30
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000

typedef struct item{
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
}Item;

void add_item(Item *menu, int n){
    printf("Enter the name of the item: ");
    scanf("%s",menu[n].name);
    printf("Enter the quantity of the item: ");
    scanf("%d",&menu[n].quantity);
    printf("Enter the price of the item: ");
    scanf("%f",&menu[n].price);
}

void display_menu(Item menu[], int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d. %s - %d items - $%.2f\n",i+1,menu[i].name,menu[i].quantity,menu[i].price);
    }
}

int main(){
    Item menu[MAX_ITEMS];
    int n=0;
    char choice;
    do{
        printf("\n");
        printf("Enter 'a' to add an item\n");
        printf("Enter 'd' to display the menu\n");
        printf("Enter 'q' to quit\n");
        scanf(" %c",&choice);
        switch(choice){
            case 'a':
                add_item(menu,n);
                n++;
                break;
            case 'd':
                display_menu(menu,n);
                break;
            case 'q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!='q');
    return 0;
}