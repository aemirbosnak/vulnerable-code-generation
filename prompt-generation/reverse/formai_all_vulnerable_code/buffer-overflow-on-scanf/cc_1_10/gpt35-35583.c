//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char itemName[MAX];
    int quantity;
    float price;
} Menu;

Menu menuList[7] = {
    {"Coffee", 0, 1.50},
    {"Tea", 0, 1.00},
    {"Sandwich", 0, 3.00},
    {"Cake", 0, 2.50},
    {"Juice", 0, 2.00},
    {"Burger", 0, 4.00},
    {"Pizza", 0, 5.00}
};

int main(){
    int choice, quantity, moreOrder;
    int i = 0, j;
    float totalCost = 0.0;

    printf("\n\nWelcome to ABC Cafe!\n");

    do{
        printf("\nHere's the Menu:\n");

        for(j = 0; j < 7; j++){
            printf("%d. %s - $%.2f\n", (j+1), menuList[j].itemName, menuList[j].price);
        }

        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 7){
            printf("Invalid Choice! Please choose again.\n");
            continue;
        }

        choice -= 1;

        printf("\nEnter Quantity: ");
        scanf("%d", &quantity);

        menuList[choice].quantity += quantity;
        totalCost += (menuList[choice].price * quantity);

        printf("\nDo you want to Order More? (1 = Yes, 0 = No) ");
        scanf("%d", &moreOrder);
    }while(moreOrder != 0);

    printf("\n\n\t\t----- Your Order Details -----\n\n");
    printf("Item Name \t\t Quantity \t Price \t Total\n");

    for(i = 0; i < 7; i++){
        if(menuList[i].quantity != 0){
            printf("%s \t\t %d \t\t $%.2f \t $%.2f\n", menuList[i].itemName, menuList[i].quantity, menuList[i].price, (menuList[i].quantity * menuList[i].price));
        }
    }

    printf("\n\n\t\t----- Total Cost: $%.2f -----\n", totalCost);

    printf("\n\nThank you for Visiting ABC Cafe! Have a Great Day :)\n");

    return 0;
}