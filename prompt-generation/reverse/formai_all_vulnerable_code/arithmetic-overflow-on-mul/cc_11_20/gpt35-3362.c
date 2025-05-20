//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char item_name[20];
    int item_price;
    int item_quantity;
};

typedef struct MenuItem MenuItem;

int main() {
    // Initializing menu items
    
    MenuItem menu[6];
    strcpy(menu[0].item_name, "Coffee");
    menu[0].item_price = 50;
    menu[0].item_quantity = 20;
    strcpy(menu[1].item_name, "Tea");
    menu[1].item_price = 30;
    menu[1].item_quantity = 15;
    strcpy(menu[2].item_name, "Sandwich");
    menu[2].item_price = 80;
    menu[2].item_quantity = 10;
    strcpy(menu[3].item_name, "Burger");
    menu[3].item_price = 100;
    menu[3].item_quantity = 8;
    strcpy(menu[4].item_name, "Fries");
    menu[4].item_price = 60;
    menu[4].item_quantity = 12;
    strcpy(menu[5].item_name, "Cake");
    menu[5].item_price = 120;
    menu[5].item_quantity = 6;
    
    int total = 0;
    int order_quantity = 0;
    int order_price = 0;
    int choice;
    int flag = 0;
    
    printf("Welcome to CyberCafe - The ultimate destination for cyberpunks!\n\n");
    
    while(1) {
        printf("Select an item:\n");
        printf("1. Coffee - %d Credits\n", menu[0].item_price);
        printf("2. Tea - %d Credits\n", menu[1].item_price);
        printf("3. Sandwich - %d Credits\n", menu[2].item_price);
        printf("4. Burger - %d Credits\n", menu[3].item_price);
        printf("5. Fries - %d Credits\n", menu[4].item_price);
        printf("6. Cake - %d Credits\n", menu[5].item_price);
        printf("0. Exit\n");
        printf("Your choice: ");
        
        scanf("%d", &choice);
        
        if(choice == 0) {
            break;
        }
        
        printf("Enter order quantity: ");
        scanf("%d", &order_quantity);
        
        switch(choice) {
            case 1:
                if(order_quantity <= menu[0].item_quantity) {
                    order_price = order_quantity * menu[0].item_price;
                    menu[0].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[0].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[0].item_name);
                }
                break;
            case 2:
                if(order_quantity <= menu[1].item_quantity) {
                    order_price = order_quantity * menu[1].item_price;
                    menu[1].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[1].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[1].item_name);
                }
                break;
            case 3:
                if(order_quantity <= menu[2].item_quantity) {
                    order_price = order_quantity * menu[2].item_price;
                    menu[2].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[2].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[2].item_name);
                }
                break;
            case 4:
                if(order_quantity <= menu[3].item_quantity) {
                    order_price = order_quantity * menu[3].item_price;
                    menu[3].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[3].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[3].item_name);
                }
                break;
            case 5:
                if(order_quantity <= menu[4].item_quantity) {
                    order_price = order_quantity * menu[4].item_price;
                    menu[4].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[4].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[4].item_name);
                }
                break;
            case 6:
                if(order_quantity <= menu[5].item_quantity) {
                    order_price = order_quantity * menu[5].item_price;
                    menu[5].item_quantity -= order_quantity;
                    total += order_price;
                    printf("%d units of %s added to order.\n", order_quantity, menu[5].item_name);
                } else {
                    printf("Sorry, not enough %s left in stock.\n", menu[5].item_name);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
        
        printf("Current order:\n");
        printf("Item Name\tQuantity\tPrice\n");
        
        for(int i=0;i<6;i++) {
            if(menu[i].item_quantity != 0) {
                printf("%s\t\t%d\t\t%d\n", menu[i].item_name, menu[i].item_quantity, menu[i].item_price);
                flag++;
            }
        }
        
        if(flag == 0) {
            printf("All items out of stock.\n");
            break;
        } else {
            flag = 0;
        }
        
        printf("Total price so far: %d Credits\n", total);
        printf("=========================================\n\n");
    }
    
    printf("Thank you for visiting CyberCafe. Your bill for this session is %d Credits.\n", total);
    printf("Please come again!\n");

    return 0;
}