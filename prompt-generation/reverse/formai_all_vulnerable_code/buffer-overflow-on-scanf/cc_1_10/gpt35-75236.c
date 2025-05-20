//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for the item in the warehouse
struct item{
    char name[20];
    int quantity;
    float price;
};

//Structure for the warehouse 
struct warehouse{
    struct item *items;
    int capacity;
};

//Function to add items to the warehouse
void add_item(struct warehouse *w){
    char name[20];
    int quantity;
    float price;
    int index = -1;
    printf("\nEnter the item name: ");
    scanf("%s", name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &price);
    
    //Checking if the item already exists in the warehouse
    for(int i=0; i<w->capacity; i++){
        if(strcmp(w->items[i].name, name) == 0){
            index = i;
            break;
        }
    }
    //If item already exists, increase the quantity
    if(index != -1){
        w->items[index].quantity += quantity;
    }
    //If item doesn't exist, add the item to the warehouse
    else{
        w->capacity++;
        w->items = (struct item*)realloc(w->items, (w->capacity)*sizeof(struct item));
        strcpy(w->items[w->capacity-1].name, name);
        w->items[w->capacity-1].quantity = quantity;
        w->items[w->capacity-1].price = price;
    }
}

//Function to remove items from the warehouse
void remove_item(struct warehouse *w){
    char name[20];
    int quantity;
    int index = -1;
    printf("\nEnter the name of the item to be removed: ");
    scanf("%s", name);
    
    //Checking if the item exists in the warehouse
    for(int i=0; i<w->capacity; i++){
        if(strcmp(w->items[i].name, name) == 0){
            index = i;
            break;
        }
    }
    //If item exists, remove the quantity
    if(index != -1){
        printf("Enter the quantity to remove: ");
        scanf("%d", &quantity);
        if(quantity <= w->items[index].quantity){
            w->items[index].quantity -= quantity;
            printf("\nRemoved %d %s(s) from the warehouse.\n", quantity, name);
        }
        else{
            printf("\nQuantity entered is greater than the available quantity in the warehouse\n");
        }
    }
    //If item doesn't exist, print message
    else{
        printf("\n%s item not found in the warehouse.\n", name);
    }
}

//Function to display the items in the warehouse
void display_items(struct warehouse *w){
    printf("\n%-20s %10s %10s\n", "Item Name", "Quantity", "Price");
    printf("---------------------------------------------\n");
    for(int i=0; i<w->capacity; i++){
        printf("%-20s %10d %10.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

//Main function to run the program
int main(){
    struct warehouse w;
    w.capacity = 0;
    w.items = (struct item*)malloc(0);
    printf("Warehouse Management System\n");
    printf("---------------------------\n");
    int choice = 0;
    while(choice != 4){
        printf("\n1. Add an item to the warehouse\n2. Remove an item from the warehouse\n3. Display all items in the warehouse\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_item(&w);
                break;
            
            case 2:
                remove_item(&w);
                break;
               
            case 3:
                display_items(&w);
                break;
            
            case 4:
                printf("\nExiting the Warehouse Management System...\n");
                break;
                
            default:
                printf("\nInvalid choice, please choose again.\n");
                break;
        }
    }
    return 0;
}