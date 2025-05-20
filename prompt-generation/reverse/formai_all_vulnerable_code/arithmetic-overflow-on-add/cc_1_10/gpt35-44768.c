//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int price;
    int quantity;
    int total;
};

int main() {
    struct item menu[5];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 30;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 80;
    strcpy(menu[3].name, "Muffin");
    menu[3].price = 40;
    strcpy(menu[4].name, "Croissant");
    menu[4].price = 60;

    int order[5] = {0, 0, 0, 0, 0};

    printf("Welcome to the C Cafe! Here's our menu:\n");
    printf("Item\t\tPrice\n");
    printf("===================================\n");
    for(int i=0; i<5; i++) {
        printf("%s\t\t$%d\n", menu[i].name, menu[i].price);
    }
    printf("===================================\n");

    while(1) {
        printf("\nWhat would you like to order? (Enter 0 to checkout)\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 0) {
            printf("Your order is:\n");
            printf("Item\t\tQuantity\tPrice\t\tTotal\n");
            printf("==============================================\n");
            int subtotal = 0;
            for(int i=0; i<5; i++) {
                if(order[i] != 0) {
                    int total = order[i] * menu[i].price;
                    printf("%s\t\t%d\t\t$%d\t\t$%d\n", menu[i].name, order[i], menu[i].price, total);
                    subtotal += total;
                }
            }
            printf("==============================================\n");
            printf("Subtotal: $%d\n", subtotal);
            printf("Tax (10%%): $%d\n", (int)(0.1 * subtotal));
            printf("Total: $%d\n", (int)(1.1 * subtotal));
            break;
        }
        if(choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }
        printf("How many %s would you like?\n", menu[choice-1].name);
        int qty;
        scanf("%d", &qty);
        order[choice-1] += qty;
    }

    return 0;
}