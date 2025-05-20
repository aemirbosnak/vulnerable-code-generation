//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct medicine{
    char name[50];
    int price;
    int quantity;
};

void main(){
    int choice,i;
    char ch;
    struct medicine m[MAX];

    printf("Enter the number of medicines:");
    scanf("%d",&choice);

    for(i=0;i<choice;i++){
        printf("\nEnter medicine name:");
        scanf("%s",&m[i].name);
        printf("Enter medicine price:");
        scanf("%d",&m[i].price);
        printf("Enter medicine quantity:");
        scanf("%d",&m[i].quantity);
    }

    while(1){
        printf("\n1.Add medicine");
        printf("\n2.Delete medicine");
        printf("\n3.Update medicine");
        printf("\n4.Display medicine");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter medicine name:");
                scanf("%s",&m[choice].name);
                printf("Enter medicine price:");
                scanf("%d",&m[choice].price);
                printf("Enter medicine quantity:");
                scanf("%d",&m[choice].quantity);
                break;

            case 2:
                printf("\nEnter medicine name to delete:");
                scanf("%s",&ch);
                for(i=0;i<choice;i++){
                    if(strcmp(m[i].name,ch)==0){
                        m[i]=m[choice-1];
                        choice--;
                        break;
                    }
                }
                break;

            case 3:
                printf("\nEnter medicine name to update:");
                scanf("%s",&ch);
                for(i=0;i<choice;i++){
                    if(strcmp(m[i].name,ch)==0){
                        printf("\nEnter new medicine name:");
                        scanf("%s",&m[i].name);
                        printf("Enter new medicine price:");
                        scanf("%d",&m[i].price);
                        printf("Enter new medicine quantity:");
                        scanf("%d",&m[i].quantity);
                        break;
                    }
                }
                break;

            case 4:
                printf("\nName\tPrice\tQuantity");
                for(i=0;i<choice;i++){
                    printf("\n%s\t%d\t%d",m[i].name,m[i].price,m[i].quantity);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }
}