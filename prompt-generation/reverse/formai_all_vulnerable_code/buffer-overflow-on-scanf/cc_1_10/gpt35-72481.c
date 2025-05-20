//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold menu items */
typedef struct {
    char name[30];
    float price;
} MenuItem;

float calculate_bill(MenuItem items[], int quantities[], int num_items);

int main() {
    MenuItem menu[5] = {{"coffee", 1.50}, {"muffin", 2.00}, {"bagel", 1.75}, {"croissant", 2.25}, {"toast", 1.00}};
    int quantities[5] = {0};
    int num_items = 5;
    
    int choice = 0;
    do {
        printf("Welcome to the Cafe Billing System! What would you like to do?\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View current order\n");
        printf("4. Calculate bill and exit\n");
        printf("> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                char item_name[30];
                printf("Enter the name of the item you would like to add: ");
                scanf("%s", item_name);
                
                int found_item = 0;
                for(int i = 0; i < num_items; i++) {
                    if(strcmp(item_name, menu[i].name) == 0) {
                        found_item = 1;
                        printf("%s added to order!\n", menu[i].name);
                        quantities[i]++;
                        break;
                    }
                }
                
                if(!found_item) {
                    printf("Sorry, we do not offer that item.\n");
                }
                
                break;
            }
            case 2: {
                char item_name[30];
                printf("Enter the name of the item you would like to remove: ");
                scanf("%s", item_name);
                
                int found_item = 0;
                for(int i = 0; i < num_items; i++) {
                    if(strcmp(item_name, menu[i].name) == 0) {
                        found_item = 1;
                        if(quantities[i] > 0) {
                            printf("%s removed from order!\n", menu[i].name);
                            quantities[i]--;
                        }
                        else {
                            printf("There are no %s items in your order.\n", menu[i].name);
                        }
                        break;
                    }
                }
                
                if(!found_item) {
                    printf("Sorry, we do not offer that item.\n");
                }
                
                break;
            }
            case 3: {
                printf("Current Order: \n");
                for(int i = 0; i < num_items; i++) {
                    if(quantities[i] > 0) {
                        printf("%s x%d\n", menu[i].name, quantities[i]);
                    }
                }
                break;
            }
            case 4: {
                float bill = calculate_bill(menu, quantities, num_items);
                printf("Your bill is $%.2f. Thank you for your business!\n", bill);
                exit(0);
            }
            default: {
                printf("Sorry, that is not a valid choice.\n");
            }
        }
    } while(choice != 4);
    
    return 0;
}

/* Calculate total bill for items in order */
float calculate_bill(MenuItem items[], int quantities[], int num_items) {
    float total_bill = 0.0;
    for(int i = 0; i < num_items; i++) {
        total_bill += items[i].price * quantities[i];
    }
    return total_bill;
}