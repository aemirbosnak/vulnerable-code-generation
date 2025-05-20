//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char item_name[100];
    float price;
    int quantity;
} item;

void generate_bill(item *order, int n);
float calculate_total(item *order, int n);

int main(){
    printf("Welcome to C Cafe!\n");
    printf("------------------\n");

    // Create an array of items
    item cafe_menu[] = {
        {"Coffee", 2.50, 0},
        {"Tea", 1.50, 0},
        {"Hot chocolate", 3.00, 0},
        {"Croissant", 2.00, 0},
        {"Bagel with cream cheese", 2.50, 0},
        {"Muffin", 2.00, 0},
        {"Fruit salad", 3.50, 0}
    };

    int n = sizeof(cafe_menu)/sizeof(cafe_menu[0]);

    // Print the menu
    printf("\nMenu\n");
    printf("----\n");
    for(int i=0; i<n; i++){
        printf("%d. %s - $%.2f\n", i+1, cafe_menu[i].item_name, cafe_menu[i].price);
    }

    // Get the order from the customer
    int option;
    do{
        printf("\nEnter the option number of the item you want to order(0 to generate the bill): ");
        scanf("%d", &option);
        if(option<0 || option>n){
            printf("Invalid option! Please try again.\n");
        } else if(option!=0) {
            printf("Enter the quantity of the item: ");
            scanf("%d", &cafe_menu[option-1].quantity);
        }
    } while(option!=0);

    // Generate the bill
    generate_bill(cafe_menu, n);

    return 0;
}

void generate_bill(item *order, int n){
    printf("\n\nC Cafe Bill\n");
    printf("-------------\n");
    printf("Item name\tPrice\tQuantity\tTotal\n");
    printf("---------\t-----\t--------\t-----\n");

    float total = calculate_total(order, n);

    for(int i=0; i<n; i++){
        if(order[i].quantity!=0){
            printf("%s\t\t$%.2f\t%d\t\t$%.2f\n", order[i].item_name, order[i].price, order[i].quantity, order[i].price*order[i].quantity);
        }
    }

    printf("\nTotal: $%.2f", total);
}

float calculate_total(item *order, int n){
    float total=0;

    for(int i=0; i<n; i++){
        total += order[i].price*order[i].quantity;
    }

    return total;
}