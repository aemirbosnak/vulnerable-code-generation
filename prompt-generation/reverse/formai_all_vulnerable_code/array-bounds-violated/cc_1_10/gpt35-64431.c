//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>

// Structure to store the menu item
struct MenuItem {
    char name[50];
    int price;
};

// Function to print the menu
void printMenu(struct MenuItem menu[], int size) {
    printf("NAME\t\tPRICE\n");
    for(int i = 0; i < size; i++) {
        printf("%s\t\t%d\n", menu[i].name, menu[i].price);
    }
}

int main() {
    // Initializing the menu
    struct MenuItem menu[5];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 30;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 70;
    strcpy(menu[3].name, "Muffin");
    menu[3].price = 40;
    strcpy(menu[4].name, "Cakeslice");
    menu[4].price = 60;
    
    int option, quantity, amount = 0;
    char choice;
    
    // Printing the menu for the user
    printMenu(menu, 5);
    
    // Taking the order from the user
    do {
        printf("Enter the option and quantity: ");
        scanf("%d %d", &option, &quantity);
        amount += (menu[option-1].price * quantity);
        printf("Do you want to order anything else? ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    
    // Printing the bill
    printf("\nBill:\n");
    printf("NAME\t\tQUANTITY\tPRICE\n");
    for(int i = 0; i < 50; i++) printf("-");
    printf("\n");
    for(int i = 0; i < 5; i++) {
        printf("%s\t\t%d\t\t%d\n", menu[i].name, quantity, (menu[i].price * quantity));
    }
    for(int i = 0; i < 50; i++) printf("-");
    printf("\nTotal Amount: %d", amount);
    
    return 0;
}