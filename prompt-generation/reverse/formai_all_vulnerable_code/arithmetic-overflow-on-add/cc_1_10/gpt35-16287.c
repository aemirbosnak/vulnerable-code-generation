//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_ITEMS 100 // Setting a maximum item limit for the cafe

struct item { // Declaring a structure to hold each item's information
    char name[30]; // Item name
    int price; // Item price
    int quantity; // Item quantity
};
struct item cafeMenu[MAX_ITEMS]; // Creating an array of items to hold menu items

int cafeSize = 0; // Initialising the array size to zero

void addMenuItem(char name[], int price, int quantity){ // Function to add a new item to the menu
    struct item newItem;
    strcpy(newItem.name, name);
    newItem.price = price;
    newItem.quantity = quantity;
    if(cafeSize==MAX_ITEMS){
        printf("Sorry, the cafe has reached its maximum item limit\n"); // Handling maximum item limit
    }
    else{
        cafeMenu[cafeSize++] = newItem; // Adding the new item to the array
        printf("New item added to the menu: %s\n", newItem.name); 
    }
}

void showMenu(){ // Function to display the cafe menu
    printf("Cafe Menu\n");
    int i;
    for(i=0; i<cafeSize; i++){
        printf("%d)%s\tPrice:$%d\tQuantity:%d\n", i+1, cafeMenu[i].name, cafeMenu[i].price, cafeMenu[i].quantity);
    }
    printf("\n");
}

int main(){
    printf("Welcome to the Cafe Billing System\n");
    int choice, total = 0, quantity, bill, i, flag=0;
    char itemName[30];
    addMenuItem("Sandwich", 5, 10);
    addMenuItem("Burger", 7, 15);
    addMenuItem("Pizza", 10, 20); // Adding initial menu items
    while(1){
        printf("Enter 1 to display menu, 2 to place an order, 3 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: // Displaying the menu
                showMenu();
                break;
            case 2: // Placing an order
                printf("Enter item name and quantity to place the order\n");
                scanf("%s %d", itemName, &quantity);
                flag=1;
                for(i=0; i<cafeSize; i++){
                    if(strcmp(cafeMenu[i].name, itemName)==0){ // Checking if the item is on the menu
                        flag=0;
                        if(cafeMenu[i].quantity>=quantity){ // Checking if enough stock is available
                            bill = quantity * cafeMenu[i].price;
                            total += bill;
                            cafeMenu[i].quantity -= quantity;
                            printf("Order placed successfully.\n");
                            break;
                        }
                        else{
                            printf("Sorry, not enough stock available for %s.\n", itemName);
                            break;
                        }
                    }
                }
                if(flag){
                    printf("Sorry, %s is not available on the menu.\n", itemName);
                }
                break;
            case 3: // Exiting the program
                printf("Thank you for using the Cafe Billing System.\n");
                printf("Total bill: $%d\n", total);
                exit(0);
                break;
            default: // Handling invalid menu options
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}