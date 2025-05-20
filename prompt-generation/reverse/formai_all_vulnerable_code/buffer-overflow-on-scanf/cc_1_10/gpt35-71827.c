//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include<stdio.h>
#include<stdlib.h>

//defining the struct for bill
struct bill{
    char item_name[100];
    int price;
    int quantity;
};

//function to calculate the total bill amount
int calculateTotal(struct bill* items, int total_items){
    int total = 0;
    for(int i=0; i<total_items; i++){
        total += items[i].price * items[i].quantity;
    }
    return total;
}

int main(){
    int total_breakfast_items, total_lunch_items, total_dinner_items;
    printf("Welcome to Zombieland's Cafe Billing System!\n");
    printf("==============================================\n");
    printf("Enter the number of Breakfast items: ");
    scanf("%d", &total_breakfast_items);

    struct bill breakfast_items[total_breakfast_items];

    for(int i=0; i<total_breakfast_items; i++){
        printf("\nEnter the item name for Breakfast item %d: ", i+1);
        scanf("%s", breakfast_items[i].item_name);
        printf("Enter the item quantity for Breakfast item %d: ", i+1);
        scanf("%d", &breakfast_items[i].quantity);
        printf("Enter the item price for Breakfast item %d: ", i+1);
        scanf("%d", &breakfast_items[i].price);
    }

    printf("\nEnter the number of Lunch items: ");
    scanf("%d", &total_lunch_items);

    struct bill lunch_items[total_lunch_items];

    for(int i=0; i<total_lunch_items; i++){
        printf("\nEnter the item name for Lunch item %d: ", i+1);
        scanf("%s", lunch_items[i].item_name);
        printf("Enter the item quantity for Lunch item %d: ", i+1);
        scanf("%d", &lunch_items[i].quantity);
        printf("Enter the item price for Lunch item %d: ", i+1);
        scanf("%d", &lunch_items[i].price);
    }

    printf("\nEnter the number of Dinner items: ");
    scanf("%d", &total_dinner_items);

    struct bill dinner_items[total_dinner_items];

    for(int i=0; i<total_dinner_items; i++){
        printf("\nEnter the item name for Dinner item %d: ", i+1);
        scanf("%s", dinner_items[i].item_name);
        printf("Enter the item quantity for Dinner item %d: ", i+1);
        scanf("%d", &dinner_items[i].quantity);
        printf("Enter the item price for Dinner item %d: ", i+1);
        scanf("%d", &dinner_items[i].price);
    }

    int total_bill = calculateTotal(breakfast_items, total_breakfast_items) + calculateTotal(lunch_items, total_lunch_items) + calculateTotal(dinner_items, total_dinner_items);

    printf("\n\n==========================================\n");
    printf("\t\t\tBILL\n");
    printf("==========================================\n");
    printf("Item Name\t\tQuantity\t\tPrice\n");

    for(int i=0; i<total_breakfast_items; i++){
        printf("%s\t\t\t%d\t\t\t%d\n", breakfast_items[i].item_name, breakfast_items[i].quantity, breakfast_items[i].price);
    }

    for(int i=0; i<total_lunch_items; i++){
        printf("%s\t\t\t%d\t\t\t%d\n", lunch_items[i].item_name, lunch_items[i].quantity, lunch_items[i].price);
    }

    for(int i=0; i<total_dinner_items; i++){
        printf("%s\t\t\t%d\t\t\t%d\n", dinner_items[i].item_name, dinner_items[i].quantity, dinner_items[i].price);
    }

    printf("\n\n==========================================\n");
    printf("\t\t\tTotal Bill: %d\n", total_bill);
    printf("==========================================\n");

    printf("\n\nThank you for dining with us in our undead-friendly cafe. Stay Alive.\n");

    return 0;
}