//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_ITEM_NAME 50

// define structure for item
typedef struct item{
    char name[MAX_ITEM_NAME];
    float price;
    int quantity;
}Item;

// function to add item to bill
void addItem(Item* bill, int* item_count){
    char input[MAX_ITEM_NAME];
    float price;
    int quantity;
    printf("\nEnter item name: ");
    scanf("%s", input);
    printf("Enter item price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    Item new_item;
    strcpy(new_item.name, input);
    new_item.price = price;
    new_item.quantity = quantity;
    bill[*item_count] = new_item;
    *item_count += 1;
}

// function to display bill
void displayBill(Item* bill, int item_count){
    float total = 0;
    printf("\n\nName\t\tQuantity\t\tPrice per unit\t\tTotal\n");
    for(int i = 0; i < item_count; i++){
        printf("%s\t\t%d\t\t\t%.2f\t\t\t%.2f\n", bill[i].name, bill[i].quantity, bill[i].price, bill[i].price*bill[i].quantity);
        total += bill[i].price*bill[i].quantity;
    }
    printf("\nTotal Bill: %.2f\n", total);
}

int main(){
    Item bill[MAX_ITEMS];
    int item_count = 0;
    char again;
    do{
        addItem(bill, &item_count);
        printf("\nAdd another item? (y/n): ");
        scanf(" %c", &again);
    }while(again == 'y' || again == 'Y');
    displayBill(bill, item_count);
    return 0;
}