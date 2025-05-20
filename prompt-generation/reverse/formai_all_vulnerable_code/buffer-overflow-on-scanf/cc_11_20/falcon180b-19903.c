//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct stock{
    char name[50];
    float price;
    int quantity;
};

void main(){
    int choice;
    struct stock s[MAX];
    int n=0;
    char ch;

    do{
        system("clear");
        printf("\n\n\t\t\tSTOCK MARKET TRACKER\n");
        printf("\n\n");
        printf("1.Add a new stock\n");
        printf("2.Update stock details\n");
        printf("3.Delete a stock\n");
        printf("4.View all stocks\n");
        printf("5.Exit\n");
        printf("\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                if(n==MAX){
                    printf("\n\nStock limit reached!!");
                }else{
                    printf("\nEnter the name of the stock: ");
                    scanf("%s",s[n].name);
                    printf("Enter the price of the stock: ");
                    scanf("%f",&s[n].price);
                    printf("Enter the quantity of the stock: ");
                    scanf("%d",&s[n].quantity);
                    n++;
                }
                break;
            }

            case 2:{
                printf("\nEnter the name of the stock to update: ");
                scanf("%s",ch);
                for(int i=0;i<n;i++){
                    if(!strcmp(s[i].name,ch)){
                        printf("\nEnter the new name of the stock: ");
                        scanf("%s",s[i].name);
                        printf("Enter the new price of the stock: ");
                        scanf("%f",&s[i].price);
                        printf("Enter the new quantity of the stock: ");
                        scanf("%d",&s[i].quantity);
                        break;
                    }
                }
                break;
            }

            case 3:{
                printf("\nEnter the name of the stock to delete: ");
                scanf("%s",ch);
                for(int i=0;i<n;i++){
                    if(!strcmp(s[i].name,ch)){
                        for(int j=i;j<n-1;j++){
                            s[j]=s[j+1];
                        }
                        n--;
                        break;
                    }
                }
                break;
            }

            case 4:{
                printf("\n\nName\tPrice\tQuantity\n");
                for(int i=0;i<n;i++){
                    printf("%s\t%.2f\t%d\n",s[i].name,s[i].price,s[i].quantity);
                }
                break;
            }

            case 5:{
                exit(0);
            }

            default:{
                printf("\n\nInvalid choice!!");
            }
        }
    }while(1);
}