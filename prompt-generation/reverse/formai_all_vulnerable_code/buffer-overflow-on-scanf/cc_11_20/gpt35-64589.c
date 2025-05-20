//FormAI DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest{
    char name[50];
    int room_no;
    int stay_duration;
    float bill;
};

typedef struct guest guest;

void main(){
    guest g[100];
    int n,i,choice, room,flag=0;
    char name[50];
    float bill;

    //Taking Inputs
    printf("Enter the number of guests: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nEnter the name of guest %d: ", i+1);
        scanf("%s",g[i].name);
        g[i].room_no=i+1;
        printf("Enter the duration of stay (in days) for guest %d: ", i+1);
        scanf("%d",&g[i].stay_duration);
        g[i].bill=0;
    }

    //Menu Driven Program
    do{
        printf("\n\n******* Hotel Management System *******");
        printf("\n\n1. Display Room Info");
        printf("\n2. Calculate Bill");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                //Display Guest Info
                printf("\nEnter the room number: ");
                scanf("%d",&room);
                for(i=0;i<n;i++){
                    if(g[i].room_no==room){
                        printf("\nName: %s",g[i].name);
                        printf("\nStay Duration: %d",g[i].stay_duration);
                        printf("\nBill: %.2f",g[i].bill);
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    printf("Room number not found!");
                }
                flag=0;
                break;

            case 2:
                //Calculate Bill
                printf("\nEnter the name of guest: ");
                scanf("%s",name);
                for(i=0;i<n;i++){
                    if(strcmp(g[i].name,name)==0){
                        printf("\nEnter the room number: ");
                        scanf("%d",&room);
                        if(g[i].room_no==room){
                            g[i].bill=(float)(g[i].stay_duration*2000);
                            printf("\nBill Amount: %.2f",g[i].bill);
                            break;
                        }
                        else{
                            printf("\nInvalid Room Number!");
                            break;
                        }
                    }
                }
                if(i==n){
                    printf("\nGuest not found!");
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid Choice!");
                break;
        }

    }while(choice!=3);

}