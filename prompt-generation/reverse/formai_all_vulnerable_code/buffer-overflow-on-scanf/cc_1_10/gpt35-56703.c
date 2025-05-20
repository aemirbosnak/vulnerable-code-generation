//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, num_items = 0, i;
    float total = 0.0;
    struct item items[50];
    
    printf("Welcome to the Cafe Billing System!\n");
    printf("----------------------------------\n");
    
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add item\n");
        printf("2. View total bill\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                struct item new_item;
                
                printf("\nEnter item name: ");
                scanf("%s", new_item.name);
                
                printf("Enter quantity: ");
                scanf("%d", &new_item.quantity);
                
                printf("Enter price: ");
                scanf("%f", &new_item.price);
                
                items[num_items++] = new_item;
                printf("\nItem added to bill.\n");
                break;
            }
            case 2: {
                printf("\n\nItem\t  Quantity\t  Price\n");
                for(i=0; i<num_items; i++) {
                    printf("%s\t\t  %d\t\t  %.2f\n", items[i].name, items[i].quantity, items[i].price);
                    total += items[i].price * items[i].quantity;
                }
                printf("\nTotal bill: $%.2f\n\n", total);
                break;
            }
            case 3: {
                printf("\nThank you for using Cafe Billing System. Have a great day!\n");
                exit(0);
                break;
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
                break;
            }
        }
    } while(choice != 3);
    
    return 0;
}