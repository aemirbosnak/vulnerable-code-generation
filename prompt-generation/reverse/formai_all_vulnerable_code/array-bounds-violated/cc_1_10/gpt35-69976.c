//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_ITEMS 10   // Maximum number of items that can be ordered
#define ITEM_NAME_LEN 20   // Maximum length of an item name
#define ITEM_PRICE_LEN 10   // Maximum length of an item price

int main() {
    char menu[MAX_ITEMS][ITEM_NAME_LEN];  // Array to store item names
    char price[MAX_ITEMS][ITEM_PRICE_LEN];  // Array to store item prices
    int qty[MAX_ITEMS];  // Array to store the quantity of each item ordered
    int total_items = 0;    // Counter to keep track of the total number of items ordered
    float sub_total = 0;    // Counter to keep track of the sub-total of the items ordered
    float vat = 0;  // Counter to keep track of the VAT amount
    float grand_total = 0;  // Counter to keep track of the grand total

    // Loop to get the item details from the user
    while(total_items < MAX_ITEMS) {
        printf("Enter item name (or 'quit' to exit): ");
        fgets(menu[total_items], ITEM_NAME_LEN, stdin);
        menu[total_items][strlen(menu[total_items])-1] = '\0';   // Removing the newline character

        if(strcmp(menu[total_items], "quit") == 0) {
            break;
        }

        printf("Enter the price of %s in Naira: ", menu[total_items]);
        fgets(price[total_items], ITEM_PRICE_LEN, stdin);
        price[total_items][strlen(price[total_items])-1] = '\0';   // Removing the newline character

        // Loop to check if the price entered is a valid number
        int valid_price = 1;
        for(int i=0; i<strlen(price[total_items]); i++) {
            if(!isdigit(price[total_items][i]) && price[total_items][i] != '.') {
                valid_price = 0;
                break;
            }
        }

        // If the price is valid, then proceed to get the quantity of the item ordered
        if(valid_price) {
            printf("Enter the quantity of %s ordered: ", menu[total_items]);
            scanf("%d", &qty[total_items]);

            // Calculating the sub-total of the order
            sub_total += atof(price[total_items]) * qty[total_items];

            // Incrementing the item count
            total_items++;
            
            // Clearing the input buffer and proceeding to the next item
            fflush(stdin);
        }
        // If the price is invalid, then prompt the user to enter a valid price
        else {
            printf("Invalid price entered for %s. Please enter a valid price.\n", menu[total_items]);
        }
    }

    // If no items were ordered, then exit the program
    if(total_items == 0) {
        printf("No items ordered. Exiting program.\n");
        return 0;
    }

    // Calculating the VAT amount and the grand total
    vat = sub_total * 0.05;
    grand_total = sub_total + vat;

    // Printing the bill
    printf("\n\n\t\tCafe Billing System\n");
    printf("---------------------------------------------\n");
    printf("Item Name\tPrice\tQuantity\tTotal\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<total_items; i++) {
        printf("%s\t\t%s\t%d\t\t%.2f\n", menu[i], price[i], qty[i], atof(price[i]) * qty[i]);
    }
    printf("---------------------------------------------\n");
    printf("Sub-Total\t\t\t\t%.2f\n", sub_total);
    printf("VAT (5%%)\t\t\t\t%.2f\n", vat);
    printf("Grand Total\t\t\t\t%.2f\n", grand_total);
    printf("---------------------------------------------\n");

    return 0;
}