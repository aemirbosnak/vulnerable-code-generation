//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Bill;

void add_item(Bill *bill, Item *item) {
    bill->items[bill->num_items] = *item;
    bill->num_items++;
    bill->total_price += item->price * item->quantity;
}

void print_bill(Bill *bill) {
    printf("=============================================================\n");
    printf("                         Cafe Billing System\n");
    printf("=============================================================\n");
    printf("Item Name\tQuantity\tPrice\tTotal Price\n");
    printf("-------------------------------------------------------------\n");
    
    for(int i=0; i<bill->num_items; i++){
        Item item=bill->items[i];
        printf("%s\t%d\t%.2f\t%.2f\n", item.name, item.quantity, item.price, item.price*item.quantity);
    }
    
    printf("-------------------------------------------------------------\n");
    printf("Total Price: %.2f\n", bill->total_price);
    printf("=============================================================\n");
}

int main() {
    Bill bill;
    bill.num_items = 0;
    bill.total_price = 0;
    
    while(1) {
        Item item;
        printf("Enter Item Name: ");
        scanf("%s", item.name);
        if(strcmp(item.name, "quit") == 0){
            break;
        }
        printf("Enter Quantity: ");
        scanf("%d", &item.quantity);
        printf("Enter Price: ");
        scanf("%f", &item.price);
        add_item(&bill, &item);
    }

    print_bill(&bill);
    
    return 0;
}