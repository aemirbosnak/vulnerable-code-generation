//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold the details of each item in the menu
typedef struct menuItem {
    char itemName[50];
    int price;
    int quantity;
} menuItem;

//Global variables declaration
menuItem menu[10]; //Array to hold the menu
int total;
int itemCount = 0; //Variable to keep count of the number of items in the menu

//Function to add an item to the menu
void addItemToMenu(char itemName[], int price) {
    //Create a new item
    menuItem newItem;
    strcpy(newItem.itemName, itemName);
    newItem.price = price;
    newItem.quantity = 0;
    
    menu[itemCount] = newItem; //Add the item to the menu array
    itemCount++; //Increase the itemCount variable
}

//Function to display the menu
void displayMenu() {
    printf("-----------------------------------------------------------\n");
    printf("%10s %30s %20s\n", "ITEM ID", "ITEM NAME", "PRICE");
    printf("-----------------------------------------------------------\n");
    
    for(int i=0; i<itemCount; i++) {
        printf("%10d %30s %20d\n", i+1, menu[i].itemName, menu[i].price);
    }
}

//Function to take the order from the customer
void takeOrder() {
    int itemId, quantity;
    printf("\nEnter the Item ID to order: ");
    scanf("%d", &itemId);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    
    //Update the quantity of the item in the menu array
    menu[itemId-1].quantity += quantity;
    
    //Calculate the total
    total += menu[itemId-1].price * quantity;
}

//Function to generate the bill
void generateBill() {
    printf("\n\n-----------------BILL-----------------\n");
    printf("%10s %30s %10s %10s\n", "ITEM ID", "ITEM NAME", "QUANTITY", "PRICE");
    printf("---------------------------------------\n");
    
    for(int i=0; i<itemCount; i++) {
        if(menu[i].quantity != 0) {
            printf("%10d %30s %10d %10d\n", i+1, menu[i].itemName, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    
    printf("---------------------------------------\n");
    printf("%50s %10d\n", "TOTAL", total);
}

int main() {
    //Add some items to the menu
    addItemToMenu("Coffee", 50);
    addItemToMenu("Tea", 30);
    addItemToMenu("Sandwich", 80);
    addItemToMenu("Burger", 100);
    
    //Display the menu
    displayMenu();
    
    //Take the order and generate the bill
    takeOrder();
    takeOrder();
    generateBill();
    
    return 0;
}