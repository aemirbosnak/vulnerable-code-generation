//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, quantity, total_items = 0;
    double item_price = 0.0, subtotal = 0.0, grand_total = 0.0, discount = 0.0;
    char item_name[50];
    
    printf("Welcome to C Cafe!\n");
    printf("Please choose an item from the menu below:\n");
    printf("1. Espresso - $2.50\n2. Latte - $3.00\n3. Cappuccino - $3.25\n4. Croissant - $2.00\n5. Blueberry Muffin - $2.50\n");
    
    while(1) {
        printf("\nEnter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("\nThank you for visiting C Cafe! Your total bill is: $%.2f\n", grand_total);
                exit(0);
            case 1:
                strcpy(item_name, "Espresso");
                item_price = 2.5;
                break;
            case 2:
                strcpy(item_name, "Latte");
                item_price = 3.0;
                break;
            case 3:
                strcpy(item_name, "Cappuccino");
                item_price = 3.25;
                break;
            case 4:
                strcpy(item_name, "Croissant");
                item_price = 2.0;
                break;
            case 5:
                strcpy(item_name, "Blueberry Muffin");
                item_price = 2.5;
                break;
            default:
                printf("\nInvalid choice, please choose again!\n");
                continue;
        }
        
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        
        total_items += quantity;
        subtotal += item_price * quantity;
        
        printf("%d %s added to your order.\n", quantity, item_name);
        printf("Press 1 to add more items, 2 to generate the bill: ");
        scanf("%d", &choice);
        
        if (choice == 2) {
            printf("\n\n\t\tC CAFE BILL\n\n");
            printf("--------------------------------------------------\n");
            printf("ITEM NAME\t\tQUANTITY\t\tPRICE\n");
            printf("--------------------------------------------------\n");
            if (total_items > 0) {
                printf("%s\t\t\t%d\t\t\t%.2f\n", item_name, quantity, item_price);
            }
            printf("\n--------------------------------------------------\n");
            printf("SUBTOTAL\t\t\t\t\t%.2f\n", subtotal);
            
            if (subtotal > 10 && subtotal <= 20) {
                discount = 0.1 * subtotal;
            } else if (subtotal > 20) {
                discount = 0.2 * subtotal;
            }
            
            grand_total = subtotal - discount;
            
            printf("DISCOUNT\t\t\t\t\t%.2f\n", discount);
            printf("GRAND TOTAL\t\t\t\t\t%.2f\n", grand_total);
        }
    }
    return 0;
}