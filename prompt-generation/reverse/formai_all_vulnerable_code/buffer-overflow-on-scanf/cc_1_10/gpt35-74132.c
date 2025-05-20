//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 50
#define MAX_NAME 50
#define MAX_TYPE 50

typedef struct{
    char name[MAX_NAME];
    char type[MAX_TYPE];
    int quantity;
    float price;
}Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void displayInventory(){
    printf("--------------------------------------\n");
    printf("|   Item Name  |  Type  | Quantity  | Price |\n");
    printf("--------------------------------------\n");

    for(int i=0; i<itemCount; i++){
        printf("| %12s | %6s | %8d | $%5.2f |\n", inventory[i].name, inventory[i].type, inventory[i].quantity, inventory[i].price);
    }

    printf("--------------------------------------\n");
}

void addItem(){
    Item newItem;

    printf("Enter item name: ");
    fgets(newItem.name, MAX_NAME, stdin);

    printf("Enter item type: ");
    fgets(newItem.type, MAX_TYPE, stdin);

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;

    printf("\nItem added to inventory!\n\n");
}

void sellItem(){
    char itemName[MAX_NAME];
    int itemIndex = -1;

    printf("Enter item name to sell: ");
    fgets(itemName, MAX_NAME, stdin);

    for(int i=0; i<itemCount; i++){
        if(strcmp(itemName, inventory[i].name) == 0){
            itemIndex = i;
            break;
        }
    }

    if(itemIndex >= 0){
        int sellQuantity;

        printf("Enter quantity to sell: ");
        scanf("%d", &sellQuantity);

        if(sellQuantity <= inventory[itemIndex].quantity){
            inventory[itemIndex].quantity -= sellQuantity;

            float totalPrice = sellQuantity * inventory[itemIndex].price;

            printf("\nSold %d %s for $%.2f.\n\n", sellQuantity, inventory[itemIndex].name, totalPrice);
        }
        else{
            printf("\nNot enough %s in stock!\n\n", inventory[itemIndex].name);
        }
    }
    else{
        printf("\n%s not found in inventory!\n\n", itemName);
    }
}

void menu(){
    char choice;

    printf("*********** CyberPunk Inventory System *********\n\n");
    printf("1. Display Inventory\n");
    printf("2. Add Item to Inventory\n");
    printf("3. Sell Item from Inventory\n");
    printf("4. Exit\n\n");

    printf("Enter choice: ");
    scanf(" %c", &choice);

    switch(choice){
        case '1':
            displayInventory();
            menu();
            break;
        case '2':
            getchar();
            addItem();
            menu();
            break;
        case '3':
            getchar();
            sellItem();
            menu();
            break;
        case '4':
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Choose again.\n");
            menu();
    }
}

int main(){
    menu();

    return 0;
}