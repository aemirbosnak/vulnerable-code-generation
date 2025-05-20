//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct Item{
    char name[50];
    int id;
    float price;
};

void addItem(struct Item items[], int n){
    printf("\nEnter the name of the item: ");
    scanf("%s",items[n].name);
    printf("Enter the ID of the item: ");
    scanf("%d",&items[n].id);
    printf("Enter the price of the item: ");
    scanf("%f",&items[n].price);
}

void displayItems(struct Item items[], int n){
    printf("\nID\tName\tPrice\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%.2f\n",items[i].id,items[i].name,items[i].price);
    }
}

void bid(struct Item items[], int n, int id){
    int flag=0;
    for(int i=0;i<n;i++){
        if(items[i].id==id){
            printf("\nEnter your bid for %s: ",items[i].name);
            float bid;
            scanf("%f",&bid);
            if(bid>items[i].price){
                items[i].price=bid;
                printf("\nYour bid of %.2f has been accepted.\n",bid);
            }
            else{
                printf("\nYour bid is too low.\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nItem not found.\n");
    }
}

int main(){
    struct Item items[MAX];
    int n=0;

    while(n<MAX){
        printf("\nDo you want to add an item? (y/n): ");
        char ch;
        scanf(" %c",&ch);
        if(ch=='y' || ch=='Y'){
            addItem(items,n);
            n++;
        }
        else{
            printf("\nEnter number of items: ");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                addItem(items,i);
            }
        }
    }

    int choice;
    while(1){
        printf("\n\nDigital Auction System\n");
        printf("1. Display items\n2. Place bid\n3. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                displayItems(items,n);
                break;
            case 2:
                printf("\nEnter the ID of the item: ");
                int id;
                scanf("%d",&id);
                bid(items,n,id);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}