//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include<stdio.h>
#include<string.h>

int main(){
    char name[30]; //string to store customer's name
    int items, choice, total=0; //items: number of items ordered, choice: menu option selected, total: total bill amount
    printf("Welcome to The Immersive Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s",name);
    printf("\nHello %s! Here's our menu:\n",name);
    printf("1. Coffee - Rs. 50\n");
    printf("2. Tea - Rs. 30\n");
    printf("3. Sandwich - Rs. 100\n");
    printf("4. Burger - Rs. 150\n");
    printf("5. Pizza - Rs. 200\n");
    printf("\nHow many items would you like to order, %s? ",name);
    scanf("%d",&items);
    int ordered_items[items]; //array to store user's ordered items
    for(int i=0;i<items;i++){
        printf("Enter the menu number for item %d: ",i+1);
        scanf("%d",&choice);
        ordered_items[i]=choice;
        switch(choice){
            case 1:
                total+=50;
                break;
            case 2:
                total+=30;
                break;
            case 3:
                total+=100;
                break;
            case 4:
                total+=150;
                break;
            case 5:
                total+=200;
                break;
            default:
                printf("Invalid option selected!\n");
                i--; //decrementing loop variable to re-ask for input
        }
    }
    printf("\nYour order summary:\n");
    for(int i=0;i<items;i++){
        switch(ordered_items[i]){
            case 1:
                printf("Coffee - Rs. 50\n");
                break;
            case 2:
                printf("Tea - Rs. 30\n");
                break;
            case 3:
                printf("Sandwich - Rs. 100\n");
                break;
            case 4:
                printf("Burger - Rs. 150\n");
                break;
            case 5:
                printf("Pizza - Rs. 200\n");
                break;
        }
    }
    printf("\nYour total bill amount is Rs. %d. Thank you for visiting The Immersive Cafe, %s! Come again soon!\n",total,name);
    return 0;
}