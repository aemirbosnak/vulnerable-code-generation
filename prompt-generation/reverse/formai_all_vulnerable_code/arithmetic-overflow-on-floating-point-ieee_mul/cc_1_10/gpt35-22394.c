//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
    char name[20];
    int quantity;
    float price;
};

struct warehouse{
    struct item items[100];
    int itemCount;
    float totalInventoryValue;
};

void addItem(struct warehouse *w, char itemName[], int quantity, float price){
    strcpy(w->items[w->itemCount].name, itemName);
    w->items[w->itemCount].quantity = quantity;
    w->items[w->itemCount].price = price;
    w->itemCount++;
    w->totalInventoryValue += quantity * price;
}

void removeItem(struct warehouse *w, char itemName[]){
    int i, itemFound = 0;
    for(i=0;i<w->itemCount;i++){
        if(strcmp(w->items[i].name, itemName) == 0){
            itemFound = 1;
            w->totalInventoryValue -= w->items[i].quantity * w->items[i].price;
            w->items[i] = w->items[w->itemCount-1];
            w->itemCount--;
            break;
        }
    }
    if(!itemFound){
        printf("\nItem not found in warehouse\n");
    }
    else{
        printf("\n%s removed from warehouse successfully\n", itemName);
    }
}

void displayWarehouse(struct warehouse *w){
    int i;
    printf("\n--------------------------\n");
    printf("Warehouse Inventory:");
    printf("\n--------------------------\n");
    printf("%-20s%-20s%-20s", "Item Name", "Quantity", "Price");
    printf("\n--------------------------\n");
    for(i=0;i<w->itemCount;i++){
        printf("%-20s%-20d%-20.2f", w->items[i].name, w->items[i].quantity, w->items[i].price);
        printf("\n");
    }
    printf("--------------------------");
    printf("\nTotal Inventory Value: %.2f", w->totalInventoryValue);
    printf("\n--------------------------\n");
}

int main(){
    struct warehouse wh = {0};
    int choice, i, quantity;
    float price;
    char itemName[20];
    do{
        printf("\nWarehouse Management System\n");
        printf("--------------------------\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Warehouse Inventory\n");
        printf("4. Quit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Item Name: ");
                scanf("%s", itemName);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                addItem(&wh, itemName, quantity, price);
                break;
            case 2:
                printf("\nEnter Item Name: ");
                scanf("%s", itemName);
                removeItem(&wh, itemName);
                break;
            case 3:
                displayWarehouse(&wh);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }while(choice != 4);

    return 0;
}