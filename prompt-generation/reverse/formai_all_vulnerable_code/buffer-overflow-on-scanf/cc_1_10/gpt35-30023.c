//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char name[30];
    int qty;
    float price;
};

struct Item menu[] = {
    {"Dosa", 5, 20.0},
    {"Idli", 10, 10.0},
    {"Vada", 8, 15.0},
    {"Tea", 20, 10.0},
    {"Coffee", 15, 15.0},
    {"Burger", 7, 25.0},
    {"Pizza", 4, 40.0},
    {"French Fries", 12, 20.0},
    {"Garlic Bread", 10, 25.0},
    {"Chicken Sandwich", 6, 30.0},
};

void displayMenu(){
    printf("**********************\n");
    printf("    Welcome to My Cafe\n");
    printf("**********************\n");
    printf("Items\t\tQty\tPrice\n");
    for(int i=0; i<10; i++){
        printf("%s\t\t%d\tRs.%.2f\n", menu[i].name, menu[i].qty, menu[i].price);
    }
}

float calculatePrice(int itemIndex, int qty){
    return menu[itemIndex].price * qty;
}

void printBill(int itemIndex, int qty){
    printf("\n**********************\n");
    printf("         Bill\n");
    printf("**********************\n");
    printf("Item\tQty\tPrice\n");
    printf("%s\t%d\tRs.%.2f\n", menu[itemIndex].name, qty, calculatePrice(itemIndex, qty));
    printf("\nThank you for visiting us!\n");
}

int main(){
    int choice, qty;

    displayMenu();

    printf("\nWhat would you like to order? (Enter menu item number): ");
    scanf("%d", &choice);

    printf("\nHow many would you like to order? ");
    scanf("%d", &qty);

    if(qty > menu[choice-1].qty){
        printf("\nSorry, we only have %d quantity of %s in stock.\n", menu[choice-1].qty, menu[choice-1].name);
    } else {
        menu[choice-1].qty -= qty;
        printBill(choice-1, qty);
    }
    return 0;
}