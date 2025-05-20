//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCK 100 // Maximum stock limit of warehouse

typedef struct{
    char product_name[20];
    int quantity;
}Stock;

Stock stock[MAX_STOCK]; // Warehouse stock array

int total_items = 0; // Total items present in the warehouse

void add_item(Stock new_item){
    if(total_items < MAX_STOCK){
        stock[total_items] = new_item; // Adding item to warehouse stock
        total_items++;
        printf("%s added successfully\n", new_item.product_name);
    }
    else{
        printf("Warehouse is full!\n");
    }
}

void remove_item(int index){
    if(index < total_items){
        for(int i=index; i<total_items-1; i++){
            stock[i] = stock[i+1]; // shifting items in the stock array
        }
        total_items--;
        printf("Item removed successfully\n");
    }
    else{
        printf("Invalid index\n");
    }
}

void display_stock(){
    printf("Product\t\tQuantity\n");
    for(int i=0; i<total_items; i++){
        printf("%s\t\t%d\n", stock[i].product_name, stock[i].quantity);
    }
}

int main(){
    int choice;
    Stock new_item;

    printf("Welcome to our Warehouse Management System.\n");

    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Add item to warehouse.\n");
        printf("2. Remove item from warehouse.\n");
        printf("3. Display warehouse stock.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter product name: ");
                scanf("%s", new_item.product_name);
                printf("Enter quantity: ");
                scanf("%d", &new_item.quantity);
                add_item(new_item);
                break;
            case 2:
                printf("Enter index to remove item: ");
                scanf("%d", &choice);
                remove_item(choice);
                break;
            case 3:
                display_stock();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}