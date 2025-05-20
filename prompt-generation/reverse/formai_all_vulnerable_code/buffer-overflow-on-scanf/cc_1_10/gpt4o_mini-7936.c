//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n------ Welcome to the Energetic Cafe! ------\n");
    printf("Here is our amazing menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-------------------------------------------------\n");
    printf("Select items by entering their numbers (999 to finish):\n");
}

void calculateBill(MenuItem menu[], int selectedItems[], int count) {
    float total = 0.0;
    printf("\n------ Your Receipt ------\n");
    for (int i = 0; i < count; i++) {
        if (selectedItems[i] != -1) {
            printf("%s - $%.2f\n", menu[selectedItems[i]].name, menu[selectedItems[i]].price);
            total += menu[selectedItems[i]].price;
        }
    }
    printf("---------------------------\n");
    printf("Total Amount Due: $%.2f\n", total);
    printf("Thank you for visiting the Energetic Cafe! Come back soon!\n");
}

int main() {
    MenuItem menu[MAX_ITEMS];
    int selectedItems[MAX_ITEMS];
    int itemCount = 0;
    int itemIndex, selectedCount = 0;

    // Adding items to our menu
    strcpy(menu[itemCount].name, "Espresso");
    menu[itemCount++].price = 3.50;

    strcpy(menu[itemCount].name, "Cappuccino");
    menu[itemCount++].price = 4.00;

    strcpy(menu[itemCount].name, "Latte");
    menu[itemCount++].price = 4.50;

    strcpy(menu[itemCount].name, "Tea");
    menu[itemCount++].price = 2.00;

    strcpy(menu[itemCount].name, "Sandwich");
    menu[itemCount++].price = 5.00;

    strcpy(menu[itemCount].name, "Cake");
    menu[itemCount++].price = 3.00;

    displayMenu(menu, itemCount);

    // User input loop
    while (1) {
        printf("Enter the item number you wish to order (999 to calculate bill): ");
        scanf("%d", &itemIndex);
        
        if (itemIndex == 999) {
            break;
        }
        else if (itemIndex < 1 || itemIndex > itemCount) {
            printf("Invalid selection! Please choose a number from the menu.\n");
            continue;
        }
        
        selectedItems[selectedCount++] = itemIndex - 1; // store the item's index
    }

    // Set remaining selected items to -1
    for (int i = selectedCount; i < MAX_ITEMS; i++) {
        selectedItems[i] = -1;
    }

    calculateBill(menu, selectedItems, selectedCount);
    
    return 0;
}