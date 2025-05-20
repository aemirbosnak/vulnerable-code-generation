//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

struct baggage{
    int id;
    char destination[20];
    int status;
};

void main(){
    int i,j,k,count=0,choice;
    struct baggage bag[MAX];
    char ch;
    int flag=0;
    
    printf("\nWelcome to the Airport Baggage Handling System\n");
    printf("---------------------------------------------\n");
    printf("Enter the number of bags you are carrying: ");
    scanf("%d",&count);
    
    for(i=0;i<count;i++){
        printf("\nEnter the Baggage ID: ");
        scanf("%d",&bag[i].id);
        printf("Enter the Destination: ");
        scanf("%s",bag[i].destination);
        bag[i].status=0;
    }
    
    while(1){
        system("clear");
        printf("\nWelcome to the Airport Baggage Handling System\n");
        printf("---------------------------------------------\n");
        printf("1. Track Baggage\n");
        printf("2. Update Baggage Status\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                for(i=0;i<count;i++){
                    if(bag[i].status==0){
                        printf("\nBaggage with ID %d and Destination %s is still in transit.\n",bag[i].id,bag[i].destination);
                    }
                    else if(bag[i].status==1){
                        printf("\nBaggage with ID %d and Destination %s has been delivered.\n",bag[i].id,bag[i].destination);
                    }
                    else{
                        printf("\nBaggage with ID %d and Destination %s has been lost.\n",bag[i].id,bag[i].destination);
                    }
                }
                break;
                
            case 2:
                printf("\nEnter the Baggage ID: ");
                scanf("%d",&k);
                for(i=0;i<count;i++){
                    if(bag[i].id==k){
                        printf("\nEnter the new status (0: In Transit, 1: Delivered, 2: Lost): ");
                        scanf("%d",&bag[i].status);
                        break;
                    }
                }
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}