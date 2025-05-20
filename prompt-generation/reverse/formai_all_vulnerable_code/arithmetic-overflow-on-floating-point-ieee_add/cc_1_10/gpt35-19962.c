//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structure to store the details of a menu item
typedef struct MenuItem{
    int id; //menu item id
    char name[50]; //menu item name
    float price; //menu item price
    int quantity; //quantity ordered
} MenuItem;

//Function to print the menu
void printMenu(MenuItem* menu, int length){
    printf("Menu:\n");
    printf("---------------------------------------\n");
    printf("|%-5s|%-20s|%-10s|\n", "ID", "Name", "Price");
    printf("---------------------------------------\n");
    for(int i=0; i<length; i++){
        printf("|%-5d|%-20s|%-10.2f|\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("---------------------------------------\n\n");
}

//Function to get the index of a menu item given its id
int getIndexById(MenuItem* menu, int length, int id){
    for(int i=0; i<length; i++){
        if(menu[i].id == id){
            return i;
        }
    }
    return -1;
}

//Function to get the total bill for the order
float getTotalBill(MenuItem* orderedItems, int length){
    float totalBill = 0;
    for(int i=0; i<length; i++){
        totalBill += orderedItems[i].price * orderedItems[i].quantity;
    }
    return totalBill;
}

int main(){
    //Initialize the menu
    MenuItem menu[5] = {
        {1, "Coffee", 2.5, 0},
        {2, "Tea", 2.0, 0},
        {3, "Sandwich", 3.5, 0},
        {4, "Burger", 4.0, 0},
        {5, "Pizza", 5.0, 0}
    };
    int menuLength = 5;

    //Print the menu
    printMenu(menu, menuLength);

    //Initialize the ordered items
    MenuItem* orderedItems = (MenuItem*) malloc(sizeof(MenuItem) * menuLength);
    memset(orderedItems, 0, sizeof(MenuItem) * menuLength);

    //Get the order from the user
    int choice = 0;
    do{
        printf("Enter the item ID (0 to exit): ");
        scanf("%d", &choice);
        if(choice != 0){
            int index = getIndexById(menu, menuLength, choice);
            if(index != -1){
                printf("Enter the quantity: ");
                scanf("%d", &orderedItems[index].quantity);
            }
            else{
                printf("Invalid item ID\n");
            }
        }
    }while(choice != 0);

    //Print the order
    printf("\nOrder:\n");
    printf("--------------------------------------------------\n");
    printf("|%-5s|%-20s|%-10s|%-10s|\n", "ID", "Name", "Price", "Quantity");
    printf("--------------------------------------------------\n");
    for(int i=0; i<menuLength; i++){
        if(orderedItems[i].quantity > 0){
            printf("|%-5d|%-20s|%-10.2f|%-10d|\n", menu[i].id, menu[i].name, menu[i].price, orderedItems[i].quantity);
        }
    }
    printf("--------------------------------------------------\n");

    //Get the total bill
    float totalBill = getTotalBill(orderedItems, menuLength);

    //Print the bill
    printf("\nTotal bill: %.2f\n", totalBill);

    //Free the memory allocated for orderedItems
    free(orderedItems);

    return 0;
}