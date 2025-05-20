//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct menu {
    char *name;
    int price;
};

int main()
{
    int num_items;
    int i;
    struct menu *items;
    int total = 0;
    
    printf("Welcome to the C Cafe Billing System!\n\n");
    
    printf("How many items did the customer purchase?\n");
    scanf("%d", &num_items);
    
    items = (struct menu *) malloc(num_items * sizeof(struct menu));
    
    // Populate menu items
    for(i=0; i<num_items; i++){
        items[i].name = (char *) malloc(20 * sizeof(char));
        
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &items[i].price);
        
        total += items[i].price;
    }
    
    // Print bill
    printf("\nThank you for eating at the C Cafe!\n\n");
    printf("+---------------+-------+\n");
    printf("|     ITEM      | PRICE |\n");
    printf("+---------------+-------+\n");
    
    for(i=0; i<num_items; i++){
        printf("| %-14s|%7d |\n", items[i].name, items[i].price);
    }
    
    printf("+---------------+-------+\n");
    printf("|      TOTAL    |%7d |\n", total);
    printf("+---------------+-------+\n");
    
    return 0;
}