//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

struct item{
    char name[50];
    int id;
    float price;
};

void create_item(struct item *item){
    printf("Enter the name of the item: ");
    scanf("%s",item->name);
    printf("Enter the ID of the item: ");
    scanf("%d",&item->id);
    printf("Enter the price of the item: ");
    scanf("%f",&item->price);
}

void display_item(struct item item){
    printf("Name: %s\n",item.name);
    printf("ID: %d\n",item.id);
    printf("Price: %.2f\n",item.price);
}

int main(){
    struct item items[MAX];
    int n,i,choice,flag=0;
    char ch[10];

    printf("Enter the number of items: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nItem %d:\n",i+1);
        create_item(&items[i]);
    }

    while(1){
        system("clear");
        printf("\nDigital Auction System\n");
        printf("1. Place a bid\n");
        printf("2. View bids\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the item ID: ");
                scanf("%d",&flag);
                if(flag==0){
                    printf("Invalid item ID!\n");
                }
                else{
                    printf("Enter your bid: ");
                    scanf("%f",&items[flag-1].price);
                }
                break;

            case 2:
                for(i=0;i<n;i++){
                    display_item(items[i]);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}