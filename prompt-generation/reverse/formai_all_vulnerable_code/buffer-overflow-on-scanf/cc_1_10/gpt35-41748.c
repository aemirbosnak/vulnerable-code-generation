//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WAREHOUSE_SIZE 100 //Maximum number of items in warehouse

typedef struct {
    char name[20];
    int quantity;
    float price;
} ITEM;

void print_menu(){
    printf("\n1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Exit\n");
}

int get_menu_choice(){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int add_item(ITEM warehouse[], int count){
    if(count >= MAX_WAREHOUSE_SIZE){
        printf("\nWarehouse is Full. No more items can be stored.\n");
        return count;
    }
    char name[20];
    int quantity;
    float price;
    printf("\nEnter Item Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);
    ITEM new_item = {.quantity=quantity, .price=price};
    strcpy(new_item.name, name);
    warehouse[count] = new_item;
    printf("\nItem Added to Warehouse.\n");
    return count+1;
}

int remove_item(ITEM warehouse[], int count){
    if(count == 0){
        printf("\nWarehouse is Empty. Cannot remove any items.\n");
        return count;
    }
    char name[20];
    printf("\nEnter Item Name to Remove: ");
    scanf("%s", name);
    int index = -1;
    for(int i=0; i<count; i++){
        if(strcmp(warehouse[i].name, name) == 0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\n%s Item not Found.\n", name);
        return count;
    }
    for(int i=index; i<count-1; i++){
        warehouse[i] = warehouse[i+1];
    }
    printf("\n%s Item Removed from Warehouse.\n", name);
    return count-1;
}

void display_items(ITEM warehouse[], int count){
    if(count == 0){
        printf("\nWarehouse is Empty. No items to display.\n");
        return;
    }
    printf("\n%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for(int i=0; i<count; i++){
        printf("%-20s %-10d %-10.2f\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

int main(){
    ITEM warehouse[MAX_WAREHOUSE_SIZE];
    int count = 0;
    int choice;
    do{
        print_menu();
        choice = get_menu_choice();
        switch(choice){
            case 1:
                count = add_item(warehouse, count);
                break;
            case 2:
                count = remove_item(warehouse, count);
                break;
            case 3:
                display_items(warehouse, count);
                break;
            case 4:
                printf("\nExiting Program.\n");
                break;
            default:
                printf("\nInvalid Choice. Try Again.\n");
                break;
        }
    }while(choice != 4);
    return 0;
}