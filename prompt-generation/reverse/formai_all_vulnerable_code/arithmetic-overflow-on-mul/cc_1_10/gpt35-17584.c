//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Menu{
    char name[50];
    int price;
};

struct Order{
    char item[50];
    int quantity;
};

int main(){
    struct Menu menu[10] = {{"Coffee", 150},{"Tea", 100},{"Sandwich", 120},{"Burger", 180},{"French Fries", 80},{"Pancake", 200},{"Waffle", 220},{"Pasta", 250},{"Pizza", 350},{"Ice Cream", 100}};
    struct Order order[10];
    int choice;
    int total = 0;
    int i = 0;
    int j = 0;
    time_t t;
    time(&t);

    printf("\t\t\tC Cafe Billing System\n");
    printf("\t\t\t------------------------\n\n");
    printf("\t\t\t     %s", ctime(&t));

    printf("\nMenu\n\n");
    for(i = 0; i < 10; i++){
        printf("%d. %s - %d\n", i+1, menu[i].name, menu[i].price);
    }

    printf("\nPlease enter your order (item number followed by quantity)\n");
    printf("Enter 0 to finish ordering\n");

    i = 0;
    do{
        printf("Order %d: ", i+1);
        scanf("%d", &choice);

        if(choice < 1 || choice > 10)
            break;

        strcpy(order[i].item, menu[choice-1].name);
        scanf("%d", &order[i].quantity);

        i++;
    }while(choice != 0);

    printf("\n\n     C Cafe\n");
    printf("    ---------------------\n");
    printf("     Order Summary\n\n");
    printf("Item\t\tQuantity\tPrice\n");

    for(j = 0; j < i; j++){
        printf("%s\t\t%d\t\t%d\n", order[j].item, order[j].quantity, order[j].quantity * menu[choice-1].price);
        total += order[j].quantity * menu[choice-1].price;
    }

    printf("\n\t\tTotal: %d\n", total);

    return 0;
}