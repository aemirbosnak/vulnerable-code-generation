//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char items[10][20] = {"Burger", "Pizza", "Sandwich", "Hotdog", "Pasta", "Fries","Coke","Pepsi","Iced Tea","Water"};
    int prices[10] = {120, 150, 100, 90, 200, 70, 30, 35, 40, 20}; 
    int quantity[10] = {0,0,0,0,0,0,0,0,0,0};
    int choice, total=0, index, quan, i;

    printf("\n\n\t\tWelcome to Cafe Billing System\n\n");

    while(choice != 3){
        printf("Choose an option from the following:\n");
        printf("1. Order Items\n");
        printf("2. Generate Bill\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n\n\t\tMenu\n\n");
                printf("SN.\tItems\t\t\tPrice\n");
                for(i=0; i<10; i++){
                    printf("%d.\t%s\t%d\n",i+1, items[i], prices[i]);
                }
                printf("Enter the SN of item you want to order:");
                scanf("%d", &index);
                printf("Enter quantity:");
                scanf("%d", &quan);
                quantity[index-1] += quan;
                break;

            case 2:
                printf("\n\n\t\tBill\n\n");
                printf("SN.\tItems\t\t\tQuantity\tPrice\n");
                for(i=0; i<10; i++){
                    if(quantity[i]!=0){
                        printf("%d.\t%s\t%d\t\t%d\n",i+1, items[i], quantity[i], quantity[i]*prices[i]);
                        total += quantity[i]*prices[i];
                    }
                }
                printf("Total Bill = %d\n", total);
                break;

            case 3:
                printf("\n\n\tThank you for using Cafe Billing System\n\n");
                break;

            default:
                printf("Invalid Input!\n");
                break;
        }
    }
    return 0;
}