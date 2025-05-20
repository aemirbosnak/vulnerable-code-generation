//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct menu {
    char name[20];
    int price;
    int quantity;
};

int main() {

    int i,j;
    char ch;
    int total = 0;
    
    struct menu item[5] = {{"Cappuccino", 100, 0},
                           {"Espresso", 80, 0},
                           {"Latte", 90, 0},
                           {"Mocha", 120, 0},
                           {"Tea", 50, 0}};
  
    printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t  CAFE BILLING SYSTEM");
    printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\tMenu:\n");

    printf("\n\tITEM\t\tPRICE\n");
    for(i=0;i<5;i++) {
        printf("\t%s\t%d\n", item[i].name, item[i].price);
    }

    printf("\n\tWould you like to take order? (y/n): ");
    scanf(" %c", &ch);

    if(ch == 'y') {
        do {
            printf("\n\tEnter item code (1-5): ");
            scanf("%d", &i);
            printf("\tEnter quantity: ");
            scanf("%d", &j);
            item[i-1].quantity = j;
            printf("\n\tAdd more items? (y/n): ");
            scanf(" %c", &ch);
        } while(ch == 'y');
    }

    // Billing

    printf("\n\tBill:\n");
    printf("\n\tITEM\t\tQUANTITY\tPRICE\t  TOTAL\n");
    
    for(i=0;i<5;i++) {
        if(item[i].quantity > 0) {
            printf("\t%s\t\t%d\t\t%d\t  %d\n", item[i].name, item[i].quantity, item[i].price, item[i].price*item[i].quantity);
            total += item[i].price*item[i].quantity;
        }
    }
    printf("\n\t---------------------------------------");
    printf("\n\tTotal\t\t\t\t\t  %d\n\n", total);

    return 0;
}