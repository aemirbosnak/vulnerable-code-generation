//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

/* Menu Items */
struct {
    char name[50];
    float price;
} menu[MAX_ITEMS] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Sandwich", 4.00},
    {"Pizza", 5.00},
    {"Burger", 6.00},
    {"Soda", 1.00},
    {"Juice", 2.00},
    {"Water", 0.50},
    {"Chips", 1.50}
};

int num_items = sizeof(menu) / sizeof(menu[0]);

int main() {
    int choice;
    char name[50];
    float total = 0.00;

    srand(time(NULL));
    printf("Welcome to the Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(1) {
        printf("\n%s, here are the available items:\n", name);
        for(int i=0; i<num_items; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= num_items) {
            total += menu[choice-1].price;
            printf("\n%s, you ordered %s for $%.2f.\n", name, menu[choice-1].name, menu[choice-1].price);
        } else {
            printf("\nInvalid choice!\n");
        }

        printf("\nDo you want to order something else? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if(tolower(answer) == 'n') {
            break;
        }
    }

    printf("\n%s, your total bill is: $%.2f\n", name, total);

    return 0;
}