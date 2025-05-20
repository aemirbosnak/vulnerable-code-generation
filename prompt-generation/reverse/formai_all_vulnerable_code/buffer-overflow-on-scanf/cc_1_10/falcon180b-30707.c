//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 10
#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 50
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int price;
} Item;

void display_menu(Item menu[], int num_items) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d - %s\n", i+1, menu[i].name, menu[i].price, menu[i].description);
    }
}

int main() {
    Item menu[MAX_ITEMS];
    int num_items = 0;

    menu[num_items++] = (Item) {.name = "Coffee",.description = "A hot cup of joe",.price = 3 };
    menu[num_items++] = (Item) {.name = "Tea",.description = "A soothing cup of tea",.price = 2 };
    menu[num_items++] = (Item) {.name = "Cake",.description = "A slice of delicious cake",.price = 5 };
    menu[num_items++] = (Item) {.name = "Sandwich",.description = "A tasty sandwich",.price = 7 };

    int choice;
    printf("Welcome to the Cafe Billing System!\n");
    while (1) {
        display_menu(menu, num_items);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= num_items) {
            printf("You chose %s for $%d.\n", menu[choice-1].name, menu[choice-1].price);
            printf("Thank you for your purchase!\n");
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}