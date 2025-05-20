//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int main() {
    int num_items, i;
    item menu[MAX_ITEMS];
    float total_cost = 0;
    char choice;

    printf("Welcome to the Cafe Billing System!\n");

    // Read in the menu items from a file
    FILE *menu_file = fopen("menu.txt", "r");
    if (menu_file == NULL) {
        printf("Error: Could not open menu file.\n");
        return 1;
    }

    num_items = 0;
    while (fscanf(menu_file, "%s %s", menu[num_items].name, menu[num_items].price)!= EOF) {
        num_items++;
    }
    fclose(menu_file);

    if (num_items == 0) {
        printf("Error: Menu file is empty.\n");
        return 1;
    }

    // Display the menu and take the customer's order
    printf("\nMenu:\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, atof(menu[i].price));
    }

    printf("\nEnter the number of the item you would like to order: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_items) {
        printf("Invalid choice.\n");
        return 1;
    }

    // Calculate the total cost of the order
    total_cost = atof(menu[choice-1].price);

    // Print the receipt
    printf("\nReceipt:\n");
    printf("Item: %s\n", menu[choice-1].name);
    printf("Price: $%.2f\n", total_cost);
    printf("Total Cost: $%.2f\n", total_cost);

    return 0;
}