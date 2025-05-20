//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct{
    char name[20];
    int quantity;
    float price;
}item;

typedef struct{
    char name[20];
    int quantity;
    float price;
    int discount;
}discounted_item;

void main(){
    int ch,i;
    float bill=0.0,discount=0.0;
    char name[20];
    item item1;
    discounted_item item2;
    FILE *fp;

    fp=fopen("menu.txt","r");
    
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }

    printf("Welcome to Cafe Billing System\n");

    while(1){
        printf("\n");
        printf("1.Order\n");
        printf("2.Check Bill\n");
        printf("3.Apply Discount\n");
        printf("4.Exit\n");
        printf("\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter item name: ");
                scanf("%s",item1.name);
                printf("Enter quantity: ");
                scanf("%d",&item1.quantity);
                printf("Enter price per unit: ");
                scanf("%f",&item1.price);
                bill+=item1.quantity*item1.price;
                break;

            case 2:
                printf("Total bill amount: $%.2f\n",bill);
                break;

            case 3:
                printf("Enter item name for discount: ");
                scanf("%s",name);
                fp=fopen("menu.txt","r");
                while(fscanf(fp,"%s %d %f %d",item2.name,&item2.quantity,&item2.price,&item2.discount)!=EOF){
                    if(strcmp(item2.name,name)==0){
                        printf("Enter discount percentage (in decimal): ");
                        scanf("%f",&discount);
                        if(discount>item2.discount){
                            printf("Invalid discount percentage\n");
                        }
                        else{
                            item2.discount=discount;
                            break;
                        }
                    }
                }
                fclose(fp);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}