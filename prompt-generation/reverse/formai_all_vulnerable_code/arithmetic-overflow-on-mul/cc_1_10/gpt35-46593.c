//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include<stdio.h>

int main(){

    int choice=0,quantity=0,bill=0,totalBill=0,discount=0;

    printf("********Welcome to our Cafe********\n");

    while(choice!=4){

        printf("1. Tea - Rs.10\n2. Coffee - Rs.15\n3. Cold Drink - Rs.20\n4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                bill=10*quantity;
                printf("Your bill for Tea is Rs.%d\n",bill);
                totalBill+=bill;
                break;

            case 2:
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                bill=15*quantity;
                printf("Your bill for Coffee is Rs.%d\n",bill);
                totalBill+=bill;
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                bill=20*quantity;
                printf("Your bill for Cold Drink is Rs.%d\n",bill);
                totalBill+=bill;
                break;

            case 4:
                printf("Thank you for visiting our Cafe!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    }

    if(totalBill>500){
        discount=50;
    }
    else if(totalBill>300){
        discount=30;
    }
    else if(totalBill>100){
        discount=10;
    }

    printf("\n\n********Bill Details********\n");
    printf("Total Bill: %d\n",totalBill);
    printf("Discount: %d\n",discount);
    printf("Net Bill: %d\n",totalBill-discount);

    return 0;

}