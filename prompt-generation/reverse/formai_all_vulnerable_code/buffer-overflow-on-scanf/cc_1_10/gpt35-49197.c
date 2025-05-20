//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

//Structure for Menu Items
struct MenuItem {
    int itemId; //Unique ID for each item
    char itemName[100]; //Name of the item
    float itemPrice; //Price of the item
    int itemQuantity; //Quantity of the item in stock
};

//Function to display the menu
void displayMenu(struct MenuItem menu[], int sizeOfMenu) {
    printf("Menu\n");
    printf("---------------\n");
    for(int i=0; i<sizeOfMenu; i++) {
        printf("%d - %s - $%0.2f\n", menu[i].itemId, menu[i].itemName, menu[i].itemPrice);
    }
    printf("---------------\n");
}

//Function to add an item to the menu
void addItemToMenu(struct MenuItem menu[], int sizeOfMenu) {
    printf("Enter Item ID: ");
    scanf("%d", &menu[sizeOfMenu].itemId);
    printf("Enter Item Name: ");
    scanf("%s", menu[sizeOfMenu].itemName);
    printf("Enter Item Price: $");
    scanf("%f", &menu[sizeOfMenu].itemPrice);
    printf("Enter Item Quantity in Stock: ");
    scanf("%d", &menu[sizeOfMenu].itemQuantity);
}

//Function to update the quantity of an item in stock
void updateQuantity(struct MenuItem menu[], int sizeOfMenu, int itemId) {
    int i;
    for(i=0; i<sizeOfMenu; i++) {
        if(menu[i].itemId == itemId) {
            printf("Enter the new quantity for %s: ", menu[i].itemName);
            scanf("%d", &menu[i].itemQuantity);
            printf("Quantity for %s has been updated to %d\n", menu[i].itemName, menu[i].itemQuantity);
            break;
        }
    }
    if(i == sizeOfMenu) {
        printf("Item not found in the menu\n");
    }
}

//Function to calculate the total bill
float calculateBill(struct MenuItem menu[], int sizeOfMenu, int order[], int orderSize) {
    float totalBill = 0;
    for(int i=0; i<orderSize; i++) {
        int itemId = order[i];
        int quantity = 1;
        int j;
        for(j=0; j<sizeOfMenu; j++) {
            if(menu[j].itemId == itemId) {
                if(menu[j].itemQuantity >= quantity) {
                    //Item is available
                    menu[j].itemQuantity -= quantity; //Reduce the quantity from stock
                    totalBill += menu[j].itemPrice * quantity; //Add the price to the total bill
                    break;
                }
                else {
                    //Item is out of stock
                    printf("%s is out of stock\n", menu[j].itemName);
                    break;
                }
            }
        }
        if(j == sizeOfMenu) {
            //Item not found in the menu
            printf("Item not found in the menu\n");
        }
    }
    return totalBill;
}

int main() {
    struct MenuItem menu[100];
    int sizeOfMenu = 0;
    int choice;
    int order[100];
    int orderSize = 0;
    float billAmount;
    
    while(1) {
        printf("\nMenu\n");
        printf("1. Display Menu\n");
        printf("2. Add Item to Menu\n");
        printf("3. Update Quantity of Item in Stock\n");
        printf("4. Take Order\n");
        printf("5. Generate Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: //Display Menu
                displayMenu(menu, sizeOfMenu);
                break;
                
            case 2: //Add Item to Menu
                addItemToMenu(menu, sizeOfMenu);
                sizeOfMenu++;
                break;
                
            case 3: //Update Quantity of Item in Stock
                printf("Enter Item ID: ");
                int itemId;
                scanf("%d", &itemId);
                updateQuantity(menu, sizeOfMenu, itemId);
                break;
                
            case 4: //Take Order
                printf("Enter Item ID (-1 to end): ");
                int item;
                scanf("%d", &item);
                while(item != -1) {
                    order[orderSize] = item;
                    orderSize++;
                    printf("Enter Item ID (-1 to end): ");
                    scanf("%d", &item);
                }
                break;
                
            case 5: //Generate Bill
                billAmount = calculateBill(menu, sizeOfMenu, order, orderSize);
                printf("Total Bill: $%.2f\n", billAmount);
                orderSize = 0;
                break;
                
            case 6: //Exit
                exit(0);
        }
    }
    return 0;
}