//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_ITEMS 20
#define MAX_ITEM_NAME_LENGTH 30
#define MAX_QUANTITY 100
#define MAX_PRICE 9999.99

//structure for item
struct MenuItem{
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
    int quantity;
};

//function prototypes
void displayMenu();
void addItem(struct MenuItem[], int*);
void removeItem(struct MenuItem[], int*);
void bill(struct MenuItem[], int*);

int main(){
    struct MenuItem menu[MAX_ITEMS]; //array of menu items
    int numItems = 0; //number of menu items initially 0

    int choice;
    do{
        printf("\n\n------- Cafe Billing System -------\n");
        printf("1. Display Menu\n");
        printf("2. Add Item to Menu\n");
        printf("3. Remove Item from Menu\n");
        printf("4. Generate Bill\n");
        printf("5. Quit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: displayMenu(menu, &numItems); break;
            case 2: addItem(menu, &numItems); break;
            case 3: removeItem(menu, &numItems); break;
            case 4: bill(menu, &numItems); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }while(choice != 5);

    return 0;
}

//function to display menu
void displayMenu(struct MenuItem menu[], int *numItems){
    printf("\n\n------- Menu -------\n");
    for(int i=0;i<*numItems;i++){
        printf("%d. %s\t$%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("---------------------\n");
}

//function to add item to menu
void addItem(struct MenuItem menu[], int *numItems){
    if(*numItems >= MAX_ITEMS){
        printf("Menu is full. Cannot add more items.\n");
        return;
    }

    char name[MAX_ITEM_NAME_LENGTH];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter price: $");
    scanf("%f", &price);
    if(price > MAX_PRICE){
        printf("Invalid price. Maximum price allowed is $%.2f\n", MAX_PRICE);
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if(quantity > MAX_QUANTITY){
        printf("Invalid quantity. Maximum quantity allowed is %d\n", MAX_QUANTITY);
        return;
    }

    strcpy(menu[*numItems].name, name);
    menu[*numItems].price = price;
    menu[*numItems].quantity = quantity;

    (*numItems)++;

    printf("%s added to the menu!\n", name);
}

//function to remove item from menu
void removeItem(struct MenuItem menu[], int *numItems){
    if(*numItems == 0){
        printf("Menu is empty. No item to remove.\n");
        return;
    }

    int index;
    displayMenu(menu, numItems);
    printf("Enter the item number to remove: ");
    scanf("%d", &index);
    if(index < 1 || index > *numItems){
        printf("Invalid item number. Try again.\n");
        return;
    }

    printf("%s removed from the menu!\n", menu[index-1].name);

    //shift items to left and reduce numItems
    for(int i=index-1;i<*numItems-1;i++){
        strcpy(menu[i].name, menu[i+1].name);
        menu[i].price = menu[i+1].price;
        menu[i].quantity = menu[i+1].quantity;
    }
    
    (*numItems)--;
}

//function to calculate and display bill
void bill(struct MenuItem menu[], int *numItems){
    if(*numItems == 0){
        printf("Menu is empty. Cannot generate bill.\n");
        return;
    }

    int numOrders[MAX_ITEMS] = {}; //initialize to 0
    int index;
    char choice;

    do{
        printf("\n\n------- Order -------\n");
        displayMenu(menu, numItems);
        printf("Enter the item number: ");
        scanf("%d", &index);
        if(index < 1 || index > *numItems){
            printf("Invalid item number. Try again.\n");
            continue;
        }

        printf("How many %s do you want to order? (max %d): ", menu[index-1].name, menu[index-1].quantity);
        scanf("%d", &numOrders[index-1]);
        if(numOrders[index-1] > menu[index-1].quantity){
            printf("Sorry, we have only %d %s left.\n", menu[index-1].quantity, menu[index-1].name);
            numOrders[index-1] = 0;
            continue;
        }

        printf("Do you want to order something else? (Y/N): ");
        scanf(" %c", &choice);
    }while(choice == 'Y' || choice == 'y');

    //display bill
    float total = 0;
    printf("\n\n------- Bill -------\n");
    printf("%-30s %-10s %s\n", "Item", "Quantity", "Total");
    for(int i=0;i<*numItems;i++){
        if(numOrders[i] > 0){
            printf("%-30s %-10d $%.2f\n", menu[i].name, numOrders[i], menu[i].price * numOrders[i]);
            total += menu[i].price * numOrders[i];
            menu[i].quantity -= numOrders[i];
        }
    }
    printf("\nGrand Total: $%.2f\n", total);
}