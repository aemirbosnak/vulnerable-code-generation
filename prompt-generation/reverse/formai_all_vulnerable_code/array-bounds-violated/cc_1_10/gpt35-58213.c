//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    int price;
} menu;

menu items[10] = {
    {"Cappuccino", 150},
    {"Latte", 120},
    {"Espresso", 90},
    {"Mocha", 170},
    {"Americano", 100},
    {"Hot Chocolate", 140},
    {"Tea", 80},
    {"Iced Coffee", 130},
    {"Iced Tea", 100},
    {"Smoothie", 200}
};

int main(){
    int choice, quantity;
    int total = 0; 
    char ans;

    printf("\n\n\t\tWelcome to our C Cafe Billing System!\n");

    do{
        printf("\n\n\t\t===== MENU =====\n");
        printf("\t\t| No. |  Name                 | Price |");
        printf("\n\t\t|===================================|");
        printf("\n");

        for(int i = 0; i < 10; i++){
            printf("\t\t| [%d] | %-20s | %5d |\n", i+1, items[i].name, items[i].price);
        }

        printf("\n\t\tWhat would you like to order? (Enter number) ");

        scanf("%d", &choice);

        printf("\n\t\tHow many would you like to order? ");

        scanf("%d", &quantity);

        total += items[choice-1].price * quantity;

        printf("\n\t\tYou have ordered %d %s(s).", quantity, items[choice-1].name);
        printf("\n\t\tYour total so far is: Php %d.", total);

        printf("\n\t\tWould you like to order again? (y/n) ");

        scanf(" %c", &ans);

    }while(ans == 'y' || ans == 'Y');

    printf("\n\n\t\tThank you for ordering from our C Cafe Billing System!\n");
    printf("\t\tYour total bill is: Php %d.", total);

    return 0;
}