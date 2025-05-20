//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

struct menu {
    int id, price;
    char *item_name;
};

typedef struct menu Menu;
Menu menu_list[10] = {
    {1, 15, "Coffee"},
    {2, 20, "Tea"},
    {3, 25, "Hot Chocolate"},
    {4, 30, "Milkshake"},
    {5, 50, "Pizza"},
    {6, 70, "Burger"},
    {7, 80, "Pasta"},
    {8, 100, "Grilled Chicken"},
    {9, 120, "Fish and Chips"},
    {10, 150, "Lasagna"},
};

int main() {
    int qty, total_price = 0, i;
    char choice;
    printf("\t\t****Welcome to JJ's Cafe!****\n");
    printf("\t\t=====MENU=====\n");
    printf("\tID\tITEM\t\t\t\tPRICE\n");
    for (i = 0; i < 10; i++) 
        printf("\t%d\t%-20s%d\n", menu_list[i].id, menu_list[i].item_name, menu_list[i].price);
    do {
        int menu_id;
        printf("\nChoose an item (Enter its ID): ");
        scanf("%d", &menu_id);
        printf("Enter the quantity: ");
        scanf("%d", &qty);
        for (i = 0; i < 10; i++) {
            if (menu_list[i].id == menu_id) {
                total_price += qty * menu_list[i].price;
                break;
            }
        }
        printf("Add another item? (y/n): ");
        fflush(stdin); // clear input buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("\nTotal cost: %d\n", total_price);
    printf("\n\t\tThank You! Visit Again :)\n");
    return 0;
}