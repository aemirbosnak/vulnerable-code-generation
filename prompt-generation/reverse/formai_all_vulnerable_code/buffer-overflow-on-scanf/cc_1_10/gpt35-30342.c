//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

// Struct to hold items in the cafe 
typedef struct Item {
    char name[50];
    float price;
} Item;

// Method to display menu
void display_menu(Item menu[], int size) {
    printf("** MENU **\n");
    for(int i=0;i<size;i++) {
        printf("%s: $%.2f\n", menu[i].name, menu[i].price);
    }
}

// Method to calculate total bill
float calculate_bill(Item menu[], int size, int order_list[], int order_size) {
    float total_bill = 0.0;
    for(int i=0;i<order_size;i++) {
        total_bill += menu[order_list[i]-1].price;
    }
    return total_bill;
}

int main() {
    Item menu[MAX_ITEMS]; // Create an array to hold menu items
    int order_list[MAX_ITEMS], order_size=0; // Create an array to hold order and its size
    int choice;
    float total_bill;
    
    // Add some items to the menu
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 1.50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 1.30;
    strcpy(menu[2].name, "Pastry");
    menu[2].price = 2.00;
    int menu_size = 3;
    
    // Display the menu
    display_menu(menu, menu_size);
    
    do {
        printf("\nWhat would you like to order? (Enter item number. Press 0 to exit): ");
        scanf("%d", &choice);
        if(choice > 0 && choice <= menu_size) {
            order_list[order_size] = choice;
            order_size++;
        }
        else if(choice != 0) {
            printf("Invalid option. Please choose again.\n");
        }
    } while(choice != 0);
    
    // Calculate total bill
    total_bill = calculate_bill(menu, menu_size, order_list, order_size);
    
    // Print the final bill
    printf("Your total bill is: $%.2f\n", total_bill);
    
    return 0;
}