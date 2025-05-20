//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM_NAME 50
#define MAX_NUM_ITEMS 10

typedef struct item{
    char name[MAX_ITEM_NAME];
    int quantity;
    float price;
}Item;

typedef struct auction_system{
    Item items[MAX_NUM_ITEMS];
    int num_items;
}AuctionSystem;

void print_menu(){
    printf("\n========================================");
    printf("\n1. Add Item");
    printf("\n2. Remove Item");
    printf("\n3. Display All Items");
    printf("\n4. Bid on Item");
    printf("\n5. Exit");
    printf("\n========================================");
}

void add_item(AuctionSystem* system, char* name, int quantity, float price){
    if(system->num_items < MAX_NUM_ITEMS){
        Item item;
        strcpy(item.name, name);
        item.quantity = quantity;
        item.price = price;
        system->items[system->num_items++] = item;
    }
    else{
        printf("\nCannot add item: Auction system is full");
    }
}

void remove_item(AuctionSystem* system, char* name){
    int i, j;
    for(i=0; i<system->num_items; i++){
        if(strcmp(system->items[i].name, name) == 0){
            for(j=i; j<system->num_items-1; j++){
                system->items[j] = system->items[j+1];
            }
            system->num_items--;
            printf("\n%s removed from auction system", name);
            return;
        }
    }
    printf("\n%s not found in auction system", name);
}

void display_items(AuctionSystem* system){
    if(system->num_items == 0){
        printf("\nNo items in auction system");
        return;
    }
    printf("\n%-20s %-10s %-10s", "Name", "Quantity", "Price");
    printf("\n======================================================");
    int i;
    for(i=0; i<system->num_items; i++){
        printf("\n%-20s %-10d %-10.2f", system->items[i].name, system->items[i].quantity, system->items[i].price);
    }
}

void bid_on_item(AuctionSystem* system, char* name, float bid_amount){
    int i;
    for(i=0; i<system->num_items; i++){
        if(strcmp(system->items[i].name, name) == 0){
            if(bid_amount > system->items[i].price){
                printf("\n%s has been sold for %.2f", system->items[i].name, bid_amount);
                remove_item(system, system->items[i].name);
                return;
            }
            else{
                printf("\nBid amount %.2f is too low", bid_amount);
                return;
            }
        }
    }
    printf("\n%s not found in auction system", name);
}

int main(){
    AuctionSystem system;
    system.num_items = 0;
    int choice;
    do{
        print_menu();
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char name[MAX_ITEM_NAME];
                int quantity;
                float price;
                printf("\nEnter item name: ");
                scanf("%s", name);
                printf("\nEnter item quantity: ");
                scanf("%d", &quantity);
                printf("\nEnter item price: ");
                scanf("%f", &price);
                add_item(&system, name, quantity, price);
                break;
            }
            case 2:{
                char name[MAX_ITEM_NAME];
                printf("\nEnter item name: ");
                scanf("%s", name);
                remove_item(&system, name);
                break;
            }
            case 3:{
                display_items(&system);
                break;
            }
            case 4:{
                char name[MAX_ITEM_NAME];
                float bid_amount;
                printf("\nEnter item name: ");
                scanf("%s", name);
                printf("\nEnter bid amount: ");
                scanf("%f", &bid_amount);
                bid_on_item(&system, name, bid_amount);
                break;
            }
            case 5:{
                printf("\nExiting auction system...");
                break;
            }
            default:{
                printf("\nInvalid choice");
                break;
            }
        }
    }while(choice != 5);

    return 0;
}