//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_ITEMS 100
#define MAX_NAME 50
 
/* Structure to store menu items */
struct MenuItem {
    char name[MAX_NAME];
    int price;
};
 
/* Global variables */
struct MenuItem menu[MAX_ITEMS];
int itemCount = 0;
int total = 0, discount = 0;
 
/* Function prototypes */
void addItem();
void removeItem();
void printBill();
 
/* Main function */
int main() {
    int choice;
 
    while (1) {
        printf("\nWelcome to our cafe billing system!\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Print Bill\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                printBill();
                break;
            case 4:
                printf("Thank you for using our cafe billing system!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
 
    return 0;
}
 
/* Function to add items to menu */
void addItem() {
    if (itemCount == MAX_ITEMS) {
        printf("Menu is full, cannot add more items.\n");
        return;
    }
 
    printf("Enter the name of the item: ");
    scanf("%s", menu[itemCount].name);
 
    printf("Enter the price of the item: ");
    scanf("%d", &menu[itemCount].price);
 
    itemCount++;
 
    printf("Item added successfully!\n");
}
 
/* Function to remove items from menu */
void removeItem() {
    char name[MAX_NAME];
    int i, j;
 
    if (itemCount == 0) {
        printf("Menu is empty, cannot remove items.\n");
        return;
    }
 
    printf("Enter the name of the item: ");
    scanf("%s", name);
 
    /* Find the menu item */
    for (i = 0; i < itemCount; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            /* Found the item, remove it */
            for (j = i; j < itemCount - 1; j++) {
                strcpy(menu[j].name, menu[j+1].name);
                menu[j].price = menu[j+1].price;
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
 
    /* Item not found */
    printf("Item not found, please try again.\n");
}
 
/* Function to print bill */
void printBill() {
    int i;
 
    if (itemCount == 0) {
        printf("Menu is empty, cannot generate bill.\n");
        return;
    }
 
    printf("\n====================\n");
    printf("     Cafe Bill\n");
    printf("====================\n");
 
    for (i = 0; i < itemCount; i++) {
        printf("%-30s %5d\n", menu[i].name, menu[i].price);
        total += menu[i].price; /* Calculate total */
    }
 
    printf("====================\n");
    printf("Total:                   %5d\n", total);
 
    /* Calculate discount based on total */
    if (total >= 100 && total < 200) {
        discount = 10;
    } else if (total >= 200 && total < 500) {
        discount = 20;
    } else if (total >= 500) {
        discount = 30;
    }
 
    if (discount > 0) {
        printf("Discount (%d%%):          %5d\n", discount, total * discount / 100);
        printf("====================\n");
        printf("Grand Total:             %5d\n", total - (total * discount / 100));
    } else {
        printf("Grand Total:             %5d\n", total);
    }
 
    /* Reset variables for next bill */
    total = 0;
    discount = 0;
}